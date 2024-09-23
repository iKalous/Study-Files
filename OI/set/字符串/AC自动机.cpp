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

struct String{ char s[N]; int len; } S;

inline void Read(String &a)
{
    a.len = 0; char ch = getchar();
    for(;ch < 'a' || ch > 'z';ch = getchar());
    for(;ch >= 'a' && ch <= 'z';ch = getchar()) a.s[ ++a.len] = ch;
}

struct AC
{
    int cnt = 0,nxt[N][26],fail[N],tag[N];
    bool fg[N];

    inline void insert(String &a)
    {
        int x = 0;
        for(int i = 1,c;i <= a.len; ++ i)
            c = a.s[i] - 'a', nxt[x][c] = !nxt[x][c] ? ++cnt : nxt[x][c], x = nxt[x][c];
        ++tag[x], fg[x] = 1;
    }
    inline void build()
    {
        int t[N],st = 1,ed = 0;
        for(int i = 0;i < 26; ++ i) nxt[0][i] ? t[++ed] = nxt[0][i] : 1;

        for(int x;st <= ed; ++ st)
        {
            x = t[st];
            for(int i = 0;i < 26; ++ i)
                (nxt[x][i]) ? (fail[nxt[x][i]] = nxt[fail[x]][i], t[++ed] = nxt[x][i]) : (nxt[x][i] = nxt[fail[x]][i]);
        }
    }
    inline int query(String a)
    {
        int x = 0,ans = 0;
        for(int i = 1;i <= a.len; ++ i)
        {
            x = nxt[x][a.s[i] - 'a'];
            for(int j = x;j && tag[j] != -1;j = fail[j])
                ans += tag[j], tag[j] = -1;
        }
        return ans;
    }

} ac;

int n;

int main()
{
    freopen("AC.in","r",stdin); 
    freopen("AC.out","w",stdout);

    read(n);
    for(int i = 1;i <= n; ++ i)
        Read(S), ac.insert(S);
    
    Read(S), ac.build();
    
    printf("%d\n",ac.query(S));
    fclose(stdin); fclose(stdout);
    return 0;
}