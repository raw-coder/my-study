let number = [1, 2, 3, 4 ,5, 10000];

let i = 0;
let total = 0;

while(i < number.length) {
  total += number[i];
  i = i + 1;
}

console.log(`total: ${total}`);
