#include <cstdio>
#include <queue>
using namespace std; 

priority_queue<int> pq;
priority_queue<int ,vector<int> ,greater<int> > q;

int n;

int main()
{
	scanf("%d" ,&n);
	for (int i = 1 ,x;i <= n; i++)
		scanf("%d" ,&x) ,pq.push(x) ,q.push(x);
	
	printf("%d\n" ,q.size());
	while (! pq.empty()) printf("%d " ,pq.top()) ,pq.pop(); printf("\n");
	while (! q.empty()) printf("%d " ,q.top()) ,q.pop();
	
	return 0;
}

//ÓÐ size £¬top £¬pop £¬push 
