#include<iostream>
using namespace std;
int num[6]={21,25,49,25,16,8};
void bubblesort(int num[],int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=n-1;j>=i;j--)
		{
			if(num[j-1]>num[j])
			{
				int tem=num[j-1];
				num[j-1]=num[j];
				num[j]=tem;
			}
		}
	}
	for(int i=0;i<n;i++) cout<<num[i]<<" ";
}

void improvebubblesort(int num[],int n)
{
	bool change;
	for(int i=1;i<n;i++)
	{
		change=false;
		for(int j=n-1;j>=1;j--)
		{
			if(num[j-1]>num[j])
			{
				int tem=num[j-1];
				num[j-1]=num[j];
				num[j]=tem;
				change=true;
			}
		}
		if(change==false)  break;
	}
	for(int i=0;i<n;i++) cout<<num[i]<<" ";
}
int main()
{
	bubblesort(num,6);
   improvebubblesort(num,6);
}