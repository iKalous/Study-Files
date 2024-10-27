#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

const int N = 1e2 + 5;

int s[N];
int n = 0;

int main()
{
    freopen("P04.in","r",stdin); 
    freopen("P04.out","w",stdout);

    char ch = getchar();
    for(;ch < 'A' || ch > 'Z';ch = getchar());
    for(;ch >= 'A' && ch <= 'Z';ch = getchar()) s[++n] = ch;

    sort(s + 1,s + 1 + n);

    for(int i = 1;i <= n; ++ i) printf("%c",s[i]);
    fclose(stdin); fclose(stdout);
    return 0;
}