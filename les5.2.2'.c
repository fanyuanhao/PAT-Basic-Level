#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
        int value;
        struct _node *next;
    }Node;
    
typedef struct _list{
        Node* head;
}List;

void add(List* pList,int nember);
void print(List* pList);
void find(List* pList);
void delete(List* pList);
void clear(List* pList);

int main(int argc,char const *argv[])
{ 
    List list;
    int number;
    list.head=NULL;
    do{
        scanf("%d",&number);
        if(number != -1){
            add(&list,number);    
        }
    }while(number !=-1);
	print(&list);
	find(&list);
	delete(&list);
	print(&list);
	clear(&list);
    return 0;
}

void add(List* pList,int number)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;
    //接下来要做的是找到最后一个结点，使得最后一个结点的next指向p
    Node *last=pList->head;
    if(last){//last不是NULL
        while(last->next){
            last=last->next;
        }
        last->next=p;
    }else{
        pList->head=p;
    }
}

void print(List* pList)
{
	Node *p;
	for(p=pList->head;p;p=p->next){
		printf("%d\t",p->value);
	}
	printf("\n");
}

void find(List* pList){
	int number;
    scanf("%d",&number);
    Node *p;
    int IsFound=0;
    for(p=pList->head;p;p=p->next){
        if(p->value == number){
            printf("找到了\n");
            IsFound=1;
            break;
        }
    }
    if( !IsFound ){
        printf("没找到");
    }
    
}

void delete(List* pList)
{
    int number;
    scanf("%d",&number);
	Node *q,*p;
    for (q=NULL,p=pList->head;p;q=p,p=p->next){
        if(p->value==number){
            if(q){
                q->next=p->next;
            }else{
                pList->head=p->next;
            }
            free(p);
            break;
        }
    }
}
void clear(List* pList){
	Node *q,*p;
	for(p=pList->head;p;p=q){
    q=p->next;
    free(p);
	}
}
