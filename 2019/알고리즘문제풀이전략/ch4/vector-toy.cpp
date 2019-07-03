/*
cpp vector test

ref: https://blockdmask.tistory.com/70
 */

#include <stdio.h>
#include <vector>

using namespace std;

// 소인수분해
vector<int> factor(int n) {
  if(n==1) return vector<int>(1, 1);
  vector<int> ret;
  for(int div = 2; n > 1; div++) {
    while(n % div == 0) {
      n /= div;
      ret.push_back(div);
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v = factor(n);

  
  return 1;
}