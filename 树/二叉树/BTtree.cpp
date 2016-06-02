#include<iostream>
#include<stack>
#include<queue>
#include"BTtree.h"
using namespace std;
BTtree::BTtree()
{
	
}
BTtree::~BTtree()
{

}
Btree BTtree::creat()
{
	char ch;
	Btree tem;
	cin >> ch;
	if (ch == '#')  tem = NULL;
	else
	{
		tem = new BTnode;
		tem->data = ch;
		tem->lchild = creat();
		tem->rchild = creat();
	}
	return tem;
}
int BTtree::getheight(Btree tem)
{
	if (tem == NULL)  return 0;
	else
	{
		int i = getheight(tem->lchild);
		int j = getheight(tem->rchild);
		return i < j ? j + 1 : i + 1;
	}
}
int BTtree::getsize(Btree tem)
{
	if (tem == NULL)  return 0;
	else
	{
		return 1 + getsize(tem->lchild) + getsize(tem->rchild);
	}
}
void BTtree::pretravel(Btree tem)
{
	if (tem == NULL) return;
	cout << tem->data << " ";
	pretravel(tem->lchild);
	pretravel(tem->rchild);
}

void BTtree::midtravel(Btree tem)
{
	if (tem == NULL) return;
	pretravel(tem->lchild);
	cout << tem->data << " ";
	pretravel(tem->rchild);
}
void BTtree::lasttravel(Btree tem)
{
	if (tem == NULL) return;
	pretravel(tem->lchild);
	pretravel(tem->rchild);
	cout << tem->data << " ";
}

void BTtree::preorder_dev(Btree root)
{
	stack<Btree>v;
	Btree tem = root;
	if (!root)
	{
		cout << "the tree is empty" << endl;
		return;
   }
	else
	{
		while (tem || !v.empty())
		{
			while (tem)
			{
				cout << tem->data << " ";
				v.push(tem);
				tem = tem->lchild;
			}
			tem = v.top();
			v.pop();
			tem = tem->rchild;
		}
	}
	cout << endl;
}

void BTtree::midorder_dev(Btree root)
{
	Btree tem = root;
	if (!tem)
	{
		cout << "the tree is empty" << endl;
		return;
	}
	else
	{
		stack<Btree>v;
		while (tem || !v.empty())
		{
			while (tem)
			{
				v.push(tem);
				tem = tem->lchild;
			}
			tem = v.top();
			v.pop();
			cout << tem->data << " ";
			tem = tem->rchild;
		}
	}
	cout << endl;
 }

void BTtree::leveltravel(Btree root)
{
	if (root == NULL)
	{
		cout << "the tree is empty" << endl;
		return;
	}
	else
	{
		Btree tem = root;
		queue<Btree>v;
		v.push(tem);
		while (!v.empty())
		{
			tem = v.front();
			cout << tem->data << " ";
			v.pop();
			if (tem->lchild)  v.push(tem->lchild);
			if (tem->rchild)  v.push(tem->rchild);
 		}
	}
	cout << endl;
}
