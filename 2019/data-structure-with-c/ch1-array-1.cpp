/*
배열의 이름은 배열의 0번째 엘레먼트의 주소를 나타내는 포인터 변수
a[0] = *a
*/
#include <stdio.h>
int calculate_sum(int * arrary) {
    int sum, i;
    sum = 0;
    for(i = 0; i < 10; i++) {
        //sum += arrary[i];
        sum += *(arrary + i);
    }
    return sum;
}

int main(void) {
  int sum, i, average;
  int num[10];
  for(i = 0; i < 10; i++) {
      scanf("%d", &num[i]);
  }
  sum = calculate_sum(num);
  average = sum / 10;
  printf("%d\n", average);
  return 0;
}