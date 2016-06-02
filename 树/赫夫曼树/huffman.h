

struct leaf
{
	char data;
	int weight;
	char code[15];
};

struct node
{
	int weight;
	int isleaf;
	node * parent, *lchild, *rchild;
};

class huffman
{
public:
	huffman();
	~huffman();
	void init();
	void creathuffmantree();
	void select(int &s1, int &s2,int k);
	void coding();
	node *root;
private:
	leaf Leaf[15];
	node Node[50];
	int num;
};