#include <stdio.h>
int main()
{
	//printf("请输入一个要转换的数值（厘米）\n");题目中没有让输出提示就不要输出提示信息 
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
