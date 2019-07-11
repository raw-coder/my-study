/*
Graham Scan  
- Convex Hull 찾기

1 .최하단 우측 점을 찾아 기준점으로 선정
2. 기준점을 원점으로 다른 점들의 좌표 재계산
3. 각도별 정렬
4. 세 점을 stack에 저장
5. 외적을 이용하여 한점씩 비교하여 진행

참조 : http://59.23.150.58/30stair/convex_hull/src/graham.c

 */
#include <stdio.h>

struct point {
  int x, y;
};
int n; // # points
struct point p[100001], q[100001];

struct point stack[1000001];
int top = 0;

int index;

void init() {
  // 초기화...
  // 입력 받고, 기준점 찾기
  int i;
  struct point min = {0, 40000}; // 0, 9999 로 초기화

  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);

    if (min.y > p[i].y || min.y == p[i].y && min.x < p[i].x) {
       min=p[i];
       index=i;
    }
  }
}

void recoordinate() {
  int i, j;
  for(i = 1; i <= n; ++i) {
    q[i].x = p[i].x - p[index].x;
    q[i].y = p[i].y - p[index].y;
  }
}

int cross_product(struct point m, struct point n) {
  return m.x * n.y - m.y * n.x;
}

struct point locationVector(struct point m, struct point n) {
  struct point tmp;

  tmp.x = n.x - m.x;
  tmp.y = n.y - m.y;

  return tmp;
}

void sort_by_angle() {
  int i, j, min_index;
  struct point tmp;

  // index 를 원점으로 
  // p[1], q[1] 위치에 index값을 둔다.

  tmp = p[index];
  p[index] = p[1];
  p[1] = tmp;

  tmp = q[index];
  q[index] = q[1];
  q[1] = tmp;

  // selection sort
  for(i = 2; i < n; i++) {
    min_index = i;
    for(j = i + 1; j <= n; j++) {
      if (cross_product(q[min_index], q[j]) < 0) min_index = j;
    }

    tmp = p[min_index];
    p[min_index] = p[i];
    p[i] = tmp;

    tmp = q[min_index];
    q[min_index] = q[i];
    q[i] = tmp;
  }  
}

void push(struct point m) {
  if (top > 99) {
    printf("stack is full!");
  }

  stack[++top] = m;
}

void pop() {
  if (top <= 0) {
    printf("stack empty");
  }
  top--;
}

void convex_hull() {
  int i;

  push(p[1]);
  push(p[2]);
  push(p[3]);

  for(i = 4; i <= n; i++) {
    while(cross_product(locationVector(stack[top - 1], stack[top]), locationVector(stack[top], p[i])) <= 0) {
      pop();
    }
    push(p[i]);
  }

  // 마지막 point와 첫 point 체크
  if(cross_product(locationVector(stack[top - 1], stack[top]), locationVector(stack[top], p[i])) <= 0) pop();
}

void output() {
  int i;
  // for(i = 1; i <= top; i++) {
    // printf("%d %d\n", stack[i].x, stack[i].y);
  // }
  printf("%d", top);
}

int main() {
  init();
  recoordinate();
  sort_by_angle();
  convex_hull();
  output();
  return 1;
}





