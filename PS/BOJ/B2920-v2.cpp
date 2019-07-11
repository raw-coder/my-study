#include <stdio.h>

int main() {
  int i, prv, cur;
  int point = 0;
  for(i = 0; i < 8; i++) {
    scanf("%d", &cur);
    if(i > 0) {
      if(prv > cur) {
        point--;
      } else {
        point++;
      }
    }
    prv = cur;
  }

  if(point == -7) {
    printf("descending");
  } else if (point == 7) {
    printf("ascending");
  } else {
    printf("mixed");
  }
}