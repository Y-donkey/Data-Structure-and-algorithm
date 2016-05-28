#include<iostream>
using namespace std;
int num[6] = { 21,25,49,7,16,8 };
void merge(int left, int mid, int right)
{
	int i = left, j = mid + 1, p = 0;
	int tem[10];
	while (i <= mid&&j <= right)
	{
		if (num[i] < num[j])
		{
			tem[p] = num[i];
			p++;
			i++;
		}
		else
		{
			tem[p] = num[j];
			j++;
			p++;
		}
	}
	while (i <= mid)
	{
		tem[p] = num[i];
		i++;
		p++;
	}
	while (j <= right)
	{
		tem[p] = num[j];
		j++;
		p++;
	}
	p = 0;
	for (int i = left; i <= right; i++)
	{
		num[i] = tem[p++];
	}
}
void mergesort(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergesort(left, mid);
		mergesort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main()
{
	mergesort(0, 5);
	for (int i = 0; i < 6; i++)  cout << num[i] << " ";
}