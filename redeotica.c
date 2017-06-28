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

int N, M, tamanhoArv=0;
Aresta aresta[max * (max-1) /2];
Item *item[max];

void inicializa(){
  register int i;
  
  for(i=0; i<N; i++){
    item[i]=malloc(sizeof(item));
    item[i]->prox=NULL;
  }
}

int compara(Aresta *a1, Aresta *a2){
	if(a1->custo > a2->custo)
		return 1;
	else if(a1->custo == a2->custo)
		return 0;
	else
		return -1;
}

int iguais(int v1, int v2){
	Item *iv1, *iv2;
	
	for(iv1=item[v1]; iv1->prox!=NULL; iv1=iv1->prox);
	for(iv2=item[v2]; iv2->prox!=NULL; iv2=iv2->prox);
	
	item[v1]=iv1;
	item[v2]=iv2;
	
	return (iv1==iv2 && iv1!=NULL);
	
}

void une(int v1, int v2){
  Item *i;

  i=malloc(sizeof(Item));
  i->prox=NULL;
  item[v1]->prox=i;
  item[v2]->prox=i;
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
	
	qsort(aresta, M, sizeof(Aresta), (void*) compara);
	
	
	for(i=0; tamanhoArv<N-1; i++){
		if(!iguais(aresta[i].v1, aresta[i].v2)){
			printf("%d %d\n", aresta[i].v1+1, aresta[i].v2+1);
			une(aresta[i].v1, aresta[i].v2);
			tamanhoArv++;
		}
		
	
	}
	
	printf("\n");
    scanf("%d %d\n", &N, &N);
	
}
		
	
	
	return 0;
}
