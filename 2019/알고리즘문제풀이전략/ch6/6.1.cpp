/*
6.1 sum(1:n)
 */
#include <stdio.h>

int n, sum = 0;

int recursiveSum(int n) {
    if (n==1) return 1;
    return n + recursiveSum(n - 1);
}

int main() {
    scanf("%d", &n);
    sum = recursiveSum(n);
    printf("%d", sum);
    return 1;
}