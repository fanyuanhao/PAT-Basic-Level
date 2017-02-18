#include <stdio.h>
#include <string.h>
int main(){
	int N;
	scanf("%d",&N);
	char *mar_num1[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	char *mar_num2[13]={"\0","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	
	int b=0;//地球数字 
	int flag=0;
	int len;
	int i,j=0;
	char *p;
	//char a[100][7];数组开的刚刚好没有放结束符的地方，会和后面的字符连起来。
	char a[100][9]; 
	
	getchar();	
	for(i=0;i<N;i++){
		gets(a[i]);
	}
	
	for(i=0;i<N;i++){
		
		if((a[i][0]>='0')&&(a[i][0]<='9')){
			b=0;
			len=strlen(a[i]);
			for(j=0;j<len;j++){
				b=b*10+a[i][j]-'0';
			}
			if(b<13){
				printf("%s\n",mar_num1[b]);
			}else{
				if(b%13!=0){
					printf("%s ",mar_num2[b/13]);
					printf("%s\n",mar_num1[b%13]);
				}else{
					printf("%s\n",mar_num2[b/13]);
				}
			}
		}else{
			/* 
			字符小于3这个条件不准确，当为13的倍数的数也是3个字符 
			len=strlen(a[i]);
			if(len<=3){
				for(j=0;j<13;j++){
					if(strcmp(a[i],mar_num1[j])!=0){
						j++; 
					}else{
						printf("%d\n",j);
					}
				}
			}else{
				sscanf(a[i],%[^ ],d);
				sscanf(a[i],%[],e);
				
			}
			*/
			flag=0;
			 for(j=0;j<13;j++){
			 	if(strcmp(a[i],mar_num1[j])==0){
			 		printf("%d\n",j);
			 		flag=1;
				 }
			 }
			 if(flag==0){
			 	for(j=0;j<13;j++){
			 		if(strncmp(a[i],mar_num2[j],3)==0){
			 			b=13*j;
					 }
				 }
				 p=&a[i][0];
				 if(a[i][3]!='\0'){
				 	for(j=0;j<13;j++){
						 if(strcmp(p+4,mar_num1[j])==0){
				 			b=b+j;
						 }
					 }
				 }
				 printf("%d\n",b);
			 }
		}
	}
	return 0;
}
