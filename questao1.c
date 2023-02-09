#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct funcionarios{
    char nome[50];
    float salarios;
    int identificador;
    char cargo[50];
}Funcionario;
int contador;
void recebe(Funcionario * funcionarios, int tamanho){
    for( contador=0; contador<tamanho; contador++){
    printf("informe seu nome\n");
    scanf(" %[^\n]s",funcionarios[contador].nome);
    printf("informe o salario\n");
    scanf("%f",&funcionarios[contador].salarios);
    printf("informe seu identificador\n");
    scanf("%d",&funcionarios[contador].identificador);
    printf("informe seu cargo\n");
    scanf(" %[^\n]s",funcionarios[contador].cargo);
    }
}

void imprime(Funcionario * funcionarios, int tamanho){
    for(contador=0; contador<tamanho; contador++){
        printf("nome:%s\nsalario:%f\nidentificador:%d\ncargo:%s\n\n",funcionarios[contador].nome, funcionarios[contador].salarios,funcionarios[contador].identificador, funcionarios[contador].cargo);
    }
}

void altera_sal(Funcionario * funcionarios){
    printf("informe o novo salario");
    float nv_sal;
    scanf("%f",&nv_sal);
    funcionarios->salarios=nv_sal;
}

void salarios(Funcionario * funcionarios, int qnt_funcionarios){
    float maior, menor;
    char mmaior[50], mmenor[50];
    for(contador=0; contador<qnt_funcionarios; contador++){
        if(contador==0){
            maior=funcionarios[contador].salarios;
            menor=funcionarios[contador].salarios;
        }
        if(funcionarios[contador].salarios>maior){
            maior=funcionarios[contador].salarios;
            strcpy(mmaior,funcionarios[contador].cargo);
        }
        if(funcionarios[contador].salarios<menor){
            menor=funcionarios[contador].salarios;
            strcpy(mmenor,funcionarios[contador].cargo);
        }
    }
    printf("maior salario:%f\ncargo do maior salario:%s\n\n menor salario:%f\ncargo do menor salario:%s",maior,mmaior,menor,mmenor);
}


int main(void){
    int tamanho;
    printf("informe a quantidade de funcionarios\n");
    scanf("%d",&tamanho);
    Funcionario * funcionarios  = (Funcionario*) malloc(tamanho * sizeof(Funcionario));
    
recebe(funcionarios,tamanho);

imprime(funcionarios,tamanho);

salarios(funcionarios,tamanho);

int funcio;
    printf("Qual funcionario você deseja alterar o salario: ");
    scanf("%d", &funcio);

altera_sal(&funcionarios[funcio-1]);

free(funcionarios);
    return 0;
}