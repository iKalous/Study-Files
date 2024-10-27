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

const int N = 5e4 + 5;

int n,m;
long long a[N],b[N],k,ans = 2e18 + 7;

int main()
{
    freopen("P46.in","r",stdin); 
    freopen("P46.out","w",stdout);

    read(n), read(m), read(k);
    for(int i = 1;i <= n; ++ i) read(a[i]);
    for(int i = 1;i <= m; ++ i) read(b[i]);

    sort(a + 1,a + 1 + n), sort(b + 1,b + 1 + m);

    int eda = n,edb = m;
    for(;eda && edb;)
    {
        ans = min(ans,abs((a[eda] - b[edb]) * (a[eda] - b[edb]) - k * k));
        if(abs(abs(a[eda - 1] - b[edb]) - k) < abs(abs(a[eda] - b[edb - 1]) - k))
            -- eda; else --edb;
    }

    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}