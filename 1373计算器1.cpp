



1373:������1
�Ѷȣ� ��ǿ��ͭ    ʱ�����ƣ� 1000MS   �ռ����ƣ� 64MB   �ύ���� 39   ͨ������ 14
��Ŀ����
��Ŀ������
����һ�б��ʽ���м�û�пո�������ʽ�ļ��������������ݱ�֤int��Χ֮�ڣ����Ǽ򵥵�һ����Ŀ��ֻ�漰�ӷ��ͼ�����

����������
һ�б��ʽ

���������
���ʽ�ļ�����

�������룺
12+21-0

���������
33

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int res, a;
	char c;
	while(cin >> res){
		while(scanf("%c",&c)) {
			if(c=='\n')
				break;
			cin >> a;
			if(c=='+')
				res += a;
			if(c=='-')
				res -= a;
		}
		cout << res << endl;
	}
}


