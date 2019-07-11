/*
cpp sort stl 연습
*/
#include <algorithm>

using namespace std;

int arr[10] = {10, 9, 8, 7, 6, 5, 4, 1, 2, 3};

int compare(int a, int b) {
  return a > b;
}

int compare2(int a, int b) {
  return a < b;
}

bool print() {
  for(int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  sort(arr, arr + 10);
  print();

  sort(arr, arr + 10, compare);
  print();

  sort(arr, arr + 10, compare2);
  print();

  return 1;
}