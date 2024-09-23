#include<cstdio>
const long maxlong=1e9+7;
long f[10000][4];
bool bz[10000];
long a[10000],k,ans;
long min1(long a,long b){return a<b ? a:b;}
void build(long x,long y,long z)
{
	f[++k][1]=y;
	f[k][2]=z;
	f[k][3]=a[x];
	a[x]=k;
}
int main()
{
	long n,m;
	scanf("%ld%ld",&n,&m);
	for (int i=1;i<=m;i++)
	{
		long x,y,z;
		scanf("%ld%ld%ld",&x,&y,&z);
		build(x,y,z);
	}
	long dist[10000]; 
	for (int i=1;i<=n;i++) dist[i]=maxlong;
	dist[1]=0;
	long num=0;
	while (num<n)
	{
		long mini=maxlong,min=maxlong;
		for (int i=1;i<=n;i++)
			if (dist[i]<min&&!bz[i]) min=dist[i],mini=i;
		for (int t=a[mini];t>0;t=f[t][3])
			dist[f[t][1]]=min1(dist[f[t][1]],f[t][2]);
		bz[mini]=1;ans+=min,num++;
	}
	printf("%ld",ans);
}
