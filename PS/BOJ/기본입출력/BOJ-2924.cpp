/*
BOJ 1924 2007 년
*/
#include <stdio.h>

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int countDays(int x, int y) {
  int i, days = -1;
  for(i = 1; i < x; i++) {
    days += months[i];
  }
  days += y;
  return days;
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%s", day[countDays(x, y) % 7]);
  return 0;
}