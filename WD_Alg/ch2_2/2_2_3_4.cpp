// 删除单链表中 值最小的结点
// 两个 指针
typedef struct List {
    int data[];
    LinkNode next;
} * LinkNode, *LinkList;

void function(LinkList &L) {
    LinkNode p = L, temp = L->next;
    LinkNode p1 = L, temp1 = L->next;
    while (temp->next) {
        if (temp->data > temp->next->data) {
            p1 = p->next;
            temp1 = temp->next;
        }
        p = p->next;
        temp = temp->next
    }

    p1->next = temp1->next;
    free(temp1);
}