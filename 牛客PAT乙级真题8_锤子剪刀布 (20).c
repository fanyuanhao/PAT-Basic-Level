#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	getchar();
	int i=0;
	int countA=0;
	int countB=0;
	int countAB=0,countAJ=0,countAC=0,countBB=0,countBJ=0,countBC=0;
	char A[N],B[N];
	for(i=0;i<N;i++){
		scanf("%c",&A[i]);
		getchar();//清除空格,%d不需要清除但%c必须清除 
		scanf("%c",&B[i]);
		getchar();//清除换行 
	}
	/* 
	for(i=0;i<N;i++){
		printf("%c ",A[i]);
		printf("%c\n",B[i]);
	}
	*/ 
	
	for(i=0;i<N;i++){
		if(A[i]=='B'){
			if(B[i]=='C'){
				countA++;
				countAB++;
			}
			if(B[i]=='J'){
				countB++;
				countBJ++;
			}
		}
		if(A[i]=='J'){
			if(B[i]=='B'){
				countA++;
				countAJ++;
			}
			if(B[i]=='C'){
				countB++;
				countBC++;
			}
		}
		if(A[i]=='C'){
			if(B[i]=='J'){
				countA++;
				countAC++;
			}
			if(B[i]=='B'){
				countB++;
				countBB++;
			}
		}
		
	}
	
	//输出甲、乙胜平负的次数
	printf("%d %d %d\n",countA,N-countA-countB,countB);
	printf("%d %d %d\n",countB,N-countA-countB,countA);
	
	//判断甲乙获胜次数最多的手势 
	if(countAB>=countAJ){
		if(countAJ>=countAC){
			printf("B ");
		}
		if(countAJ<countAC){
			if(countAB>=countAC){
				printf("B ");
			}
			if(countAB<countAC){
				printf("C ");
			}
		}
	}
	if(countAB<countAJ){
		if(countAJ<=countAC){
			printf("C ");
		}else{
			printf("J ");
		}
		
		
	}
	if(countBB>=countBJ){
		if(countBJ>=countBC){
			printf("B");
		}
		if(countBJ<countBC){
			if(countBB>=countBC){
				printf("B");
			}
			if(countBB<countBC){
				printf("C");
			}
		}
	}
	if(countBB<countBJ){
		if(countBJ<=countBC){
			printf("C");
		}else{
			printf("J");
		}
		
	}
		
	return 0;
} 
