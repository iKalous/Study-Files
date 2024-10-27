#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

const int N = 1010;
const ll P = 202220222022;

int n;
ll inv[N],s[N],ans = 0,fg = 1ll;

ll fpow(ll a,ll x) { ll ans = 1; a = (a + P) % P; for(;x;x >>= 1) 
    ans = (x & 1) ? (ans * a) % P : ans, a = a * a % P; return ans; }

ll C(int a,int b) { return (s[a] * inv[b] % P * inv[a - b] % P + P) % P; }

int main()
{
    freopen("P06.in","r",stdin); 
    freopen("P6.out","w",stdout);

    s[0] = 1ll;
    for(int i = 1;i <= 1005; ++ i)
        s[i] = s[i - 1] * 1ll * i % P;
    inv[1005] = fpow(s[1005],P - 2);
    for(int i = 1005;i; -- i)
        inv[i - 1] = inv[i] * 1ll * i % P;
    
    printf("%lld\n",fpow(2,10));
    read(n), n += 3;
    for(int i = 12 * n;i <= 20 * n; ++ i)
    {
        ans = (ans + C(20 * n,i) + P) % P, fg = 1ll;
        for(int j = 1;j <= n && j * 20 <= i; ++ j)
            fg = fg * -1, ans = (ans + (C(n,j) * C((n - j) * 20,i - (j * 20)) % P) * fg + P) % P;
    }
    
    printf("%lld\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}