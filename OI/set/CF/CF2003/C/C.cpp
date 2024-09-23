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

const int N = 2e5 + 5;

struct String { char s[N]; int len; } s;
int stk[30],T,tot;
char ans[N];

inline void Read(String &a)
{
    a.len = 0; char ch = getchar();
    for(;ch < 'a' || ch > 'z';ch = getchar());
    for(;ch >= 'a' && ch <= 'z';ch = getchar()) a.s[ ++a.len] = ch, ++ stk[a.s[a.len] - 'a'];
}

int main()
{
    freopen("C.in","r",stdin); 
    freopen("C.out","w",stdout);

    read(T);
    for(;T; -- T,tot = 0)
    {
        read(s.len), Read(s);
        for(int i = 1;i <= s.len; ++ i)
            for(int j = 0;j < 26; ++ j)
                if(stk[j]) --stk[j], ans[++tot] = 'a' + j;


        for(int i = 1;i <= s.len; ++ i) putchar(ans[i]);
        putchar('\n');
        for(int i = 0;i < 26; ++ i) stk[i] = 0;
    }

    fclose(stdin); fclose(stdout);
    return 0;
}