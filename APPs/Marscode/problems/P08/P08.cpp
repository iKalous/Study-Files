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

const int N = 2e2 + 5;

struct math 
{ 
    int a[N],num = 0; 
    math operator = (int x)
    {
      num = 0;
      for(;x;x /= 10) a[++num] = x % 10;
    }
    math operator = (math x)
    {
        num = x.num;
        for(int i = 1;i <= x.num; ++ i) a[i] = x.a[i];
    }
    math operator * (int x)
    {
        math c; c.num = num + 1;
        memset(c.a,0,sizeof(c.a));
        for(int i = 1;i <= num; ++ i)
            c.a[i] += a[i] * x, c.a[i + 1] += c.a[i] / 10, c.a[i] %= 10;
        for(;!c.a[c.num]; -- c.num);
        return c;
    }
    math operator + (math b)
    {
        math c; c.num = max(num,b.num + 1);
        memset(c.a,0,sizeof(c.a));
        for(int i = 1;i <= c.num; ++ i)
            c.a[i] += a[i] + b.a[i], c.a[i + 1] += c.a[i] / 10, c.a[i] %= 10;
        for(;!c.a[c.num]; -- c.num);
        return c; 
    }
} s[N >> 1],ans;

int a[N],b[N],a1,b1,c[N],c1;

int main()
{
    freopen("P08.in","r",stdin); 
    freopen("P08.out","w",stdout);

    s[1] = 1;
    for(int i = 2;i <= 100; ++ i)
        s[i] = s[i - 1] * 2;

    char ch = getchar();
    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar()) a[++a1] = ch - '0';

    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar()) b[++b1] = ch - '0';

    for(int i = 1;i <= a1; ++ i)
        c[a1 - i + 1] = a[i];
    for(int i = 1;i <= a1; ++ i) a[i] = c[i];
    for(int i = 1;i <= b1; ++ i)
        c[b1 - i + 1] = b[i];
    for(int i = 1;i <= b1; ++ i) b[i] = c[i];

    memset(c,0,sizeof(c)), c1 = max(a1,b1) + 1;
    for(int i = 1;i <= c1; ++ i)
        c[i] += a[i] + b[i], c[i + 1] += c[i] / 2, c[i] %= 2;
    for(;!c[c1]; -- c1);

    for(int i = 1;i <= c1; ++ i)
        if(c[i]) ans = ans + s[i];
    for(int i = ans.num;i; -- i)
        printf("%d",ans.a[i]);

    fclose(stdin); fclose(stdout);
    return 0;
}