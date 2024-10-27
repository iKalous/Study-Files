#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void end(){ printf("0\n"); fclose(stdin); fclose(stdout); exit(0); }

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

#define ll long long

const int N = 1e5 + 5;
const ll P = 1e9 + 7;

ll ans = 1,s[N],cur;
int n,w,a[N],last[N],cnt = 0,fg = 0,mx = 0;
struct node{ int sz,nxt; } g[N];

void pre()
{
    s[0] = 1ll;
    for(int i = 1;i <= N - 5; ++ i)
        s[i] = s[i - 1] * 2ll, s[i] %= P;
}

int main()
{
    freopen("P75.in","r",stdin); 
    freopen("P75.out","w",stdout);

    pre(); read(n), read(w);
    for(int i = 1;i <= n; ++ i)
    {
        read(a[i]), a[i] = w - a[i];
        if(a[i] < 0) end();
    }
    
    for(int i = 1,j;i <= n; ++ i)
        if(a[i] != 0)
        {
            for(int k = 1;k <= mx; ++ k) last[k] = 0;
            int pre = 1; cnt = 0, cur = 1ll, fg = 1;
            if(a[i] != 1) end();
            
            for(j = i;j <= n && a[j] > 0; ++ j)
            {
                int sz = 0; mx = max(mx,a[j]);
                for(;a[j] == pre && j <= n; ++ j) ++ sz;
                -- j;
                if(abs(a[j + 1] - pre) > 1) end();
                g[++cnt] = (node){ sz,last[pre] }, last[pre] = cnt, pre = a[j + 1];
            } --j;
            
            for(int k = 1;k <= n; ++ k)
            {
                if(!last[k]) break;
                for(int p = last[k];p;p = g[p].nxt)
                    cur = cur * 1ll * s[g[p].sz - 1], cur = (cur % P + P) % P;
            }

            i = j, ans *= cur, ans = (ans % P + P) % P;
            if(a[j] != 1) end();
        }
    if(!fg) ans = 0ll;

    printf("%lld\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}