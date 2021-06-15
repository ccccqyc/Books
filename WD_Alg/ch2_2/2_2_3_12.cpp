//去除有序表重复值结点
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
void del_same(LinkList &L) {
    LNode *p = L->next, *q;
    if (p == NULL) return;
    while (p->next) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}
