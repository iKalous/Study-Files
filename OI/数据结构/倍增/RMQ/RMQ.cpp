#include<cstdio>
long log[21];
long f[1000][21];
long a[1000],n,m;
long max(long a,long b){return a>b ? a:b;}
int main()
{
	scanf("%ld",&n);
	log[0]=-1;
	for (int i=1;i<=n;i++) 
	{
		scanf("%ld",&a[i]);
		f[i][0]=a[i];
		log[i]=log[i>>1]+1;
	}
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j-1)<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	scanf("%ld",&m);
	for (int i=1;i<=m;i++)
	{
		long x,y;
		scanf("%ld%ld",&x,&y);
		long s=log[y-x+1];
		printf("%ld\n",max(f[x][s],f[y-(1<<s)+1][s]));
	}		
}
