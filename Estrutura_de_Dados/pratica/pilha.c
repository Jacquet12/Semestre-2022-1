#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//salve?
struct tdado {
	char c;
};
typedef struct tdado dado;
struct tpilha {
	dado info;
	struct tpilha *next;
};
typedef struct tpilha pilha;
struct tsent {
	pilha *top; // head   
};
typedef struct tsent sentinela;
//
int emptystack(sentinela s)
{
	if (s.top==NULL) return 1;
	return 0;
}
//
void initstack(sentinela *s) 
{                           
	s->top=NULL;          
}              
//
void pushitem(sentinela *s, dado d)
{
	pilha *f;
	f=(pilha *)malloc(sizeof(pilha));
	f->info=d;
	f->next=NULL;
	if (emptystack(*s)==1) {
		s->top=f;
		return;
	}
	f->next=s->top;
    s->top=f;
	return;
}
//
dado popItem(sentinela *s) {
	dado d={'}'};
	pilha *aux=s->top;
	if (emptystack(*s)==1) return d;
	d=s->top->info;
	s->top=s->top->next;
	free(aux);
	return d;
}
//
void freestack(sentinela *s)
{
	pilha *aux=s->top, *aux2;
	while (aux!=NULL)
	{
		aux2=aux;
		aux=aux->next;
		free(aux2);
    }
    initstack(s);
    return;
}
//
int main()
{
	sentinela s;
	dado d;
	char *st={"Inserir na fila!"};
	int i;
	initstack(&s);
	for (i=0;i<strlen(st);i++) {
		d.c=st[i];
		pushitem(&s,d);
	}
	while (emptystack(s)!=1)
	{
		d=popItem(&s);
		printf("%c\n",d.c);
	}
	return 0;
}