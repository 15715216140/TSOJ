# include<stdio.h>
int main()
{
	int N, M, T, L, R, i, j, count = 0, front = 0;
	int sum[10];
	while(scanf("%d %d %d", &N, &M, &T) != EOF) 
	{
		int Map[100005] = {0}, Sum[100005] = {0};
		for(i = 1; i <= M; i++)
		{
			scanf("%d %d", &L, &R);
			Map[L]++;             //��L����������ÿ����������һ�仨 
			Map[R+1]--;	         //��R+1����������ÿ�������ϰε�һ�仨 
		}
		for(i = 1; i <= N+1; i++)
		{
			front += Map[i];//������������������ÿ��������Ҫ�ֵĻ�����Ŀ
			Sum[i] = Sum[i-1] + front;// ����ӵ�һ�����ص���i������֮ǰ��������i�����أ���Щ�������ֻ������� 	 
		}
		for(j = 0; j < T; j++)
		{
			scanf("%d %d", &L, &R);
			sum[j] = Sum[R] - Sum[L-1];//��������[L,R]��Щ�����ϻ������� 
		 } 
		 for(j = 0; j < T; j++)
		 	printf("%d\n", sum[j]);
		 front = count = 0;
	}
	
 } 
