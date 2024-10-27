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

const int N = 110;

#define ll long long
const ll P = 998244353;

struct String
{ 
    char s[N]; int len;
    void clear()
    {
        for(int i = 1;i <= len; ++ i) s[i] = '#';
        len = 0;
    }
} s,s1;

inline void Read(String &a)
{
    a.len = 0; char ch = getchar();
    for(;ch < 'A' || ch > 'Z';ch = getchar());
    for(;ch >= 'A' && ch <= 'Z';ch = getchar()) a.s[ ++a.len] = ch;
}

int n,map[N][N],m,fg,stk[N],cnt;
ll s[N],stk1[N],stk2[N],cnt1,cnt2;

void dfs(int pre,int x,int st1,int st2)
{
    ll now = 0;
    if(st1 > cnt1 && st2 > cnt2 && x > s1.len)
    {
        for(int i = 1;i <= cnt2; ++ i)
            for(int j = i + 1;j <= cnt2; ++ j)
                if(stk2[i] != stk2[j] && map[i][j]) return;
        fg = 1;
    }

    if(st1 > cnt1 && st2 < cnt2) return;
    if(st1 > cnt1 && st2 == cnt2)
    {
        for(int i = x;i <= s1.len; ++ i)
            now = (now * 27ll % P + (s1.s[i] - 'a') + P) % P;
    }

    if(x == 1 && stk1[st1] == 0) dfs(1,1,2,1);
    for(int i = x;i <= n; ++ i)
    {
        int tag = i;
        for(int j = i;j <= n; ++ j)
        {
            now = (now * 27ll % P + (s1.s[i] - 'a') + P) % P;
            if(now == stk1[st1]) { tag = j + 1; break; }
        }
        if(tag == i) return;
        now = 0;
        for(int j = x;j < i; ++ j)
            now = (now * 27ll % P + (s1.s[i] - 'a') + P) % P;
        stk2[st2 + 1] = now;
        dfs(x,tag,st1 + 1,st2 + 1);
    }
}

int main()
{
    freopen("P25.in","r",stdin); 
    freopen("P25.out","w",stdout);

/*    s[0] = 1ll;1
    for(int i = 1;i <= 100; ++ i)
        s[i] = (s[i - 1] * 27ll % P + P) % P;
*/
    read(n); Read(s); ll now = 0;
    for(int i = 1;i <= s.len; ++ i)
    {
        if(s.s[i] == '{')
        {
            stk1[++cnt1] = now, now = 0;
            for(;s.s[i] != '}'; ++ i)
                now = (now * 27ll % P + (s.s[i] - 'a') + P) % P;
            stk2[++cnt2] = now; now = 0;
        }
    }
    if(now != 0) stk1[++cnt1] = now;

    for(int i = 1;i <= cnt2; ++ i)
        for(int j = i + 1;j <= cnt2; ++ j)
            if(stk2[i] == stk2[j]) map[i][j] = 1;

    memset(stk2,0,sizeof(stk2)), cnt2 = 0;
    for(;n; --n)
    {
        Read(s1); fg = 0;
        memset(stk2,0,sizeof(stk2)), cnt2 = 0;
        dfs(1,1,1,1);
        s1.clear();
        fg == 1 ? printf("True\n") : printf("False\n");
    }
    
    fclose(stdin); fclose(stdout);
    return 0;
}