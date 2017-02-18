#include <stdio.h>
#include <stdlib.h>
	struct node{
		int num;
		int mindscore;
		int giftscore;
		int sumscore;
	};
int cmp(const void *a,const void *b){
	struct node *pa=(struct node*)a;
	struct node *pb=(struct node*)b;
	if(pa->sumscore!=pb->sumscore){
		return pb->sumscore-pa->sumscore;
	}else if(pa->mindscore!=pb->mindscore){
		return pb->mindscore-pa->mindscore;
	}else{
		return pa->num-pb->num;
	}
}
void print(struct node *A,int a);
int main(){
	int N,L,H;
	scanf("%d%d%d",&N,&L,&H);
	int Num,MindScore,GiftScore;
	
	struct node A[N];
	struct node B[N];
	struct node C[N];
	struct node D[N];
	
	int i=0,a=0,b=0,c=0,d=0;
	for(i=0;i<N;i++){
		scanf("%d%d%d",&Num,&MindScore,&GiftScore);
		if((MindScore<L)||(GiftScore<L)){
			continue;
		}
		if((MindScore>=H)&&(GiftScore>=H)){
			A[a].mindscore=MindScore;
			A[a].giftscore=GiftScore;
			A[a].num=Num;
			A[a].sumscore=MindScore+GiftScore;
			a++;
		}else if((MindScore>=H)&&(GiftScore<H)){
			B[b].mindscore=MindScore;
			B[b].giftscore=GiftScore;
			B[b].num=Num;
			B[b].sumscore=MindScore+GiftScore;
			b++;
		}else if(MindScore>=GiftScore){
			C[c].mindscore=MindScore;
			C[c].giftscore=GiftScore;
			C[c].num=Num;
			C[c].sumscore=MindScore+GiftScore;
			c++;
		}else{
			D[d].mindscore=MindScore;
			D[d].giftscore=GiftScore;
			D[d].num=Num;
			D[d].sumscore=MindScore+GiftScore;
			d++;
		}
	}
	printf("%d\n",a+b+c+d);
	qsort(A,a,sizeof(A[0]),cmp);
	qsort(B,b,sizeof(B[0]),cmp);	
	qsort(C,c,sizeof(C[0]),cmp);
	qsort(D,d,sizeof(D[0]),cmp);
	print(A,a);
	print(B,b);
	print(C,c);
	print(D,d);
	
	return 0;
}
void print(struct node *A,int a){
	int i=0;
	for(i=0;i<a;i++){
		printf("%d %d %d\n",A[i].num,A[i].mindscore,A[i].giftscore);
	}	
}
