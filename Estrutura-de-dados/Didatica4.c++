/*Didatica de como fazer uma lista de Tabela Hash perfeita*/

/*Função de Expalhamento Linear*/

#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int FuncaoHash(int chave){
    int indice = chave % 10; // Esta linha e responsavel por definir as posiçoes da tabela Hash que necessitam da % para serem declaradas

    return indice;
}

int inserirNaTabelaHash(int tabelaHash[], int chave, int tamanhoTabelaHash){
    int indice;
    indice = FuncaoHash(chave);

    while(tabelaHash[indice] != -1){
        if(indice == tamanhoTabelaHash){ // Esta linha e responsavel por fazer a comparação de quando a tabela estiver cheia ela parar
            indice = -2; 
            break;
        }

        if(tabelaHash[indice] == chave){ // Quando for digitado uma chave ja existente o comando para 
            indice = -1;
            break;
        }

        indice++;
    }

    if(indice >= 0){ // Esta linha e responsavel por armazenar a chave na posição livre quando ela for encontrada (exeto = -1 ou -2)
        tabelaHash[indice] = chave;
    }

    return indice;

}

int procurarNaTabelaHash(int tabelaHash[],int chave,int tamanhoTabelaHash){

    int indice;

    indice = FuncaoHash(chave);

    while(tabelaHash[indice] != chave){ // Esta linha sera a responsavel por procurar a chave que vai estar na posição i

        if(tabelaHash[indice] == -1){ // Se a comparação nao achar a chave ela retornara uma posição vazia
            indice = -1;
            break;
        }
        

        if(indice == tamanhoTabelaHash){ // Retornara um resultado pois a comparação chegou ao final da tabela e nao encontrou a chave
            indice = -2;
            break;
        }

        indice++;

    }

    return indice; // retorna a posição que encontrou
}


void imprimirTabelaHash(int tabelaHash[], int tamanhoTabelaHash){

    for(int i = 0; i < tamanhoTabelaHash; i++){
        printf("[%d] %d", i, tabelaHash[i]);
    }

    printf("Fim");
}

int main(){

    int tamahoTabelaHash = 10; // alocação estatica da tabelaHahs[tamanhoTabela]
    int *TabelaHash = (int*)malloc(sizeof(int) * tamahoTabelaHash); // alocação dinamica

        for(int i = 0; i < 10; i++){

            TabelaHash[i] = -1;
        }

    int chave = 0;
    int resultado;
    

        while(chave != -1){
            printf("\n Digite o numero que devera ser inserido:");
            cin >> chave;

            resultado = inserirNaTabelaHash(TabelaHash,chave,tamahoTabelaHash);
            if(resultado >=0){
                printf(" \n-- Chave inserido com sucesso -- \n");
                imprimirTabelaHash(TabelaHash,tamahoTabelaHash);
            }else if(resultado == -2){
                printf(" \n-- Nao existe espaco livre na tabela hash -- \n");
             }else{
                printf(" \n  -- Chave ja existe -- \n");
              }
        }

        printf(" Buscar na tabela Hash \n");
        chave = 0;

        while(chave != -1){

            printf("Digite a chave que voce deseja procurar: \n");
            cin >> chave;

            resultado = procurarNaTabelaHash(TabelaHash,chave,tamahoTabelaHash);
            if(resultado >= 0){
                printf("A chave procurada esta no indice %d \n",resultado);
                imprimirTabelaHash(TabelaHash,tamahoTabelaHash);
            }else printf("\n Chave nao localizada");

        }

        return 1;
        }

