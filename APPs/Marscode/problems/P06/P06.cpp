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

const int N = 1e3 + 5;
const long long P = 202220222022;

int n;
long long c[25][25],ans,Ans = 1ll;

int main()
{
    freopen("P06.in","r",stdin); 
    freopen("P06.out","w",stdout);

    read(n), n += 3;
    c[1][1] = 1ll, c[0][1] = 1ll;
    for(int i = 2;i <= 20; ++ i)
        for(int j = 1;j <= i; ++ j)
            c[i][j] = ((c[i - 1][j] + c[i - 1][j - 1]) % P + P) % P;
    
    for(int i = 12;i <= 20; ++ i)
        ans = ((ans + c[20][i]) % P + P) % P;
    
    ans = (ans + P) % P;
    for(int i = 1;i <= n; ++ i)
        Ans = ((Ans * ans) % P + P) % P;

    Ans = (Ans + P) % P;
    printf("%lld\n",Ans);
    fclose(stdin); fclose(stdout);
    return 0;
}