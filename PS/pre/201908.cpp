/*
8

*/
#include <stdio.h>
#include <vector>
#include <queue>
#define MAX_NODES 20000
#define MAX_EDGES 50000

using namespace std;

struct Edge {
  int to,
  
};

struct Node {

};

vector<Edge> edges[MAX_NODES + 1];

int t;
// n : # nodes
// e : # edges
// c : # centers
// k : # centers + # bases
// m : # engineers
int n, e, c, k, m; 

int main() {
  scanf("%d", &t);
  scanf("%d %d %d %d %d", &n, &e, &c, &k, &m);
  int x, y, z;
  for(int i = 1; i <= e; i++) {
    scanf("%d %d %d", &x, &y, &z);

  }

  return 0;
}