#include <bits/stdc++.h>
using namespace std;
typedef struct BiTNode {
	struct BiTNode* left, * right;
	int data;
}BTNode, *BiTree;
typedef struct Tag {
	struct Tag* next;
	BTNode* p;
}tag_t, *ptag_t;
void CreateTree(BiTree& T);
void OrderTraverse(BiTree T);
int WPL(BiTree T, int deep);
int main(void)
{
	BiTree T;
	CreateTree(T);
	OrderTraverse(T);
	cout << "\n408-2014-41" << endl;
	cout << "带权路径长度WPL：" << WPL(T, 0) << endl;
	return 0;
}
void CreateTree(BiTree& T) {
	T = NULL;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	BTNode* pnew;
	ptag_t phead = NULL, ptail = NULL, pcur = NULL;
	ptag_t list_tag = NULL;
	
	for (int i = 0; i < 10; i++) {
		pnew = (BTNode*)calloc(1, sizeof(BTNode));
		list_tag = (ptag_t)calloc(1, sizeof(tag_t));
		pnew->data = a[i];
		list_tag->p = pnew;
		if (T == NULL) {
			T = pnew;
			phead = list_tag; 
			ptail = list_tag;
			pcur = list_tag;
		}
		else {
			if (pcur->p->left == NULL) {
				pcur->p->left = pnew;
				ptail->next = list_tag;
				ptail = list_tag;
			}
			else if (pcur->p->right == NULL) {
				pcur->p->right = pnew;
				ptail->next = list_tag;
				ptail->next = list_tag;
				pcur = pcur->next;
			}
		}
	}
}
void OrderTraverse(BiTree T) {
	if (T == NULL) return;
	OrderTraverse(T->left);
	cout << T->data << ' ';
	OrderTraverse(T->right);
}
int WPL(BiTree T, int deep) {
	static int wpl = 0;
	if (T->left == NULL && T->right == NULL) {
		wpl +=  deep * T->data; 
	}
	if (T->left != NULL)
		WPL(T->left, deep + 1);
	if (T->right != NULL)
		WPL(T->right, deep + 1);
	return wpl;
}