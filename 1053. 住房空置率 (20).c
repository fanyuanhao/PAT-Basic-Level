#include <stdio.h>
int main(){
	int N,D,K;
	double e,value;
	double cnt=0.0,cnt1=0.0,cnt2=0.0;//低于e的个数，可能空置的个数，空置的个数 
	scanf("%d%lf%d",&N,&e,&D);
	int i=0,j=0;
	for(i=0;i<N;i++){
		scanf("%d",&K);
		cnt=0;
		for(j=0;j<K;j++){
			scanf("%lf",&value);
			if(value<e){
				cnt++;
			}
		}
		if(cnt>(K/2)){
			cnt1++;
			if(K>D){
				cnt1--;
				cnt2++;
			}
		}
	}
	printf("%.1lf%%",cnt1/N*100);
	printf(" ");
	printf("%.1lf%%",cnt2/N*100);
	return 0;
}
