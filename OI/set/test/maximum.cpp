#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
void read(T &x)
{
	int fg = 1; char ch = getchar(); x = 0;
	for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
	for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg; 
}

const int N = 40010;

struct num { int a[N],n; } ans,t;
void time(num a,num &b)
{
	num c; c.n = a.n + b.n;
	for(int i = 1;i <= c.n; ++ i) c.a[i] = 0;
	for(int i = 1;i <= a.n; ++ i)
		for(int j = 1;j <= b.n; ++ j)
			c.a[i + j - 1] += a.a[i] * b.a[j], 
			c.a[i + j] += c.a[i + j - 1] / 10,
			c.a[i + j - 1] %= 10;
			
	for(;c.a[c.n] == 0; -- c.n);
	b.n = c.n;
	for(int i = 1;i <= c.n; ++ i)
		b.a[i] = c.a[i];
}
void add(num a,num &b)
{
	num c; c.n = a.n + b.n;
	for(int i = 1;i <= c.n; ++ i) c.a[i] = 0;
	for(int i = 1;i <= a.n; ++ i)
		for(int j = 1;j <= b.n; ++ j)
			c.a[i + j - 1] += a.a[i] + b.a[j],
			c.a[i + j] += c.a[i + j - 1] / 10,
			c.a[i + j - 1] %= 10;
		
	for(;c.a[c.n] == 0; -- c.n);
	b.n = c.n;
	for(int i = 1;i <= c.n; ++ i)
		b.a[i] = c.a[i];
}
void assign(num &t,int x)
{
	t.n = 0;
	for(;x;x /= 10)
		t.a[++t.n] = x % 10;
}
void write(num t)
{
	for(int i = t.n;i >= 1; -- i) printf("%d",t.a[i]);
}
int n,m;

int main()
{
	read(n);
	ans.n = 1; ans.a[1] = 1;
	for(int i = 1;i <= n; ++ i)
		if(((i + 1) * (i) / 2 - 1) >= n) { m = i; break; }
	int x = m * (m + 1) / 2 - n - 1;
	if(x == 1)
	{
		for(int i = 3;i < m; ++ i) 
			assign(t,i), time(t,ans), printf("%d ",i); 
		assign(t,m + 1), time(t,ans), printf("%d\n",m + 1);
	}
	else
	{
		for(int i = 2;i <= m; ++ i)
			if(i != x) assign(t,i), time(t,ans), printf("%d ",i);
		printf("\n");
	}
	
	write(ans);
	return 0;
}
