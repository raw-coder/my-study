/*
2
2
6 -15 0 -20
4 8 -3 15
5
9 12 2 7
6 1 4 -5
1 8 6 13
22 -8 19 0
6 15 -1 17
*/

#include <stdio.h>

int T, N, i, j;
struct Point {
  long x, y;
} P;
struct Team {
    struct Point p1, p2;
} Team;
struct Team team[101];

int isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
    long sign1_p1p2_cross_p1p3 = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) > 0 ? 1L : -1L;
    long sign2_p1p2_cross_p1p4 = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1) > 0 ? 1L : -1L;

    if (sign1_p1p2_cross_p1p3 == 0 || sign2_p1p2_cross_p1p4 == 0) return 1;
    if ((sign1_p1p2_cross_p1p3 > 0 && sign2_p1p2_cross_p1p4 < 0) || (sign1_p1p2_cross_p1p3 < 0 && sign2_p1p2_cross_p1p4 < 0)) return 1;
    return -1;
}

int isOverlap() {
    return -1;
}

int main() {
  scanf("%d", &T);
  for(i = 1; i <= T; i++) {
    scanf("%d", &N);
    for(j = 1; j <= N; j++) {
      scanf("%d %d %d %d", &team[j].p1.x, &team[j].p1.y, &team[j].p2.x, team[j].p2.y);
    }

    for(j = 1; j <= N; j++) {
      printf("%d %d %d %d", team[j].p1.x, team[j].p1.y, team[j].p2.x, team[j].p2.y)
    }

  }
  return 0;
}



