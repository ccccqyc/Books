#include <cstdio>
#define MaxSize 50
typedef int Elemtype;
using namespace std;

typedef struct Stack {
    Elemtype data[MaxSize];
    int top;
} SqStack;

typedef struct Linknode
{
    Elemtype data;
    struct Linknode *next;
}*LiStack;


void InitStack(Stack &S);
bool StackEmpty(Stack S);
void Push(Stack &S, Elemtype x);
void Pop(Stack &S, Elemtype &x);
void GetTop(Stack S, Elemtype &x);
void DestoryStack(Stack &S);