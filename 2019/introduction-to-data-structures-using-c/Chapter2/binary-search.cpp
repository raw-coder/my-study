/*
binary search by recursive function
*/
#include <stdio.h>

// recursive function
int binarySearch(int arr[], int first, int last, int target) {
  if(first > last) return -1;
  int mid = (first + last) / 2;
  if(arr[mid] == target) return mid;
  else if(target < arr[mid]) return binarySearch(arr, first, mid - 1, target);
  else return binarySearch(arr, mid + 1, last, target);
}

// with loop
int binarySearch2(int arr[], int len, int target) {
  int first = 0, last = len - 1, mid;
  while(first <= last) {
    mid = (first + last) / 2;
    if(target == arr[mid]) return mid;
    else if(target < arr[mid]) last = mid - 1;
    else first = mid + 1;
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int idx;

  idx = binarySearch(arr, 0, sizeof(arr)/sizeof(int) - 1, 7);
  if(idx == -1) printf("fail");
  else printf("idx : %d \n", idx);

  idx = binarySearch(arr, 0, sizeof(arr)/sizeof(int) - 1, 4);
  if(idx == -1) printf("fail");
  else printf("idx : %d \n", idx);

  return 0;
}