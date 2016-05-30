#include<iostream>
using namespace std;
int num[7] = { 21,25,49,25,16,8,16 };
int Partition(int low, int high)
{
	int tem = num[low];
	int i = low;               
	int j = high;           
	while (i<j)
	{
		while (num[j]>tem&&i<j)
		{
			j--;
		}
		if (i<j)
		{
			swap(num[i], num[j]);
			i++;
		}
		while (num[i]<tem&&i<j)
		{
			i++;
		}
		if (i<j)
		{
			swap(num[i], num[j]);
			j--;
		}
	}
	return j;
}

void quicksort(int left, int right)
{
	if (left<right)
	{
		int q = Partition(left, right);
		quicksort(left, q - 1);
		quicksort(q + 1, right);
	}
}


int main()
{
	quicksort(0, 6);
	//Partition(0, 5);
	for (int i = 0; i <= 6; i++)  cout << num[i] << " ";
}
