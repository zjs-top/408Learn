#include <stdio.h>
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front;  // 队头
    int rear;   // 队尾
} SqQueue;

// 初始化
void InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
}

// 入队
int EnQueue(SqQueue& Q, int x) {
    if (Q.rear == MaxSize) return 0; // 队满
    Q.data[Q.rear++] = x;
    return 1;
}

// 出队
int DeQueue(SqQueue& Q, int& x) {
    if (Q.front == Q.rear) return 0; // 队空
    x = Q.data[Q.front++];
    return 1;
}