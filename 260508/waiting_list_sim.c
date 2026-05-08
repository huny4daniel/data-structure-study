#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Waiting {
    int id;
    int nperson;
    char info[32];
};

typedef struct Waiting Element;
#include "DbLinkedList.h"

void reserve(int nperson, const char info[]) {
    static int id = 0;
    Element e;
    e.id = ++id;
    e.nperson = nperson;

    strcpy_s(e.info, 32, info);
    insert(size(), e);

    printf("<등록> 번호 %d: 인원 %d명 %s\n", e.id, e.nperson, e.info);
}

void find(int wid) {
    int nTeam = 0, nPeople = 0;

    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);

        if (e.id == wid) { // = 하나 뺴먹으심
            printf("<확인> 번호 %d번 앞 대기팀: %d팀, %d명\n", e.id, nTeam, nPeople);
            
            return;
        }

        nTeam++;
        nPeople += e.nperson;
    }
}

void cancel(int wid) {
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);

        if (e.id == wid) {
            delete(pos);
            printf("<취소> %d번 웨이팅이 취소되었습니다\n", wid);
            
            return;
        }
    }
}

void delay(int wid) {
    for (int pos = 0; pos < size() - 1; pos++) {
        Element e = get_entry(pos);

        if (e.id == wid) {
            delete(pos);
            insert(pos + 1, e);

            printf("<연기> %d번 웨이팅이 한 칸 연기되었습니다.\n", wid);
            
            return;
        }
    }
}

void print(void) {
    printf("<출력>\n");

    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);

        printf(" 번호 %2d: %d명 %s\n", e.id, e.nperson, e.info);
    }
    printf("\n");
}

void service(void) {
    Element e = delete(0);

    printf("<입장> %d번 손님이 입장 (%d명, %s)\n", e.id, e.nperson, e.info);
}

// id 확인 후 있으면 인원, 전화번호 scanf로 입력받아서 수정 후 수정 결과 출력
void modify(int wid) {
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);

        if (e.id == wid) {
            printf("<수정> 번호 %d: 인원 %d명 %s\n", e.id, e.nperson, e.info);
            
            printf("수정할 인원, 전화번호를 입력하세요: ");
            scanf_s("%d", &e.nperson);
            scanf_s("%s", e.info, 32);

            delete(pos);
            insert(pos, e);
            printf("<수정 완료> 번호 %d: 인원 %d명 %s\n", e.id, e.nperson, e.info);
            
            return;
        }
    }
}

int main(void) {
    init_list();
    print();

    reserve(2, "010-xxxx-8762");
    reserve(2, "010-xxxx-3303");
    reserve(5, "010-xxxx-1212");
    reserve(1, "010-xxxx-2305");
    print();

    service();
    print();

    reserve(3, "010-xxxx-4949");
    reserve(4, "010-xxxx-7345");
    modify(3);
    print();

    find(4);
    delay(3);
    delay(3);
    print();

    cancel(5);
    print();

    destroy_list();
}