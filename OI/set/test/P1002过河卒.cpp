#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
void read(T &x)
{
	int fg = 1; x = 0; char ch = getchar();
	for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
	for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

const int N = 25;

int n,m,x,y;
int f[N][N];

int judge(int a,int b)
{
	int fg = 0;
	if((a == x - 2) && (b == y - 1)) fg = 1;
	if((a == x - 1) && (b == y - 2)) fg = 1;
	if((a == x + 1) && (b == y - 2)) fg = 1;
	if((a == x + 2) && (b == y - 1)) fg = 1;
	if((a == x - 2) && (b == y + 1)) fg = 1;
	if((a == x - 1) && (b == y + 2)) fg = 1;
	if((a == x + 1) && (b == y + 2)) fg = 1;
	if((a == x + 2) && (b == y + 1)) fg = 1;
	return fg; 
}

int main()
{
	//freopen("P1002.in","r",stdin);
	//freopen("P1002.out","w",stdout);
	
	read(n), read(m), read(x), read(y);
	f[0][0] = 1;
	for(int i = 0;i <= n; ++i)
		for(int j = 0;j <= m; ++j)
			judge(i,j) == 1 ? f[i][j] = 0 : f[i][j] = f[i - 1][j] + f[i][j - 1];
	
	printf("%d\n",f[n][m]);
	
	//fclose(stdin); fclose(stdout);
	return 0;
}
