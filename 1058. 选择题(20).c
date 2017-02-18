#include <stdio.h>
#include <stdlib.h>
#define MaxOptionN 5
#define MaxMC 100
typedef struct{
	int score;
	int OptionNum;
	int ROptionN;
	char ROption[MaxOptionN];
}Subject;
typedef struct{
	int SelectOptionN;
	char SelectOption[MaxOptionN];
}Answer;
typedef struct{
	Answer answer[MaxMC];
	int defen;
}Student;
void InputData(Student *student,Subject* subject,int N,int M);
int main(){
	int N,M;
	int i;
	Subject *subject;
	Student *student;
	scanf("%d%d",&N,&M);
	subject=(Subject*)malloc(sizeof(Subject)*M);
	student=(Student*)malloc(sizeof(Student)*N);
	InputData(student,subject,N,M);
	for(i=0;i<N;i++){
		printf("%d\n",student[i].defen);
	}
	
	return 0;
}
void InputData(Student *student,Subject* subject,int N,int M){
	int i,j,k;
	int temp,tempk;
	for(i=0;i<M;i++){
		scanf("%d %d %d",&(subject[i].score),&subject[i].OptionNum,&subject[i].ROptionN);
		for(j=0;j<subject[i].ROptionN;j++){
			scanf("%c",subject[i].ROption[j]);
		}
		subject[i].ROption[j]='\0';
	}
	for(i=0;i<N;i++){
		student[i].defen=0;
		for(j=0;j<M;j++){
			getchar();
			scanf("%d",&temp);
			student[i].answer[j].SelectOptionN=temp;
			for(k=0;k<student[i].answer[j].SelectOptionN;k++){
				scanf("%d",&student[i].answer[j].SelectOption[k]);
			}
			tempk=k;
			k=0;
			if(temp==subject[j].ROptionN){
				while(student[i].answer[j].SelectOption[k]==subject[j].ROption[k]){
					k++;
				}
				if(k==tempk){
					student[i].defen+=subject[j].score;
				}
			}
			getchar();
		}
	}
}
