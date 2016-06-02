#include<iostream>
#include<cstring>
using namespace std;
int NEXT[100];
char target[100];
char pattern[100];
void get_next(char Pattern[])
{
	NEXT[0] = -1;
	int i = 0, j = -1;
	while (i < strlen(Pattern))
	{
		if (j == -1 || Pattern[i] == Pattern[j])
		{
			i++;
			j++;
			NEXT[i] = j;
		}
		else
		{
			j = NEXT[j];
		}
	}
}

int index(char T[], char P[])
{
	int i= 0;
	int j = 0;
	while (i<strlen(T))
	{
		if ( j==-1||T[i] == P[j])
		{
			i++;
			j++;
		}
		else j = NEXT[j];
		if (j == strlen(P)) return i - j;
	}
	return -1;
}
int main()
{
	cout << "请依次输入目标串和模式串" << endl;
	cin >> target >> pattern;
	get_next(pattern);
	cout << index(target, pattern);
}