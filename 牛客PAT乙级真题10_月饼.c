#include <stdio.h>
#include <stdlib.h>
 
int N,D;
	typedef struct node{
		double store;//�����ܲ����������ܲ������� 
		double Tprice;
		double Uprice;
	} Good;
	Good a[1005];
/*
int cmp(const void *a,const void *b){
	Good i=*(Good*)a;
	Good j=*(Good*)b;
	if(i.Uprice>j.Uprice){
		return 1;
	}esle{
		return -1;
	}
	
}
*/
int main(){
	
	scanf("%d%d",&N,&D);
	
	int i=0,j=0;
	int temp1;
	double temp2,temp3;
	int last=0;
	double profit=0;
	
	for(i=0;i<N;i++){
		scanf("%lf",&a[i].store);
	}
	for(i=0;i<N;i++){
		scanf("%lf",&a[i].Tprice);
	}
	for(i=0;i<N;i++){
		a[i].Uprice=a[i].Tprice/a[i].store;
	}
	/*
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
	}
	*/
	
	//���ÿ�����������Ŀǰ���ǲ�̫�� 
	//qsort(a,N,sizeof(a[0]),cmp); 
	/*
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n"); 
	}
	*/ 
	/* 
	//�����۴Ӵ�С����ð������ 
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(a[j].Uprice<a[j+1].Uprice){
				temp1=a[j].store;
				temp2=a[j].Tprice;
				temp3=a[j].Uprice;
				
				a[j].store=a[j+1].store;
				a[j].Tprice=a[j+1].Tprice;
				a[j].Uprice=a[j+1].Uprice;
				
				a[j+1].store=temp1;
				a[j+1].Tprice=temp2;
				a[j+1].Uprice=temp3;
			}
		}
	}
	
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n"); 
	}
	*/
	/*
	ѡ������1 
	for(i=0;i<N-1;i++){
		for(j=i;j<N;j++){
			if(a[i].Uprice<a[j].Uprice){//��i=0ʱ��ֻҪ�Ǳ�i=0λ���ϴ��ֵ����������ֱ���������ġ���ʼ���յ���i=0���λ�� 
				temp1=a[i].store;
				temp2=a[i].Tprice;
				temp3=a[i].Uprice;
				
				a[i].store=a[j].store;
				a[i].Tprice=a[j].Tprice;
				a[i].Uprice=a[j].Uprice;
				
				a[j].store=temp1;
				a[j].Tprice=temp2;
				a[j].Uprice=temp3;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n");
	}
	*/
	//ѡ������2 
	int max=0;
	for(i=0;i<N-1;i++){
		max=i;
		for(j=i;j<N;j++){
			if(a[max].Uprice<a[j].Uprice){// 
				max=j;
			}
		}
		if(max!=i){
			temp1=a[max].store;
			temp2=a[max].Tprice;
			temp3=a[max].Uprice;
				
			a[max].store=a[i].store;
			a[max].Tprice=a[i].Tprice;
			a[max].Uprice=a[i].Uprice;
				
			a[i].store=temp1;
			a[i].Tprice=temp2;
			a[i].Uprice=temp3;	
		}
	}
	 
	/*
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n");
	}
	*/ 
	
	
	last=D;
	for(i=0;last>0&&i<N;i++){
		if(a[i].store>last){
			profit+=last*a[i].Uprice;
		}else{
			profit+=a[i].Tprice;
		}
		last=last-a[i].store;
	}
	printf("%.2lf",profit);
	
	
	
	/* 
	for(i=0;i<N;i++){//�ҵ�����Ʒ��>D 
		sum+=a[i].store;//�Ϲ�Ķ����Ŀ��
		
		if(sum<=D){//����Ϲ�Ŀ�治������ʱ
			profit+=a[i].Tprice;//����
			surplus=D-sum;//��������Ĳ�ֵ
		}
        if(sum>D&&(i==0)){//���i=0ʱ�Ŀ�����������
			printf("%.2lf",a[i].Uprice*D);
            break;
		}
        if(sum>D&&(i!=0)){//��ĳ��ֵʱ�Ϲ�Ŀ������������
			printf("%.2lf",profit+a[i].Uprice*surplus);
			break;
		}
	}//������п��ʼ�ղ���������
	if(sum<=D){
		printf("%.2lf",profit);
	}
	*/ 
	return 0;
} 
