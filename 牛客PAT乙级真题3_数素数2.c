#include <stdio.h>
#include <math.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int k, a, b=0 ,i, c[10000];
    for(a = 2; ; a++) {                      //����ǰ10000�������������c������ 
        k=sqrt(a);                           //k����a�Ŀ����� 
        for(i = 2; i <= k; i++) {
            if(a % i == 0)                    
                break;
        }
        if(i>k) {                            //�ж��Ƿ�Ϊ���� 
            c[b]=a;
            b++;
            if(b >= 10000)                   //�������� 
                break;
        }
    }
    int d = 0; 
    for(i = m; i <= n; i++) {
        d++;
        printf("%d", c[i-1]);                //�����i������ 
        if(d % 10 != 0 && i != n) {
            printf(" ");
        }
        else if(d % 10 == 0) {
            printf("\n");
        }
    }
}
