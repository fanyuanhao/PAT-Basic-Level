#include <stdio.h>
 
int main()
{
    int n,i;
    scanf("%d",&n);
	int a[3]; 
	for(i=0;i<3;i++){
		a[i]=n%10;
		n=n/10;
	} 
	for(i=0;i<a[2];i++)
        printf("B");
    for(i=0;i<a[1];i++)
        printf("S");
    for(i=1;i<=a[0];i++)
        printf("%d",i);
    return 0;
}
