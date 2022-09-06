#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct elemento{
    char c;
    struct elemento *proximo;
};
typedef struct elemento Elemento;


struct fila {
    Elemento *first, *last;
};
typedef struct fila Fila;



void inicializaFila(Fila *f){
    f->first=NULL;
    f->last=NULL:
}


void insereFila(Fila *f, char item){
    
}