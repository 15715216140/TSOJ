#include <iostream>
#include <algorithm>
int a[95005];
int sum[95005];
using namespace std;
int MaxSum(int n)
{
    sum[0] = a[0];
    int t = a[0];
    for(int i = 1; i < n; i++) 
    {	
    	//sum[i]��ʾ��a[i]Ϊ�Ӵ�βʱ�����������еĺ� �� 
		//�����sum[i-1]<0;˵��֮ǰ��������������У��Ǵ�ʱ����Ҫ���¿�ʼ������������sum[i] = a[i];
		//�����sum[i-1]>=0;˵��֮ǰ������������У��Ǵ�ʱ�������
		if(sum[i-1] >= 0) 			 
			sum[i] = sum[i-1] + a[i];
		else
			sum[i] = a[i];
		if(t < sum[i]) 
			t = sum[i];
    }
	return t;
	
}
int main() {
//	freopen("test.txt","r",stdin);
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		cout << MaxSum(n) << endl;
	}
	return 0;
}


