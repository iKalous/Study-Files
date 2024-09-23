#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template <class T>
inline void read(T &x)
{
    int fg = 1; char ch = getchar(); x = 0
    for(;ch < '0' || ch > '9';ch = getchar()) fg = ch == '-' ? -1 : 1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ '0'); x *= fg;
}
int main()
{
    freopen("D.in","r",stdin); 
    freopen(.out,w,stdout);


    fclose(stdin); fclose(stdout);
    return 0;
}