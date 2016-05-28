#include<iostream>
using namespace std;
int num[6] = { 21,25,49,7,16,8 };
void quicksort(int left, int right)
{

	int i, j, t;
	if (left < right)
	{
		i = left;
		j = right;
		while (1)
		{
			while (i + 1 < 6 && num[++i] < num[left]);
			while (j - 1 >= 0 && num[--j]>num[left]);
			if (i >= j)  break;
			swap(num[i], num[j]);
		}
		swap(num[left], num[j]);
		quicksort(left, j - 1);
		quicksort(j + 1, right);
	}
}

int main()
{
	quicksort( 0, 6);
	for (int i = 0; i < 6; i++) cout << num[i] << " ";
}