#include <cstdio>
#include <stack>
using namespace std;

stack <int> q;

int n;

int main()
{
	scanf("%d" ,&n);
	for (int i = 1 ,x;i <= n; i++)
		scanf("%d" ,&x) ,q.push(x);
	
	printf("%d\n" ,q.size());
	while (! q.empty()) printf("%d " ,q.top()) ,q.pop();
	
	return 0;
}
