#include <stdio.h>
#include <math.h> 
/*
这个主要的思路是从2~10000中的数判断它是不是素数，
如果是素数，count++,判断count和MN之间的关系
如果count在NM中的次序，则输出对应位置上的值 
然后判断count与N的关系，如果相等就跳出第一层循环
判断是不是素数要用另一层循环，两层循环的嵌套，
会大量浪费时间，虽然能运行起来但是会导致运行超时
所以考虑把这两层循环分成两个部分，或者只用一层循环
不行，把所有的数过一遍并且判断是不是素数还要过一层循环
可以把里面那层循环求素数的条件改一下 
因为求素数的话,其实就是判断是否能被除了1和自身的其他数整除嘛...

比如100开根号是10
其实你的循环过了10以后,找到的都是重复的数...
比如说你循环到20...100/20=5
其实当你循环到5的时候,就已经能整除了
*/ 
int main(){
	int M,N,i,k;
	int count=0;
	int j=1;
	k=2;
	int w;
	scanf("%d%d",&M,&N);
	//for(i=1;i<=110000;i++){
	//素数的定义一个大于1的自然数，除了1和它本身外，不能被其他自然数整除，所以i从2开始 
	/* 
	for(i=1;;i++){
		//w=sqrt(i);
		if(i==2){
				count++;
			if((count>=M)&&(count<=N)){
				if(j==(M-N+1)){
					printf("%d",i); 
				}else{
					if((j%10)!=0){
						printf("%d",i);
						printf(" ");
						j++;
					}else{
						printf("%d\n",i);
						j++;
					}
				}
			}
		}
	*/
	for(i=2;;i++){
		w=sqrt(i);
		for(k=2;k<=w;k++){
			if(i%k==0) break;
		}
		if(k>w){
			count++;
			if((count>=M)&&(count<=N)){
				
				if(j==(N-M+1)){
					printf("%d",i); 
				}else{
				
					if((j%10)!=0){
						printf("%d",i);
						printf(" ");
						j++;
					}else{
						printf("%d\n",i);
						j++;
					}
				}
			}
		}
		
		if(count>10000) break;
		
	}
	return 0;
} 
