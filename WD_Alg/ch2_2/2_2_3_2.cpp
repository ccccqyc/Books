// 反向输出带头结点 单链表
// 利用栈实现
typedef struct LNode {
    int data;
    struct LNode* next;
} * node, *SqlList;
void funtion(SqlList L) {
    Stack S;       //栈
    InitStack(S);  // 初始化

    LNode* temp = L->next;
    while (temp) {
        push(S, temp->data);
        temp = temp->next;
    }  // while

    int x;
    while (!isEmpty(S)) {
        pop(S, x);
        printf("%d ", x);
    }
}

// 递归
void function2(SqlList L) {
    if (L->next != NULL) {
        function2(L->next);
    }
    if (L != NULL) print(L->data);
}