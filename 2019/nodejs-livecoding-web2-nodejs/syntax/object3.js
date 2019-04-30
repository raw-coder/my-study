let v1 = 'v1';
// ... 중간에 v1 = 'aaaa' 라는 code가 들어가면 v1 값을 보장할 수 없음
let v2 = 'v2';


let o = {
  v1: 'v1',
  v2: 'v2',
  f1: function () {
    console.log(this.v1);
  },
  f2: function () {
    console.log(this.v2);
  }
};

let f1 = () => {
  console.log(o.v1);
};

// ... 중간에 f1 재정의하면 함수 동작을 보장할 수 없음

let f2 = () => {
  console.log(o.v2);
};

f1();
f2();

o.f1();
o.f2();

