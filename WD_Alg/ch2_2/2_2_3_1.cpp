typedef struct LNode {
    int data;
    struct LNode *next;
} * node, *SqlList;

bool function(SqlList &L, int x) {
    if (L == NULL) return false;
    LNode *T = L, *temp;

    // 第一个结点
    while (T != NULL && T->data == x) {
        temp = T;
        T = T->next;
        free(temp);
    }

    while (T->next != NULL) {
        temp = T->next;
        if (T->next->data == x) {
            T->next = temp->next;
            free(temp);
        }
        T = T->next;
    }

    return true;
}

// 递归
// 递归终点 L==NULL
// 如果 L->data ==x 删掉L 并继续递归
// 如果 L->data != x 递归

void delx(SqlList &L, int x) {
    LNode *p;
    if (L == NULL) return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        delx(L, x);
    } else {
        delx(L->next, x);
    }
}