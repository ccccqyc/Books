typedef struct LNode {
    int data;
    struct LNode *next;
} Lnode, *Linklist;

// 使链表增序列
// 类似选择算法
void f2(Linklist &L) {
    Lnode *temp = L->next, *index = temp->next, *the = NULL;
    int min;
    while (temp) {
        the = temp;
        while (index) {
            if (the->data > index->data) {
                the = index;
            }
            index = index->next;
        }
        min = index->data;
        index->data = temp->data;
        temp->data = min;

        temp = temp->next;
        index = temp->next;
    }
}