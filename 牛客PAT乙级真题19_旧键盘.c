#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	
	char a[80],b[80],c[80];
	char *str1,*str2;
	typedef struct node{
		char value;
		struct node *next;
	}Node;//���嵥���������� 
	
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
	
	//�ҵ�ȱ��ķ��� 
	for(i=0;i<len1;i++){
		if(a[i]!=b[j]){
			c[count]=a[i];
			count++;
		}
		if(a[i]==b[j]){
			j++;
		}
	}
	
	
	//���������Сдת��ɴ�д
	for(i=0;i<count;i++){
		if(c[i]>='a'&&c[i]<='z'){
			c[i]-=32;
		}
	}
	/*
	���Զ����Ƿ���ȷ 
	for(i=0;i<count;i++){
		printf("%c",c[i]);
	}
	*/
	
	
	//�������Ԫ�ش浽������ 
	for(i=0;i<count;i++){
		Node *p=(Node*)malloc(sizeof(Node));
		p->value=c[i];
		p->next=NULL;
		last=head; 
		if(last){//���last�ǿ� 
			while(last->next){//��Ϊÿ��ѭ��last��Ҫ����Ϊhead,����Ҫ�ҵ�last->nextΪ�յĵ� 
				last=last->next;
			}
			last->next=p;
			last=p;
		}else{
			head=p;//�����Ͱ�p��ֵ�����head 
		}	
	}
	Node *r,*s,*temp;
	/*
	����������������Ƿ���ȷ 
	for(r=head;r->next!=NULL;r=r->next){
		printf("%c",r->value);
	}
	*/
	
	//ɾ����������ͬ��Ԫ�� 
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
