typedef struct LNode {
    int data;
    struct LNode* next;
} * node, *SqlList;

void del_x(SqlList& L, int x) {
    LNode *temp = L->next, *pre = L;
    while (temp) {
        if (temp->data == x) {
            pre->next = temp->next;
            free(temp);
            temp = pre->next;
        } else {
            pre = pre->next;
            temp = temp->next;
        }  // else
    }      // while
}