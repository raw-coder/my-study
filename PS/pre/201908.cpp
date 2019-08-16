/*
8
*/
#include <stdio.h>
#include <vector>
#include <queue>
#define MAX_NODES 20000
#define MAX_EDGES 50000
#define INF __INT_MAX__

using namespace std;

struct Edge {
  Edge(short _to, short _w) : to(_to), w(_w) {};
  int to, w;
};

struct Node {
  Node(short _idx, int _d, short _center) : idx(_idx), d(_d), center(_center) {};
  short idx;
  int d;
  short center;
  bool operator < (const Node &v) const {
    return d < v.d;
  }
};

vector<Edge> edges[MAX_NODES + 1];
int nodes[MAX_NODES + 1];
priority_queue<Node, vector<Node>, greater<Node> > pq;

void dijkstra() {
  // TODO : 센터 정보 초기 전달 관련 로직 추가
  while(!pq.empty()) {
    Node now = pq.top(); 
    pq.pop();
    if(now.d > nodes[now.idx]) continue;
    if(nodes[now.idx] == INF) continue;
    for(Edge e: edges[now.idx]) {
      if(nodes[e.to] > nodes[now.idx] + e.w) {
        nodes[e.to] = nodes[now.idx] + e.w;
        pq.push(Node(e.to, nodes[e.to], now.center));
      }
    }
  }
}

// n : # nodes
// e : # edges
// c : # centers
// k : # centers + # bases
// m : # engineers
int n, e, c, k, m; 

int main() {
  int T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    scanf("%d %d %d %d %d", &n, &e, &c, &k, &m);
    int x, y, z;
    for(int i = 1; i <= e; i++) {
      scanf("%d %d %d", &x, &y, &z);
      edges[x].push_back(Edge(y, z));
    }
    for(int i = 1; i <= n; i++) {
      nodes[i] = INF;
      pq.push(Node(i,nodes[i], -1));
    }
    // 가상노드 0 출발점으로 추가
    pq.push(Node(0, 0, -1));
    // 가상노드 0 에서 각 센터 연결
    for(int i = 1; i <= c; i++) {
      edges[0].push_back(Edge(i, 0));
    }
    dijkstra();

    // TODO : m 할당
    // 두번째 dijkstra 지정

    
  }


  return 0;
}


/*
(입력) 
3 
8 12 2 5 3 
1 6 9 
6 4 3 
7 4 3 
1 7 5 
7 8 3 
1 8 3 
8 5 1 
5 1 5 
2 5 7 
2 3 4 
4 3 6 
3 5 2 
5 7 2 4 1 
4 2 7 
1 4 4 
1 5 1 
5 2 2 
5 3 1 
1 3 4 
3 2 3 
8 8 3 7 2 
1 2 1 
2 3 1 
3 4 1 
4 5 1 
5 6 1 
6 7 1 
4 8 0 
5 8 0

(출력) 
#1 16 
#2 7 
#3 9
*/