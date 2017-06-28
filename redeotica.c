#include<stdio.h>
#include <stdlib.h>
#define max 100

typedef struct aresta{
	int custo;
	int v1, v2;
}Aresta;

typedef struct item {
  struct item *prox;
}Item; 

int N, M;
Aresta aresta[max * (max-1) /2];
Item *item[max];

void inicializa(){
  register int i;
  
  for(i=0; i<N; i++){
    item[i]=malloc(sizeof(item));
    item[i]->prox=NULL;
  }
}

int main(){
	int X, Y, Z, teste=1;
	register i;
	
	scanf("%d %d", &N, &M);
		
	
	while(N!=0){
		inicializa();
		
		for(i=0;i<M;i++){
			scanf("%d %d %d\n", &X, &Y, &aresta[i].custo);
			if(X<Y){
				aresta[i].v1 = X-1;
				aresta[i].v2 = Y-1;
			}else{
				aresta[i].v1 = Y-1;
				aresta[i].v2 = X-1;
			}
		}
		
	
	
	return 0;
}
