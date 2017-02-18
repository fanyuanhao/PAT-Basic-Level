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
//寻找第一个相同大写字母和寻找第一个相同的大写字母后面第二个相同的大写字母或数字 
void find_ab(char *s1,char*s2){
	//找第一个相同的大写字母 
	char *temp1;
	char *temp2;//保存字符串str_b中第一个相同的大写字母的地址，第二个大写字母或数字在它之后找 
	
	for(;*s1!='\0';s1++){
			if(*s1==*s2){
				
				if((*s2 >= 'A' && *s2 <= 'G')){
					a[j]=*s2;
					temp2=s2;
					temp1=s1;//保存字符串str_a第一个大写字母的地址，找第二个的时候从它之后一位为起点 
					
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
	//寻找第一个相同的大写字母后面第二个相同的大写字母或数字
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

//寻找第三个相同的的小写字母，并记录位置 
void find_cd(char *s1,char*s2){
	
	for(;*s1!=0;s1++){
		char *temp=s2;//嵌套的循环完成一层后要使第二层的循环回原值 
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
		if(c!='\0'){//a不为空 
			break;
		}
		s2=temp;
	}
}
