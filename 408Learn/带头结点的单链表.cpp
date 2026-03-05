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
