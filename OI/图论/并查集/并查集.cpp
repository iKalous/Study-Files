#include<cstdio>
long dad[1000000];
long n,m;
long find(long x)
{
	if (dad[x]==x) return x;
	dad[x]=find(dad[x]);
	return dad[x];
}
int main()
{
	scanf("%ld%ld",&n,&m);
	for (int i=1;i<=n;i++) dad[i]=i;
	for (int i=1;i<=m;i++)
	{
		long x,y,k,l;
		scanf("%ld%ld",&x,&y);
		k=find(x);
		l=find(y);
		dad[k]=dad[l];
	}
	scanf("%ld",&m);
	for (int i=1;i<=m;i++);
	{
		long x,y;
		scanf("%ld%ld",&x,&y);
	    find(x)==find(y) ? printf("YES\n"):printf("NO\n");
	}
}
