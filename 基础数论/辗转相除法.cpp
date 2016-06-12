/*
辗转相除法又称欧几里得算法，用于求两个正整数的最大公因子
gcd(a,b)=gcd(b,a%b)

*/

//核心代码：

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}