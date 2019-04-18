const condition = true;

// promise 기본 생성 방법
const promise = new Promise(((resolve, reject) => {
  if (condition) {
    resolve('성공');
  } else {
    reject('실패');
  }
}));

// then, catch 로 promise의 resolve, reject의 매개변수를 인자로 받아서 처리
promise.then((message) => {
  console.log(message);
}).catch((error) => {
  console.log(error);
});

// chaining 가능
promise.then((message) => {
  return new Promise((resolve, reject) => {
    resolve(message);
  });
}).then((message2) => {
  return new Promise((resolve, reject) => {
    resolve(message2);
  })
}).then((message3) => {
  console.log(message3);
});

// callback
function findAndSaveUser(user) {
  Users.findOne({}, (err, user) => {
    if (err) {
      return console.log(err);
    }
    user.name = 'userName';
    user.save((err) => {
      if (err) {
        return console.log(err);
      }
      Users.findOne({gender: 'm'}, (err, user) => {
        //...
      });
    })
  })
}

function findAndSaveUserWithoutCallback(user) {
  Users.findOne({})
    .then((user) => {
      user.name = 'userName';
      return user.save();
    }).then((user) => {
      return Users.findOne({gender: 'm'});
  }).then((user) => {
    //...
  })
}

// promise 여러개 한번에 실행
const promise1 = Promise.resolve('성공1');
const promise2 = Promise.resolve('성공2');
Promise.all([promise1, promise2])  // 모든 promise resolve 기다렸다가 넘어감, 하나라도 reject되면 catch로 이동
  .then((result) => {
    console.log(result);
  }).catch((error) => {
    console.log(error);
});

// async await
async function findAndSaveUserWithAsyncAwait(Users) {
  let user = await Users.findOne(user);
  user.name = 'userName';
  user = await Users.save();
  user = await Users.findOne({gender: 'm'});
  // ...
}

async function findAndSaveUserWithAsyncAwaitAndCatchError(Users) {
  try {
    let user = await Users.findOne(user);
    user.name = 'userName';
    user = await Users.save();
    user = await Users.findOne({gender: 'm'});
    // ...
  } catch (error) {
    console.log(error);
  }
}

// async function with arrow function
const findAndSaveUserWithArrowFunction = async (Users) => {
  try {
    let user = await Users.findOne(user);
    user.name = 'userName';
    user = await Users.save();
    user = await Users.findOne({gender: 'm'});
    // ...
  } catch (error) {
    console.log(error);
  }
};

// for await of
const promise3 = Promise.resolve('성공3');
const promise4 = Promise.resolve('성공4');
(async () => {
  for await (promise of [promise3, promise4]) {
    console.log(promise);
  }
})();

