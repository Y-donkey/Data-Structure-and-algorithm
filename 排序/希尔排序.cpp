#include<iostream>
using namespace std;
int num[6]={21,25,49,25,16,8};
void shellsort(int num[],int n)
{
	int gap,i,j;
	gap=n/2;
	while(gap>=1)
	{
		for( i=gap;i<n;i++)
		{
			int tem=num[i];
			for( j=i-gap;j>=0&&num[j]>tem;j-=gap)
			{
               num[j+gap]=num[j];
			}
			num[j+gap]=tem;
		}
		gap/=2;
	}
	for(int i=0;i<n;i++)  cout<<num[i]<<" ";
 
    cout<<endl;
}

int main()
{
	shellsort(num,6);
}