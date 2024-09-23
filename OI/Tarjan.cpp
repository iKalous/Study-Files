#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template < class T >
inline void read(T &x)
{
	char ch = getchar(); x = 0; int fg = 1;
	for(;ch < '0' || ch > '9';) fg = ch == '-' ? -1 : 1, ch = getchar();
	for(;ch >= '0' && ch <= '9';) x = x * 10 + (ch ^ '0'), ch = getchar(); x *= fg;
}

const int N = 100010;

struct Edge{ int to,nxt; } g[N << 1];
int n,m,ans,dfn[N],low[N],tot,fa[N],l,r;
int stk[N],q[N],last[N],cnt = 0,dep[N],f[N];

void add(int u,int v) { g[++cnt] = (Edge){ v,last[u] }, last[u] = cnt; }

void ring(int rt,int x)
{
	int t = dep[x] - dep[rt] + 1; r = t;
	for(int i = x;i != rt;i = fa[i])
		stk[r--] = f[i]; stk[r] = f[rt];
	for(int i = 1;i <= t; ++ i) stk[i + t] = stk[i];
	q[l = r = 0] = 1;
	for(int i = 2;i <= 2 * t; ++ i)
	{
		while(l <= r && i - q[l] > t / 2) ++ l;
		ans = max(ans,stk[i] + i + stk[q[l]] - q[l]);
		while(l <= r && stk[q[r]] - q[r] < stk[i] - i) -- r;
		q[++r] = i;
	}
	for(int i = 2;i <= t; ++ i)
		f[rt] = max(f[rt],stk[i] + min(i - 1,t - i + 1));
}

void tarjan(int x)
{
	dfn[x] = low[x] = ++tot;
	for(int i = last[x];i;i = g[i].nxt) if(g[i].to != fa[x])
	{
		if(!dfn[g[i].to]) fa[g[i].to] = x, dep[g[i].to] = dep[x] + 1, 
		tarjan(g[i].to), low[x] = min(low[x],low[g[i].to]);
		else low[x] = min(low[x],dfn[g[i].to]);
		if(dfn[x] < low[g[i].to])
			ans = max(ans,f[x] + f[g[i].to] + 1), f[x] = max(f[x],f[g[i].to] + 1);
	}
	for(int i = last[x];i;i = g[i].nxt)
		if(fa[g[i].to] != x && dfn[x] < dfn[g[i].to]) ring(x,g[i].to);
}

int main()
{
	read(n), read(m);
	for(int i = 1,k,u,v;i <= m; ++ i)
	{
		read(k), read(u);
		for(int j = 2;j <= k; ++ j)
			read(v), add(u,v), add(v,u), u = v;
	}
	tarjan(1), printf("%d\n",ans);
	return 0;
}
