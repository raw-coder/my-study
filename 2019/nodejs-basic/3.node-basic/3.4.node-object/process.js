console.log(process.version);
console.log(process.arch);
console.log(process.platform);
console.log(process.pid);
console.log(process.uptime());
console.log(process.execPath);
console.log(process.cwd());
console.log(process.cpuUsage());

console.log('########');
console.log(process.env); // 운영체제 마다 환경변수 넣는 방법 다름, dotenv 참고