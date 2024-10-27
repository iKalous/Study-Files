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

const int N = 5050;

#define ll long long

ll n,a,b,sum[N];
int ans = 0;

int main()
{
    //freopen("P02.in","r",stdin); 
    //freopen("P02.out","w",stdout);

    sum[1] = 1;
    for(int i = 1;i <= 5000; ++ i)
        sum[i] = sum[i - 1] + i * 1ll;
    read(a), read(b), n = abs(a - b);
    
    for(int i = 1;i <= n; ++ i)
        if(sum[i] + sum[i - 1] == n) { ans = i + i - 1; break; }
        else if(sum[i] + sum[i - 1] < n && 2 * sum[i] >= n) { ans = 2 * i; break; }
        else if(2 * sum[i] < n && 2 * sum[i] + i >= n) { ans = 2 * i + 1; break; }
    
    printf("%d\n",ans);
    //fclose(stdin); fclose(stdout);
    return 0;
}