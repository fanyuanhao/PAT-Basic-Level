#include "stdio.h"
#include "string.h"
int main()
{char a[80],b[80];
    scanf("%s",a);
    scanf("%s",b);
    int i,j;
    for(i=0;i<strlen(a);i++)
        for(j=0;j<strlen(b);j++)
        {if(a[i]==b[j])
            a[i]='+';
         
        }
     
    for(i=0;i<strlen(a);i++)
    if(a[i]>=97&&a[i]<=122)
        a[i]=a[i]-32;
     
    for(i=0;i<strlen(a);i++)
    {for(j=i+1;j<strlen(a);j++)
    {if(a[i]==a[j])
         a[j]='+';}
    }
    for(i=0;i<strlen(a);i++)
        if(a[i]!='+')
            printf("%c",a[i]);
    return 0;
}
