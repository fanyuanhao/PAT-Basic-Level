#include <stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    
    char num[N][19];//身份证号数组+判断是否全为数字的位置 
    
	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int i=0,j=0,cnt=0,sum=0,Z;
    
    //二维数组第19列初始化为& 
	for(i=0;i<N;i++){
    	num[i][18]='&';
	}
	//读入值
	for(i=0;i<N;i++){
        getchar();//读入回车 
        for(j=0;j<18;j++){
            scanf("%c",&num[i][j]);
            if((j!=17)&&(num[i][j]=='X')){
                num[i][18]='*';
				cnt++; 
            }
        }
    }
    //判断身份证是否错误 
    for(i=0;i<N;i++){
        if(num[i][18]!='*'){
			sum=0;
        	for(j=0;j<17;j++){//用数组存放权重，用循环计算显得简洁 
        	  	sum+=(num[i][j]-48)*weight[j];
			}
			if(sum>=11){
        	    Z=sum%11;
        	}else{
        	    Z=sum;
        	}
        	/*
			if(num[i][17]!=M[Z]){
        		num[i][18]='*';
        		cnt++;
			}
			*/
			
        	if(Z==2){
        	    //if(num[i][17]-48!='X'){//这个地方是字符没有必要减48， 
        		if(num[i][17]!='X'){
				
				    num[i][18]='*';
        	        cnt++;             
        		}
			}else{
        	    if((Z+(num[i][17]-48))!=1&&Z+(num[i][17]-48)!=12){
        	         num[i][18]='*';
        	         cnt++;
        	    }
        	} 
			           	
		}
    }
    //输出
    if(cnt==0){
        printf("All passed");
    } else{
        for(i=0;i<N;i++){
            if(num[i][18]=='*'){
                for(j=0;j<18;j++){
                    printf("%c",num[i][j]);
                }
                //printf("\n");//这样的话会多输出一个换行符
				
				if(cnt!=1){
					printf("\n");
				}
				cnt--;
				 
            } 
        }
    }
     
     
    return 0;
}
