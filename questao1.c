#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionarios // criando uma estrutura para funcionarios
{
    char nome[50];
    float salarios;
    int identificador;
    char cargo[50];
} Funcionario;
int contador;

/***
 * função que lê as variaveis de funcionario
 * @param *funcionarios
 * @param tamanho
 */
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

/***
 * função para imprimir os dados do funcionario
 * @param *funcionarios
 * @param tamanho
 */
void imprime(Funcionario *funcionarios, int tamanho)
{
    for (contador = 0; contador < tamanho; contador++)
    {
        printf("\nnome do funcionario %d:%s\nsalario:%.2f\nidentificador:%d\ncargo:%s\n\n", contador + 1, funcionarios[contador].nome, funcionarios[contador].salarios, funcionarios[contador].identificador, funcionarios[contador].cargo);
    }
}

/***
 * função para alterar o salario de um funcionario
 * @param *funcionarios
 */
void altera_sal(Funcionario *funcionarios)
{
    printf("informe o novo salario");
    float nv_sal;
    scanf("%f", &nv_sal);
    funcionarios->salarios = nv_sal;
}

/**
 * função que descobre o maior e o menor salario
 * @param *funcionarios
 * @param qnt_funcionarios
 */
void salarios(Funcionario *funcionarios, int qnt_funcionarios)
{
    float maior = funcionarios[0].salarios, menor = funcionarios[0].salarios; // atribui a primeira posição de funcionarios o maior e o menor salario
    int mmaior = 0, mmenor = 0;                                               // inicia os registradores de indice em 0, mmaior registra o indice do maior salario, e mmenor o indice do menor salario

    for (contador = 0; contador < qnt_funcionarios; contador++) // laço for para percorrer todas as posições de funcionarios
    {

        if (funcionarios[contador].salarios > maior) // verifica se o salario do funcionario na posição contador é maior que o salario armazenado em maior
        {
            maior = funcionarios[contador].salarios; // quando a condição do if é verdadeira maior é atualizado
            mmaior = contador;                       // o indice do maior salario é registrado
        }
        if (funcionarios[contador].salarios < menor) // verifica se o salario do funcionario na posição contador é menor que o salario armazenado em menor
        {
            menor = funcionarios[contador].salarios; // quando a condição do if é verdadeira menor é atualizado
            mmenor = contador;                       // o indice do menor salario é registrado
        }                                            // os indices são salvos para impressão do cargo do funcionario com o maior ou menor salario
    }
    printf("\nmaior salario:%.2f\ncargo do maior salario:%s\n\nmenor salario:%.2f\ncargo do menor salario:%s\n", maior, funcionarios[mmaior].cargo, menor, funcionarios[mmenor].cargo);
}

int main(void)
{
    int tamanho;
    printf("informe a quantidade de funcionarios\n");
    scanf("%d", &tamanho);
    Funcionario *funcionarios = (Funcionario *)malloc(tamanho * sizeof(Funcionario)); // aloca dinamicamente um vetor de estruturas
    if (funcionarios == NULL)
    { // se a alocação foi mal sucedida a execução do programa é abortada
        exit(1);
    }
    recebe(funcionarios, tamanho);

    imprime(funcionarios, tamanho);

    salarios(funcionarios, tamanho);

    int funcio;
    printf("\nQual funcionario voce deseja alterar o salario: (1-primeiro funcionario, 2-segundo funcionario,3...)");
    scanf("%d", &funcio);

    altera_sal(&funcionarios[funcio - 1]);
    printf("novo salario do funcionario %d:%.2f", funcio, funcionarios[funcio - 1].salarios);
    free(funcionarios); // libera a memoria alocada por funcionarios
    return 0;
}
