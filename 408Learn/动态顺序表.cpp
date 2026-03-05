#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef struct {
	int length;
	int MaxSize;
	int *data;
}SqList;
void InitList(SqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.MaxSize = InitSize;
	L.length = 0;
}
void IncreaseSize(SqList& L, int len) {
	int* p = L.data;
	//如果先L.MaxSize = L.MaxSize + len;万一分配失败MaxSize任然更新了
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
}
int GetElem(SqList& L, int i) {
	return L.data[i-1];
}
int LocateElem(SqList& L, int e)
{
	for (int i=0; i < L.length; i++) {
		if (L.data[i] == e)return i + 1;
	}
	return -1;
}
int main() {
	SqList L;
	InitList(L);
	IncreaseSize(L, 5);
	for (int i = 0; i < L.MaxSize; i++) {
		printf("L.data[%d]=%d\n", i, L.data[i]);
	}
}