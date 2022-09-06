#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

struct lista
{
    char matricula[20];
    char nome[40];
    Data nascimento;
    float media;
    struct lista *next;
};
typedef struct lista Lista;

// inserir dados na lista
Lista *inserirDados(Lista *first)
{   
Lista *Dado, *aux;

    Dado = (Lista *)malloc(sizeof(Lista));

    scanf("%s", Dado->matricula);
    scanf("%s", Dado->nome);
    scanf("%d %d %d", &Dado->nascimento.dia, &Dado->nascimento.mes, &Dado->nascimento.ano);
    scanf("%f", &Dado->media);
    Dado->next = NULL;

    if (first == NULL)
    {
        first = Dado; aux = Dado;
    }
    else
    {
        
         Dado->next = first;
         first = Dado;
         aux = Dado;
    }

}

// remover elemento da lista
Lista *remover( Lista *first, char matri[20])
{
    Lista *aux, *anterior = NULL;
    aux = first;

    while(aux != NULL){
        if((strcmp(aux ->matricula, matri)) == 0 ){
            if ( aux == first){
                first= aux ->next;
            }
            else{

                anterior->next = anterior->next->next;

            }
            free(aux);
        }
        anterior = aux;

        aux = aux ->next;
    }
    return first;

}


int conta(Lista *first)
{
    int contador = 0;
    Lista *aux;

    for(aux = first; aux!= NULL; aux=aux->next){
        contador+=1;
        
    }
    return contador;
       
}

void imprimir(Lista *first)
{
    Lista *aux;

    for (aux = first; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.mes, aux->nascimento.mes, aux->nascimento.ano, aux->media);
    }
}

// void imprimir1(Lista *first)
// {
//     Lista *aux;

//     for (aux = first; aux != NULL; aux = aux->next)
//     {
//         printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.mes, aux->nascimento.mes, aux->nascimento.ano, aux->media);
//     }
// }

void menu(Lista *first)
{
    int x, cont ;
    char matricula[20];

    while (x != 0)
    {
        printf("1- inserir dados\n2-excluir dados\n3-Listar dados\n4-contar\n0-sair\n");
        scanf("%d", &x);

        if (x == 1)
        {
            // inserirDados(first);
            first = inserirDados(first);
        }
        else if (x == 2)
        {
            if (first == NULL)
            {
                printf("Lista vazia!\n");
            }
            else
            {
                scanf("%s", matricula);
                first = remover(first, matricula);
            }
        }
        else if (x == 3)
        {
            if (first == NULL)
            {
                printf("Lista vazia\n");
            }
            else
            {
                imprimir(first);
            }
        }
        else if (x == 4)
        {
            if(first == NULL){
                printf("lista vazia\n");
            }
            else{
                cont=conta(first);
                printf("%d\n",cont);
            }
        }
        else if (x == 0)
        {
            break;
        }
    }
}

int main()
{

    Lista *first = NULL;
    menu(first);

    // Lista *valor,*varial;

    // varial=inserirDados(first);

    // imprimir(varial);

    return 0;
}
