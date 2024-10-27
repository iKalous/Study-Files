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

const int N = 1e5 + 5;
const int P = 1e9 + 7;

int n,a[N],A,B,sum,f[N][10];
long long ans = 0;

int main()
{
    //freopen("P35.in","r",stdin); 
    //freopen("P35.out","w",stdout);

    read(n), read(A), read(B);
    for(int i = 1;i <= n; ++ i)
        read(a[i]), a[i] %= 10, sum = (sum + a[i]) % 10;
    
    if((sum + 10 - A) % 10 != B)
    {
        if(sum == A) ++ ans;
        if(sum == B) ++ ans;
        printf("%lld\n",ans); 
        return 0;
    }

    for(int i = 1;i <= n; ++ i)
    {
        ++f[i][a[i]];
        for(int j = 0;j < 10; ++ j)
            f[i][j] += f[i - 1][j] + f[i - 1][(j + 10 - a[i]) % 10],
            f[i][j] %= P;
    }

    ans = f[n][A];
    printf("%lld\n",ans);
    //fclose(stdin); fclose(stdout);
    return 0;
}