#include<cstdio>
bool bz[10000000];
long p[10000];
int main()
{
	long n,t,m;
	t=0;
	scanf("%ld%ld",&n,&m);
	for (int i=2;i<=n;i++)
	{
		if (!bz[i]) p[++t]=i;
		for (int j=1;j<=t;j++)
		{
			if (i*p[j]>n) break;
			bz[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
	for (int i=1;i<=m;i++)
	{
		long x;
		scanf("%ld",&x);
		bz[x]==0 ? printf("YES\n"):printf("NO\n");
	}
}
