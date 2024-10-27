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

const int P = 70921;
const int N = 1e5 + 5;

int f(int x) { return (x % P + P) % P; }

struct hash_map
{ 
    int last[N],cnt = 0;
    struct node{ int nxt,key,tot; } a[N];
    void insert(int x)
    {
        int fg = 1;
        for(int p = last[f(x)];p;p = a[p].nxt)
            if(a[p].key == x) { ++a[p].tot, fg = 0; break; }
        if(fg) a[++cnt] = (node){ last[f(x)],x,1 }, last[f(x)] = cnt;
    }
} hash;

int n,k,a[N],tot = 0,stack[N],tot_e;
bool map[N];

struct element{ int key,cnt; } e[N];
bool operator < (element a,element b) { return a.cnt > b.cnt; }

int main()
{
    freopen("P27.in","r",stdin); 
    freopen("P27.out","w",stdout);

    read(n), read(k);
    for(int i = 1;i <= n; ++ i)
    {
        read(a[i]), hash.insert(a[i]);
        if(!map[f(a[i])]) map[f(a[i])] = 1, stack[++tot] = f(a[i]);
    }
    
    for(int i = 1;i <= tot; ++ i)
        for(int p = hash.last[stack[i]];p;p = hash.a[p].nxt)
            e[++tot_e] = (element){ hash.a[p].key,hash.a[p].tot };

    sort(e + 1,e + 1 + tot_e);

    for(int i = 1;i <= k; ++ i)
        printf("%d ",e[i].key);

    fclose(stdin); fclose(stdout);
    return 0;
}