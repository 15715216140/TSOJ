#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[700005] ; 
bool is(int n) {
	int count = 0;
	if(n < 5)
		return false;
	else {
		int i;
		for( i = 2; i*i <= n; i++) {
			if(n%i == 0)
				count++;
			if(count == 2)
				return false;
		}
		if(count == 1 && (i-1)*(i-1) != n)
		return true;
		else
		return false;	
	}
}
int main() {
	memset(a,0,sizeof(a));
	for(int i = 1; i <= 700005; i++) {
			if(is(i) == true)
			a[i] = 1;
			a[i] += a[i-1] ;//��sum[]����������������Ϊ�����ڴ�ռ�þ�˳���ű���a[]����Ӱ��ģ� 
		}
	int m, n;
	while(cin >> m >> n) {
		cout << a[n] - a[m-1] << endl;
	}
	return 0;
}

/*1.	ÿ����������n��������Ϊ1, a, n/a ,n;���;
	ֻҪ��i*i <= n;ǰ�ж�ֻҪ����һ��a������(n/a һ������); (ע����� a == n/a; ����ظ���������; ) 
	���ԣ���Ҫ����ֻ��һ�������һ�����i*i==n; 
2.	����жϳ���2��a;��ôһ�������ϣ�����ֱ��break; */
 

