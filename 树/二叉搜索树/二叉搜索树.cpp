#include<iostream>
using namespace std;
int num[7] = { 53,80,60,45,57,32,88 };
typedef struct node
{
	int data;
	node *lchild;
	node *rchild;
}BTnode, *BTtree;
BTtree insert(BTtree root, BTtree tem)
{
	if (root == NULL)  return tem;
	else
	{
		if (tem->data < root->data)
		{
			root->lchild = insert(root->lchild, tem);
		}
		else
		{
			root->rchild = insert(root->rchild, tem);
		}
		return root;
	}
}
BTtree creat()
{
	BTtree root=NULL;
	for (int i = 0; i < 7; i++)
	{
		BTtree tem = new node;
		tem->data = num[i];
		tem->lchild = NULL;
		tem->rchild = NULL;
		root = insert(root, tem);
	}
	return root;
}
BTtree find(BTtree root, int k)
{
	if (root == NULL)
	{
		cout << "NOT FOUND!" << endl;
		return NULL;
	}
	else
	{
		if (root->data == k)
		{
			cout << "FOUND IT" << endl;
			return root;
		}
		else
		{
			if (k < root->data)    return find(root->lchild, k);
			else return find(root->rchild, k);
		}
	}
}
BTtree findparent(BTtree root, int k)
{
	if (root->lchild->data == k || root->rchild->data == k)   return root;
	else
	{
		if (k < root->data)   return findparent(root->lchild, k);
		else return findparent(root->rchild, k);
	}
}
void Delete(BTtree root, int k)
{
	BTtree tem = find(root, k);
	BTtree pre = findparent(root, k);
	int flag;
	if (pre->lchild->data == k)   flag = 1;
	else flag = 0;
	if (tem == NULL)
	{
		cout << "this number is not in the tree" << endl;
		return;
	}
	else
	{
		if (!tem->lchild&&!tem->rchild)
		{
			if (flag)   pre->lchild = NULL;
			else pre->rchild = NULL;
			delete tem;
		}
		else
		{
			if (!tem->rchild)
			{
				if (flag)
				{
					pre->lchild = tem->lchild;
				}
				else  pre->rchild = tem->lchild;
				delete tem;
			}
			else if (!tem->lchild)
			{
				if (flag)
				{
					pre->lchild = tem->rchild;
				}
				else  pre->rchild = tem->rchild;
				delete tem;
			}
			else
			{
				BTtree p, q;
				p = tem;
				q = tem->rchild;
				while (q->lchild != NULL)
				{
					p = q;
					q = q->lchild;
				}
				tem->data = q->data;
				if (p == tem)  p->rchild = q->rchild;
				else p->lchild = q->rchild;
				delete q;
			}
		}
	}
}
void print(BTtree root)
{
	if (root == NULL)  return;
	cout << root->data << " ";
	print(root->lchild);
	print(root->rchild);
}
int main()
{
	BTtree root = creat();
	BTtree tem;
	print(root);
	cout << endl;
	Delete(root,80);
	print(root);
	tem = findparent(root,57);
	cout << tem->data;
	cout << endl;
}