#include<cstdio>
const long maxlong=1e9+7;
long f[10000][4];
bool bz[10000];
long a[10000],k,ans,tot,min,mini;
long heap[10000000][3];
void swap(long x,long y,long z)
{
	long t=heap[x][z];
	heap[x][z]=heap[y][z];
	heap[y][z]=t;
}
void insert(long x,long y)
{
	long now,father;
	heap[++tot][1]=x;
	heap[tot][2]=y;
	now=tot;
	father=now/2;
	while (now>1&&heap[now][1]<heap[father][1])
	{
		swap(now,father,1);
		swap(now,father,2);
		now=father;
		father=now/2;
	}
}
void delete1()  //����λ�� 
{
	long s,s1,s2,now;
	long k=heap[1][2]; 
	heap[1][1]=heap[tot][1];
	heap[1][2]=heap[tot][2];
	--tot;
	now=1;
	s1=now<<1;
	s2=s1+1;
	while ((s1<=tot&&heap[s1][1]<heap[now][1])||(s2<=tot&&heap[s2][1]<heap[now][1]))
	{
		s=s1;
		if (heap[s][1]>heap[s2][1]&&s2<=tot) s=s2;
		swap(now,s,1);
		swap(now,s,2);
		now=s;
		s1=now<<1;
		s2=s1+1;
	}
	mini=k;
}
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
	long num=0;
	scanf("%ld",&num);
	dist[num]=0;
	insert(0,num);
	num=0;
	while (num<n)
	{
		mini=heap[1][2];
		while (bz[mini]) delete1();
		min=dist[mini];
		for (int t=a[mini];t>0;t=f[t][3])
		{
			//dist[f[t][1]]=min1(dist[f[t][1]],f[t][2]+min);
			if (dist[f[t][1]]>f[t][2]+min)
			{
				dist[f[t][1]]=f[t][2]+min;
				insert(f[t][2]+min,f[t][1]);
			}
		}
		bz[mini]=1;ans+=min,num++;
	}
	for (int i=1;i<=n;i++)printf("%ld ",dist[i]);
}
