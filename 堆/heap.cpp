#include"heap.h"
#include<iostream>
using namespace std;
M_heap::M_heap()
{
	data = new int[100];
}
M_heap::~M_heap()
{

}
void M_heap::init(int arr[], int size)
{
	for (int i = 1; i <= size; i++)
	{
		data[i] = arr[i];
	}
	currentsize = size;
	int flag = (size) / 2;
	for (int i = flag; i > 0; i--)
	{
		rebuildheap(i, size);
	}
}
void M_heap::rebuildheap(int left, int right)
{
	int tem = data[left];
	for (int i = left * 2; i <= right; i *= 2)
	{
		if (i < right&&data[i] > data[i + 1])  i++;
		if (tem <= data[i])  break;
		data[left] = data[i];
		left = i;
	}
	data[left] = tem;
}
void M_heap::print()
{
	for (int i = 1; i <= currentsize; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
void M_heap::Insert(int x)
{
	currentsize++;
	data[currentsize] = x;
	int i = currentsize;
	int j = i / 2;
	while (i > 0)
	{
		if (data[j] <= x)  break;
		else
		{
			data[i] = data[j];
			i = j;
			j = (i) / 2;
		}
	}
	data[i] = x;
}
void M_heap::removemin(int &x)
{
	x = data[1];
	data[1] = data[currentsize];
	currentsize--;
	rebuildheap(1, currentsize - 1);
}
