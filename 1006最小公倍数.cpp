



1006:��С������
�Ѷȣ� �������    ʱ�����ƣ� 1000MS   �ռ����ƣ� 64MB   �ύ���� 92   ͨ������ 36
��Ŀ����
��Ŀ����:
����2������a��b(3 < a,b < =10000)�����a��b����С��������

����������
�������룬����ĵ�һ��Ϊһ��������n����ʾ��������n�����ݣ�ÿһ��Ϊ����������a��b(3 < a,b < =10000)

���������
����ÿһ�����ݣ����a��b����С��������

��������:
2

2 4

3 5

�������:
4

15
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int a, b, t, a1, b1;
	int n;
	while( cin >> n ) {
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			a1 = a; 
			b1 = b;
			while( a % b) {
				t = a % b;
				a = b;
				b = t;
			}
			cout << a1*b1/b << endl;
		}
	} 
	return 0;
}
//int gcd(int a, int b) { �ݹ�����飬˼·������ŷ�������չ 
//	if(b == 0) return a;   ���ǲ���ѭ��Ч�ʸ� 
//	return gcd(b,a%b);
//}



