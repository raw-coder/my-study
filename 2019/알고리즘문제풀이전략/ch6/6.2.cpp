/*
n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
??? 해결안됨...
 */
#include <stdio.h>
#include <vector>

using namespace std;

// void printPicked(vector<int> &picked) {
//   int i;
//   for(i = 0; i < picked.size(); i++) {
//     printf("%d ", picked.at(i));
//   }
//   printf("\n");
// }

void pick(int n, vector<int> &picked, int toPick) {
  // n : 전체 원소수
  // picked : 지금까지 고른 원소들의 번호
  // toPick: 더 고를 원소의 수
  if(toPick == 0) {
      //printPicked(picked);
      return;
  }
  int smallest = picked.empty() ?  0 : picked.back() + 1;
  for(int next = smallest; next < n; ++next) {
      picked.push_back(next);
      pick(n, picked, toPick - 1);
      picked.pop_back();
  }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> picked(n + 1);
    int i;
    for(i = 0; i < n; i++) {
        picked.push_back(i);
    }
    pick(n, picked, m);
    return 1;
}