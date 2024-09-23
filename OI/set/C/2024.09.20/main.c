#include <stdio.h>
#include "max.h"
#include "min.h"

int a,b;

int main()
{
    scanf("%d%d",&a,&b);
    printf("Max: %d\n",max(a,b));
    printf("Min: %d\n",min(a,b));
}