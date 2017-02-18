#include <stdio.h>
 
int main()
{
    int arr[101];
    int input[101];
    int i,k;
    for(i=2;i<101;i++)
        arr[i]=0;
    scanf("%d",&k);
    for(i=0;i<k;i++)
        scanf("%d",&input[i]);
 
     int j;
     ///sort the input data
    for(i=k;i>0;i--){
        for(j=0;j<i-1;j++){
            if(input[j]>input[j+1]){
                int temp=input[j+1];
                input[j+1]=input[j];
                input[j]=temp;
            }
        }
    }
 
    for(i=k-1;i>=0;i--){
        int t=input[i];
        if(t%2==0){
            t=t/2;
        }else{
            t=(3*t+1)/2;
        }
        while(t>1){
            if(t>1&&t<=100){
                if(arr[t]){
                    break;
                }else{
                    arr[t]=1;
                }
            }
              if(t%2==0){
                  t=t/2;
              }else{
                  t=(3*t+1)/2;
              }
        }
    }
 
    for(i=k-1;i>=0;i--){
        if(arr[input[i]]==0){
            break;
        }
    }
    printf("%d",input[i]);
    for(i--;i>=0;i--){
        if(arr[input[i]]==0){
            printf(" %d",input[i]);
        }
    }
 
    return 0;
}
