#include <stdio.h>
int main()
{
	//printf("������һ��Ҫת������ֵ�����ף�\n");��Ŀ��û���������ʾ�Ͳ�Ҫ�����ʾ��Ϣ 
	int cm;
	double t;
	int foot;
	int inch;
	double const Number=30.48;
	scanf("%d",&cm);
	t=cm/30.48;
	foot=(int)t;
	inch=(int)((t-foot)*12);
	printf("%d %d",foot,inch);
	return 0;
} 
