#include <stdio.h>
#include <string.h>
int main(){
	int N;
	scanf("%d",&N);
	char a[7];//读队伍和成员编号 
	int len;//队伍成员编号字符的长度 
	int b[1000]={0};//存每个队伍的总成绩 
	int i,j;
	int num=0;//临时变量存队伍编号
	int score;//读成绩
	int cnt;//纪录-的下标 
	for(i=0;i<N;i++){
		scanf("%s%d",a,&score);
		len=strlen(a);
		
		for(j=0;j<len;j++){
			if(a[j]=='-'){
				cnt=j;
			}
		}
		num=0;
		for(j=0;j<cnt;j++){
			num=num*10+a[j]-'0';
		}
		b[num]+=score;
	}
	int max=0;
	int MAX=0;//纪录最大值的下标 
	for(i=0;i<1000;i++){
		if(b[i]>max){
			max=b[i];
			MAX=i; 
		}
	}
	printf("%d %d",MAX,max);
	
	return 0;
} 
