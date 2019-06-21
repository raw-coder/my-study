/*
malloc : 메모리 할당하고 시작 주소 리턴
*/
#include <stdio.h>

int main() {
    int *p;
    p = (int *)malloc(40);
    if (p == NULL) {
        // do something
    }

    p[0] = 12;
    p[1] = 24;
    *(p + 2) = 36;

    return 1;
}