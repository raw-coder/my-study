const f = () => {
  console.log(1 + 1);
  console.log(1 + 2);
};

console.log(f);
f();

const a = [f]; // 배열의 원소로 함수
a[0]();

const o = {
  func: f
}; // 객체의 원소로 함수
o.func();


