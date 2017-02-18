#include <stdio.h>  
  
int main()  
{  
    double a ;  
    int b ;  
    char c ;  
    double d ;  
    scanf("%lf %d %c %lf",&a,&b,&c,&d);  
      
//  printf("%lf %d %c %lf",a,b,'c',d);  
      
    printf("%c %d %.2lf %.2lf",c,b,a,d);  
      
    return 0;  
}  
