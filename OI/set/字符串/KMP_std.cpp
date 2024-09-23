#include<iostream>
#include<string>
using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
string s, p;

void get_Next(string s, int ne[])		//����������ַ���s����Ԥ����õ�next����
{
	int j = 0;
	ne[0] = 0;	//��ʼ��
	for (int i = 1; i < s.size(); i++) {	//iָ��ָ����Ǻ�׺ĩβ��jָ��ָ�����ǰ׺ĩβ
		while (j > 0 && s[i] != s[j])	j = ne[j - 1];	//ǰ��׺����ͬ��ȥ��jǰһλ������ǰ��׺
		if (s[i] == s[j])	j++;	//ǰ��׺��ͬ��jָ�����
		ne[i] = j;	//����next����
	}
}

int main()
{
	freopen("kmp1.in","r",stdin);
	cin >> n >> p >> m >> s;

	get_Next(p, ne);

	for (int i = 0, j = 0; i < m; i++) {	
		while (j > 0 && s[i] != p[j])	j = ne[j - 1];
		if (s[i] == p[j])	j++;
		if (j == n) {
			cout << i - n + 1 << " ";
			j = ne[j - 1];	
		}
	}
	
	fclose(stdin);
	return 0;
}

