#include <stdio.h>
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front;
    int rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
}

// 队空
int QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

// 入队
int EnQueue(SqQueue& Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front) return 0;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return 1;
}

// 出队
int DeQueue(SqQueue& Q, int& x) {
    if (QueueEmpty(Q)) return 0;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return 1;
}