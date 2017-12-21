#include <stdio.h>
#include <string.h>
#define MAXM 30     //���M ѯ�ʴ���
#define MAXN 10000  //���N
#define MAXL 3000  //��� 9959
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MLEN (sizeof(int)*MAXL) //����ռ�ÿռ�
#define I(x) ((i/4%2*2+(x))%4)  //ѭ������

int answer[MAXM][MAXL];
int a[4], b[4], p, q, m, maxm, l, ll;
int query[MAXM];

int tempf[4][MAXL]; // 쳲�������������
int tempm[2][MAXL]; // ��ʱ�˷�

int empty; // tempf�п��е�����

		   /*
		   //f3=af2+bf1 => a0, b0
		   //f4=af3+bf2=(a^2+b)f2+abf1 => a1, b1
		   f5=af4+bf3=(a^3+2ab)f2+(a^2b+b^2)f1 => a2, b2
		   f6=af5+bf4=(a^4+3a^2b+b^2)f2+(a^3b+2ab^2)f1 => a3, b3
		   */

		   //�ռ�����
void memclr(int addr[]) {
	memset(addr, 0, MLEN);
}

//����
int input() {
	maxm = -1;
	if (scanf("%d %d %d %d", b, a, &p, &q) == EOF)
		return -1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", query + i);
		if (maxm < query[i]) maxm = query[i];

	}



	//Ԥ������λ���㣬һ��ʹ��a[2]/b[2], a[3]/b[3]�����������ʹ��a[0]/b[0], a[1]/b[1]
	a[1] = a[0] * a[0] + b[0];
	b[1] = a[0] * b[0];
	a[2] = a[0] * a[0] * a[0] + 2 * a[0] * b[0];
	b[2] = a[0] * a[0] * b[0] + b[0] * b[0];
	a[3] = a[0] * a[0] * a[0] * a[0] + 3 * a[0] * a[0] * b[0] + b[0] * b[0];
	b[3] = a[0] * a[0] * a[0] * b[0] + 2 * a[0] * b[0] * b[0];

	//쳲�������f0, f1
	tempf[2][0] = 1;
	tempf[2][1] = p;
	tempf[3][0] = 1;
	tempf[3][1] = q;
	// tempf[2], tempf[3] => tempf[0], tempf[1]
	return 0;
}

//�߾��ȴ���x��С����y
void multiply(int x[], int y, int ans[]) {
	for (int i = 1; i <= x[0]; i++) {
		ans[i] += y * x[i];
		ans[i + 1] = ans[i] / 10000;
		ans[i] %= 10000;
	}
	ans[0] = x[0];
	while (ans[ans[0] + 1]) {
		ans[0]++;
		ans[ans[0] + 1] = ans[ans[0]] / 10000;
		ans[ans[0]] %= 10000;
	}
}

//�߾��ȴ���x�Ӹ߾��ȴ���y
void add(int x[], int y[], int ans[]) {
	int l = MAX(x[0], y[0]);
	for (int i = 1; i <= l; i++) {
		ans[i] += x[i] + y[i];
		ans[i + 1] = ans[i] / 10000;
		ans[i] %= 10000;
	}
	ans[0] = l;
	if (ans[ans[0] + 1])
		ans[0]++;
}

//쳲���������f=ax+by
void f(int a, int x[], int b, int y[], int ans[]) {
	memclr(tempm[0]);
	memclr(tempm[1]);
	multiply(x, a, tempm[0]);
	multiply(y, b, tempm[1]);
	add(tempm[0], tempm[1], ans);
}

//��ѭ������Ĵ𰸱��浽answer��
void save(int ia, int _if) {
	memcpy(answer[ia], tempf[_if], MLEN);
}

int main() {
	freopen("test.txt","r",stdin);
	while (1) {
		int ret = input();
		if (ret == -1)
			break;
		for (int i = 5; i <= maxm + 4; i += 4) {
			//ÿ4λ���ż���
			for (int j = 0; j < m; j++) {
				//�ж��Ƿ���ѯ�ʵ�λ��
				//�����Ѿ�����97,98�����ڵ�iΪ101
				//������ʵ�97,98,99,100λ��ֵ�Ƕ��٣��ڴ˴��õ���
				int delta = query[j] - (i - 4);
				//�ȼ���97/98/99/100��97�Ĳ�ֵ
				//�������0/1�����ʵ�97/98λ��ʲô�����Ѿ�������tempf��
				if (delta == 0 || delta == 1) {
					save(j, I(delta));
				}
				//�������2/3�����ʵ�99/100λ��ʲô����Ҫ����f99=bf97+af98=b[0]f97+a[0]f98
				//                              f100=bf98+af99=abf97+(a^2+b)f98=b[1]f97+a[1]f98
				else if (delta == 2 || delta == 3) {
					memclr(tempf[I(delta)]);
					f(b[delta - 2], tempf[I(0)], a[delta - 2], tempf[I(1)], tempf[I(delta)]);
					save(j, I(delta));
				}
			}
			memclr(tempf[I(2)]);
			memclr(tempf[I(3)]);
			f(b[2], tempf[I(0)], a[2], tempf[I(1)], tempf[I(2)]);   // fn+2=b[2]fn+1+a[2]fn
			f(b[3], tempf[I(0)], a[3], tempf[I(1)], tempf[I(3)]);   // fn+3=b[3]fn+1+a[3]fn
		}

		for (int i = 0; i < m; i++) {
			for (int j = answer[i][0]; j > 0; j--) {
				ll = answer[i][j];
				l = 0; 
				while (ll > 0) {
					ll /= 10;
					l++;
				}//�ж�λ����0 
				
				if (j != answer[i][0] && l < 4) {
					for (int k = 0; k < (4 - l); k++)
						printf("0");
				}
				if(answer[i][j] !=0 )	printf("%d", answer[i][j]);

				if (i != m - 1) printf(" ");
			}
		}
		printf("\n");
	}
}
