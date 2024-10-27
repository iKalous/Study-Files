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

const int N = 15;

int n,m,sum[(N * N >> 1) + 5],a[N];
int map[N][N],tag[(N * N >> 1) + 5];

void dfs(int x,int num)
{
    if(tag[x]) dfs(x + 1,num);
    if(x == m + 1)
        {
            for(int i = 1;i <= n; ++ i)
                for(int j = i + 1;j <= n; ++ j)
                    if(!map[i][j]) return;
            for(int i = 1;i <= n; ++ i) printf("%d ",a[i]);
            exit(0);
        }
    for(int i = 1;i < num; ++ i)
        for(int j = i + 1;j < num; ++ j)
            if(!map[i][j] && a[i] + a[j] == sum[x])
                map[i][j] = 1, map[j][i] = 1, dfs(x + 1,num);
    for(int i = 1;i < num; ++ i)
        if(!map[i][num])
        {
            map[i][num] = 1, map[num][i] = 1, a[num] = sum[x] - a[i];
            if(a[num] < a[num - 1]) return;
            dfs(x + 1,num + 1);
        }
}

int main()
{
    //freopen("P02.in","r",stdin); 
    //freopen("P02.out","w",stdout);

    read(n), m = n * (n - 1) >> 1;
    for(int i = 1;i <= m; ++ i)
        read(sum[i]);
    
    sort(sum + 1,sum + 1 + m);

    if(n == 1) printf("%d\n",sum[1]);
    else if(n == 2) printf("%d %d\n",1,sum[1] - 1);
    else    
    {
        for(int i = 3;i <= m; ++ i)
            if(!(((sum[i] - (sum[2] - sum[1]))) % 2))
            {
                for(int i = 1;i <= n; ++ i)
                    for(int j = 1;j <= n; ++ j) map[i][j] = 0, a[i] = 0;
                a[2] = (sum[i] - (sum[2] - sum[1])) >> 1,
                a[3] = (sum[i] + (sum[2] - sum[1])) >> 1,
                a[1] = sum[1] - a[2];
                map[1][2] = 1, map[2][1] = 1;
                map[1][3] = 1, map[3][1] = 1;
                map[2][3] = 1, map[3][2] = 1;
                tag[i] = 1, dfs(3,4), tag[i] = 0;
            }
    } 

    puts("Impossible\n");

    //fclose(stdin); fclose(stdout);
    return 0;
}