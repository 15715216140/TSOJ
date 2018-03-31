1343:���ָ
�Ѷȣ� ��ǿ��ͭ    ʱ�����ƣ� 1000MS   �ռ����ƣ� 16MB   �ύ���� 49   ͨ������ 12 ��Ŀ��Դ: admin
��Ŀ����
[2017 NUIST ������ƾ���]
C. ���ָ
��Ŀ����
������Ů����(tan90��)ȥ���ָ�������кö��ָ�����Ϊ1��2��3������ָ�ϵ���ʯ��С������ͬ�����Ǵ�һ�ѽ�ָ�������ȡ��ö���Ƚ�������ʯ�Ĵ�С���ڱȽ� m ��֮�����ǿ�������ö��ָ a �� b �������������֮ǰ�Ƚϵ���Ϣ�ж�����ö��ָ��һö����ʯ����

��������
�ж������롣

ÿ���һ������������a, b, m (1 <= a, b, c <= 1000)��

a �� b ������Ҫ�Ƚϵ���ö��ָ��m ��ʾ�ȽϵĴ�����

������ m �У�ÿ���������� u, v����ʾ�� u ����ָ����ʯ�ȵ� v ����

�������
�����ָ a ����ʯ�� b ������� 1��

�����ָ a ����ʯ�� b С������� -1��

�������������Ϣ����ָ a �� b �޷��Ƚϣ������ 0��

��������
2 3 4

1 2

2 4

1 3

4 3

�������
1
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int m[1005][1005], vis[1005];
int a, b, maxn;
bool dfs(int be ,int end) {
	queue<int> q;
	q.push(be);
	vis[be] = 1;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 1; i <= maxn; i++) {
			if(m[t][i] && vis[i] == 0) {
				vis[i] = 1;
				if(i == end)	return true;
				q.push(i);
			} 
		}
	}
	return false;
}
int main() {
	int n, ta, tb;
	while(cin >> a >> b >> n) {
		maxn = 0;
		memset(m,0,sizeof(m));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; i++) {
			cin >> ta >> tb;
			maxn = max(maxn,max(ta,tb));
			m[tb][ta] = 1;
		}
		bool t1 = dfs(a,b);
		memset(vis,0,sizeof(vis));
		bool t2 = dfs(b,a);
		int ans;
		if(!t1 && !t2)	 ans = 0;
		if(t2)	 ans = 1;
		if(t1) 	 ans = -1;
		cout << ans << endl;
	}
	return 0;
}

