const http = require('http');
const fs = require('fs');
const url = require('url');

const app = http.createServer(function (request, response) {
  let _url = request.url;
  const queryData = url.parse(_url, true).query;
  const pathname = url.parse(_url, true).pathname;

  if (pathname === '/') {
    if (queryData.id === undefined) {
      let title = 'Welcome';
      let description = 'Welcome, Node.js';

      fs.readdir('./data', (err, files) => {

        let list = '<ul>';

        let i = 0;
        while(i < files.length) {
          list += `<li><a href="/?id=${files[i]}">${files[i]}</a></li>`;
          i = i + 1;
        }
        list += '</ul>';

        const template = `
        <!doctype html>
        <html>
        <head>
          <title>WEB1 - ${title}</title>
          <meta charset="utf-8">
        </head>
        <body>
          <h1><a href="/">WEB</a></h1>
          ${list}
          <h2>${title}</h2>
          <p>${description}
          </p>
        </body>
        </html>
        `;
        response.writeHead(200);
        response.end(template);
      });
    } else {
      fs.readFile(`data/${queryData.id}`, 'utf-8', (err, description) => {
        let title = queryData.id;

        fs.readdir('./data', (err, files) => {

          let list = '<ul>';

          let i = 0;
          while (i < files.length) {
            list += `<li><a href="/?id=${files[i]}">${files[i]}</a></li>`;
            i = i + 1;
          }
          list += '</ul>';

          const template = `
          <!doctype html>
          <html>
          <head>
            <title>WEB1 - ${title}</title>
            <meta charset="utf-8">
          </head>
          <body>
            <h1><a href="/">WEB</a></h1>
            ${list}
            <h2>${title}</h2>
            <p>${description}
            </p>
          </body>
          </html>
          `;
          response.writeHead(200);
          response.end(template);
        });
      });
    }
  } else {
    response.writeHead(404);
    response.end('Not found');
  }

});
app.listen(3000);