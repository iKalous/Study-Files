#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tag = 0;

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

const int N = 1e6 + 5;

int n,a[N];

int main()
{
    freopen("P32.in","r",stdin); 
    freopen("P32.out","w",stdout);

    for(;!tag;)
        if(!tag) ++n, read(a[n]);
    
    --n, sort(a + 1,a + 1 + n);
    
    printf("\"");
    for(int i = 1;i <= n; ++ i)
        if(a[i + 1] - a[i] == 1 && a[i + 2] - a[i + 1] == 1)
        {
            printf("%d",a[i]); int t = 0;
            for(int j = i + 1;j <= n; ++ j)
                if(a[j + 1] - a[j] != 1) { t = j; break; }
            printf("-%d",a[t]); i = t;
            if(t != n) printf(",");
        }
        else
        {
            printf("%d",a[i]);
            if(i != n) printf(",");
        }
    
    printf("\"");
    fclose(stdin); fclose(stdout);
    return 0;
}