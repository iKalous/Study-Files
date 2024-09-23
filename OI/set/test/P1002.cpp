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

const int N = 100;

int n,m,x,y;
long long f[N][N];

int judge(int a,int b)
{
	if((a == x) && (b == y)) return 0;
	if((a == x - 1) && (b == y - 2)) return 0;
	if((a == x - 2) && (b == y - 1)) return 0;
	if((a == x - 1) && (b == y + 2)) return 0;
	if((a == x - 2) && (b == y + 1)) return 0;
	if((a == x + 1) && (b == y - 2)) return 0;
	if((a == x + 2) && (b == y - 1)) return 0;
	if((a == x + 1) && (b == y + 2)) return 0;
	if((a == x + 2) && (b == y + 1)) return 0;
	return 1;
}
int main()
{
	read(n), read(m), read(x), read(y);
	++n, ++m, ++x, ++y;
	
	f[1][1] = 1;
	for(int i = 1;i <= n; ++ i)
		for(int j = 1;j <= m; ++ j)
			if(judge(i,j)) f[i][j] += f[i - 1][j] + f[i][j - 1];
	
	printf("%lld\n",f[n][m]);
	return 0;
}
