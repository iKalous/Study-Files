#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;

int n;

int main()
{
	scanf("%d" ,&n);
	for (int i = 1 ,x ,y;i <= n; i++)
		scanf("%d" ,&x) ,q.push(x);
	
	printf("%d\n" ,q.size());
	while (! q.empty()) printf("%d %d\n" ,q.front() ,q.back()) ,q.pop();
	
	return 0;
} 
