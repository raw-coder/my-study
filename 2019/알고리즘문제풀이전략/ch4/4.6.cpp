/*
소인수분해
 */

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> factor(int n) {
  if(n == 1) return vector<int>(1, 1); // size 1짜리 vector 생성 && 1로 초기화
  vector<int> ret;
  for(int div = 2; n > 1; ++div) {
      while(n % div == 0) {
          n /= div;
          ret.push_back(div);
      }
  }
  return ret;
}

int main() {
    int n;
    vector<int> v;
    scanf("%d", &n);

    v = factor(n);
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v.at(i));
    }
    return 1;
}