#include <iostream>
#include <algorithm>
#include <string>
struct stu {
	int sco;
	int num;
}a[1000001],aa[1000001]; 
using namespace std;
int comp(stu a, stu b) {
	if(a.sco < b.sco )
		return 1;
	else
		return 0;
}
int main() {
	//freopen("test.txt","r",stdin); 
	int N;
	while (cin >> N) {
		for(int i = 0; i < N; i++) {
			cin >> a[i].sco;
			a[i].num = 1;//��˼�������������Ҫ�� 
		}
		for(int i = 0; i < N; i++) {//���������ݽ��кϲ�ȥ�� 
			if(a[i].sco != -1) {
				for(int j = i+1; j < N; j++) {
					if(a[i].sco == a[j].sco) {
						a[i].num++;
						a[j].sco = -1;//��˼������������Ҳ������Ժ� ���� 
					}
				}
			}
		}
		int t;
		for(int i = 0,j = 0; i < N; i++) {//ɸѡ��������� 
			if(a[i].sco != -1) {
				aa[j].num = a[i].num;
				aa[j].sco = a[i].sco;
				j++;
				t = j;
	
			}
		}
		sort(aa,aa+t,comp);
		for(int i = 0; i < t; i++) {
			cout << aa[i].sco << " " <<  aa[i].num << endl;
		}
	} 
	return 0;
}
/*1.sort ��ʱ
2.ѧ���ɼ���Ϊ�±꣬�������ȡ���γɼ���������
		���������п��ܻ���100000000�ֵ�����ͬѧ���ڴ汬����runtime error�����Ͼ�ħ��ѧԺ�� 
3.�����÷������±꣬����ͬʱ�棬�ɼ���������
		����ýṹ�壻
4ÿ��ͬѧ�ö����Լ��ķ���������ȡ���ķ�������Ϊ1��
	��ô���������ǰ�ͬ���������ݺϲ�ȥ���ˣ�
		����ÿ��ѧ����ifĳͬѧ�ǵ�һ�����˸÷ֵģ������������ˣ�
		����Ϊ���������Ǹ�����������������ݣ�������
		����ͬ�ֵĲ����������ߣ��Ѳ����ͬѧnum��Ϊ-1�����һ�£�
		��˼�����������ݿɶ����ˣ�û���ˣ�
	����������ֻ��num>=1 ��num == -1 �� �����ˣ�
	ɸѡ���������ţ��������ɶ���
	�����㷨���Ӷȸо�����n2����Ϊ�ö�������ݲ�������Ϊ��������ˣ�*/ 
