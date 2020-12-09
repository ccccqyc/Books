typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
// 分开链表
void f(LinkList& A, LinkList& B) {
    int i = 1;
    LNode *a = A->next, *b = B->next;
    while (a) {
        if (i % 2 == 1) {
            b->next = a->next->next;
            if (b->next->next) {
                a->next = b->next->next;
            }
            b->next->next = NULL;
        }
        a = a->next;
        b = b->next;
    }
}