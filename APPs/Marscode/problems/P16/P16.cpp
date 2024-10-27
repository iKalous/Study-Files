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

const int N = 5e2 + 5;
const int Max = 998244353;

struct String{ char s[N]; int len; } s1,s2;

inline void Read(String &a)
{
    a.len = 0; char ch = getchar();
    for(;ch < 'A' || ch > 'Z';ch = getchar());
    for(;ch >= 'A' && ch <= 'Z';ch = getchar()) a.s[ ++a.len] = ch;
}

int f[N][N];

int main()
{
    freopen("P16.in","r",stdin); 
    freopen("P16.out","w",stdout);

    Read(s1), Read(s2);

    for(int i = 0;i <= s1.len; ++ i)
        for(int j = 0;j <= s2.len; ++ j) f[i][j] = Max;

    for(int i = 0;i <= s1.len; ++ i) f[i][0] = i;
    for(int i = 0;i <= s2.len; ++ i) f[0][i] = i;

    for(int i = 1;i <= s1.len; ++ i)
        for(int j = 1;j <= s2.len; ++ j)
            if(s1.s[i] == s2.s[j]) 
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j],f[i][j - 1]) + 1,
                f[i][j] = min(f[i][j],f[i - 1][j - 1] + 1);

    printf("%d\n",f[s1.len][s2.len]);
    fclose(stdin); fclose(stdout);
    return 0;
}