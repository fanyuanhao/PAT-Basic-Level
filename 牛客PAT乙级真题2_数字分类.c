#include <stdio.h>
#include <math.h>
int main(){
	int N;
	int i=0;
	int A1=0,A2=0,A3=0,A5=0;
	double A4=0.0;
	
	int k=0;
	int j=0;
	double w=0.0;
	double sum=0.0;
	int max=0;
	
	scanf("%d",&N);
	int a[N];
	for(;i<N;i++){
		scanf("%d",&a[i]);
		if((a[i]%5==0) && (a[i]%2==0)){
			A1+=a[i];
		}
		if(a[i]%5==1){
			A2+=pow(-1,k)*a[i];//+=��ָ���� 
			k++;
		}
		if(a[i]%5==2){
			j++;
		}
		if(a[i]%5==3){
			w++;
			sum+=a[i];
		}
		if(a[i]%5==4){
			if(a[i]>max){
				max=a[i];
			}
		}
	}
	

	A3=j;
	if(w!=0){//������ʲô�ط�ʹ�ó�����ʱ�򣬶�Ҫ���ǵ��������ܵ���0 
		A4=(sum/w);//sum��w�������͵Ļ���A4�õ��Ľ��ȥ�������õ�һ������ 
	}
	
	A5=max;
	if(A1==0){
		printf("N ");
	}else{
		printf("%d ",A1);
	}
	if(A2==0&&k==0){//��Ŀ��û��˵����������ͬ���֣����Ե���5ȡ�࣬����Ϊ1��ֵ������ͬ������A2����0�����Ի�Ҫȷ��k==0 
		printf("N ");
	}else{
		printf("%d ",A2);
	}
	if(A3==0){
		printf("N ");
	}else{
		printf("%d ",A3);
	}
	if(A4>0.000000001){
		printf("%.1lf ",A4);
	}else{
		printf("N ");
	}
	if(A5==0){
		printf("N");//ע�����Ҫ��û�пո� 
	}else{
		printf("%d",A5);
	}
	
	return 0;
} 
