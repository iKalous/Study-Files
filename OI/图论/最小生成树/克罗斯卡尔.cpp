#include<cstdio>
long dad[111],f[10000][4],ans,k;
long find(long x)
{
	if (dad[x]==x) return x;
	dad[x]=find(dad[x]);
	return dad[x];
}
void swap(long x,long y,long z)
{
	long t;
	t=f[x][z];
	f[x][z]=f[y][z];
	f[y][z]=t;
}
void build(long x,long y,long z)
{
	f[++k][1]=x;
	f[k][2]=y;
	f[k][3]=z;
}
void qsort(long l,long r)
{
	long i=l,j=r,x=f[(l+r)>>1][3];
	while (i<=j)
	{
		while (f[i][3]<x) i++;
		while (f[j][3]>x) j--;
		if (i<=j)
		{
			swap(i,j,3);
			swap(i,j,1);
			swap(i,j,2);
			i++,j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
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
	qsort(1,k);
	for (int i=1;i<=n;i++) dad[i]=i;
	for (int i=1;i<=k;i++)
	{
		long x,y;
		x=find(f[i][1]);
		y=find(f[i][2]);
		if (x!=y) dad[x]=dad[y],ans+=f[i][3];
	}
	printf("%ld",ans);
}
