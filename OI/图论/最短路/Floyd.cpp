#include<cstdio>
long f[1000][1000],n,m,t;
const long p=1e9+7;
int main() 
{
	scanf("%ld%ld",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) if (i!=j) f[i][j]=p;
	for (int i=1; i<=m; i++) {
		long x,y,z;
		scanf("%ld%ld%ld",&x,&y,&z);
		f[x][y]=z;
	}
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				f[i][k]+f[k][j]<f[i][j] ? f[i][j]=f[i][k]+f[k][j]:f[i][j]=f[i][j];
	scanf("%ld",&t);
	for (int i=1; i<=n; i++) printf("%ld\n",f[t][i]);
}
