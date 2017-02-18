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
            //增加一个新结点
            Node *p=(Node*)malloc(sizeof(Node));
            p->value=number;
            p->next=NULL;
            //接下来要做的是找到最后一个结点，使得最后一个结点的next指向p
            Node *last=head;
            if(last){//last不是NULL
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

