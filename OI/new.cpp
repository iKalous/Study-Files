#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <class T>
void read(T &x)
{
	int fg = 1; x = 0; char ch = getchar();
	for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
	for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

ll n;

int main()
{
	read(n);
	printf("%lld\n",n);
	return 0;
}
