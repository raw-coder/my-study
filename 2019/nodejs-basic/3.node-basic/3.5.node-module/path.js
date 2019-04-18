const path = require('path');

const string = __filename;

console.log(path.sep); // 경로 구분자
console.log(path.delimiter); // 환경 변수 구분자

console.log(path.dirname(string)); // 파일경로
console.log(path.extname(string)); // 확장자
console.log(path.basename(string)); // 파일이름(확장자포함)
console.log(path.basename(string, path.extname(string))); // 파일이름

console.log(path.parse(string));
console.log(path.format({
  dir: 'c:\\users\\steve',
  name: 'path',
  ext: '.js'
}));

console.log(path.normalize('C:///steve\\\\\helllo.js')); // 중복된 경로 구분자 정상처리

console.log(path.isAbsolute('C:\\'));  // 절대경로 여부 리턴
console.log(path.isAbsolute('./home'));

console.log(path.relative('c:\\home\\abc\\def', 'c:\\home')); // 두 경로 사이의 상대경로

console.log(path.join(__dirname, '..', '..', '/users', '.', '/steve')); // 하나의 경로로 합침
console.log(path.resolve(__dirname, '..', 'users', '/steve')); // 하나의 경로로 합침 (절대 경로 있을 시 앞의 경로 무시)

