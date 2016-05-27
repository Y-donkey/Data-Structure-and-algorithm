#include<iostream>
using namespace std;
int num[6]={21,25,49,25,16,8};
void selectsort(int num[],int n)
{
	int tem,i,j;
	for(i=0;i<n;i++)
	{
		int k=i;
		for(j=i+1;j<n;j++)
		{
			if(num[j]<num[k])   k=j;
		}
		if(k!=i)
		{
			tem=num[k];
			num[k]=num[i];
			num[i]=tem;
		}
	}

	for(int i=0;i<n;i++)  cout<<num[i]<<" ";
 
    cout<<endl;
}
int main()
{
  selectsort(num,6);
}