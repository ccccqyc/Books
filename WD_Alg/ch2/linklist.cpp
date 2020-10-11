#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode {
    int data;
    LinkNode *next;
} LNode, *LinkList;

void InitList(LinkList &L);
LNode *LocateElem(LinkList L, int e);
LNode *GetElem(LinkList L, int i);
bool ListInsert(LinkList &L, int i, int e);
bool ListDelete(LinkList &L, int i, int &e);
void PrintList(LinkList L);
bool Empty(LinkList L);
bool DestoryList(LinkList &L);

//头插法 建立单链表 含头结点
LinkList List_HeadInsert1(LinkList &L) {
    LNode *s;
    int x;
    //创建头结点
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
//头插法 建立单链表 不含头结点 仅头指针
LinkList List_HeadInsert2(LinkList &L) {
    LNode *s;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L = s;  //和头结点区别
        scanf("%d", &x);
    }

    return L;
}
//尾插法 头节点 L + 尾指针 r
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LinkNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = x;
        r->next = s;  //尾插法体现
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;  //重要
    return L;
}
//按序号查找 含头节点L
LNode *GetElem(LinkList L, int i) {
    LNode *temp = L->next;
    int j = 1;
    if (i == 0) return L;
    if (i < 1) return NULL;
    for (j = 1; j < i && temp; j++) {
        temp = temp->next;
    }
    return temp;
}
// 按值查找  头结点L
LNode *LocateElem(LinkList L, int e) {
    LNode *temp = L->next;
    while (temp && temp->data != e) {
        temp = temp->next;
    }
    return temp;
}
//插入 后插法 找i-1点
bool ListInsert1(LinkList &L, int i, int e) {
    LNode *temp = GetElem(L, i - 1);
    LNode *s = (LinkNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = temp->next;
    temp->next = s;
    return true;
}
//插入 交换数据域
bool ListInsert2(LinkList &L, int i, int e) {
    LNode *temp = GetElem(L, i);
    LNode *s = (LinkNode *)malloc(sizeof(LNode));
    s->data = temp->data;
    temp->data = e;
    s->next = temp->next;
    temp->next = s;
    return true;
}
//删除
void ListDelete(LinkList &L, int i) {
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}

//求表长
int Length(LinkList L) {
    int length = 0;
    LNode *p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}
