#include<cstdio>
const long max=1e9+7;
long dist[1000],f[10000][5],a[1000],que[100000];
bool bz[100000];
long n,m,k;
void build(long x,long y,long z)
{
	f[++k][1]=x;
	f[k][2]=y;
	f[k][3]=z;
	f[k][4]=a[x];
	a[x]=k;
}
int main()
{
	scanf("%ld%ld",&n,&m);
	for (int i=1;i<=m;i++)
	{
		long x,y,z;
		scanf("%ld%ld%ld",&x,&y,&z);
		build(x,y,z);
	}
	for (int i=1;i<=n;i++) dist[i]=max;
	scanf("%ld",&m);
	dist[m]=0;
	long st,en;
	st=0;en=1;que[1]=m;
	while (st<en)
	{
		long t=a[que[++st]];
		while (t>0)
		{
			if (f[t][3]+dist[que[st]]<dist[f[t][2]])
			{
				dist[f[t][2]]=f[t][3]+dist[que[st]];
				if (!bz[f[t][2]])
				{
					bz[f[t][2]]=1;
					que[++en]=f[t][2];
				}
			}
			t=f[t][4];
		}
		bz[que[st]]=0;
	}
	for (int i=1;i<=n;i++) printf("%ld ",dist[i]);
	return 0;
}


