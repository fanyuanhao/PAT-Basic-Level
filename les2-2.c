#include <stdio.h>
#include <stdlib.h>
int main(){
	int *a,count=0;
	while(a=(int*)malloc(100*1024*1024))
	{
		count++;
	}
	free(a);
	printf("%d00MB\n",count);
	return 0;
} 
