#include <stdio.h>
void find_ab(char *s1,char*s2);
void find_cd(char *s1,char*s2); 


char c='\0';
char a[2]={'\0','\0'};
int count1=0,count2=0;
int j=0;

int main(){
	int i=0;
	const int num=70;
	int count=0;
	char str_a[num],str_b[num],str_c[num],str_d[num]; 
	char *day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	
	scanf("%s%s%s%s",str_a,str_b,str_c,str_d);
	find_ab(str_a,str_b);
	find_cd(str_c,str_d);
	int x=a[0]-'A';
	printf("%s ",day[x]);
	if((a[1]>='0')&&(a[1]<='9')){
		printf("0%d:",a[1]-'0');
	}else{
		printf("%d:",a[1]-'A'+10);
	}
	
	
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
	
	for(;*s1!='\0';s1++){
			if(*s1==*s2){
				
				if((*s2 >= 'A' && *s2 <= 'G')){
					a[j]=*s2;
					temp2=s2;
					temp1=s1;//�����ַ���str_a��һ����д��ĸ�ĵ�ַ���ҵڶ�����ʱ�����֮��һλΪ��� 
					
					break;
				}
				s2++;
			}else{
				s2++;
				if(*s2=='\0'){
					break;
				}
			}
		
	}
	//Ѱ�ҵ�һ����ͬ�Ĵ�д��ĸ����ڶ�����ͬ�Ĵ�д��ĸ������
	s2=temp2+1;
	for(s1= temp1+1;*s1!=0;s1++){
	
		if(*s1==*s2){
			if((*s2 >= 'A' && *s2 <= 'N')||(*s2 >= '0' && *s2 <= '9' )){
				j++; 
				a[j]=*s2;
				
				break;
			}
			s2++;
		}else{
			s2++;
			if(*s2=='\0'){
				break;
			}
		}
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
				if((*s2 >= 'a' && *s2 <= 'z') ||(*s2 >= 'A' && *s2 <= 'Z' )){
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
