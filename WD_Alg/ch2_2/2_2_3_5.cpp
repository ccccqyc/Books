typedef struct LNode {
    int data;
    struct LNode *next;
} * node, *SqlList;

// 头插法 将其逆序
void f1(SqlList &L) {
    LNode *p, *r;

    p = L->next;
    r = p->next;
    L->next = NULL;
    while (p != NULL) {
        p->next = L->next;
        L->next = p;
        p = r;
        r = p->next;
    }
}

// 将结点中指针依次指向前驱
void f2(SqlList &L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}