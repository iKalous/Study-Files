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
const int S = 1e4 + 5;
const int Max = 998244353;

struct node{ int a,b; }a[N];
int n,s,f[S][N],map[S],ans = Max;

bool operator < (node a,node b)
    { return a.a < b.a || (a.a == b.a && a.b < b.b); }

void end(){ printf("Impossible\n"); exit(0); }

void dfs(int x,int pre,int now,int tot)
{
    if(x == n + 2) { ans = min(ans,tot); return; }
    int j = x + 1,k = Max,dd = 0;
    for(int i = 0;i <= now && j <= n + 2; ++ i)
        for(;a[x].a + i >= a[j].a && j <= n + 2; ++ j) 
            if(a[j].b <= k) k = a[j].b, dd = j;

    if(k <= a[x].b)
        dfs(dd,a[dd].a,now - (a[dd].a - pre),tot + (a[dd].a - pre) * a[x].b);
    else 
    {
        int j = x + 1,k = Max,dd = 0,ii;
        int mx = x == 1 ? 200 : 400;
        for(int i = 0;i <= mx && j <= n + 2; ++ i)
            for(;a[x].a + i >= a[j].a && j <= n + 2; ++ j) 
                if(a[j].b <= k) k = a[j].b, dd = j, ii = i;
                
        if(k <= a[x].b)
            dfs(dd,a[dd].a,0,tot + (a[dd].a - now - a[x].a) * a[x].b);
        else
            dfs(dd,a[dd].a,mx - (a[dd].a - a[x].a),tot + (400 - now) * a[x].b);
    }
}

int main()
{
    freopen("P01.in","r",stdin); 
    freopen("P01.out","w",stdout);

    read(s), read(n);
    for(int i = 1;i <= n; ++ i)
        read(a[i].a), read(a[i].b), a[i].a = s - a[i].a;
    
    a[n + 1] = (node){ 0,0 }; a[n + 2] = (node){ s + 200,0 };
    sort(a + 1,a + 1 + n + 1); a[0].b = Max;
    dfs(0,0,200,0);

    if(ans == Max) end();
    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}

