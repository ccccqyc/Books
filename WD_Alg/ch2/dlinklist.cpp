#include <stdio.h>
#include <stdlib.h>
//双链表
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void InitList(DLinkList &L);
int Length(DLinkList L);
DNode *LocateElem(DLinkList L, int e);
DNode *GetElem(DLinkList L, int i);
void ListInsert(DLinkList &L, int i, int e);
bool ListDelete(DLinkList &L, int i, int &e);
void PrintList(DLinkList L);
bool Empty(DLinkList L);
bool DestoryList(DLinkList &L);
DNode *GetElem(DLinkList L, int i) {
    DNode *temp = L->next;
    if (i == 0) return L;
    if (i < 1) return NULL;
    int index = i;
    while (temp && --index) {
        temp = temp->next;
    }
    return temp;
}
//双链表插入
void ListInsert(DLinkList &L, int i, int e) {
    DNode *temp = GetElem(L, i);
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->prior = temp->prior;
    s->next = temp;
    temp->prior->next = s;
    temp->prior = s;
}
//双链表删除
bool ListDelete(DLinkList &L, int i) {
    DNode *temp = GetElem(L, i);
    temp->prior->next = temp->next;
    temp->next->prior = temp->prior;
    free(temp);
}
