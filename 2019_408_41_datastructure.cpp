/*2019-408-41*/
/*
* 2019年408数据结构真题，题目要求对单链表在空间复杂度为O(1)的情况下
* 改造为1, n, 2, n-1, ....的排序！
*/
#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 100;
typedef int ElemType; 
typedef struct LNode {
	struct LNode* next;
	int val;
}LNode, *LinkList;
void CreateList(LinkList& L);	//建新单链表
void FindMid(LinkList L, LinkList& L1, LinkList& L2);	//找到链表的中间位置进行分割
void MargeMid(LinkList& L1, LinkList& L2);	//合并两表
void ReverseList(LinkList& L);	//链表拟制
void TraverseList(LinkList L);	//遍历链表
int main(void) {
	LinkList L = (LNode*)malloc(sizeof(LNode) * MaxSize);
	CreateList(L);
	TraverseList(L);
	LinkList L1, L2;
	FindMid(L, L1, L2); 
	ReverseList(L2);
	TraverseList(L2);
	MargeMid(L1, L2);
	TraverseList(L);
}
void CreateList(LinkList& L) {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	L->next = NULL;
	LNode* p = L;
	for (int i = 0; i < 10; ++i) {
		LNode* t = (LNode*)malloc(sizeof(LNode));
		t->val = a[i];
		p->next = t;
		t->next = NULL;
		p = t;
	}
}
void FindMid(LinkList L, LinkList& L1, LinkList& L2) {	//将链表分割为两个部分
	LNode* i;
	LNode* j;
	i = L; j = L->next;
	while (j != NULL) {
		i = i->next;
		j = j->next->next;
	}
	L1 = L;
	L2 = i; 

}
void MargeMid(LinkList& L1, LinkList& L2) {	//链表的合并
	LNode* i = L1->next;
	LNode* j = L2->next;
	LNode* end = j;
	while (true) {
		LNode* t1 = i->next;
		LNode* t2 = j->next;
		i->next = j;
		i = t1;
		if (t2 == NULL) break;	// 若无此语句，'6'节点的Next将会指向10，造成无限循环链表！
		j->next = i;	
		j = t2; 
			
	}
	
}
void ReverseList(LinkList& L) {
	LNode* i = L->next;
	LNode* j = i->next;
	LNode* k = j->next;
	i->next = NULL;
	while (k != NULL) {
		j->next = i;
		i = j;
		j = k;
		k = k->next;
	}
	j->next = i; 
	L->next = j;
}
void TraverseList(LinkList L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
}