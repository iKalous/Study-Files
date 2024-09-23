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


int main()
{
    freopen("boat.in","w",stdout);

    int m; m = rand() % 29;
    
    printf("7 %d\n",m);

    for(int i = 1;i <= m; ++ i)
    {
        int x,y; x = rand() % 8, y = rand() % 8;
        while(x == 0) x = rand() % 8;
        while(y == x) y = rand() % 8;
        printf("%d %d\n",x,y);
        
    }

    fclose(stdout);
    return 0;
}