/*
3
2
6 -15 0 -20
4 8 -3 15
5
9 12 2 7
6 1 4 -5
1 8 6 13
22 -8 19 0
6 15 -1 17
10
1 6 0 0
10 5 8 -4
6 20 -3 16
-15 21 -17 16
20 0 23 6
8 9 15 15
2 -19 5 -10
2 5 -3 8
-11 -2 -19 2
-11 -24 -14 -21
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int T, N; // T: # test case, N: # teams 

struct Point {
  long x, y;
} P;

struct Team {
    struct Point p1, p2;
    int gameover;
    int isOver;
} Team;

struct Team team[101];

long ccw(long x1, long y1, long x2, long y2, long x3, long y3) {
  return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
  // 떨어져있는 선분 체크
  if(max(x1, x2) < min(x3, x4)) return -1;
  if(min(x1, x2) > max(x3, x4)) return -1;
  if(max(y1, y2) < min(y3, y4)) return -1;
  if(min(y1, y2) > max(y3, y4)) return -1;

  // ccw 체크
  long ccw_p1p2p3 = ccw(x1, y1, x2, y2, x3, y3);
  long ccw_p1p2p4 = ccw(x1, y1, x2, y2, x4, y4);

  long ccw_p3p4p1 = ccw(x3, y3, x4, y4, x1, y1);
  long ccw_p3p4p2 = ccw(x3, y3, x4, y4, x2, y2);

  if(ccw_p1p2p3 == 0 && ccw_p1p2p4 == 0 && ccw_p3p4p1 == 0 && ccw_p3p4p2 == 0) return 1;
    
  if((ccw_p1p2p3 > 0 && ccw_p1p2p4 < 0 || ccw_p1p2p3 < 0 && ccw_p1p2p4 > 0 || ccw_p1p2p3 == 0 || ccw_p1p2p4 == 0)&&
     (ccw_p3p4p1 > 0 && ccw_p3p4p2 < 0 || ccw_p3p4p1 < 0 && ccw_p3p4p2 > 0 || ccw_p3p4p1 == 0 || ccw_p3p4p2 == 0)) return 1;
    
  return -1;
}

void escape(int turn) {
  int i, j;
  for(i = 1; i <= N; i++) {
    if(turn == 10) {
      // 4 -> 3
      if(team[i].p1.x > 0 && team[i].p1.y < 0) {
        team[i].p1.x *= -1;
      }
      if(team[i].p2.x > 0 && team[i].p2.y < 0) {
        team[i].p2.x *= -1;
      }
    } else if(turn == 20) {
      // 3 -> 2
      if(team[i].p1.x < 0 && team[i].p1.y < 0) {
        team[i].p1.y *= -1;
      }
      if(team[i].p2.x < 0 && team[i].p2.y < 0) {
        team[i].p2.y *= -1;
      }
    } else if(turn == 30) {
      // 2 -> 1
      if(team[i].p1.x < 0 && team[i].p1.y > 0) {
        team[i].p1.x *= -1;
      }
      if(team[i].p2.x < 0 && team[i].p2.y > 0) {
        team[i].p2.x *= -1;
      }
    }
  }
}

void checkGameover() {
  int i;
  for(i = 1; i <= N; i++) {
    if(team[i].gameover != 32) team[i].isOver = 1;
  }
}

void doBattle(int turn) {
  int i, j;
  for(i = 1; i <= N - 1; i++) {
    for(j = i + 1; j <= N; j++) {
      if(i == j) continue;
      if(team[i].isOver == 1 || team[j].isOver == 1) continue; 
      if(isCross(team[i].p1.x, team[i].p1.y, team[i].p2.x, team[i].p2.y, team[j].p1.x, team[j].p1.y, team[j].p2.x, team[j].p2.y) == 1) {
        team[i].gameover = turn;
        team[j].gameover = turn;
      }
    }
  }
  checkGameover();
}

int main() {
  int i, j, k;
  scanf("%d", &T);
    
  for(i = 1; i <= T; i++) {
    scanf("%d", &N);
    for(j = 1; j <= N; j++) {
      scanf("%ld %ld %ld %ld", &team[j].p1.x, &team[j].p1.y, &team[j].p2.x, &team[j].p2.y);
      team[j].gameover = 32;
      team[j].isOver = -1;
    }
    // 입력값 확인
    /*
    for(j = 1; j <= N; j++) {
        if(i == 9  && (j == 2 || j == 11))
         printf("%ld %ld %ld %ld\n", team[j].p1.x, team[j].p1.y, team[j].p2.x, team[j].p2.y);
    }
    */         
    doBattle(0);
    for(j = 1; j <= 31; j++) {
      
      for(k = 1; k <= N; k++) {
        team[k].p1.x /= 2;
        team[k].p1.y /= 2;
        team[k].p2.x /= 2;
        team[k].p2.y /= 2;
      }

      if(j == 10 || j == 20 || j == 30) {
        escape(j);
      } 
      doBattle(j);
    }

    // 출력
    printf("#%d ", i);
    for(j = 1; j <= N; j++) {
      printf("%d ", team[j].gameover);
    }
    printf("\n");
  }
  
  return 0;
}



