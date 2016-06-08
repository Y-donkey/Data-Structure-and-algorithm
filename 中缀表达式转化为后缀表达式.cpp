/*
   规则：借助一个栈
         1：如果是数字，直接输出
		 2：如果是 '(' ,'*' ,'/'  ，直接进栈
		 3：如果是 ')' ,弹栈，知道遇见'('或者栈为空，最后将 '(' 弹出
		 4：如果是 '+', '-', 弹栈，知道遇见'('或者栈为空，最后将'+'压入
		 5：输入结束后，将栈中的元素依次弹出

*/




#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
	stack<char>v;
	char ch;
	cout << "请输入中缀表达式，以#结束：" << endl;
	scanf("%c", &ch);
	while ('#' != ch)
	{
		while (ch >= '0'&&ch <= '9')
		{
			cout << ch;
			scanf("%c", &ch);
		}
		cout << " ";
		if ('#' == ch)   break;
		else if (ch == '(' || ch == '*' || ch == '/')     v.push(ch);
		else if (ch == ')')
		{
			while (!v.empty() && v.top() != '(')
			{
				cout << v.top() << " ";
				v.pop();
			}
			if (!v.empty())  v.pop();
		}
		else if (ch == '+' || ch == '-')
		{
			while (!v.empty()&&v.top()!='(')
			{
				cout << v.top() << " ";
				v.pop();
			}
			v.push(ch);
		}
		else
		{
			cout << "输入错误" << endl;
			return 0;
		}

		scanf("%c", &ch);
	}
	while (!v.empty())
	{
		cout << v.top() << " ";
		v.pop();
	}
}