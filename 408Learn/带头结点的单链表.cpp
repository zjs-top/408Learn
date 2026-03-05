#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;
bool InitList(LinkList L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return	true;
}
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 1) {
		return false;
	}
	int j = 0;
	LNode *p = L;
	while (j < i - 1 && p != NULL) {
		p=p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//指定节点后插
bool InsertNextNode(LNode* p, int e) {
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
} 
//指定节点前插
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL) {
		return false;
	} 
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = p->data;
	s->next = p->next;
	p->next = s; 
	p->data = e;
	return true;
}
//按序号插入节点
bool InsertNextNode(LinkList& L,int i, int e) {
	if (i < 1) {
		return false;
	}
	int j = 0;//记录当前节点位序
	LNode* p = L;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode*));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//按序号查找节点
LNode* GetElem(LinkList &L, int i) {
	if (i < 1) {
		return NULL;
	}
	LNode* p = L;
	while (i > 0&&p!=NULL) {
		p = p->next;
		i--;
	}
	return p;
}
//按值查找
LNode* LocateElem(LinkList& L, int e) {
	LNode* p = L;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
//删除节点已知位序
bool ListDelete(LinkList& L, int i,int &e) {
	if (i < 0) {
		return false;
	}
	int j = 0;
	LNode* p = L;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	e = p->next->data;
	//不要写成p->next = p->next ->next;节点实际没被删除,内存不会被释放
	LNode* s = p->next;
	p->next = s->next;
	free(s);//清除的是s节点指向的内存空间
	return true;
}
//删除已知节点(该方法删除时会有问题，采用从头判断没问题逻辑如位序)
bool ListDelete(LinkList& L,LNode* q ,int i, int& e) {
	e=q->data;
	LNode* p = q->next;//当q为链表链尾元素时p为NULL,p->next不存在
	p->data = q->data;
	q->next = p->next;
	free(p);
}
//头插法建表
LinkList List_HeadInsert(LinkList& L) {
	LNode* s;
	int e;
	L = (LNode*)(malloc)(sizeof(LNode));
	L->next = NULL;//注意初始化头结点
	scanf("%d", &e);
	while (e != 9999) {
		s = (LNode*)malloc(sizeof(LNode));//每次循环都要创建新节点
		s->data = e;
		s->next = L->next;
		L->next = s;
		scanf("%d", &e);
	}
	return L;
}
// 带头结点的单链表原地逆置
LinkList List_Reverse(LinkList& L) {
	if (L->next == NULL || L->next->next == NULL) {
		return L;
	}

	LNode* prev = NULL;          // 已逆置部分的前一个节点
	LNode* curr = L->next;        // 当前待处理节点
	LNode* next = NULL;           // 保存下一个节点

	while (curr != NULL) {
		next = curr->next;        // 暂存后继节点
		curr->next = prev;        // 反转当前节点的指针
		prev = curr;              // prev 前进
		curr = next;              // curr 前进
	}
	// 此时 prev 指向原链表的尾节点（即新链表的第一个数据节点）
	L->next = prev;

	return L;
}
//不带头结点的头插法
LinkList List_HeadIsert2(LinkList& L) {
	LNode* s;
	int x;
	scanf("%d", &s);
	L = NULL;
	while (x != 9999) {
		s =(LNode*) malloc(sizeof(LNode));
		s->data = x;
		s->next = L;
		L = s;
		scanf("%d", &x);
	}
	return L;
}