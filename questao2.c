#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pessoa{
    char nome[50];
    int numero;
    int idade;
}Pessoa;
int contador;
void recebe(Pessoa * pessoa, int tamanho){
    for( contador=0; contador<tamanho; contador++){
    printf("informe seu nome\n");
    scanf(" %[^\n]s",pessoa[contador].nome);
    printf("informe o numero do documento\n");
    scanf("%d",&pessoa[contador].numero);
    printf("informe sua idade\n");
    scanf("%d",&pessoa[contador].idade);
    }
}

void imprime(Pessoa * pessoa, int tamanho){
    for(contador=0; contador<tamanho; contador++){
        printf("\nNome:%s\nNumero do documento:%d\nidade:%d\n\n",pessoa[contador].nome, pessoa[contador].numero, pessoa[contador].idade);
    }
}

void altera_id(Pessoa * pessoa){
    printf("informe a nova idade");
    int nv_idade;
    scanf("%d",&nv_idade);
    pessoa->idade=nv_idade;
}

void maisvelho_novo(Pessoa * pessoa,int tamanho){
    int ivelho=0, inovo=0;
    
    int velho = pessoa[0].idade;
    int novo = pessoa[0].idade;
    for(contador=0; contador<tamanho; contador++){
        
        if(pessoa[contador].idade>velho){
            velho = pessoa[contador].idade;
            ivelho = contador;
        }
        if(pessoa[contador].idade<novo){
            novo = pessoa[contador].idade;
            inovo =contador;
        }
    }
    printf("nome da pessoa mais velha:%s\nnome da pessoa mais nova:%s",pessoa[ivelho].nome,pessoa[inovo].nome);
}


int main(void){
    int tamanho;
    printf("informe a quantidade de pessoas\n");
    scanf("%d",&tamanho);
    Pessoa * pessoa  = (Pessoa*) malloc(tamanho * sizeof(Pessoa));
    
recebe(pessoa,tamanho);

imprime(pessoa,tamanho);

int funcio;
    printf("Qual pessoa voce deseja alterar a idade: ");
    scanf("%d", &funcio);

altera_id(&pessoa[funcio-1]);

imprime(pessoa,tamanho);

maisvelho_novo(pessoa,tamanho);

free(pessoa);
    return 0;
}