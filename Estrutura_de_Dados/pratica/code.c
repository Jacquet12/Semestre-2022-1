#include<stdio.h>
#include<math.h>

typedef struct{
    char nome[40];
    char curso[40];
    long cpf;
} Dados;


int main (){
Dados vector[3];
for (int i =0; i < 3; i++){
    printf("Digite seu nome: ");
    scanf("%s", vector[i].nome);

    printf("Digite seu curso: ");
    scanf("%s", vector[i].curso);

    printf("Digite o seu cpf: ");
    scanf("%ld", &vector[i].cpf);

    printf("\n");
}

for (int i =0; i < 3; i++){
    printf("Nome: %s\n", vector->nome);
    printf("Curso: %s\n", vector->curso);
    printf("CPF:: %ld\n", vector->cpf);

    printf("\n");
}


return 0;
}