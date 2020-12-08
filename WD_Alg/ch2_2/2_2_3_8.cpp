typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
// 寻找公共结点
// 公共结点定义: 链表该结点值相等,且以后对应位序上值也相等
LinkList f(LinkList L1, LinkList L2) {
    LNode *temp = L1, *temp2;
    int length1, length2;
    while (temp) {
        length1++;
    }
    temp = L2;
    while (temp) {
        length2++;
    }
    if (length1 == length2) {
        return L1;
    }
    int i;
    temp = L1;
    temp2 = L2;
    if (length1 > length2) {
        i = length1 - length2;
        while (i > 0) {
            temp = temp->next;
            i--;
        }
    } else {
        i = length2 - length1;
        while (i > 0) {
            temp2 = temp2->next;
            i--;
        }
    }

    while (temp != temp2) {
        if (temp2 == NULL) {
            return NULL;
        }
        temp2 = temp2->next;
        temp = temp->next;
    }

    return temp;
}