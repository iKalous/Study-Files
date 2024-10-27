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

int n,m,mx[N],llim[N],rlim[N],ans;

int main()
{
    freopen("P99.in","r",stdin); 
    freopen("P99.out","w",stdout);

    read(n), read(m); --n;
    for(int i = 1,x;i <= m; ++ i)
        read(x), read(mx[x]);
    for(int i = 1;i <= n; ++ i)
        if(!mx[i]) mx[i] = n;
    
    int lim = n,x = n + 1;
    for(int i = n;i; -- i)
        if(mx[i] > lim + x - i) rlim[i] = lim + x - i;
        else lim = mx[i], x = i, rlim[i] = mx[i];

    lim = n,x = 0;
    for(int i = 1;i <= n; ++ i) mx[i] = min(mx[i],rlim[i]);

    for(int i = 1;i <= n; ++ i)
        if(mx[i] > lim + i - x) llim[i] = lim + i - x;
        else lim = mx[i], x = i, llim[x] = mx[i];

    for(int i = 1;i <= n; ++ i)
        ans = max(ans,min(i,llim[i]));
    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}