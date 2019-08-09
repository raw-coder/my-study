#include <stdio.h>
#define MAX_SIZE 1000000

typedef long long ll;

ll arr[MAX_SIZE * 4];

void update() {

}

ll query(int node, int start, int end, int left, int right) {
  // if(start == end) return arr[node];
  if(start == left && end == right) return arr[node];
  int mid = (start + end) / 2;
  
  if(mid < left) { mid

  }

}

int main() {
  return 0;
}