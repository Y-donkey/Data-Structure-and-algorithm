#include<iostream>
using namespace std;
typedef struct node
{
	char data;
	int ltag, rtag;
	node *lchild, *rchild;
}Node, *Tree;
Tree pre = NULL;
Tree creat()
{
	Tree root;
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		root = NULL;
	}
	else
	{
		root = new node;
		root->data = ch;
		root->ltag = root->rtag = 0;
		root->lchild = creat();
		root->rchild = creat();
	}
	return root;
}

void travel(Tree root, Tree pre)
{
	if (root == NULL)  return;
	travel(root->lchild,pre);
	if (root->lchild == NULL)
	{
		root->ltag = 1;
		root->lchild = pre;
	}

	if (pre != NULL&&pre->rchild == NULL)
	{
		pre->rtag = 1;
		pre->rchild = root;
	}
	pre = root;
	travel(root->rchild, pre);
}
void print1(Tree root)
{
	if (root == NULL)  return;
	Tree tem = root;
	print(root->lchild);
	cout << root->data << " ";
	print(root->rchild);
}

void print2(Tree root)
{
	

}
int main()
{
	Tree root = creat();
	print1(root);
	cout << endl;
}

