#include <stdio.h>
struct people{
    char name[10];
    int year;
    int month;
    int day;
}temp,old,young;
int time(int year,int month,int day){
    return (year*10000+month*100+day);
}
int main(){
    int n,count=0;
    scanf("%d",&n);
    old.year=2014,old.month=9,old.day=7;
    young.year=1814,young.month=9,young.day=5;
    int i;
	
	for(i=0;i<n;i++){
        scanf("%s %d/%d/%d",temp.name,&temp.year,&temp.month,&temp.day);
        if(time(temp.year,temp.month,temp.day)>=18140906&&time(temp.year,temp.month,temp.day)<=20140906){
            count++;
            if(time(temp.year,temp.month,temp.day)<time(old.year,old.month,old.day)){
                old=temp;
            }
            if(time(temp.year,temp.month,temp.day)>time(young.year,young.month,young.day)){
                young=temp;
            }
        }
    }
    
    if(count==0){
    	printf("%d",count);
	}else{
    	printf("%d %s %s",count,old.name,young.name);
    	return 0;		
	}

}
