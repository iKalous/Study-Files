#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

char ch[N],s[N];
int n = 0,m = 0,length = 0,tot = 0;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    char c = getchar();
    for(;c < 'a' || c > 'z';c = getchar());
    for(;c >= 'a' && c <= 'z';c = getchar()) ch[++n] = c;

    for(;c < 'a' || c > 'z';c = getchar());
    for(;c >= 'a' && c <= 'z';c = getchar()) s[++m] = c;

    for(int i = 1;i <= m - n + 1; ++ i)
    {
        int t = 0,fg = 1;
        for(int j = 1;j <= n; ++ j)
            if(ch[j] != s[i + j - 1]) { fg = 0,t = j - 1; break; }
        fg ? ++tot,length = n : length = max(length,t);
    }

    printf("%d\n%d\n",length,tot);
    fclose(stdin); fclose(stdout);
    return 0;
}