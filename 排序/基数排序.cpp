/*
 基数排序分为分配和收集两个过程，从个位依次向高位操作
分配： 按照每个数在相应位数的值分配在0~9十个桶中
收集：由小至大依次从桶中收集数

最后，便可得到有序的数列

*/


#include<iostream>
using namespace std;
int Array[] = {50, 123, 543, 187, 49, 30, 0, 2, 11, 100};
int getnuminpos(int num, int pos)     //得到num由个位开始数的第pos位上的数值
{
	int tem = 1;
	for (int i = 1; i < pos; i++)  tem *= 10;
	return (num / tem) % 10;
}
void radixsort(int n)   //n为数组元素的个数
{
	int * bucket[10];   //十个桶
	for (int i = 0; i < 10; i++)
	{
		bucket[i] = new int[20];
		bucket[i][0] = 0;      //第一个位置存放桶中元素的个数
	}
	for (int i = 1; i <= 3; i++)   //个位到最高位
	{
		for (int j = 0; j < n; j++)   //分配
		{
			int tem = getnuminpos(Array[j], i);
			int index = ++bucket[tem][0];
			bucket[tem][index] = Array[j];
		}
		int p = 0;
		for (int k = 0; k < 10; k++)
		{
			for (int t = 1; t <= bucket[k][0]; t++)
			{
				Array[p++] = bucket[k][t];
			}
			bucket[k][0] = 0;
		}

	}

}

int main()
{
	radixsort(10);
	for (int i = 0; i < 10; i++)  cout << Array[i] << " ";
}