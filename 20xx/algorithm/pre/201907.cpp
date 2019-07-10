/*
2
5 8
1 1 5 1 3
1 2 5 2 5
1 1 4 3 4
1 1 3 2 2 
2 3 3 
2 5 2
2 1 5
3 1 4
5 15
1 1 4 1 9
1 1 5 2 5
1 1 5 3 5
1 2 4 1 8
1 2 4 2 8
2 1 3
3 1 1 
2 2 1
2 4 7
1 3 5 3 4
3 4 5
2 4 5
2 3 15
2 4 943
3 4 4

#1 5
#2 17
 */

#include <stdio.h>

int T, N, Q;
int SUM;
int p[3][100001];
long long c[100001];

int minByCap(int a, int b, int c, int cap) {
    int min = 12345678;
    if(a < min) min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    return min < cap ? min : cap;
}

void init() {
    N = Q = SUM = 0;
    for(int i = 1; i <= 100000; i++) {
        p[0][i] = p[1][i] = p[2][i] = 0;
        c[i] = 0;
    }
}

void fill(int x, int y, int k, int c) {
    for(int i = x; i <= y; i++) {
        p[k - 1][i] += c;  
    }
}

void sell(int x, int c) {
    int toSell = minByCap(p[0][x], p[1][x], p[2][x], c);

    p[1][x] -= toSell;
    p[2][x] -= toSell;
    p[3][x] -= toSell;
    p[0][x] += toSell;
}

void check(int x, int y) {
    for(int i = x; i <= y; i++) {
        SUM += p[0][i];
    }
}

int main() {
    int t, q;
    int qc;
    int x, y, k, c;
    scanf("%d", &T);
    for(t = 1; t <= T; t++) {
        init();
        scanf("%d %d", &N, &Q);
        for(q = 1; q <= Q; q++) {
            scanf("%d", &qc);
            if(qc == 1) {
                scanf("%d %d %d %d", &x, &y, &k, &c);
                fill(x, y, k, c);
            } else if(qc == 2) {
                scanf("%d %d", &x, &y);
                sell(x, y);
            } else {
                scanf("%d %d", &x, &y);
                check(x, y);
            }
        }
        printf("#%d %d\n", t, SUM);
    }
    return 1;
}