#include<iostream>
using namespace std;
long long q_mul_mod(long long a, long long b, long long m)  //计算（a*b)%m
{
	a %= m;
	b %= m;
	long long t = 0;
	while (b)
	{
		if (b & 1)   //如果该位二进制是1
		{
			t += a;
			if (t > m)  t -= m;
		}
		a <<= 1;
		if (a >= m)  a -= m;
		b >>= 1;
	}
	return t;
}

long long q_pow_mod(long long a, long long b, long long m)  //计算(a^b)%m
{
	long long ans = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
		{
			ans = q_mul_mod(ans,a, m);    //(a*b)%m=((a%m)*(b%m))%m
		}
		b >>= 1;
		a = q_mul_mod(a, a, m);
	}
	return ans;
}
int main()
{
	q_pow_mod(3, 5, 7);
}