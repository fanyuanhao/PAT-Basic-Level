#include <stdio.h>
int main(){
	char a[3][12][7];
	int i,j,k=1;
	int cntk=0;
	int cntj[4];
	char c;
	int flag=0,flag1;
	for(i=1;i<=3;i++){
		flag1=0;
		for(j=1;;j++){
			for(cntk=0;;cntk++){
				c=getchar();
				if(c=='['){
					flag=1;
					continue;
				}
				if(c==']'){
					flag=0;
					break;
				}
				if(c=='\n'){
					flag1=-1;
					break;
				}
				if(flag){
					a[i][j][k]=c;
					k++;
				}
			}
			a[i][j][k]='\0';//加上结束符 
			k=1;
			if(flag1==-1){
				cntj[i]=j;
				break;
			}
		}
	}
	int N;
	scanf("%d",&N);
	int b[N+1][6];
	int countj=0;
	flag=0;
	for(i=1;i<=N;i++){
		for(j=1;j<=5;j++){
			scanf("%d",&b[i][j]);		
		}
	}
	for(i=1;i<=N;i++){
		//判断是不是能输出，b中每行的每个值都小于相应的可选值 
		for(j=1;j<=5;j++){
			countj=j;
			if(j==4){
				countj=2;
			}
			if(j==5){
				countj=1;
			}
			if(b[i][j]>cntj[countj]){
				flag=1;
			}
		}
		if(flag){
			printf("Are you kidding me? @\\/@");
		}else{
			printf("%s",a[1][b[i][1]]);
			printf("(");
			printf("%s",a[2][b[i][2]]);
			printf("%s",a[3][b[i][3]]);
			printf("%s",a[2][b[i][4]]);
			printf(")");
			printf("%s",a[1][b[i][5]]);
			printf("\n");
		}
	}
	
	
	return 0;
} 
