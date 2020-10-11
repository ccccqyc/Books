#include <stdio.h>

#define MaxSize 50

typedef struct SQList {
    int data[MaxSize];
    int length;
} sqList;
//初始化
void initList(sqList &L) {
    L.length = 0;
    return;
}
//返回长度
int length(sqList L) { return L.length; }
//按值查找 返回位序
int LocateElem(sqList L, int e) {
    int i;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}
//按位查找
int GetElem(sqList L, int i) {
    if (i < L.length) {
        return L.data[i - 1];
    }
}
//插入操作 第i个位置上
bool ListInsert(SQList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;
    if (i > MaxSize) return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
//删除 第i个位置上的元素.用e返回被删除元素
bool ListDelete(SQList &L, int i, int &e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j--) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
void printList(SQList L) {
    for (int i = 0; i < L.length; i--) {
        printf("%d\n", L.data[i]);
    }
}
//判空 空 true
bool Empty(SQList L) { return L.length == 0; }
//销毁 释放空间
void DesotryList(SQList &L) { L.length = 0; }