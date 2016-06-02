#pragma once
typedef struct BTnode
{
	char data;
	BTnode * lchild;
	BTnode * rchild;
}Bnode,*Btree;
class BTtree
{
public:
	BTtree();
	~BTtree();
	int getheight(Btree tem);    //二叉树高度
	int getsize(Btree tem);        //节点个数
	Btree creat();    //构建二叉树
	void pretravel(Btree tem);   //前序遍历
	void midtravel(Btree tem);   //中序遍历
	void lasttravel(Btree tem);  //后序遍历
	void preorder_dev(Btree root);    //非递归前序遍历
	void midorder_dev(Btree root);  //非递归中序遍历
	void leveltravel(Btree root);  //层序遍历
};