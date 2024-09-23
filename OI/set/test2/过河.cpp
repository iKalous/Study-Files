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

int map[N][N],n,m,dep[N][2];
int tag[N];

int stk[N],cnt = 0;


int dfs(int x)
{
    int tot = 1;
    for(int i = 1;i <= n; ++ i)
        if(!tag[i] && map[x][i])
        {
            tag[i] = 1, tot += dfs(i);
            if(dep[i][1] > dep[x][1]) dep[x][2] = dep[x][1], dep[x][1] = dep[i][1], dep[x][2] = max(dep[x][2],dep[i][2]);
            else dep[x][2] = max(dep[i][1],dep[x][2]);
        }
    ++ dep[x][1], ++ dep[x][2];
    return tot;
}

int main()
{
    freopen("boat.in","r",stdin); 
    freopen("boat.out","w",stdout);

    read(n), read(m);
    for(int i = 1,x,y;i <= m; ++ i)
        read(x), read(y), map[x][y] = 1, map[y][x] = 1;
    
    //for(int i = 1;i <= n; ++ i)
    //    for(int j = 1;j <= n; ++ j) map[i][j] = 1 - map[i][j];

    for(int i = 1;i <= n; ++ i)
        if(!tag[i]) 
        {
            tag[i] = 1, stk[++cnt] = dfs(i);
            if((stk[cnt] > 3 && dep[i][1] + dep[i][2] - 1 < 4) || stk[cnt] == 1) { printf("No\n"); return 0; } 
        }
    
    int fg = 0;
    for(int i = 1;i <= cnt; ++ i) if(stk[i] != 3) fg = 1;

    fg == 0 ? printf("No\n") : printf("Yes\n");

    fclose(stdin); fclose(stdout);
    return 0;
}