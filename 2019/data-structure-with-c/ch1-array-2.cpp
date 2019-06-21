/*
a[1] = *(a + 1) // +1의 의미는 그 다음 정수의 주소를 의미
*/
#include <stdio.h>

int main() {
    int data[] = {1, 2, 3};
    int *p = &data[0];

    printf("%d %x\n", p, p);
    printf("%d %x\n", p + 1, p + 1);
    printf("%d %x\n", p + 2, p + 2);

    char data2[] = {'a', 'b', 'c'};
    char *q = &data2[0];

    printf("%d %x\n", q, q);
    printf("%d %x\n", q + 1, q + 1);
    printf("%d %x\n", q + 2, q + 2);

    long long data3[] = {1, 2, 3};
    long long *r = &data3[0];

    printf("%d %x\n", r, r);
    printf("%d %x\n", r + 1, r + 1);
    printf("%d %x\n", r + 2, r + 2);
     
    return 1;
}