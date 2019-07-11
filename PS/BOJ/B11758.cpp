#include <stdio.h>

struct Point {
    int x, y;
};

int ccw(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
};

int main() {
  struct Point p[4];

  for(int i = 1; i <=3; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);
  }

  int result = ccw(p[1], p[2], p[3]);

  if(result > 0) {
    printf("1");
  } else if(result < 0) {
    printf("-1");
  } else {
    printf("0");
  }
  return 0;
}

