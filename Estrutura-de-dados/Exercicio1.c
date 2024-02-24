/*Escreva um programa na linguagem C para armazenar
os dados de 5 automóveis. Para cada automóvel, o
usuário deverá informar as seguintes informações:
modelo (char[20]), ano (int) e valor (float).
Após a leitura de todos os automóveis, o programa deverá
exibir um relatório de todos os carros cadastrados.*/

#include <stdio.h>
#include<stdlib.h>

struct Automovel
{
    char modelo[20];
    int ano;
    float valor;
};

int main(){

struct Automovel automovel[3];

    for(int i = 0; i <3 ; i++){
        printf("Digite o modelo do carro %d que voce deseja cadastra: \n",i+1);
        scanf("%s",&automovel[i].modelo);
        printf("Agora cadastre o ano do modelo: \n");
        scanf("%d",&automovel[i].ano);
        printf("Por fim agora digite o valor do automovel:\n");
        scanf("%f",&automovel[i].valor);
    }

    printf("--------Automoveis cadastrados--------\n");

    for(int i = 0; i <3; i++){
        printf("Modelo: %s \n", automovel[i].modelo);
        printf("Ano do carro: %d \n", automovel[i].ano);
        printf("O valor do carro e: %.2f \n",automovel[i].valor);
        printf("---------------------------\n");
    }


}