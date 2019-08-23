#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX_NODES 300000
using namespace std;

int tree[MAX_NODES * 4];

struct Node {
  int idx;
  int height;
};

struct Query {
  int idx;
  int from;
  int to;
  int height;
  long long sum;
};

bool compareNode(Node n1, Node n2) {
  return n1.height > n2.height;
}

bool compareQuery(Query q1, Query q2) {
  return q1.height > q2.height;
}

bool compareQueryByIdx(Query q1, Query q2) {
  return q1.idx < q2.idx;
}

void update(int node, int start, int end, int position) {
  tree[node]++;
  if(start == end) return;
  int mid = (start + end) / 2;
  if(mid < position) {
    update(node * 2 + 1, mid + 1, end, position);
  } else {
    update(node * 2, start, mid, position);
  }
}

long long sum(int node, int start, int end, int left, int right) {
  //printf("## sum : %d, %d, %d, %d, %d\n", node, start, end, left, right);
  if(left > end || right < start) return 0;
  if(left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int T, n, q;
vector<Query> queries;
vector<Node> heights;

int height, from, to;

int main() {
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    scanf("%d %d", &n, &q);

    heights.clear();
    queries.clear();

    for(int i = 1; i <= n; i++) {
      scanf("%d", &height);
      Node n;
      n.idx = i;
      n.height = height;
      heights.push_back(n);
    }
    for(int i = 1; i <= q; i++) {
      scanf("%d %d %d", &from, &to, &height);
      Query q;
      q.idx = i;
      q.from = from;
      q.to = to;
      q.height = height;
      queries.push_back(q);
    }

    sort(heights.begin(), heights.end(), compareNode);
    sort(queries.begin(), queries.end(), compareQuery);
    
    int idx = 2;
    while(idx < n) {
      idx = idx << 1;
    }

    /*
    printf("## heights \n");
    for(Node n : heights) {
      printf("%d\n", n.height);
    }

    printf("## queries \n");
    for(Query q : queries) {
      printf("%d\n", q.height);
    }
    */
    
    int idxH = 0;
    int idxQ = 0;
    while(true) {
      if(queries[idxQ].height < heights[idxH].height) {
        // printf("##start update : %d\n", heights[idxH].idx);
        update(1, 1, idx, heights[idxH].idx);
        idxH++;
      } else {
        break;
      }
    }
    while(idxQ < q && idxH < n) {
      //printf("q(%d)-%d vs h(%d)-%d\n", idxQ, queries[idxQ].height, heights[idxH].idx, heights[idxH].height);
      if(queries[idxQ].height < heights[idxH].height) {
        // update
        // printf("##start update : %d\n", heights[idxH].idx);
        update(1, 1, idx, heights[idxH].idx);
        idxH++;
      } else {
        // sum
        queries[idxQ].sum = sum(1, 1, idx, queries[idxQ].from, queries[idxQ].to); 
        idxQ++;
      }
    }
    while(idxQ < q) {
      queries[idxQ].sum = sum(1, 1, idx, queries[idxQ].from, queries[idxQ].to); 
      idxQ++;
    }

    sort(queries.begin(), queries.end(), compareQueryByIdx);

    printf("#%d ", t);
    for(int i = 0; i < q; i++) {
      printf("%lld ", queries[i].sum);
    }
    printf("\n");
    for(int i = 0; i <= MAX_NODES; i++) {
      tree[i] = 0;
    }
  }
}


/*
(입력)

3                                              
10 3                                           
175 182 178 179 170 179 171 185 185 181 
3 7 175 
1 10 180 
1 10 179 
7 5                                          
183 176 175 183 174 182 186 
1 4 176 
2 6 177 
1 7 180 
1 7 160 
5 7 180 
2 2
161 168 
1 2 175 
1 2 188 



(출력)

#1 3 4 4 
#2 2 2 4 7 2 
#3 0 0


3                                              
10 3                                           
175 182 178 179 170 179 171 185 185 181 
3 7 175 
1 10 180 
1 10 179 

*/
