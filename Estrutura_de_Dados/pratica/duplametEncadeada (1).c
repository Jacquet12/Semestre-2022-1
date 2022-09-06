#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dt {
    int dia;
    int mes;
    int ano;
};
//
struct tprod{
    int cod ;
    char nome [20];
    struct dt  dtcompra;
    struct tprod *prev, *next;
};
//
typedef struct tprod prod;

int main (){
    prod entrada;
    prod *p, * aux, *first=NULL, * last=NULL;

    int i;

    for( i=0; i<5; i++) {
        scanf("%d", &entrada.cod);
        scanf("%s", entrada.nome);
        scanf("%d %d %d",&entrada.dtcompra.dia,&entrada.dtcompra.dia,&entrada.dtcompra.ano);
        p=(prod *)malloc(sizeof(prod));
        p->cod=entrada.cod;
        strcpy(p->nome,entrada.nome);
        p->dtcompra=entrada.dtcompra;
        p->next=NULL;
        p->prev=NULL;
        if( first==NULL){
            first=p;
            last=p;
            aux=p;
        }else{
            last->next=p;
            p->prev=last;
            last=p;

        }

    }


    for(aux=first; aux!=NULL; aux=aux->next){
        printf("cod: %d\nNome:%s\nData:%2d/%2d/%2d\n",aux->cod, aux->nome, aux->dtcompra.dia, aux->dtcompra.mes, aux->dtcompra.ano);
    }

    printf("==============================================\n");

    for(aux=last; aux!=NULL; aux=aux->prev){
        printf("cod: %d\nNome:%s\nData:%2d/%2d/%2d\n",aux->cod, aux->nome, aux->dtcompra.dia, aux->dtcompra.mes, aux->dtcompra.ano);
    }

    return 0;
//https://replit.com/login?goto=/join/pavyqfwtak-denioduarte
}