/*
BOJ 1753 최단거리

Dijkstra 단순 구현
*/

#include <stdio.h>
#include <vector>
#include <queue>
#define INF __INT_MAX__
#define MAX_NODES 20000

using namespace std;

struct Edge {
  Edge(short _v, short _w) : to(_v), w(_w) {}
  short to, w;
};

struct Node {
  Node(short _idx, int _d) : idx(_idx), d(_d) {}
  short idx;
  int d;
  bool operator < (const Node &v) const {
    return d < v.d;
  }
};

vector<Edge> edges[MAX_NODES + 1];
int nodes[MAX_NODES + 1];
priority_queue<Node, vector<Node>, greater<Node>> pq;

void dijkstra() {
  while(!pq.empty()) {
    Node now = pq.top();
    pq.pop();
    if(now.d > nodes[now.idx]) continue;
    if(nodes[now.idx] == INF) continue;
    for(Edge e: edges[now.idx]) {
      if(nodes[e.to] > nodes[now.idx] + e.w) {
        nodes[e.to] = nodes[now.idx] + e.w;
        pq.push(Node(e.to, nodes[e.to]));
      }
    }
  }
}

int main() {
  int v, e, start, from, to, w;
  scanf("%d %d %d", &v, &e, &start);
  while(e--) {
    scanf("%d %d %d", &from, &to, &w);
    edges[from].push_back(Edge(to, w));
  }
  for(int i = 1; i <= v; i++) {
    nodes[i] = i == start ? 0 : INF;
    pq.push(Node(i, nodes[i]));
  }
  dijkstra();

  for(int i = 1; i <= v; i++) {
    if(nodes[i] == INF) {
      printf("INF\n");
    } else {
      printf("%d\n", nodes[i]);
    }
  }
  return 0;
}