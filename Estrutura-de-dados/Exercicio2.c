/*Escreva um programa para ler e armazenar as
informações de 5 clientes:
• O código do cliente (inteiro);
• A idade;
• O salário.
As informações devem ser armazenadas em structs de
maneira apropriada. Em seguida, o programa deverá
exibir um menu com as seguintes opções:
1– Exibir clientes
2 – Consultar cliente
3 – Sair do programa
• A opção 1 deverá exibir um relatório contendo todos
os dados de todos os clientes cadastrados.
• A opção 2 deverá pedir ao usuário o código de um
cliente e verificar se tal cliente encontra-se cadastrado, ou seja, se o código informado está
presente no vetor de códigos. Caso afirmativo, o programa deverá mostrar todos os dados do cliente
consultado. Caso contrário, o programa deverá mostrar uma mensagem informando que o cliente
não está cadastrado*/


#include <stdio.h>
#include<stdlib.h>

struct Clientes {
    int codCliente;
    int idade;
    float salario;
};

int main(){

struct Clientes clientes[5];
int instrucao;

    for(int i = 0; i < 5; i ++){

        printf("Digite o codigo do cliente %d: \n",i+1);
        scanf("%d",&clientes[i].codCliente);
        printf("Agora digite a idade do cliente: \n");
        scanf("%d",&clientes[i].idade);
        printf("Agora digite o valor que esse cliente recebe: \n");
        scanf("%f",&clientes[i].salario);
    }

printf("-----------------------\n");
printf("O que voce deseja fazer agora ? \n");
printf("1 - Exibir os clientes\n");
printf("2 - Consultar um cliente \n");
printf("3 - Sair do programa\n");
scanf("%d",&instrucao);
int encontrar = 0;
int encontrarCod;

    switch (instrucao)
    {
    case 1 : 
        printf("--------Clientes cadastrados--------\n");

        for(int i = 0; i <3; i++){
            printf("O codigo do cliente e: %d \n", clientes[i].codCliente);
            printf("O cliente possui %d anos \n", clientes[i].idade);
            printf("Ele recebe %.2f reais \n",clientes[i].salario);
            printf("---------------------------\n");
        }
        break;
    case 2 :
        printf("Digite o codigo do cliente:");
        scanf("%d",&encontrarCod);
        for(int i = 0; i<5; i++){
            if(encontrarCod == clientes[i].codCliente){
                printf("O cliente possui %d anos \n", clientes[i].idade);
                printf("Ele recebe %.2f reais \n",clientes[i].salario);
                encontrar= 1;
            }
        }
            if(encontrar == 0){
                printf("O cliente nao esta cadastrado");
            }
        break;
    case 3 : 
    
        break;
            
        break;
    default:
        break;
    }

}