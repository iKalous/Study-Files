#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3e3 + 5;

int n,tag = 1,tot = 0,ans[N],tag1[N];

template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar()) 
    {
        fg = ch == '-' ? -1 : 1;
        if(ch == EOF) { tag = 1; return; } 
    }
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}

int main()
{
    freopen("P30.in","r",stdin); 
    freopen("test.out","w",stdout);

    do
    {
        read(n); char ch = getchar(); tot = 0;
        if(n == 0) break;
        for(;ch != '.' && ch != 'L' && ch != 'R';ch = getchar());
        for(int i = 1;i <= n; ++ i, ch = getchar())
        {
            if(ch == 'L') tag1[i] = 1;
            else if(ch == 'R') tag1[i] = -1;
        }

        int L = 0,R = 0;
        for(int i = 1;i <= n; ++ i,L = 0,R = 0) 
        {
            for(int j = i - 1;j; -- j)
                if(tag1[j] == 1) { L = 0; break; }
                else if(tag1[j] == -1) { L = j; break; }

            for(int j = i + 1;j <= n; ++ j)
                if(tag1[j] == -1) { R = 0; break; }
                else if(tag1[j] == 1) { R = j; break; }
			
			if(tag1[i] == 1) L = i;
			if(tag1[i] == -1) R = i;
            if((L == 0 && R == 0) || ((i - L) == (R - i) && L && R))  ans[++tot] = i;
        }

        printf("%d\n",tot);
        for(int i = 1;i <= tot; ++ i) printf("%d ",ans[i]);
        if(tot > 0) puts("");

        for(int i = 1;i <= n; ++ i) tag1[i] = 0;
    } while(tag);

    fclose(stdin); fclose(stdout);
    return 0;
}
