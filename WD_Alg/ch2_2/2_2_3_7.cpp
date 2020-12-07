typedef struct LNode {
    int data;
    struct LNode *next;
} Lnode, *Linklist;
// 删除介于两者之间的值
void function(Linklist &L, int a, int b) {
    Lnode *pre = L, *temp = pre->next;
    while (temp) {
        if (temp->data > a && temp->data < b) {
            pre->next = temp->next;
            free(temp);
        }
        pre = pre->next;
        temp = pre->next;
    }
}