#include <stdio.h>
void PrintN(int N){
 	if(N!=0){
 		PrintN(N-1);
 		printf("%d\n",N);
	 }
	 return;
 }
 int main(){
	int i=0;
	PrintN(3);
 	return 0;
 }
 
