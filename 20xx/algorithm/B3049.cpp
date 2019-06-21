/*
백준 3049
다각형의 대각선
*/

#include <stdio.h>

int N;

int main() {
    scanf("%d", &N);
    printf("%d", N * (N-1) * (N-2) * (N-3) / 24);
}