#include <stdio.h>
int main(){
    //int T,A,B,C,i;ABC的值是-2的31次方到2的31次方之间的值，所以不能用int类型了 
    int T,i;
	long A,B,C; 
	scanf("%d",&T);
     
    for(i=1;i<=T;i++){//T组测试用例 
        scanf("%ld%ld%ld",&A,&B,&C);
        if((A+B)>C){
            printf("Case #%ld: true\n",i);//注意用%d输出变量，true单词的写法 
        }else{
            printf("Case #%ld: false\n",i);
        }
    }

    return 0;
}
