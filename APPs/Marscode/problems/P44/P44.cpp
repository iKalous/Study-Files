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

const int N = 55;
const int M = 4e3 + 5;

int Q,V,f[M],g[M],ans;
int st,ed,que[M];

int main()
{
    freopen("P44.in","r",stdin); 
    freopen("P44.out","w",stdout);

    read(Q), read(V);
    for(int i = 1,m,v,w;i <= Q; ++ i)
    {
        read(m), read(v), read(w);
        memcpy(g,f,sizeof(f));
        for(int j = 0;j < v; ++ j)
        {
            st = 0, ed = -1;
            for(int k = j;k <= V;k += v)
            {
                if(st <= ed && que[st] < k - m * v) ++ st;
                if(st <= ed) f[k] = max(f[k],g[que[st]] + (k - que[st]) / v * w);
                for(;st <= ed && g[k] >= g[que[ed - 1]] + (k - que[ed - 1]) / v * w; -- ed);
                que[++ed] = k;
            }
        }
    }

    for(int i = 1;i <= V; ++ i)
        ans = max(ans,f[i]);

    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
} 