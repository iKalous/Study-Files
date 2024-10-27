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

const int N = 1e6 + 5;

int n,a[N],s1[N],s2[N],l[N],r[N],ans = -2147483647;

int main()
{
    freopen("P39.in","r",stdin); 
    freopen("P39.out","w",stdout);

    read(n);
    for(int i = 1;i <= n; ++ i)
        read(a[i]);

    int mn = 0;
    for(int i = n;i; -- i)
        s1[i] = s1[i + 1] + a[i], l[i] = s1[i] - mn, mn = min(mn,s1[i]);
    for(int i = n - 1;i; -- i) l[i] = max(l[i],l[i + 1]);

    mn = 0;
    for(int i = 1;i <= n; ++ i)
        s2[i] = s2[i - 1] + a[i], r[i] = s2[i] - mn, mn = min(mn,s2[i]);
    for(int i = 2;i <= n; ++ i) r[i] = max(r[i],r[i - 1]);

    for(int i = 1;i <= n; ++ i)
        ans = max(ans,r[i - 1] + l[i]);

    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}