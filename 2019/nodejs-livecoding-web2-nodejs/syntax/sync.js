const fs = require('fs');

/*
// readFileSync : A B C
console.log('A');
const result = fs.readFileSync('./syntax/sample.txt', 'utf-8');
console.log(result);
console.log('C');
 */

// readFile : A C B
console.log('A');
fs.readFile('./syntax/sample.txt', 'utf-8', (err, result) => {
  console.log(result);
});
console.log('C');