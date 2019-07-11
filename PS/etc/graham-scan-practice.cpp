/*
1. 입력받으면서 기준점 찾기(최우측 하단점)
2. 기준점 1번으로 두고 각도 기준 정렬
3. 1, 2번점 stack에 넣고, 다음 점부터 ccw 계산하여 stack에 넣기
- ccw > 0 stack에 넣기
- ccw <= 0 top에 있는 point 제거 후 넣기
- 마지막 point - 기준점도 ccw 체크
*/
#include <stdio.h>

struct point {
  int x, y;
};
struct point points[100001];

int stack[100001];
int top = 0;

void push(int x) {
  stack[top++] = x;
}

int pop() {
    return stack[top--];
}

int ccw(point p1, point p2, point p3) {
    return (p1.x - p2.x) * (p3.y - p2.y) - (p1.y - p2.y) * (p3.x - p2.x);
}

int sort_by_angle() {
    
}
