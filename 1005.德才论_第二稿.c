//答案错误运行超时，自己写的快速排序函数不对 
#include <stdio.h>
#define cutoff 8 
//结构体要写在外面 
typedef struct node{
		int num;
		int mindscore;
		int giftscore;
		int sumscore;
} student;

void Quick_Sort(student *a,int N);
void Quicksort(student *a,int Left,int Right);
student Median3(student *a,int Left,int Right);
void Swap(student *a,student *b);
//void Insertion_Sort(student *a,int N);
//void Mindsort(student *a,int N);
void Print(student *a,int size);
void Selection_Sort(student *a,int Left,int Right);

int Pivot;

int main(){
	int N,L,H,M,i;
	scanf("%d%d%d",&N,&L,&H);
	int count=0;
	//先分类在读入数据 
	student A[N],B[N],C[N],D[N];
	int a=0,b=0,c=0,d=0;//这是数组下标 
	int mindscore,giftscore,num;
	 
	for(i=0;i<N;i++){
		scanf("%d",&num);
		scanf("%d",&mindscore);
		scanf("%d",&giftscore);
		if(mindscore>=H&&giftscore>=H){
			A[a].num=num;
			A[a].mindscore=mindscore;
			A[a].giftscore=giftscore;
			A[a].sumscore =mindscore+giftscore;
			a++;
		}else if(mindscore>=H&&giftscore<H){
			B[b].num=num;
			B[b].mindscore=mindscore;
			B[b].giftscore=giftscore;
			B[b].sumscore =mindscore+giftscore;
			b++;			
		}else if(mindscore<H&&mindscore>mindscore){
			C[c].num=num;
			C[c].mindscore=mindscore;
			C[c].giftscore=giftscore;
			C[c].sumscore =mindscore+giftscore;
			c++;			
		}else if(mindscore>L&&giftscore>L){
			D[d].num=num;
			D[d].mindscore=mindscore;
			D[d].giftscore=giftscore;
			D[d].sumscore =mindscore+giftscore;
			d++;			
		}
	}
	for(i=0;i<a;i++){
		printf("%d\n",A[i].num);
	}
	
	M=a+b+c+d;
	printf("%d\n",M);
	
	Quick_Sort(A,a);
	Quick_Sort(B,b);
	Quick_Sort(C,c);
	Quick_Sort(D,d);
	
	Print(A,a);
	Print(B,b);	
	Print(C,c);
	Print(D,d);

	return 0;
}
void Print(student *a,int size){
	student *p;
	for(p=a;p<a+size;p++){
		printf("%d %d %d\n",a->num,a->mindscore,a->giftscore);
	}
}

void Quick_Sort(student *a,int N)
{
	Quicksort(a,0,N-1);
}
void Quicksort(student *a,int Left,int Right){	
	if(Right-Left<=cutoff){
		Selection_Sort(a,Left,Right);
	}else{
		student Pivot;
		int i,j;
		if(Right-Left<=2)
		Pivot=Median3(a,Left,Right);
		i=Left+1;
		j=Right-2;
		while(1){
			while((i<j)&&(a[i].sumscore>Pivot.sumscore)){i++;}
			while((i<j)&&(a[j].sumscore<Pivot.sumscore)){j--;}	
			if(i<j){
				Swap(&a[i],&a[j]);
			}else{
				break;
			}		
		}
		Swap(&a[i],&a[Right-1]);
		Quicksort(a,Left,i-1);
		Quicksort(a,i+1,Right);		
	}
}

student Median3(student *a,int Left,int Right){
	int Center=(Left+Right)/2;
	if(a[Left].sumscore > a[Center].sumscore){
		Swap(&a[Left],&a[Center]);
	}
	if(a[Left].sumscore > a[Right].sumscore){
		Swap(&a[Left],&a[Right]);
	}
	if(a[Center].sumscore > a[Right].sumscore){
		Swap(&a[Center],&a[Right]);
	}
	Swap(&a[Center],&a[Right-1]);
	return a[Right-1];
}

void Swap(student *a,student *b){
	student temp1,temp2,temp3,temp4;
	temp1.num=a->num;//要写成temp.num的形式 
	temp2.mindscore=a->mindscore;
	temp3.giftscore=a->giftscore;
	temp4.sumscore=a->sumscore;
			
	a->num=b->num;
	a->mindscore=b->mindscore;
	a->giftscore=b->giftscore;
	a->sumscore=b->sumscore;
			
	b->num=temp1.num;
	b->mindscore=temp2.mindscore;
	b->giftscore=temp3.giftscore;
	b->sumscore=temp4.sumscore;
}

//数组的选择排序算法 
void Selection_Sort(student *a,int Left,int Right){
	int i=Right;
	int j=Left;
	
	for(;i>Left;i--){
		int min=i;		
		for(j=Left;j<i;j++){//j不能小于Right而是要<i,找i之前有没有比min小的值 
			if(a[j].sumscore<min){
				min=j;
			}
		}
		if(i!=min){
			Swap(&a[i],&a[min]);
		}
	}
}


/*
void Mindsort(student *a,int N){
	int i=0,j=0,max_s,max_m,min_n;
	student *b=a;	
	
	//总分相同按德分排序,德分相同按学号排序 
	for(i=0;i<N;i++){
		max_m=i;
		min_n=i;
		for(j=i;j<N;j++){
			if(b[i].sumscore==b[j].sumscore){
				if(b[i].mindscore<b[j].mindscore){
					max_m=j;
				}
				if(b[i].mindscore==b[j].mindscore){
					if(a[i].num>a[j].num){
						min_n=j;
					}
				} 
				if(max_m!=i){
					Swap(&b[i],&b[max_m]); 
				}
				if(min_n!=j){
					Swap(&b[i],&b[min_n]);
				}
			}
		}
	}
}

*/
/*
	while(1){
		if(a[i].sumscore!=Pivot.sumscore&&a[j].sumscore!=Pivot.sumscore){
			while(a[i].sumscore>Pivot.sumscore){i++;}
			while(a[j].sumscore<Pivot.sumscore){j--;}				
		}else{
			if(a[i].mindscore!=Pivot.mindscore&&a[j].mindscore!=Pivot.mindscore){
				if(a[i].sumscore==Pivot.sumscore){
					if(a[i].mindscore>Pivot.mindscore){i++;}else{
						Swap(&a[i],&Pivot);
					}
				}
				if(a[j].sumscore==Pivot.sumscore){
					if(a[j].mindscore<Pivot.mindscore){j--;}else{
						Swap(&a[j],&Pivot);
					}
				}				
			}else{
				if(a[i].mindscore==Pivot.mindscore){
					if(a[i].num<Pivot.num){i++;}else{
						Swap(&a[i],&Pivot);
					}
				}
				if(a[j].mindscore==Pivot.mindscore){
					if(a[j].num>Pivot.num){j--;}else{
						Swap(&a[j],&Pivot);
					}
				}				
			}
		}
*/
