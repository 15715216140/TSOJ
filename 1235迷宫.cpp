1235:�Թ�
�Ѷȣ� �������    ʱ�����ƣ� 1000MS   �ռ����ƣ� 64MB   �ύ���� 45   ͨ������ 10 ��Ŀ��Դ: nuistoj
��Ŀ����
��Ŀ����:
�ɹ�սʤ�˹����Ipomy ���뵽��һ���Թ����С�����Թ��Ĺ��Ϊ m * n��ֻ��һ����ں�һ�����ڡ�Ipomy ���ţ�ֻҪ�߳�����Թ��������ؿ˱��ؾ�����ǰ�ˡ�����Ҫ֪���뿪�Թ�������Ҫ�߶��ٲ��������̰���������һ�¡�

����������
�������롣

ÿ������ĵ�һ��Ϊ�������� m �� n����ʾ�Թ��Ĺ�񣬱�֤ 1 <= n, m <= 100��

�������� m �У�ÿ�� n �����������Թ�ÿ�����ӵ���Ϣ�����У�0 ��ʾ���ӿ����ƶ���1 ��ʾ�����������ϰ�������ƶ���ÿ���������ݾ�����ڶ������Ͻǣ����ڶ������½ǣ����������ӵ�������ֵ��Ϊ 0��

���������
���������

ÿ�����ռ��һ�У�Ϊһ����������ʾ���·�������޷��뿪�Թ�ʱ����� -1��

��������:
4 5

0 1 1 0 0

0 1 0 0 0

0 0 0 1 0

1 1 1 0 0

3 3

0 1 0

0 1 0

0 1 0

�������:
9

-1

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[105][105];
int vis[105][105];
int x[] = {-1,0,1,0};
int y[] = { 0,1,0,-1};
int m, n, t;
struct pos{
	int x, y, step;
}; 
int f(void) {
		queue <pos> q;
		pos p;
		int tx,ty,tstep;
		vis[0][0] = true;
		p.x = p.y = p.step = 0;//��¼��ǰ���˼��� 
		q.push(p);
		int cnt = 0;
		while(!q.empty()) {
			cnt++;
			tx = q.front().x;
			ty = q.front().y; 
			tstep = q.front().step;
			q.pop();
			for(int i = 0; i < 4; i++) {
				if(tx+x[i] >=0 && tx+x[i] < m && ty+y[i] >= 0 && ty+y[i] < n 
				&& tx+x[i] == m-1 && ty+y[i] == n-1 && map[tx+x[i]][ty+y[i]] == 0) {
					cout << tstep+1 << endl;//�ҵ�����Ҫ��ʱ������ 
					return 0;
				}
				if(tx+x[i] >=0 && tx+x[i] < m && ty+y[i] >= 0 && ty+y[i] < n && 
				vis[tx+x[i]][ty+y[i]] == false && map[tx+x[i]][ty+y[i]] == 0 ) {
					p.x = tx+x[i];
					p.y = ty+y[i];
					p.step = tstep+1;//�ò�����һ����Ҫ��+1 
					q.push(p);
					vis[tx+x[i]][ty+y[i]] = true;
				} 
			}
		}
		cout << -1 << endl;
		return 0;
}
int main() {
//	freopen("test.txt","r",stdin);
	while(cin >> m >> n) {
		memset(map,0,sizeof(map));
		memset(vis,false,sizeof(vis));
		for(int i = 0; i < m; i++) 
			for(int j = 0; j < n; j++) 
				cin >> map[i][j];
		f();
	}
	return 0;
}

