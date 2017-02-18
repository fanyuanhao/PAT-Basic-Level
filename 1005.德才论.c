//这段代码运行超时 

#include <stdio.h>

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
void Insertion_Sort(student *a,int N);
void Mindsort(student *a,int N);

int Pivot;
const int cutoff=100;

int main(){
	int N,L,H,M,i;
	scanf("%d%d%d",&N,&L,&H);
	int count=0;
	
	student a[N];
	
	for(i=0;i<N;i++){
		scanf("%d",&a[i].num);
		scanf("%d",&a[i].mindscore);
		scanf("%d",&a[i].giftscore);
		a[i].sumscore=a[i].giftscore+a[i].mindscore;
	}
	
	for(i=0;i<N;i++){
		if(a[i].giftscore<L||a[i].mindscore<L){
			a[i].num=0;
			count++;
		}
	}
	
	M=N-count;
	printf("%d\n",M);
	
	Quick_Sort(a,N);
	Mindsort(a,N);
	 
	for(i=0;i<N;i++){
		if(a[i].num!=0){		
			if(a[i].giftscore>=H&&a[i].mindscore>=H){
				printf("%d %d %d\n",a[i].num,a[i].mindscore,a[i].giftscore);
			}
		}
	}
	for(i=0;i<N;i++){
		if(a[i].num!=0){
			if(a[i].giftscore<H&&a[i].mindscore>=H){
				printf("%d %d %d\n",a[i].num,a[i].mindscore,a[i].giftscore);
			}
		}
	}
	for(i=0;i<N;i++){
		if(a[i].num!=0){
			if(a[i].giftscore<H&&a[i].mindscore<H){
				if(a[i].mindscore>=a[i].giftscore){
					printf("%d %d %d\n",a[i].num,a[i].mindscore,a[i].giftscore);
				}
			}
		}
	}
	for(i=0;i<N;i++){
		if(a[i].num!=0){
			if(a[i].mindscore<H){
				if(a[i].mindscore<a[i].giftscore){
					printf("%d %d %d\n",a[i].num,a[i].mindscore,a[i].giftscore);
				}
			}
		}
	}
	return 0;
}
void Quick_Sort(student *a,int N)
{
	Quicksort(a,0,N-1);
}
void Quicksort(student *a,int Left,int Right){	
	student Pivot;
	int i,j;
	if(cutoff<=Right-Left){
		Pivot=Median3(a,Left,Right);
		i=Left;
		j=Right-1;
		while(1){
			while(a[++i].sumscore<Pivot.sumscore){
			
			}
			while(a[--j].sumscore>Pivot.sumscore){
				
			}
			if(i<j){
				Swap(&a[i],&a[j]);
			}else{
				break;
			}
		}
		Swap(&a[i],&a[Right-1]);
		Quicksort(a,Left,i-1);
		Quicksort(a,i+1,Right);
	}else{
		Insertion_Sort(a+Left,Right-Left+1);
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

//普通排序 
void Insertion_Sort(student *a,int N){
	int i=0,j=0,max_s,max_m,min_n;
	student *b=a;
	
	//按总成绩排序 
	for(i=0;i<N;i++){
		max_s=i;
		for(j=i;j<N;j++){
			if(b[max_s].sumscore<b[j].sumscore){
				max_s=j;
			}
		}
		if(max_s!=i){
			Swap(&b[i],&b[max_s]);
		}				
	}
	
}
 
