#include <iostream>//1.�ַ����洢��2.ģ���ֶ����� 3.���ص���ÿһ�� 4.����Ҫ���� 
#include <string>
using namespace std;
#define N 10001
string s[N];
string mul(string s1,int n) {//�ֶ�ģ��˷�����λ���� 
	int jin = 0;
	char c;
	string st = s1;
	for(int i = s1.size() - 1; i >= 0; i--) {
		st[i] = ((s1[i] - '0') * n + jin) % 10 + '0';
		jin = ((s1[i] - '0') * n + jin) / 10;
	}
	c = jin + '0';//����˺�����һλ 
	if(jin >= 1)
		st = c + st;
	return st;
}

string add(string s1, string s2) {
	string st = s1;
	char c;
	int jin = 0;
	if(s1.size() > s2.size() ) {//��ǰ����s1.s2λ����һ��,(ֻ�����s1>=s2�����)��Ϊs1�Ǻ�һ� 
		for(int i = 0; i < s1.size() - s2.size();i++) {//�յ�λ�ò�0 ,����888 66 -> 888 066; 
			st[i] = '0';
		}
		for(int i = s1.size() - s2.size(),j = 0; i < s1.size() ; i++,j++)	{
			st[i] = s2[j];
		}
		s2 = st;
	}
	for(int i =  s2.size() - 1; i >= 0; i--)	{//�ֶ�ģ�⣬��λ����
		st[i] = ((s1[i] + s2[i] - '0' - '0' + jin) % 10) + '0';
		jin = (s1[i] + s2[i] - '0' - '0' + jin) / 10;
	}
	c = jin + '0';//����˺�����һλ
	if(jin >= 1) {
		st = c + st;
	}
	return st;
	
}

string fun(string s1, string s2, int n1, int n2) {
	s1 = mul(s1,n1);
	s2 = mul(s2,n2);
	return add(s1,s2);
}
int main() {
	int a, b, m, n,t;
	string p, q;
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d",&a,&b) != EOF) {
		cin >> p >> q;//1.���ַ�����ÿһ�� ����̫��int ��long longҲ��ը�� 
		scanf("%d",&m);
		s[1] = p;
		s[2] = q;
		int ar[m+1];
		for(int i = 1; i <= m; i++) {
			scanf("%d",&ar[i]);
		}
		t = ar[1];	
		for(int i = 2; i <= m; i++) {//��Ҫ�õ��ڼ���ͼ��㵽�ڼ��� 
			if(t < ar[i])
				t = ar[i]; 
		}
		for(int i = 3; i <= t; i++) {
			s[i] = fun(s[i-1],s[i-2],b,a);//ÿһ����� 
		}
		for(int i = 1; i <= m-1; i++) {
			cout << s[ar[i]] << ' '; 
		}
		cout << s[ar[m]] << endl;
	}
	return 0;
}
/*��һ����ǣ�����Ҫ������
֮ǰ fun(s[i-1],s[i-2],b,a)ֱ��д��һ�������
��Ȼ����������Ǻ��ң����ڵ��Ի����Ķ�����ܲ����� 
֮ǰд��һ�����������ǵ����طѾ����Լ����붼������ 
��ɼ���С��������������*/ 
