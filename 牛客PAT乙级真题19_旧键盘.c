#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	
	char a[80],b[80],c[80];
	char *str1,*str2;
	typedef struct node{
		char value;
		struct node *next;
	}Node;//定义单链表结点类型 
	
	Node *head=NULL;
	Node *last=NULL;
	
	scanf("%s",a);
	scanf("%s",b);
	
	int i,j=0,len1,len2,count=0;
	len1=strlen(a);
	len2=strlen(b);
	
	/*
	printf("%s",a);
	for(i=0;i<len1;i++){
		printf("%c",a[i]);
	}
	*/
	
	//找到缺损的符号 
	for(i=0;i<len1;i++){
		if(a[i]!=b[j]){
			c[count]=a[i];
			count++;
		}
		if(a[i]==b[j]){
			j++;
		}
	}
	
	
	//如果符号是小写转变成大写
	for(i=0;i<count;i++){
		if(c[i]>='a'&&c[i]<='z'){
			c[i]-=32;
		}
	}
	/*
	测试读入是否正确 
	for(i=0;i<count;i++){
		printf("%c",c[i]);
	}
	*/
	
	
	//把数组的元素存到链表中 
	for(i=0;i<count;i++){
		Node *p=(Node*)malloc(sizeof(Node));
		p->value=c[i];
		p->next=NULL;
		last=head; 
		if(last){//如果last非空 
			while(last->next){//因为每次循环last都要重置为head,所以要找到last->next为空的点 
				last=last->next;
			}
			last->next=p;
			last=p;
		}else{
			head=p;//这样就把p的值存给了head 
		}	
	}
	Node *r,*s,*temp;
	/*
	测试数组存入链表是否正确 
	for(r=head;r->next!=NULL;r=r->next){
		printf("%c",r->value);
	}
	*/
	
	//删掉链表中相同的元素 
	for(r=head;r!=NULL;r=r->next){
		for(s=r;s->next!=NULL;){
			if(r->value==s->next->value){			
				temp=s->next;
				s->next=temp->next;
				free(temp);
			}else{
				s=s->next;
			}	
		}
	}
	
	for(r=head;r!=NULL;r=r->next){
		printf("%c",r->value);
	}
	
	return 0;
}
