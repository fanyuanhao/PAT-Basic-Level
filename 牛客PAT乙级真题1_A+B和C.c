#include <stdio.h>
int main(){
    //int T,A,B,C,i;ABC��ֵ��-2��31�η���2��31�η�֮���ֵ�����Բ�����int������ 
    int T,i;
	long A,B,C; 
	scanf("%d",&T);
     
    for(i=1;i<=T;i++){//T��������� 
        scanf("%ld%ld%ld",&A,&B,&C);
        if((A+B)>C){
            printf("Case #%ld: true\n",i);//ע����%d���������true���ʵ�д�� 
        }else{
            printf("Case #%ld: false\n",i);
        }
    }

    return 0;
}
