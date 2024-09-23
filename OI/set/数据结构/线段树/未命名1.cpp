#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg; //printf("%d\n",x);
}

const int N = 1e6 + 5;

int n,m,a[N];

struct num{ int ls,rs,sum,tag,l,r; };
struct SGT
{
    num t[N];
    int cnt = 1,rt = 1;
    
    #define ls(x) t[x].ls
    #define rs(x) t[x].rs
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define tag(x) t[x].tag
    #define sum(x) t[x].sum

    inline void update(int x)
    {
        if(!tag(x)) return;
        tag(ls(x)) += tag(x), tag(rs(x)) += tag(x);
        sum(ls(x)) += tag(x) * (r(ls(x)) - l(ls(x)) + 1);
        sum(rs(x)) += tag(x) * (r(rs(x)) - l(rs(x)) + 1);
        tag(x) = 0;
    }

    inline void build(int x,int l,int r)
    {
        if(l == r) { t[x] = (num){ 0,0,a[l],0,l,r }; return; }
        int mid = (l + r) >> 1;
        ls(x) = ++ cnt, rs(x) = ++cnt, l(x) = l, r(x) = r;
        build(ls(x),l,mid), build(rs(x),mid + 1,r);
        sum(x) = sum(ls(x)) + sum(rs(x));
    }
    inline void insert(int x,int l,int r,int k)
    {
        if(l <= l(x) && r(x) <= r) 
            { tag(x) += k; sum(x) += (r(x) - l(x) + 1) * k; return; }
        update(x);
        int mid = (l(x) + r(x)) >> 1;
		if(l <= mid) insert(ls(x),l,r,k);
        if(r > mid) insert(rs(x),l,r,k);
        sum(x) = sum(ls(x)) + sum(rs(x));
    }
    inline ll query(int x,int l,int r)
    {
        if(l(x) >= l && r(x) <= r) return sum(x);
        update(x);
        int mid = (l(x) + r(x)) >> 1; ll ans = 0;
        if(l <= mid) ans += query(ls(x),l,r);
		if(r > mid) ans += query(rs(x),l,r);
        return ans;
    }

} sgt;

int main()
{
    freopen("sgt1.in","r",stdin); 
    freopen("sgt1.out","w",stdout);

    read(n), read(m);
    for(int i = 1;i <= n; ++ i) read(a[i]);

    sgt.build(1,1,n);
    for(int i = 1,fg,L,R,k;i <= m; ++ i)
    	read(fg), read(L), read(R),
		fg == 1 ? (read(k), sgt.insert(1,L,R,k),1) : (printf("%lld\n",sgt.query(1,L,R)),1);

    fclose(stdin); fclose(stdout);
    return 0;
}
