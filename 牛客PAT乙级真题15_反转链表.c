#include <stdio.h>
int main(){
	
	int amount,K,add;
	scanf("%d%d%d",&amount,&N,&K);
	
	struct node{
		int Data;
		int Next;
		int Num;
	};
	
	struct node a[100000];
	
	int i=0;
	for(i=0;i<10000;i++){
		a[i].Data=100000;
		a[i].Next=100000;
		a[i].Num=100000;
	}
	
	int address,data,next;//用于临时存储的一个变量 
	
	for(i=0;i<amount;i++){
		scanf("%d%d%d",&address,&data,&next);
		a[address].Data=data;
		a[address].Next=next;
	}
	
	//串起来的链表 
	struct Node{
		int ADD;
		int DATA;
		int NEXT;
	};
	struct Node b[amount+1];
	
	for(i=1;i<=amount;i++){
		a[add].Num=i;
		b[i].ADD=add;
		b[i].DATA=a[add].Data;
		b[i].NEXT=a[add].Next;
		add=a[add].Next;
	}
	
	int cnt=0;
	int n=0,remainder=0;
	
	n=amount/K;
	remainder=amount%K;
	
	
		
	return 0;
} 
