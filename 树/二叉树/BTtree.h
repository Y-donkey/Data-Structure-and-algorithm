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
	int getheight(Btree tem);    //�������߶�
	int getsize(Btree tem);        //�ڵ����
	Btree creat();    //����������
	void pretravel(Btree tem);   //ǰ�����
	void midtravel(Btree tem);   //�������
	void lasttravel(Btree tem);  //�������
	void preorder_dev(Btree root);    //�ǵݹ�ǰ�����
	void midorder_dev(Btree root);  //�ǵݹ��������
	void leveltravel(Btree root);  //�������
};