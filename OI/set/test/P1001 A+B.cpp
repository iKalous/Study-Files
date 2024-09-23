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

int n,m;

int main()
{
	read(n), read(m);
	printf("%d\n",n + m);
	return 0;
}
