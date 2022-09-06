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

Lista *inserirDados(Lista *first)
{
    Lista *Dado, *aux, *First;
    Dado = (Lista *)malloc(sizeof(Lista));

    scanf("%s", Dado->matricula);
    scanf("%s", Dado->nome);
    scanf("%d %d %d", &Dado->nascimento.dia, &Dado->nascimento.mes, &Dado->nascimento.ano);
    scanf("%f", &Dado->media);
    Dado->next = NULL;

    if (first == NULL)
    {
        first = Dado;
        aux = Dado;
    }
    else
    {
        Dado->next = first;
        first = Dado;
        aux = Dado;
    }
}

Lista* remover(Lista **lis, char matricula[20]){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}
 
 

// void imprimir(Lista *first)
// {
//     Lista *aux;

//     aux = first;

//     while (aux != NULL)
//     {
//         printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.mes, aux->nascimento.mes, aux->nascimento.ano, aux->media);

//         aux = aux->next;
//     }
// }

void imprimir1(Lista *first){
    Lista *aux;
    for(aux = first; aux!=NULL; aux=aux->next){
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.mes, aux->nascimento.mes, aux->nascimento.ano, aux->media);
    }
}




void menu(Lista *first)
{
    int x;
    char matricula[20];

    while (x != 0)
    {
        printf("1- inserir dados\n2-excluir dados\n3-Listar dados\n0-sair\n");
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
                imprimir1(first);
            }
        }
        else if (x == 0)
            break;
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
