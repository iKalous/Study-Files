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

const int N = 1e6 + 5;

int a[N],b[N],n,ans;
int q1[N],q2[N],s1 = 1,e1 = 0,s2 = 1,e2 = 0;

int main()
{
    freopen("P86.in","r",stdin); 
    freopen("P86.out","w",stdout);

    char ch = getchar();
    for(;ch >= '0' && ch <= '1';ch = getchar()) a[++n] = ch ^ '0';
    for(;ch < '0' || ch > '1';ch = getchar());
    for(int i = 1;i <= n; ++ i)
    {
        b[i] = ch ^ '0', ch = getchar();
        if(a[i] == 0 && b[i] == 1) b[i] = 1;
        else if(a[i] == 1 && b[i] == 0) b[i] = 2;
        else b[i] = 0;
    }

    for(int i = 1;i <= n; ++ i)
        if(b[i] == 1)
        {
            for(;s2 <= e2 && i - q2[s2] > 3; ++ s2, ans += 2);
            if(s2 <= e2) ans += i - q2[e2], --e2;
            else q1[++e1] = i;
        }
        else if(b[i] == 2)
        {
            for(;s1 <= e1 && i - q1[s1] > 3; ++ s1, ans += 2);
            if(s1 <= e1) ans += i - q1[e1], --e1;
            else q2[++e2] = i;
        }

    printf("%d\n",ans + (e2 - s2 + e1 - s1 + 2) * 2);
    fclose(stdin); fclose(stdout);
    return 0;
}