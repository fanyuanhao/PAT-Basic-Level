//我不知道这个题为什么N和p都要用long? 
#include <stdio.h>
#include <stdlib.h> 
int cmp(const void *a,const void *b){
  return *(int*)a-*(int*)b;
}
int main(){
  long N,p;
  scanf("%ld",&N);
  scanf("%ld",&p);
  long a[N];
  long m,i,j;//最小值、最大值、m*p的值
  long V;
  int cnt=1;
  
  for(i=0;i<N;i++){
    scanf("%ld",&a[i]);
  }
  
  //对数组从小到大排序
  qsort(a,N,sizeof(a[0]),cmp); 
  
  for(i=0;i<N;i++){
    m=a[i];
    V=m*p; 
    for(j=i+cnt;j<N;j++){
      if(a[j]>V){
        break;
      }
      cnt++;
    }
  }
  printf("%d",cnt);  
  return 0;
}
