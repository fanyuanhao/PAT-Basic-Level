/* 
��δ��������⣺
1��һ���ַ����͵ڶ����ַ���֮���һ����ͬ�Ĵ�д��ĸ�Ǵ�A��G���ڶ��Դ�д��ĸ�Ǵ�A��N�����û�п��ǵ� 
2ÿһ�ԣ�����ĶԲ��������ַ���ͬ������Ԫ�ص��±껹Ҫ��ͬ�����û�п��ǵ� 
*/ 
#include <stdio.h>

void find_ab(char *s1,char*s2);
void find_cd(char *s1,char*s2); 
void SearchDay(void);
void SearchHour(void);

char c='\0';
char a[2]={'\0','\0'};
int count1=0,count2=0;
int j=0;

int main(){
	int i=0;
	const int num=60;
	int count=0;

	//char str_a[],str_b[],str_c[],str_d[];//����ʹ�õ�ʱ����붨�ô�С��������ʹ�� 
	char str_a[num],str_b[num],str_c[num],str_d[num]; 
	//�����һ���ַ��� 
	scanf("%s%s%s%s",str_a,str_b,str_c,str_d);
	//���һ���ַ���ʹ�����printf("%s",str_a);
	find_ab(str_a,str_b);
	find_cd(str_c,str_d);
	//printf("%c",a[0]);�������� 
	//printf("%c",a[1]);
	//SearchDay;��ʹ����û�в���ҲҪ������ 
	//SearchHour;
	SearchDay();
	SearchHour();
	
	if(count1<=9){
		printf("0%d",--count1); 
	}else{
		printf("%d",--count1); 
	}
	
	return 0;
} 
//Ѱ�ҵ�һ����ͬ��д��ĸ��Ѱ�ҵ�һ����ͬ�Ĵ�д��ĸ����ڶ�����ͬ�Ĵ�д��ĸ������ 
void find_ab(char *s1,char*s2){
	//�ҵ�һ����ͬ�Ĵ�д��ĸ 
	char *temp1;
	char *temp2;//�����ַ���str_b�е�һ����ͬ�Ĵ�д��ĸ�ĵ�ַ���ڶ�����д��ĸ����������֮���� 
	
	for(;*s1!=0;s1++){
		char *temp=s2;//Ƕ�׵�ѭ�����һ���Ҫʹ�ڶ����ѭ����ԭֵ 
		for(;*s2!=0;s2++){
			if(*s1==*s2){
				//if((*s2 >= 'a' && *s2 <= 'z') ||(*s2 >= 'A' && *s2 <= 'Z' )){��ĿҪ������Ǵ�д 
				if((*s2 >= 'A' && *s2 <= 'Z')){
					a[j]=*s2;
					temp2=s2;
					temp1=s1;//�����ַ���str_a��һ����д��ĸ�ĵ�ַ���ҵڶ�����ʱ�����֮��һλΪ��� 
					break;
				}
			}
		}
		s2=temp;
		if(a[j]!='\0'){
			break;//��������ѭ�� 
		} 
	}
	//Ѱ�ҵ�һ����ͬ�Ĵ�д��ĸ����ڶ�����ͬ�Ĵ�д��ĸ������
	for(s1= temp1;*s1!=0;s1++){
		char *temp=s2;//Ƕ�׵�ѭ�����һ���Ҫʹ�ڶ����ѭ����ԭֵ 
		for(s2= temp2;*s2!=0;s2++){
			if((*s1==*s2)&&(s2!=temp2)){
				if((*s2 >= 'A' && *s2 <= 'Z')||(*s2 >= '0' && *s2 <= '9' )){
					j++; 
					a[j]=*s2;
					break;
				}
			}
		}
		s2=temp2;
	} 
	
}

//Ѱ�ҵ�������ͬ�ĵ�Сд��ĸ������¼λ�� 
void find_cd(char *s1,char*s2){
	
	
	for(;*s1!=0;s1++){
		char *temp=s2;//Ƕ�׵�ѭ�����һ���Ҫʹ�ڶ����ѭ����ԭֵ 
		count1++;
		count2=0;
		for(;*s2!=0;s2++){
			count2++;
			if((*s1==*s2)&&(count1==count2)){
				//if((*s2 >= 'a' && *s2 <= 'z') ||(*s2 >= 'A' && *s2 <= 'Z' )){��ĿҪ������Ǵ�д 
				
				if((*s2 >= 'a' && *s2 <= 'z')){
					c=*s2;
					break;
				}	
			}			
		}
		if(c!='\0'){//a��Ϊ�� 
			break;
		}
		s2=temp;
	}
}

void SearchDay(void){
	switch(a[0]){
		case'A':{
			printf("MON ");
			break;
		} 
		case'B':{
			printf("TUE ");
			break;
		}
		case'C':{
			printf("WED ");
			break;
		}
		case'D':{
			printf("THU ");
			break;
		}
		case'E':{
			printf("FRI ");
			break;
		}
		case'F':{
			printf("SAT ");
			break;
		}
		case'G':{
			printf("SUN ");
			break;
		}
		default:{
			break;
		}	
	}
}
void SearchHour(void){
	switch(a[1]){
		case'0':{
			printf("00:");
			break;
		}
		case'1':{
			printf("01:");
			break;
		}
		case'2':{
			printf("02:");
			break;
		}
		case'3':{
			printf("03:");
			break;
		}
		case'4':{
			printf("04:");
			break;
		}
		case'5':{
			printf("05:");
			break;
		}
		case'6':{
			printf("06:");
			break;
		}
		case'7':{
			printf("07:");
			break;
		}
		case'8':{
			printf("08:");
			break;
		}
		case'9':{
			printf("09:");
			break;
		}
		case'A':{
			printf("10:");
			break;
		}
		case'B':{
			printf("11:");
			break;
		}
		case'C':{
			printf("12:");
			break;
		}
		case'D':{
			printf("13:");
			break;
		}
		case'E':{
			printf("14:");
			break;
		}
		case'F':{
			printf("15:");
			break;
		}
		case'G':{
			printf("16:");
			break;
		}
		case'H':{
			printf("17:");
			break;
		}
		case'I':{
			printf("18:");
			break;
		}
		case'J':{
			printf("19:");
			break;
		}
		case'K':{
			printf("20:");
			break;
		}
		case'L':{
			printf("21:");
			break;
		}
		case'M':{
			printf("22:");
			break;
		}
		case'N':{
			printf("23:");
			break;
		}
		default:{
			break;
		}
	}
}
