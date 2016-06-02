#pragma once
class M_heap
{
public:
	M_heap();
	~M_heap();
	void init(int arr[], int size);
	void  Insert(int x);    //≤Â»ÎΩ·µ„
	void rebuildheap(int left, int right);
	void removemin(int &x);
	void print();
private:
	int *data;
	int currentsize;
};
