1142:Encoding
�Ѷȣ� �������    ʱ�����ƣ� 1000MS   �ռ����ƣ� 16MB   �ύ���� 57   ͨ������ 14 ��Ŀ��Դ: nuistoj
��Ŀ����
��Ŀ����:
Given a string containing only "A" - "Z", we could encode it using the following method:

1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.

2. If the length of the sub-string is 1, "1" should be ignored.
����������
The first line contains an integer N (1 <= N <= 100) which indicates the number of test cases. The next N lines contain N strings. Each string consists of only "A" - "Z" and the length is less than 10000.

���������
For each test case, output the encoded string in a line.

��������:
2

ABC

ABBCCC

�������:
ABC

A2B3C
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n; 
	string s;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0, k; j < s.size(); j = k) {
			for(k = j + 1; s[k] == s[j]; k++) ;
			if(k - j > 1) 	cout << k-j;
			cout << s[j];
		}
		cout << endl;
	}
	return 0;
}
