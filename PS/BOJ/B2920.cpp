#include <stdio.h>

int main() {
  int i, prv, cur;
  int asc = 0;
  for(i = 0; i < 8; i++) {
    scanf("%d", &cur);
    if(i == 1) {
      if(prv > cur) {
        asc = -1;
      } else {
        asc = 1;
      }
    } else {
      if(asc < 0 && prv < cur) {
        asc = 0;
      } else if (asc > 0 && prv > cur) {
        asc = 0;
      }
    }
    prv = cur;
  }

  if(asc < 0) {
    printf("descending");
  } else if (asc > 0) {
    printf("ascending");
  } else {
    printf("mixed");
  }
}