#include"huffman.h"
#include<iostream>
#include<cstring>
using namespace std;


huffman::huffman()
{

}

huffman::~huffman()
{

}
void huffman::init()
{
	cout << "请输入叶子结点个数（不超过15个）：" << endl;
	cin >> num;
	cout << endl << "请依次输入" << num << "个叶子结点的数据域（字符）"<<endl;
	for (int i = 1; i <= num; i++)
	{
		cin >> Leaf[i].data;
	}
	cout << endl << "请依次输入" << num << "个叶子结点的权值"<<endl;
	for (int i = 1; i <= num; i++)
	{
		cin >> Leaf[i].weight;
	}
	cout << endl;

   

	int m = 2 * num - 1;
	for (int i = 1; i <= m; i++)
	{
		if (i <= num)
		{
			Node[i].weight = Leaf[i].weight;
			Node[i].isleaf = 1;
		}
		else
		{
			Node[i].isleaf = 0;
			Node[i].weight = 0;
		}

		Node[i].parent = Node[i].lchild = Node[i].rchild = NULL;
	}
}

void huffman::select(int &s1, int &s2, int k)
{
	int i;
	for (i = 1; i <= k; ++i) {
		if (Node[i].parent == NULL)
			break;
	}
	s1 = i;

	for (int i = 2; i <= k; i++)
	{
		if (Node[i].parent == NULL&&Node[i].weight < Node[s1].weight&&Node[i].parent == NULL)
		{
			s1 = i;
		}
	}
	for ( i = 1; i <= k; ++i) {
		if (Node[i].parent == NULL && i != s1)
			break;
	}
	s2 = i;

	for ( i = 1; i <= k; i++)
	{
		if (Node[i].parent == NULL&&Node[i].weight < Node[s2].weight&&Node[i].parent == NULL&&i!=s1)
		{
			s2 = i;
		}
	}

}


void huffman::creathuffmantree()
{
	int m = 2 * num - 1;
	int s1, s2, k;
	for (int i = num + 1; i <= m; i++)
	{
		select(s1, s2, i - 1);
		Node[s1].parent = Node[s2].parent = &Node[i];
		Node[i].lchild = &Node[s1];
		Node[i].rchild = &Node[s2];
		Node[i].weight = Node[s1].weight + Node[s2].weight;
	}
	root = &Node[m];
}

void huffman::coding()
{
	char tem[20];
	int start = num - 1;
	tem[start] = '\0';
	node *child, *fa;
	for (int i = 1; i <= num; i++)
	{
		start = num - 1;
		for (child = &Node[i], fa = Node[i].parent; fa != NULL; child = fa, fa = fa->parent)
		{
			if (fa->lchild == child)  tem[--start] = '0';
			else if (fa->rchild == child)  tem[--start] = '1';
		}
		strcpy(Leaf[i].code, &tem[start]);
	}

	cout << endl << "相应字符对应的不定编码是：" << endl;
	for (int i = 1; i <= num; i++)
	{
		cout << Leaf[i].data << ": " << Leaf[i].code << endl;
	}
}

