/*
동적메모리할당
malloc : 메모리 할당하고 시작 주소 리턴
sizeof : 입력한 데이터타입의 크기 리턴
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // int *p;
    // p = (int *)malloc(4 * sizeof(int));
    // if (p == NULL) {
    //     // do something
    // }

    // p[0] = 12;
    // p[1] = 24;
    // *(p + 2) = 36;

    int * array = (int *)malloc(4 * sizeof(int)); // 16 bytes
    // int array[4]; // 배열로 선언하면 array 변수의 값을 변경할 수 없다

    array[0] = 1;
    array[1] = 2;
    *(array + 2) = 3;

    int * tmp = (int *)malloc(8 * sizeof(int));
    int i;
    for(i = 0; i < 4; i++) {
        tmp[i] = array[i];
    }
    array = tmp; // 포인터 변수 tmp의 값(배열의 주소)을 array에 할당 

    array[4] = 4;
    array[5] = 5;

    for(i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
    return 1;
}