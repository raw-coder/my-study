/*
직사각형 합집합 - 면적 구하기

*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
  int x1, y1, x2, y2;
  Rectangle(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

struct Event {
  int x, lr, no; // x좌표, 사각형번호
  int delta; // 좌우(-1 or 1)
  Event(int _x, int _d, int _no) : x(_x), delta(_d), no(_no) {} 
};

vector<Rectangle> rects;
vector<Event> events;
vector<int> ys;
int N;

int unionArea() {
  for(int i = 0; i < events.size(); i++) {
    int x = events[i].x;
    int delta = 

  }
}

void initData() {
  int x1, y1, x2, y2;
  for(int i = 0; i < N; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    rects.push_back(Rectangle(x1, y1, x2, y2));
    events.push_back(Event(x1, -1, i));
    events.push_back(Event(x2, 1, i));
    ys.push_back(y1);
    ys.push_back(y2);
  }
  sort(events.begin(), events.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
}

int main() {
  return 0;
}