1053:������
�Ѷȣ� �������    ʱ�����ƣ� 1000MS   �ռ����ƣ� 64MB   �ύ���� 86   ͨ������ 35 ��Ŀ��Դ: nuistoj
��Ŀ����
��Ŀ����:
�ж�һ���������Ƿ�Ϊ��������������������������һ���������������Ҷ��ʹ������������һ������

����������
����һ��������ռһ�У�12321

���������
���ռһ�У��Ƿ�Ϊ���������������yes�����������no

��������:
1234

121

454

�������:
no

yes

yes
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string res, s;
	while(cin >> s) {
		res = s;
		reverse(s.begin() ,s.end() );
		if(res == s )	cout << "yes\n";
		else			cout << "no\n";
	} 
return 0;
}

