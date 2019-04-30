const http = require('http');
const fs = require('fs');
const url = require('url');
const qs = require('querystring');
const template = require('./lib/template');
const path = require('path');
const sanitizeHtml = require('sanitize-html');

const app = http.createServer(function (request, response) {
  let _url = request.url;
  const queryData = url.parse(_url, true).query;
  const pathname = url.parse(_url, true).pathname;

  if (pathname === '/') {
    if (queryData.id === undefined) {
      const title = 'Welcome';
      const description = 'Welcome, Node.js';
      fs.readdir('./data', (err, files) => {
        const list = template.list(files);
        const templateHtml = template.html(title, list,
          `<h2>${title}</h2><p>${description}</p>`,
          '<a href="/create">Create</a>');
        response.writeHead(200);
        response.end(templateHtml);
      });
    } else {
      const filteredId = path.parse(queryData.id).base;
      fs.readFile(`data/${filteredId}`, 'utf-8', (err, description) => {
        fs.readdir('./data', (err, files) => {
          const title = queryData.id;
          const sanitizedTitle = sanitizeHtml(title);
          const sanitizedDescription = sanitizeHtml(description, {
              allowedTags: ['h1']
          });
          const list = template.list(files);
          const templateHtml = template.html(title, list,
            `<h2>${sanitizedTitle}</h2><p>${sanitizedDescription}</p>`,
            `<a href="/create">Create</a> <a href="/update?id=${sanitizedTitle}">Update</a> 
            <form action="/delete_process" method="post">
                <input type="hidden" name="id" value="${sanitizedTitle}">
                <input type="submit" value="Delete">
            </form>`);
          response.writeHead(200);
          response.end(templateHtml);
        });
      });
    }
  } else if (pathname === '/create') {
    const title = 'Web - create';
    fs.readdir('./data', (err, files) => {
      const list = template.list(files);
      const templateHtml = template.html(title, list,
        `<form action="/create_process" method="post">
                  <p><input type="text" name="title" placeholder="title"></p>
                  <p>
                    <textarea name="description" placeholder="description"></textarea>
                  </p>
                  <p>
                    <input type="submit">
                  </p>
                </form>`,
        '');
      response.writeHead(200);
      response.end(templateHtml);
    });
  } else if (pathname === '/create_process') {
    let body = '';

    request.on('data', (data) => {
      body = body + data;
    });

    request.on('end', () => {
      let post = qs.parse(body);
      let title = post.title;
      let description = post.description
      fs.writeFile(`./data/${title}`, description, 'utf-8', (err) => {
        response.writeHead(302, {
          Location: `/?id=${title}`
        });
        response.end();
      })
    });
  } else if (pathname === '/update') {
    const filteredId = path.parse(queryData.id).base;
    fs.readFile(`data/${filteredId}`, 'utf-8', (err, description) => {
      fs.readdir('./data', (err, files) => {
        const title = queryData.id;
        const list = template.list(files);
        const templateHtml = template.html(title, list,
          `<form action="/update_process" method="post">
                    <input type="hidden" name="id" value="${title}">
                    <p><input type="text" name="title" placeholder="title" value="${title}"></p>
                    <p>
                      <textarea name="description" placeholder="description">${description}</textarea>
                    </p>
                    <p>
                      <input type="submit">
                    </p>
                  </form>`,
          `<a href="/create">Create</a> <a href="/update?id=${title}">Update</a>`);
        response.writeHead(200);
        response.end(templateHtml);
      });
    });
  } else if (pathname === '/update_process') {
    let body = '';
    request.on('data', (data) => {
      body = body + data;
    });
    request.on('end', () => {
      let post = qs.parse(body);
      let id = post.id;
      let title = post.title;
      let description = post.description;

      fs.rename(`./data/${id}`, `./data/${title}`, (error) => {
        fs.writeFile(`./data/${title}`, description, 'utf-8', (err) => {
          response.writeHead(302, {
            Location: `/?id=${title}`
          });
          response.end();
        })
      });
    });
  } else if (pathname === '/delete_process') {
    let body = '';
    request.on('data', (data) => {
      body = body + data;
    });
    request.on('end', () => {
      let post = qs.parse(body);
      let id = post.id;
      const filteredId = path.parse(id).base;
      fs.unlink(`./data/${filteredId}`, (error) => {
        response.writeHead(302, {
          Location: '/'
        });
        response.end();
      })
    });
  } else {
    response.writeHead(404);
    response.end('Not found');
  }

});
app.listen(3000);