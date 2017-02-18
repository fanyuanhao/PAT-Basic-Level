/* 
这段代码有问题：
1第一个字符串和第二个字符串之间第一对相同的大写字母是从A到G，第二对大写字母是从A到N，这个没有考虑到 
2每一对，这里的对不仅仅是字符相同，数组元素的下标还要相同，这个没有考虑到 
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

	//char str_a[],str_b[],str_c[],str_d[];//数组使用的时候必须定好大小，否则不能使用 
	char str_a[num],str_b[num],str_c[num],str_d[num]; 
	//读入第一个字符串 
	scanf("%s%s%s%s",str_a,str_b,str_c,str_d);
	//输出一个字符串使用语句printf("%s",str_a);
	find_ab(str_a,str_b);
	find_cd(str_c,str_d);
	//printf("%c",a[0]);测试用例 
	//printf("%c",a[1]);
	//SearchDay;即使函数没有参数也要加括号 
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
//寻找第一个相同大写字母和寻找第一个相同的大写字母后面第二个相同的大写字母或数字 
void find_ab(char *s1,char*s2){
	//找第一个相同的大写字母 
	char *temp1;
	char *temp2;//保存字符串str_b中第一个相同的大写字母的地址，第二个大写字母或数字在它之后找 
	
	for(;*s1!=0;s1++){
		char *temp=s2;//嵌套的循环完成一层后要使第二层的循环回原值 
		for(;*s2!=0;s2++){
			if(*s1==*s2){
				//if((*s2 >= 'a' && *s2 <= 'z') ||(*s2 >= 'A' && *s2 <= 'Z' )){题目要求必须是大写 
				if((*s2 >= 'A' && *s2 <= 'Z')){
					a[j]=*s2;
					temp2=s2;
					temp1=s1;//保存字符串str_a第一个大写字母的地址，找第二个的时候从它之后一位为起点 
					break;
				}
			}
		}
		s2=temp;
		if(a[j]!='\0'){
			break;//跳出两层循环 
		} 
	}
	//寻找第一个相同的大写字母后面第二个相同的大写字母或数字
	for(s1= temp1;*s1!=0;s1++){
		char *temp=s2;//嵌套的循环完成一层后要使第二层的循环回原值 
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

//寻找第三个相同的的小写字母，并记录位置 
void find_cd(char *s1,char*s2){
	
	
	for(;*s1!=0;s1++){
		char *temp=s2;//嵌套的循环完成一层后要使第二层的循环回原值 
		count1++;
		count2=0;
		for(;*s2!=0;s2++){
			count2++;
			if((*s1==*s2)&&(count1==count2)){
				//if((*s2 >= 'a' && *s2 <= 'z') ||(*s2 >= 'A' && *s2 <= 'Z' )){题目要求必须是大写 
				
				if((*s2 >= 'a' && *s2 <= 'z')){
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
