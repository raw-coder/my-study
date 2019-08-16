/*
8
*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
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
  long d;
  short center;
};

struct Node2 {
  Node2(short _idx, long _d1, long _d2) : idx(_idx), d1(_d1), d2(_d2) {};
  short idx;
  long d1;
  long d2;
};

bool operator< (Node n1, Node n2) {
  return n1.d > n2.d;
}

bool costCompare (Node2 n1, Node2 n2) {
  return (n1.d1 - n1.d2) < (n2.d1 - n2.d2);
}

vector<Edge> edges[MAX_NODES + 1];
long cost1[MAX_NODES + 1];
long cost2[MAX_NODES + 1];
short center[MAX_NODES + 1];
short center2[MAX_NODES + 1];
priority_queue<Node> pq;
short numEng[MAX_NODES + 1];
short numEng2[MAX_NODES + 1];

// n : # nodes
// e : # edges
// c : # centers
// k : # centers + # bases
// m : # engineers
int n, e, c, k, m; 

void dijkstra() {
  while(!pq.empty()) {
    Node now = pq.top(); 
    pq.pop();
    if(now.d > cost1[now.idx]) continue;
    if(cost1[now.idx] == INF) continue;
    if(now.idx <= c && now.idx >= 1) now.center = now.idx;
    // printf("Now %d : %d %d\n", now.idx, now.d, now.center);
    for(Edge e: edges[now.idx]) {
      if(cost1[e.to] > cost1[now.idx] + e.w) {
        cost1[e.to] = cost1[now.idx] + e.w;
        pq.push(Node(e.to, cost1[e.to], now.center));
        center[e.to] = now.center;
        // printf("pq pushed %d : %d %d\n", e.to, cost1[e.to], now.center);
      }
    }
  }
}

void dijkstra2() {
  while(!pq.empty()) {
    Node now = pq.top(); 
    pq.pop();
    if(now.d > cost2[now.idx]) continue;
    if(cost2[now.idx] == INF) continue;
    if(now.idx <= c && now.idx >= 1) now.center = now.idx;
    //printf("Now %d : %d %d\n", now.idx, now.d, now.center);
    for(Edge e: edges[now.idx]) {
      if(cost2[e.to] > cost2[now.idx] + e.w) {
        cost2[e.to] = cost2[now.idx] + e.w;
        pq.push(Node(e.to, cost2[e.to], now.center));
        center2[e.to] = now.center;
        //printf("pq pushed %d : %d %d\n", e.to, cost2[e.to], now.center);
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    scanf("%d %d %d %d %d", &n, &e, &c, &k, &m);
    int x, y, z;
    for(int i = 1; i <= e; i++) {
      scanf("%d %d %d", &x, &y, &z);
      edges[x].push_back(Edge(y, z));
      edges[y].push_back(Edge(x, z));
    }
    for(int i = 1; i <= n; i++) {
      cost1[i] = INF;
      pq.push(Node(i, cost1[i], -1));
    }
    pq.push(Node(0, 0, -1)); // 가상노드 0 출발점으로 추가
    for(int i = 1; i <= c; i++) { // 가상노드 0 에서 각 센터 연결
      edges[0].push_back(Edge(i, 0));
    }
    dijkstra();
    for(int i = c + 1; i <= k ; i++) { // 요청 초과 센터 체크
      numEng[center[i]]++;
    }

    // print
    /*
    for(int i = 1; i <= n; i++) {
      printf("%d : %d\n", i, numEng[i]);
    }
    */
   /*
    printf("#### 1 \n");
    for(int i = 1; i <= n; i++) {
      printf("%d : %d %d\n", i, cost1[i], center[i]);
    }
    */

    while(!edges[0].empty()) {
      edges[0].pop_back();
    }
    for(int i = 1; i <= n; i++) {
      cost2[i] = INF;
      pq.push(Node(i, cost2[i], -1));
    }
    for(int i = 1; i <= c; i++) { // 가상노드 0 에서 초과요청 센터 제외 연결
      if(numEng[i] < m) {
        edges[0].push_back(Edge(i, 0));
      }
    }
    pq.push(Node(0, 0, -1)); // 가상노드 0 출발점으로 추가

    dijkstra2();

    // print
    /*
    printf("#### 2 \n");
    for(int i = 1; i <= n; i++) {
      printf("%d : %d %d\n", i, cost2[i], center2[i]);
    }
    */
   vector<Node2> costs;
   for(int i = c + 1; i <= k; i++) {
    costs.push_back(Node2(i, cost1[i], cost2[i]));
   }

   sort(costs.begin(), costs.end(), costCompare);


    long long sum = 0;

  for(Node2 n : costs) {

    int idx = n.idx;
    if(numEng2[center[idx]] < m) {
        sum += cost1[idx];
        numEng2[center[idx]]++;
      } else {
        sum += cost2[idx];
        numEng2[center2[idx]]++;
      }
  }
    printf("#%d %ld\n", t, sum);


    for(int i = 0; i <= n; i++) {
      while(!edges[i].empty()) {
        edges[i].pop_back();
      }
    }
    for(int i = 0; i <= n; i++) {
      center[i] = 0;
      center2[i] = 0;
      numEng[i] = 0;
      numEng2[i] = 0;
      cost1[i] = 0;
      cost2[i] = 0;
    }

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



1 
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


1
5 7 2 4 1 
4 2 7 
1 4 4 
1 5 1 
5 2 2 
5 3 1 
1 3 4 
3 2 3 
*/