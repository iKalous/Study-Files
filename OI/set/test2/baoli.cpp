#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int read(){
	int f = 1 , s = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}
int n,m,vis[55],lim[55][55],cnt=0;
bool check1(){//check���� 
	if(cnt == 2){
		int x = 0 , y = 0;
		for(int i=1;i<=n;i++){
			if(!x&&vis[i]==1) x = i;
			else if(x&&vis[i]==1) y = i; 
		}
		if(lim[x][y]) return 1; 
	}
	return 0;
}
bool check2(){//check���� 
	if(cnt == n-2){
		int x = 0 , y = 0;
		for(int i=1;i<=n;i++){
			if(!x&&vis[i]==0) x = i;
			else if(x&&vis[i]==0) y = i; 
		}
		if(lim[x][y]) return 1; 
	}
	return 0;
}
bool dfs(int x){ 
	vis[x] = 1;
	for(int i=1;i<=n;i++){
		if(lim[x][i]||vis[i]) continue; 
		vis[i] = 1;
		cnt += 2;
		if(check2()){
			cnt-=2;
			vis[i] = 0;
			continue;
		}
		if(cnt == n) return 1;
		//������ȥ
		for(int j=1;j<=n;j++){
			if(vis[j]){
				vis[j] = 0;
				if(check1()){
					vis[j] = 1;//�߲��� 
					continue;
				}
				cnt --; 
		//		cout << ' ' << j << endl;
				if(dfs(j)){
					return 1;
				}
				cnt ++;
			}
		} 
		//��ʼ�� 
		cnt-=2;
		vis[i] = 0;
	} 
	vis[x] = 0;
	return 0;
}
int main(){
	freopen("boat.in","r",stdin);
	freopen("boat2.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=50;i++){
		vis[i] = 0;
		for(int j=1;j<=50;j++){
			lim[i][j] = 1;
		}
		lim[i][i] = 1;
	}
	for(int i=1;i<=m;i++){
		int x = read() , y = read();
		lim[x][y] = lim[y][x] = 0;
	}
	for(int i=1;i<=n;i++){
		if(dfs(i)){
			cout << "YES" << endl;
			return 0;
		}
	} 
	cout << "NO" << endl;
}
/*4 3
1 4 3 4 1 3*/
