#include <iostream>//�����ѧ�ķ�ֵ�ݹ� 
#include <algorithm>
using namespace std;
	//�����㷨 
int a[95005];
int f(int left,int center, int right) {
	//�������벿������Ԫ�ص����� 
        int s1 = a[left];
        int lefts = 0;
        for(int i = center; i >= left; i--)
        {
            lefts += a[i];
            if(lefts > s1) 
				s1 = lefts;
        }
        //������Ұ벿������Ԫ�ص����� 
        int s2 = a[center+1];
        int rights = 0;
        for(int i = center+1; i <= right; i++)
        {
            rights += a[i];
            if(rights > s2) 
			s2 = rights;
        }
        return s1 + s2;
}
int maxsubsum(int left,int right)
{
    int sum = 0;
    if(left == right)//���������ֻ��һ��Ԫ�� 
        sum = a[left];
    else
    {
        int center = (left+right)/2;
        int leftsum = maxsubsum(left,center);//��벿�� 
        int rightsum = maxsubsum(center+1,right);//�Ұ벿��
        int centersum  = f(left,center,right);//�������֮�����+�ұ�����֮����� 
		sum = max(centersum,max(leftsum,rightsum));
    }
    return sum;
}
int main() {
	freopen("test.txt","r",stdin);
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		} 
		cout << maxsubsum(0,n-1) << endl;
		}
	return 0;
}

