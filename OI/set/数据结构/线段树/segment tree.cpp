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
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg; //printf("%d\n",x);
}

const int N = 1e6 + 5;

int n,m,a[N];
ll p;

struct num{ int ls,rs,l,r; ll tag_add,sum,tag_mul; };
struct SGT
{
    num t[N];
    int cnt = 1,rt = 1;

    #define ls(x) t[x].ls
    #define rs(x) t[x].rs
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define tag_add(x) t[x].tag_add
    #define tag_mul(x) t[x].tag_mul
    #define sum(x) t[x].sum

    /*inline void update(int x)
    {
        /*if(!tag(x)) return;
        tag(ls(x)) += tag(x), tag(rs(x)) += tag(x);
        sum(ls(x)) += tag(x) * (r(ls(x)) - l(ls(x)) + 1);
        sum(rs(x)) += tag(x) * (r(rs(x)) - l(rs(x)) + 1);
        tag_add(x) = 0; 

    } */

    inline void update(int x) { sum(x) = (sum(ls(x)) + sum(rs(x))) % p; }
    inline void pushdown(int x)
    {
        sum(ls(x)) = (sum(ls(x)) * tag_mul(ls(x)) % p + (r(ls(x)) - l(ls(x)) + 1) % p * tag_add(ls(x)) % p) % p;
        sum(rs(x)) = (sum(rs(x)) * tag_mul(rs(x)) % p + (r(rs(x)) - l(rs(x)) + 1) % p * tag_add(rs(x)) % p) % p;

        tag_mul(ls(x)) *= tag_mul(x), tag_mul(rs(x)) *= tag_mul(x);
        tag_add(ls(x)) = (tag_mul(x) * tag_add(ls(x)) % p + tag_add(x)) % p;
        tag_add(rs(x)) = (tag_mul(x) * tag_add(rs(x)) % p + tag_add(x)) % p;

        tag_add(x) = 0, tag_mul(x) = 1;

    }
    inline void build(int x,int l,int r)
    {
        if(l == r) { t[x] = (num){ 0,0,l,r,0,a[l],1 }; return; }
        int mid = (l + r) >> 1;
        ls(x) = ++ cnt, rs(x) = ++cnt, l(x) = l, r(x) = r;
        tag_add(x) = 0, tag_mul(x) = 1;
        build(ls(x),l,mid), build(rs(x),mid + 1,r), update(x);
    }
    inline void add(int x,int l,int r,int k)
    {
        if(l <= l(x) && r(x) <= r) 
        {
            tag_add(x) += (ll)k; sum(x) += (ll)(r(x) - l(x) + 1ll) * k;
            tag_add(x) %= p, sum(x) %= p;
            return;
        }
        pushdown(x);
        int mid = (l(x) + r(x)) >> 1;
		if(l <= mid) add(ls(x),l,r,k);
        if(r > mid) add(rs(x),l,r,k);
        update(x);
    }
    inline void multiple(int x,int l,int r,int k)
    {  
        if(l <= l(x) && r(x) <= r)
        {
            tag_add(x) *= (ll)k, tag_mul(x) *= (ll)k, sum(x) *= (ll)k;
            tag_add(x) %= p, tag_mul(x) %= p, sum(x) %= p;
            return;
        }
        pushdown(x);
        int mid = (l(x) + r(x)) >> 1;
        if(l <= mid) multiple(ls(x),l,r,k);
        if(r > mid) multiple(rs(x),l,r,k);
        update(x);
    }
    inline ll query(int x,int l,int r)
    {
        if(l(x) >= l && r(x) <= r) return sum(x);
        pushdown(x);
        int mid = (l(x) + r(x)) >> 1; ll ans = 0;
        if(l <= mid) ans += query(ls(x),l,r), ans %= p;
		if(r > mid) ans += query(rs(x),l,r), ans %= p;
        return ans;
    }

} sgt;

int main()
{
    freopen("sgt2.in","r",stdin); 
    freopen("sgt2.out","w",stdout);

    read(n), read(m), read(p);
    for(int i = 1;i <= n; ++ i) read(a[i]), a[i] %= (int)p;

    sgt.build(1,1,n);
    for(int i = 1,fg,L,R,k;i <= m; ++ i)
    	read(fg), read(L), read(R),
		fg == 1 ? (read(k), sgt.add(1,L,R,k),1) : (printf("%lld\n",sgt.query(1,L,R)),1);

    fclose(stdin); fclose(stdout);
    return 0;
}