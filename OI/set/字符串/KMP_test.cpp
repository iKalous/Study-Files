#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

void read(char *ch,int &len)
{
    char c = getchar(); len = 0;
    for(;c < 'a' || c > 'z';c = getchar());
    for(;c >= 'a' && c <= 'z';c = getchar()) ch[++ len] = c;
}

char s1[N],s2[N];
int len1,len2,next[N];

void get_next(char ch[],int a[],int len)
{
    int j = 1; a[1] = 0; a[0] = 0;
    for(int i = 2;i <= len; ++ i)
    {
        for(;j > 1 && ch[i] != ch[j];j = a[j - 1] + 1);
        if(ch[i] == ch[j]) ++ j;
        a[i] = j - 1;
    }
}

int find(char a[],char b[],int x1,int x2)
{
    int tot = 0;
    //for(int i = 1;i <= x1; ++ i) putchar(a[i]); printf("\n");
    for(int i = 1,j = 1;i <= x2; ++ i)
    {
        for(;j > 1 && a[i] != b[j]; j = next[j - 1] + 1);
        if(a[i] == b[j]) ++ j;
        if(j > x1) ++ tot, printf("%d\n",i - x1 + 1), j = next[j - 1] + 1;
    }
    return tot;
}

int main()
{
    freopen("kmp.in","r",stdin);
    freopen("kmp.out","w",stdout);

    read(s1,len1), read(s2,len2);
    //printf("%d %d\n",len1,len2);
    get_next(s1,next,len1);
    //printf("%d\n",len1);
    //for(int i = 1;i <= len1; ++ i) printf("%d ",next[i]);
    printf("%d\n",find(s1,s2,len1,len2));

    fclose(stdin); fclose(stdout);
    return 0;
}
