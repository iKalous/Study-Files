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

const int M = 45;

int buc[M];

int main()
{
    freopen("P38.in","r",stdin); 
    freopen("P38.out","w",stdout);

    for(int a;!tag;)
    {
        read(a);
        if(a) ++buc[a];
        else break;
    }

    for(int i = 1;i <= 40; ++ i)
        if(buc[i] % 5 != 0) { printf("false\n"); return 0; }

    printf("true\n");

    fclose(stdin); fclose(stdout);
    return 0;
}