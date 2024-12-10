#include <stdio.h>
#include <malloc.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node Node;
typedef struct node* pNode;

int main() {
    int n = 10;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pNode head = NULL;
    pNode recent = head;
    for (int i = 0; i < n; i++) {
        Node temp;
        temp.value = a[i];
        temp.next = NULL;
        if (head == NULL) head = &temp;
        else recent->next = &temp;
        recent = &temp; // new Node = malloc malloc = สร้าง node ใหม่มา ปุ่มอะไรตรงไหน
    }
    // Node อะไร คอมช้า... ไม่ ก็กด run คอมช้าเฉยๆ ถูกแล้วมั้ง มันผ่านอะ
    // ต่อมาอยาก insert node ที่ตำแหน่งระหว่าง 3 กับ 4
    // int pos = 3;
    pNode iter = head;
    // for (int i = 1; i < pos; i++) iter = iter->next;
    // // understand?
    // Node temp;
    // temp.value = 50; // เอาค่าเท่าไหร่
    // temp.next = iter->next; // ตั้งให้ temp -> node 4 understand? @thimphu ถ้าทิมพูเข้าใจแล้ว ไปต่อ ตอบห่นอยซักคน
    // iter->next = &temp; // ก้ให้ iter -> temp * เราตกอังกฤษ ไม้รู้ ไปต่อยัง ไม่ได้ฟัง
    // iter -> node 4 [iter ต่อกับ node 4]
    // build temp -> (iter->next) [node 4] สร้าง temp มาชี้ไปที่ที่ iter ชี้อยู่ ซึ่งก้คือ node 4
    // iter-next = &temp [iter -> temp] เข้าใจปะ

    // [iter, value, next] -> [node 4, value, next]
    // [temp, value, next] -> [node 4, value, next]
    // [iter, value, next] -> [temp, value, next] -> [node 4, value, next] ทove next of iter to temp instead of node 4

    // ต่อมาอยากได้ค่าของ node ที่ x อยากไปไหนก็ไปไกลๆ
    int x = 4;
    // // then what?
    iter = head; // how easy access? it not array [iter is a pointer] อะไรนะ ใช่ ใช้ในข้อสอบที่เค้าบังคับ ตอนนี้โค้ดบัคอยู
    for (int i = 1; i < x; i++) iter = iter->next;
    int ans = iter->value;
    printf("%d", ans);
}