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

#define ll long long

const int P = 70921;
const int N = 1e5 + 5;

int f(int x){ return (x % P + P) % P; }

struct hash_map
{ 
    int last[N],cnt = 0,stk[N],tot = 0;
    struct node{ int nxt,key,tot; } a[N];
    void insert(int x)
    {
        int fg = 1;
        for(int p = last[f(x)];p;p = a[p].nxt)
            if(a[p].key == x) { ++a[p].tot, fg = 0; break; }
        if(fg) a[++cnt] = (node){ last[f(x)],x,1 }, last[f(x)] = cnt, stk[++tot] = f(x);
    }
    ll get(int x)
    {
        for(int p = last[f(x)];p;p = a[p].nxt)
            if(a[p].key == x) return 1ll * a[p].tot;
        return 0ll;
    }
} hash[2];

const int M = 30;

int n,m,Max;
ll S,a[M],s[M],ans = 0;

void preparation()
{
    s[1] = 1, Max = 1; 
    for(int i = 2;i <= 19; ++ i)
        s[i] = s[i - 1] * i, Max = s[i] <= S ? i : Max;
}

void dfs(int x,int lim,int fg,ll sum,int t)
{
    if(sum > S || t > m) return;
    if(x > lim)
        { hash[fg].insert(sum); return; }
    
    dfs(x + 1,lim,fg,sum,t),
    dfs(x + 1,lim,fg,sum + a[x],t);
    if(a[x] <= Max) dfs(x + 1,lim,fg,sum + s[a[x]],t + 1);
    return;
}

int main()
{
    freopen("P23.in","r",stdin); 
    freopen("P23.out","w",stdout);

    read(n), read(m), read(S);
    for(int i = 1;i <= n; ++ i) read(a[i]);

    preparation();

    dfs(1,n / 2,0,0,0), dfs(n / 2 + 1,n,1,0,0);

    for(int i = 1;i <= hash[0].tot; ++ i)
        for(int p = hash[0].last[hash[0].stk[i]];p;p = hash[0].a[p].nxt)
            if(hash[0].a[p].key <= S) ans += 1ll * hash[0].a[p].tot * hash[1].get(S - hash[0].a[p].key);

    printf("%lld\n",ans);

    fclose(stdin); fclose(stdout);
    return 0;
}