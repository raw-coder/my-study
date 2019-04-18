const os = require('os');

// 운영체제 정보
console.log('운영체제 정보');
console.log(os.arch());
console.log(os.platform());
console.log(os.type());
console.log(os.uptime());
console.log(os.hostname());
console.log(os.release());

// 경로
console.log('경로');
console.log(os.homedir());
console.log(os.tmpdir());

// cpu 정보
console.log('cpu 정보');
console.log(os.cpus());
console.log(os.cpus().length);

// 메모리 정보
console.log('메모리 정보');
console.log(os.freemem());
console.log(os.totalmem());