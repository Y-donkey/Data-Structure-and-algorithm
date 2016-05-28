#include<iostream>
#include<algorithm>
using namespace std;
int num[10];
void rebuildheap(int,int);
void buildheap()
{
	int i;
	for (i = 4; i > 0; i--)
	{
		rebuildheap(i, 8);
	}
}
void rebuildheap(int left, int right)
{
	int tem = num[left];
	for (int i = left * 2; i <= right; i*=2)
	{
		if (i < right&&num[i] < num[i + 1])  i++;
		if (tem >= num[i])  break;
		num[left] = num[i];
		left = i;
 	}
	num[left] = tem;
}
int main()
{
	for (int i = 1; i <= 8; i++)
	{
		cin >> num[i];
	}
	buildheap();
	for (int i = 8; i >= 1; i--)
	{
		swap(num[i], num[1]);
		rebuildheap(1, i - 1);
		for (int i = 1; i <= 8; i++)
		{
			cout << num[i] << " ";
		}
		cout << endl;
	}
}