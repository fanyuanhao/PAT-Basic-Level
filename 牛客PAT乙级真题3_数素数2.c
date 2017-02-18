#include <stdio.h>
#include <math.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int k, a, b=0 ,i, c[10000];
    for(a = 2; ; a++) {                      //先求前10000个素数并存放在c数组中 
        k=sqrt(a);                           //k等于a的开根号 
        for(i = 2; i <= k; i++) {
            if(a % i == 0)                    
                break;
        }
        if(i>k) {                            //判断是否为素数 
            c[b]=a;
            b++;
            if(b >= 10000)                   //结束条件 
                break;
        }
    }
    int d = 0; 
    for(i = m; i <= n; i++) {
        d++;
        printf("%d", c[i-1]);                //输出第i个素数 
        if(d % 10 != 0 && i != n) {
            printf(" ");
        }
        else if(d % 10 == 0) {
            printf("\n");
        }
    }
}
