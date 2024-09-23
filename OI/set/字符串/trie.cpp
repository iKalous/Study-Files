#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar();
    for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

const int N = 1e5 + 5;

struct String{ char s[N]; int len; } S;
struct trie
{
    int nxt[N][30],cnt = 0;
    bool fg[N];
    void insert(String a)
    {
        int x = 0;
        for(int i = 1,c;i <= a.len; ++ i)
            c = a.s[i] - 'a', nxt[x][c] = (!nxt[x][c]) ? ++cnt : nxt[x][c],
            x = nxt[x][c];
        fg[x] = 1;
    }
    int find(String a)
    {
        int x = 0;
        for(int i = 1,c;i <= a.len; ++ i)
        {
            c = a.s[i] - 'a';
            if(!nxt[x][c]) return 0;
            x = nxt[x][c];
        }
        return fg[x];
    }
} Trie; 

void Read(String &a)
{
    a.len = 0; char ch = getchar();
    for(;ch < 'a' || ch > 'z';ch = getchar());
    for(;ch >= 'a' && ch <= 'z';ch = getchar()) a.s[ ++a.len] = ch;
}

int n,m;

int main()
{
    freopen("trie.in","r",stdin); 
    freopen("trie.out","w",stdout);

    read(n);
    for(int i = 1;i <= n; ++ i)
        Read(S), Trie.insert(S);
    
    read(m);
    for(int i = 1;i <= m; ++ i)
        Read(S), Trie.find(S) ? printf("YES\n") : printf("NO\n");

    fclose(stdin); fclose(stdout);
    return 0;
}