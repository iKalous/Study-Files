#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tag = 0;

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar()) 
    {
        fg = ch == '-' ? -1 : 1;
        if(ch == EOF) { tag = 1; return; } 
    }
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

const int N = 1e6 + 5;

struct node{ int st,ed; } a[N];
int n,ans,st = -(1e9 + 7),ed = -(1e9 + 7),fg = 0;

bool operator <(node a,node b) { return a.st < b.st || (a.st == b.st && a.ed >= b.ed); }

int main()
{
    freopen("P28.in","r",stdin); 
    freopen("P28.out","w",stdout);

    for(;!tag;)
        !tag ? (++n, read(a[n].st), read(a[n].ed),1) : 1;

    --n;
    sort(a + 1,a + 1 + n);
    
    for(int i = 1;i <= n; ++ i)
    {
        if(a[i].st > ed)
        {
            if(i != 1) ans += ed - st + 1;
            printf("%d %d %d\n",st,ed,ans);
            st = a[i].st, ed = a[i].ed;
        }
        else fg = 1, ed = max(ed,a[i].ed);
    }

    ans += ed - st + 1;
    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}