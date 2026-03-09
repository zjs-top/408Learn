#include <stdio.h>
#include <stdlib.h>

// 结点
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

// 队列（队头、队尾指针）
typedef struct {
    QNode* front;
    QNode* rear;
} LinkQueue;

// 初始化
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
}

// 入队
int EnQueue(LinkQueue& Q, int x) {
    QNode* s = (QNode*)malloc(sizeof(QNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return 1;
}

// 出队
int DeQueue(LinkQueue& Q, int& x) {
    if (Q.front == Q.rear) return 0;
    QNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return 1;
}