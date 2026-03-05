#include<stdio.h>
#define Maxsize 10
typedef struct {
	int data[Maxsize];
	int length;//length代表顺序表当前长度，Maxsize为顺序表的最大长度
}SqList;

void InitList(SqList &L) {
	L.length = 0;
}
bool InsertList(SqList& L, int i, int e) {
	//判断i是否有效
	if (i<1 || i>L.length + 1) {
		return false;
	}
	//存储空间是否满
	if(L.length>=Maxsize){
		return false;
	}
	//移动n-i+1项
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	//插入值
	L.data[i-1] = e;
	//当前长度加一
	L.length++;
}
