setImmediate(() => {
  console.log('immediate');
});

process.nextTick(() => {
  console.log('nextTick');
});

setTimeout(() => {
  console.log('setTimeout');
}, 0);

Promise.resolve().then(() => {
  console.log('promise');
});

// nextTick, promise 가 우선 실행됨 : microtask (task 큐와 별도의 마이크로 태스트 큐에서 처리됨)
