#include <stdio.h>
#include <string.h>

const int N = 1e5 + 5;

char ch[];

int main()
{
    freopen("Quine.in","r",stdin);
    freopen("Quine.out","w",stdout);

    scanf("%s",ch);
    puts(ch);

    fclose(stdin); 
    fclose(stdout);
    return 0;
}