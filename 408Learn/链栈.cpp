#include <stdio.h>
#include <stdlib.h>

// 1. 链栈结点定义
typedef struct StackNode {
    int data;               // 数据域
    struct StackNode* next; // 指针域
} StackNode, * LinkStack;

// 2. 初始化栈（栈顶指针置空）
void InitStack(LinkStack& S) {
    S = NULL; // 链栈空
}

// 3. 判断栈空
int StackEmpty(LinkStack S) {
    return S == NULL;
}

// 4. 入栈（头插法！核心操作）
int Push(LinkStack& S, int x) {
    // 新建结点
    StackNode* s = (StackNode*)malloc(sizeof(StackNode));
    s->data = x;

    // 头插法
    s->next = S;  // 新结点指向原栈顶
    S = s;        // 栈顶指针移动到新结点

    printf("入栈：%d\n", x);
    return 1;
}

// 5. 出栈（删除头结点）
int Pop(LinkStack& S, int& x) {
    if (StackEmpty(S)) {
        printf("栈空，出栈失败！\n");
        return 0;
    }

    StackNode* p = S;   // 暂存栈顶
    x = p->data;        // 取出数据
    S = S->next;        // 栈顶指针后移
    free(p);            // 释放结点

    printf("出栈：%d\n", x);
    return 1;
}

// 6. 遍历栈（从栈顶到栈底）
void PrintStack(LinkStack S) {
    StackNode* p = S;
    printf("栈内容（栈顶→栈底）：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 主函数测试
int main() {
    LinkStack S;
    InitStack(S);

    // 入栈
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    PrintStack(S); // 30 20 10

    // 出栈
    int x;
    Pop(S, x);
    PrintStack(S); // 20 10

    Pop(S, x);
    Pop(S, x);
    Pop(S, x); // 栈空

    return 0;
}