#include <stdio.h>

int T, N, L, H;
int N1, N2, N3, N4;

struct Point {
    int x, y, idx;
};

struct Point p[5001];
struct Point p1[5001];
struct Point p2[5001];
struct Point p3[5001];
struct Point p4[5001];

int is_in_range(int l, int h, int d) {
    if (d >= l * l && d <= h * h) {
        return 1;
    } else {
        return -1;
    }
}

// 벡터 외적 
// result < 0 : cw
// result > 0 : ccw
// result = 0 : 일직선
int cross_product(Point p, Point q) {
    return p.x * q.y - p.y * q.x;
}

// selection sort
void sort_by_angle() {
    int i, j, selected_idx;
    Point temp;

    for(i = 1; i <= N1 - 1; i++) {
        selected_idx = i;
        for(j = i + 1 ; j <= N1; j++) {
            if(cross_product(p1[selected_idx], p1[j]) > 0) {
                selected_idx = j;
            }
        }
        temp.x = p1[selected_idx].x;
        temp.y = p1[selected_idx].y;
        temp.idx = p1[selected_idx].idx;

        p1[selected_idx].x = p1[i].x;
        p1[selected_idx].y = p1[i].y;
        p1[selected_idx].idx = p1[i].idx;

        p1[i].x = temp.x;
        p1[i].y = temp.y;
        p1[i].idx = temp.idx;
    }

    for(i = 1; i <= N2 - 1; i++) {
        selected_idx = i;
        for(j = i + 1 ; j <= N2; j++) {
            if(cross_product(p2[selected_idx], p2[j]) > 0) {
                selected_idx = j;
            }
        }
        temp.x = p2[selected_idx].x;
        temp.y = p2[selected_idx].y;
        temp.idx = p2[selected_idx].idx;

        p2[selected_idx].x = p2[i].x;
        p2[selected_idx].y = p2[i].y;
        p2[selected_idx].idx = p2[i].idx;

        p2[i].x = temp.x;
        p2[i].y = temp.y;
        p2[i].idx = temp.idx;
    }

    for(i = 1; i <= N3 - 1; i++) {
        selected_idx = i;
        for(j = i + 1 ; j <= N3; j++) {
            if(cross_product(p3[selected_idx], p3[j]) > 0) {
                selected_idx = j;
            }
        }
        temp.x = p3[selected_idx].x;
        temp.y = p3[selected_idx].y;
        temp.idx = p3[selected_idx].idx;

        p3[selected_idx].x = p3[i].x;
        p3[selected_idx].y = p3[i].y;
        p3[selected_idx].idx = p3[i].idx;

        p3[i].x = temp.x;
        p3[i].y = temp.y;
        p3[i].idx = temp.idx;
    }

    for(i = 1; i <= N4 - 1; i++) {
        selected_idx = i;
        for(j = i + 1 ; j <= N4; j++) {
            if(cross_product(p4[selected_idx], p4[j]) > 0) {
                selected_idx = j;
            }
        }
        temp.x = p4[selected_idx].x;
        temp.y = p4[selected_idx].y;
        temp.idx = p4[selected_idx].idx;

        p4[selected_idx].x = p4[i].x;
        p4[selected_idx].y = p4[i].y;
        p4[selected_idx].idx = p4[i].idx;

        p4[i].x = temp.x;
        p4[i].y = temp.y;
        p4[i].idx = temp.idx;
    }
}

void print_result(int t) {
    int i;
    printf("#%d ", t);

    int result[5001] = {0};
    int seq = 1;

    for(i = 1; i <= N4; i++) {
        int d = p4[i].x * p4[i].x + p4[i].y * p4[i].y;
        if(d >= H * H && d <= (L + H) * (L + H)) {
            result[p4[i].idx] = seq++;
        } 
    }
    for(i = 1; i <= N3; i++) {
        int d = p3[i].x * p3[i].x + p3[i].y * p3[i].y;
        if(d >= H * H && d <= (L + H) * (L + H)) {
            result[p3[i].idx] = seq++;
        } 
    }
    for(i = 1; i <= N2; i++) {
        int d = p2[i].x * p2[i].x + p2[i].y * p2[i].y;
        if(d >= H * H && d <= (L + H) * (L + H)) {
            result[p2[i].idx] = seq++;
        } 
    }
    for(i = 1; i <= N1; i++) {
        int d = p1[i].x * p1[i].x + p1[i].y * p1[i].y;
        if(d >= H * H && d <= (L + H) * (L + H)) {
            result[p1[i].idx] = seq++;
        } 
    }    
    
    for(i = 1; i <= N; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int t, i;
    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        N= N1 = N2 = N3 = N4 = 0;
        scanf("%d %d %d", &N, &L, &H);    
        for(i=1; i <= N; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
            p[i].idx = i;
        }

        for(i=1; i <= N; i++) {
            if (p[i].x >= 0) {
                if (p[i].y <= 0) {
                    p4[++N4].x = p[i].x;
                    p4[N4].y = p[i].y;
                    p4[N4].idx = p[i].idx;
                } else {
                    p1[++N1].x = p[i].x;
                    p1[N1].y = p[i].y;
                    p1[N1].idx = p[i].idx;
                }
            } else {
                if (p[i].y <= 0) {
                    p3[++N3].x = p[i].x;
                    p3[N3].y = p[i].y;
                    p3[N3].idx = p[i].idx;
                } else {
                    p2[++N2].x = p[i].x;
                    p2[N2].y = p[i].y;
                    p2[N3].idx = p[i].idx;
                }
            }
        }
        sort_by_angle();
        print_result(t);

        // printf("======4\n");
        // for(i = 1; i <= N4; i++) {
        //     printf("%d %d %d\n", p4[i].x, p4[i].y, p4[i].idx);
        // }
        // printf("======3\n");
        // for(i = 1; i <= N3; i++) {
        //     printf("%d %d %d\n", p3[i].x, p3[i].y, p3[i].idx);
        // }
        // printf("======2\n");
        // for(i = 1; i <= N2; i++) {
        //     printf("%d %d %d\n", p2[i].x, p2[i].y, p2[i].idx);
        // }
        // printf("======1\n");
        // for(i = 1; i <= N1; i++) {
        //     printf("%d %d %d\n", p1[i].x, p1[i].y, p1[i].idx);
        // }
    }   
    return 0;
}