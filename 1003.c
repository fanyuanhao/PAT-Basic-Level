#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 510
#define INFINITY 65535
#define FALSE 0
#define TRUE 1
typedef int VertexType;
typedef int EdgeType;
typedef struct{
	VertexType Vertices[MaxVertexNum];//store the number of rescue teams
	EdgeType Edges[MaxVertexNum][MaxVertexNum];
	int n,e;
}MGraph;
typedef struct{
	int MinPathNum;
	int MaxTeamsNum;
	int isVisited[MaxVertexNum];
}Answer;
void Dijkstra(MGraph *G,int C1,int *D);
void CreateMGraph(MGraph *G);
void dfs(MGraph *G,Answer *A,int start,int C2,int* D,int curdis,int curteams);

int main(){
	int C1,C2;
	MGraph *G;
	Answer *A;
	int *D,*P;
	int i;
	G=(MGraph*)malloc(sizeof(MGraph));
	D=(int*)malloc(sizeof(int)*(G->n));//the distance from C1 to v
	P=(int*)malloc(sizeof(int)*(G->n));//the path from C1 to v
	A=(Answer*)malloc(sizeof(Answer));
	A->MaxTeamsNum=0;
	A->MinPathNum=0;
	for(i=0;i<G->n;i++){
		A->isVisited[i]=FALSE;
	}
	scanf("%d%d%d%d",&G->n,&G->e,&C1,&C2);
	
	CreateMGraph(G);
	
	Dijkstra(G,C1,D);
	
	dfs(G,A,C1,C2,D,0,G->Vertices[C1]);
	
	printf("%d %d",A->MinPathNum,A->MaxTeamsNum);
	return 0;
}
void CreateMGraph(MGraph *G){
	int i,j,k,w;
	//scanf vertices weight
	for(i=0;i<G->n;i++){
		scanf("%d",&(G->Vertices[i]));
	}
	//initialize edges weight
	for(i=0;i<G->n;i++){
		for(j=0;j<G->n;j++){
			G->Edges[i][j]=INFINITY;
		}
	}
	//scanf edges weight
	for(k=0;k<G->e;k++){
		scanf("%d%d%d",&i,&j,&w);
		G->Edges[i][j]=w;
		G->Edges[j][i]=w;
	}
}
void Dijkstra(MGraph *G,int C1,int *D){
	int Final[MaxVertexNum],v,w,i,min;
	
	for(w=0;w<G->n;w++){
		Final[w]=FALSE;
		D[w]=G->Edges[C1][w];
	}
	D[C1]=0;
	Final[C1]=TRUE;
	for(i=1;i<G->n;i++){
		min=INFINITY;
		for(w=0;w<G->n;w++){
			if(!Final[w]){
				if(D[w]<min){//choose the first minimum if equal
					v=w;
					min=D[w];
				}
			}
		}
		if(min<INFINITY){
			Final[v]=TRUE;
		}else{
			return;
		}
		for(w=0;w<G->n;w++){
			if(!Final[w]&&(G->Edges[v][w]+min<D[w])){//if adjoin v,see it if get smaller
					D[w]=min+G->Edges[v][w];
			}
		}
	}
	/*test the function correct or not*/
	/*
	for(i=0;i<G->n;i++){
		printf("%d ",D[i]);
	}
	*/
}
void dfs(MGraph *G,Answer *A,int start,int C2,int* D,int curdis,int curteams){
	int i;
	A->isVisited[start]=TRUE;
	if(start==C2){
		if(curdis==D[C2]){
			A->MinPathNum++;
			if(curteams > A->MaxTeamsNum){//from each path choose the max teams sum
				A->MaxTeamsNum=curteams;
			}
		}
		return;
	}
	if(curdis>D[start]){
		return;
	}
	for(i=0;i<G->n;i++){
		if(D[start]+G->Edges[i][start]==D[i]){
			dfs(G,A,i,C2,D,curdis+G->Edges[i][start],curteams+G->Vertices[i]);
		}
	}
}