1263:�߾��ȳ˷�������
�Ѷȣ� �������    ʱ�����ƣ� 1000MS   �ռ����ƣ� 16MB   �ύ���� 44   ͨ������ 14 ��Ŀ��Դ: nuistoj
��Ŀ����
��Ŀ����:
��������С�� 100 λ��������������˻���

����������
��һ����һ�������� n (n < 50)����ʾ�� n ��������ݣ�ÿ��������������й��ɡ�ÿ�б�ʾһ���������ݣ�ÿ�����������ǳ���С�� 100 λ����������

���������
n �У�ÿ��һ����������

��������:
2

11111

22222

1937

2931

�������:
246908642

5677347
#include <iostream>
#include <algorithm>
using namespace std;
string mul(string s1, string s2) {
	string ans = "";
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int l1 = s1.length() , l2 = s2.length();
	vector<int> v(s1.size() + s2.size(), 0);
	for(int i = 0; i < s1.size(); i++) {
		for(int j = 0; j < s2.size(); j++) {
			int t = (s1[i] - '0') * (s2[j] - '0') + v[i+j];
			v[i+j+1] += t / 10;
			v[i+j] = t % 10;
		}
	}
	int j;
	for(j = l1 + l2 - 1; v[j] == 0; j--)	;
	for(; j >= 0; j--)	ans += to_string(v[j]);
	if(ans == "")	return "0";
	return ans; 
}
int main() {
	int n;
	cin >> n;
	string s1, s2;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		cout << mul(s1,s2) << endl;
	} 
	return 0;
}

