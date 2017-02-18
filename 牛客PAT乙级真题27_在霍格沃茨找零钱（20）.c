#include <stdio.h>
int main(){
	int PG,PS,PK,AG,AS,AK,BG,BS,BK;
	scanf("%d.%d.%d",&PG,&PS,&PK);
	scanf("%d.%d.%d",&AG,&AS,&AK);
	if((AG>PG)||((AG==PG)&&(AS>PS))||((AG==PG)&&(AS==PS)&&(AK>=PG))){
		if(AK-PK<0){
			BK=AK+29-PK;
			AS--;
		}else{
			BK=AK-PK;
		}
		if(AS-PS<0){
			BS=AS+17-PS;
			AG--;
		}else{
			BS=AS-PS;
		}
		printf("%d.%d.%d",AG-PG,BS,BK);
	}else{
	
		if(AG-PG<0){
			if(PK-AK<0){
				BK=PK+29-AK;
				PS--;
			}else{
				BK=PK-AK;
			}
		
			if(PS-AS<0){
				BS=PS+17-AS;
				PG--;
			}else{
				BS=PS-AS;
			}
			printf("-%d.%d.%d",PG-AG,BS,BK);		
		}

	}
	
	return 0;
}
