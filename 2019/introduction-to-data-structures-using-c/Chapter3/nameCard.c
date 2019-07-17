#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nameCard.h"

 // NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * makeNameCard(char * name, char * phone) {
  NameCard * pcard = (NameCard *)malloc(sizeof(NameCard));
  strcpy(pcard->name, name);
  strcpy(pcard->phone, phone);
  return pcard;
}

 // NameCard 구조체 변수의 정보 출력
void showNameCard(NameCard * pcard) {
  printf("name : %s\n", pcard->name);
  printf("phone : %s\n", pcard->phone);
}

// 이름이 같으면 0, 다르면 0 아닌 값 반환
int compareNameCard(NameCard * pcard, char * name) {
  return strcmp(name, pcard->name);
}

// 전화번호 정보를 변경
void changePhoneNum(NameCard * pcard, char * phone) {
  strcpy(phone, pcard->phone); 
}