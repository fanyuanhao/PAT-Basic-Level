#include <stdio.h>
#include <math.h>
//��������������ȡ�࣬������ɸ�λ����Ȼ����ĳ����ͬ������¼���� 
int find(int A,int DA);

int main(){
	
	int A,B,DA,DB,PA,PB;
	
	
	scanf("%d%d%d%d",&A,&DA,&B,&DB);
	PA=find(A,DA);
	PB=find(B,DB);
	printf("%d",PA+PB);
	return 0;
} 
int find(int A,int DA){
	//����������ҲҪ��ʱ�����Ҫ����ȫ�ֱ���������Ķ�ε��øú��������� 
	int count=0;
	int i;
	int sum=0;
	int a=0;//���ABȡ���ֵ
	for(i=0;A!=0;i++){
		a=A%10; 
		if(a==DA){
			count++;
		}
		A=A/10;
		
	}	
	
	for(--count;count!=-1;count--){
		sum+=pow(10,count)*DA;
		//printf("%d\n",sum);�����õ� 
	}
	return sum;
}
