// Queue 队列
#include <malloc.h>

#include <cstdio>
#define MaxSize 50
typedef int Elemtype;
using namespace std;

// 顺序队列
typedef struct Queue {
    Elemtype data[MaxSize];
    int front, rear;
} SqQueue;

// 链式存储
typedef struct {
    Elemtype data;
    struct LinkNode *next;
} LinkNode;  //链式队列结点
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(Queue &Q);
bool QueueEmpty(Queue Q);
void EnQueue(Queue &Q, Elemtype x);
void DeQueue(Queue &Q, Elemtype &x);
void GetHead(Queue Q, Elemtype &x);
//链式队列实现队列基本操作
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
}
bool QueueEmpty(LinkQueue Q) { return Q.rear == Q.front; };
void EnQueue(LinkQueue &Q, Elemtype x) {
    LinkNode *n = (LinkNode *)malloc(sizeof(LinkNode));
    n->data = x;
    Q.rear->next = n;
    n->next = NULL;
    Q.rear = n;
};
void DeQueue(LinkQueue &Q, Elemtype &x) {
    if (QueueEmpty(Q)) return;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next; //头结点作用体现
    if(Q.rear == p){
        Q.rear = Q.front; //原队列仅有一个结点 删除后空
    }
    free(p);
};
void GetHead(LinkQueue Q, Elemtype &x);

// 循环队列
void InitQueue(Queue &Q) {
    Q.rear = 0;
    Q.front = 0;
}

bool QueueEmpty_(Queue Q) { return Q.front == Q.rear; }

void EnQueue_(Queue &Q, Elemtype x) {
    // 第一步应该判 队满
    // (Q.rear+1)%Maxsize == Q.front ? return false : true;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
}

void EnQueue_(Queue &Q, Elemtype &x) {
    // 第一步 该判空
    // Q.rear == Q.front ? return false : true
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
}
// 循环队列结束