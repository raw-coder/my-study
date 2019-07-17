#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "nameCard.h"

int main() {
  List list;
  NameCard * pcard;
  Linit(&list);

  pcard = makeNameCard("PeterJackson", "010-1111-2222");
  Linsert(&list, pcard);

  pcard = makeNameCard("MichealJordan", "010-3333-4444");
  Linsert(&list, pcard);

  pcard = makeNameCard("Steve Jobs", "010-5555-6666");
  Linsert(&list, pcard);

  // Steve Jobs 정보 조회 출력
  if(Lfirst(&list, &pcard)) {
    if(!compareNameCard(pcard, "Steve Jobs")) {
      showNameCard(pcard);
    } else {
      while(Lnext(&list, &pcard)) {
        if(!compareNameCard(pcard, "Steve Jobs")) {
          showNameCard(pcard);
          break;
        }   
      }
    }
  }

  return 0;
}