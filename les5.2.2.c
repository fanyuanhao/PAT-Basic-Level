#include <stdio.h>
#include <stdlib.h>

int main(int argc,char const *argv[])
{
    typedef struct _node{
    	int value;
    	struct _node *next;
	}Node;  
	Node *head=NULL;
    int number;
    do{
        scanf("%d",&number);
        if(number != -1){
            //����һ���½��
            Node *p=(Node*)malloc(sizeof(Node));
            p->value=number;
            p->next=NULL;
            //������Ҫ�������ҵ����һ����㣬ʹ�����һ������nextָ��p
            Node *last=head;
            if(last){//last����NULL
                while(last->next){
                last=last->next;
                }
                last->next=p;
            }else{
                head=p;
            }
        }
    }while(number !=-1);
    
	return 0;
}

