let members = ['steve', 'jane', 'no one'];
console.log(members[1]); // jane

let i = 0;
while(i < members.length) {
  console.log('# array : ', members[i]);
  i = i + 1;
}


let roles = {
  'programmer': 'steve',
  'designer': 'jane',
  'manager': 'no one'
};
console.log(roles.designer); // jane
console.log(roles['designer']); // jane
for(let name in roles) {
  console.log(`# key:${name}, value: ${roles[name]}`);
}

