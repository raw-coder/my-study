/*
BOJ 2672 여러 직사각형의 전체 면적 구하기
*/
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Rectangle {
  double x1, y1, x2, y2;

  Rectangle(double x, double y, double width, double height) {
    x1 = x;
    y1 = y;
    x2 = x + width;
    y2 = y + height;
  }
};

double unionArea(vector<Rectangle> & rects) {
  
  // printf("#### rectangels : \n");
  // for(Rectangle r: rects) {
  //   printf("%d %d %d %d\n", r.x1, r.y1, r.x2, r.y2);
  // }
  
  if(rects.empty()) return 0;
  if(rects.size() == 1) return (rects[0].x2 - rects[0].x1) * (rects[0].y2 - rects[0].y1);  
  typedef pair<double, pair<int, int>> Event; // x좌표, 좌우, 사각형 번호
  vector<Event> events;
  vector<double> ys; // y좌표들
  
  // y좌표 및 이벤트 정보 저장
  for(int i = 0; i < rects.size(); i++) {
    ys.push_back(rects[i].y1);  
    ys.push_back(rects[i].y2);
    events.push_back(Event(rects[i].x1, make_pair(1, i)));  
    events.push_back(Event(rects[i].x2, make_pair(-1, i)));  
  }
  // y 좌표 중복 제거
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  // 이벤트 정보 정렬
  sort(events.begin(), events.end());

  // printf("#### events : \n");
  // for(Event ev: events) {
  //   printf("%d %d %d \n", ev.first, ev.second.first, ev.second.second);
  // }

  // printf("#### ys : \n");
  // for(int _y: ys) {
  //   printf("%d\n", _y);
  // }
  double ret = 0;
  
  vector<int> count(ys.size() - 1, 0); // count[i] : ys[i] ~ ys[i+1] 구간에 겹쳐진 사각형의 수
  
  for(int i = 0; i < events.size(); i++) {
    double x = events[i].first;
    int delta = events[i].second.first;
    int rectNo = events[i].second.second;
    double y1 = rects[rectNo].y1;
    double y2 = rects[rectNo].y2;

    for(int j = 0; j < ys.size(); j++) {
      if(y1 <= ys[j] && ys[j] < y2) {
        count[j] += delta;
      }
    }

    double cutLength = 0;
    for(int j = 0; j < ys.size(); j++) {
      if(count[j] > 0) {
        cutLength += (ys[j + 1] - ys[j]);
      }
    }

    // 다음 이벤트까지 거리 * cutLength 구해 ret 집계
    if(i + 1 < events.size()) {
      ret += cutLength * (events[i + 1].first - x);
    } 
  }
  return ret;
}

int main() {
  vector<Rectangle> rects;
  int N;
  scanf("%d", &N);
  double x, y, w, h;
  while(N--) {
    scanf("%lf %lf %lf %lf", &x, &y, &w, &h);
    rects.push_back(Rectangle(x, y, w, h));
  }
  double area = unionArea(rects);
  if(area - (int)area == 0) {
    printf("%lld", (long long)area);
  } else {
    printf("%.2f", (double)area);
  }
  return 0;
}

/*
2
1 1 2 2
3 3 5 5
29

4
52.7 22.9 27.3 13.3
68.8 57.6 23.2 8.0
20.0 48.0 37.0 23.5
41.5 36.2 27.3 21.4


1853.61
*/
