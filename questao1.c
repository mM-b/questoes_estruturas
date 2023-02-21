#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionarios
{
    char nome[50];
    float salarios;
    int identificador;
    char cargo[50];
} Funcionario;
int contador;
void recebe(Funcionario *funcionarios, int tamanho)
{
    for (contador = 0; contador < tamanho; contador++)
    {
        printf("\ninforme seu nome\n");
        scanf(" %[^\n]s", funcionarios[contador].nome);
        printf("informe o salario\n");
        scanf("%f", &funcionarios[contador].salarios);
        printf("informe seu identificador\n");
        scanf("%d", &funcionarios[contador].identificador);
        printf("informe seu cargo\n");
        scanf(" %[^\n]s", funcionarios[contador].cargo);
    }
}

void imprime(Funcionario *funcionarios, int tamanho)
{
    for (contador = 0; contador < tamanho; contador++)
    {
        printf("\nnome do funcionario %d:%s\nsalario:%.2f\nidentificador:%d\ncargo:%s\n\n", contador + 1, funcionarios[contador].nome, funcionarios[contador].salarios, funcionarios[contador].identificador, funcionarios[contador].cargo);
    }
}

void altera_sal(Funcionario *funcionarios)
{
    printf("informe o novo salario");
    float nv_sal;
    scanf("%f", &nv_sal);
    funcionarios->salarios = nv_sal;
}

void salarios(Funcionario *funcionarios, int qnt_funcionarios)
{
    float maior = funcionarios[0].salarios, menor = funcionarios[0].salarios;
    int mmaior = 0, mmenor = 0;

    for (contador = 0; contador < qnt_funcionarios; contador++)
    {

        if (funcionarios[contador].salarios > maior)
        {
            maior = funcionarios[contador].salarios;
            mmaior = contador;
        }
        if (funcionarios[contador].salarios < menor)
        {
            menor = funcionarios[contador].salarios;
            mmenor = contador;
        }
    }
    printf("\nmaior salario:%.2f\ncargo do maior salario:%s\n\nmenor salario:%.2f\ncargo do menor salario:%s\n", maior, funcionarios[mmaior].cargo, menor, funcionarios[mmenor].cargo);
}

int main(void)
{
    int tamanho;
    printf("informe a quantidade de funcionarios\n");
    scanf("%d", &tamanho);
    Funcionario *funcionarios = (Funcionario *)malloc(tamanho * sizeof(Funcionario));

    recebe(funcionarios, tamanho);

    imprime(funcionarios, tamanho);

    salarios(funcionarios, tamanho);

    int funcio;
    printf("\nQual funcionario voce deseja alterar o salario: (1-primeiro funcionario, 2-segundo funcionario,3...)");
    scanf("%d", &funcio);

    altera_sal(&funcionarios[funcio - 1]);
    printf("novo salario do funcionario %d:%.2f", funcio, funcionarios[funcio - 1].salarios);
    free(funcionarios);
    return 0;
}
