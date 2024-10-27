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


const int N = 10010;

bool num(char ch) { return (ch >= '0' && ch <= '9') ? 1 : 0; }
int opt(char ch)
{
    if(ch == '+') return 1;
    if(ch == '-') return -1;
    if(ch == '*') return 2;
    if(ch == '/') return 3;
}

int stk[N],st[N],st1[N];
int cnt,tot,tot1,fg = 0,ans;

int main()
{
    freopen("P05.in","r",stdin); 
    freopen("P05.out","w",stdout);

    st[cnt = 0] = 0; st1[0] = 1;
    for(char ch = getchar();ch != EOF;ch = getchar())
    {
        if(num(ch)) 
        {
            if(fg == 1) stk[tot] *= (ch - '0');
            if(fg == 2) stk[tot] /= (ch - '0');
            if(fg == 0) stk[++tot] = ch - '0';
            fg = 0;
        }
        if(ch == '(') st[++cnt] = tot;
        if(opt(ch) < 2) st1[++tot1] = opt(ch);
        if(ch == ')')
        {
            int cur = 0;
            for(;tot > st[cnt]; -- tot, -- tot1) 
                cur += st1[tot1] * stk[tot];
            stk[++tot] = cur; printf("%d\n",stk[tot]);
        }
        if(ch == '*') fg = 1;
        if(ch == '/') fg = 2;
    }

    ans = 0; printf("%d %d\n",stk[0],stk[1]);
    for(;tot; -- tot, -- tot1) 
            ans += st1[tot1] * stk[tot];
    
    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}