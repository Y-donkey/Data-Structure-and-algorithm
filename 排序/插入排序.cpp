#include<iostream>
using namespace std;
int num[6]={21,25,49,25,16,8};
void insertsort(int num[],int n)    //直接插入排序
{
	int tem,j;
	for(int i=1;i<n;i++)
	{
		tem=num[i];
		j=i-1;
		while(j>=0&&num[j]>tem)
		{
			num[j+1]=num[j];
			j--;
		}
		num[j+1]=tem;
	}
	for(int i=0;i<n;i++)  cout<<num[i]<<" ";
 
    cout<<endl;
}

void binaryinsertsort(int num[],int n)
{
	int i,j,left,right,mid,tem;
	for(int i=1;i<n;i++)
	{
		left=0,right=i-1;
		tem=num[i];
		while(left<=right)
		{
           mid=(left+right)/2;
           if(num[mid]>tem)
           {
           	right=mid-1;
           }
           else left=mid+1;
		}
        for(int k=i-1;k>=left;k--)   num[k+1]=num[k];

        num[left]=tem;
	}
	for(int i=0;i<n;i++)  cout<<num[i]<<" ";
 
    cout<<endl;
}
int main()
{
	insertsort(num,6);
	binaryinsertsort(num,6);
}