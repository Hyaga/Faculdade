/*Didatica de como fazer uma lista de Tabela Hash perfeita*/

/*Função de Expalhamento Dupla*/

#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int FuncaoHash(int chave, int tamanhoTabelaHash){
    int indice = chave % tamanhoTabelaHash; // Esta linha e responsavel por definir as posiçoes da tabela Hash que necessitam da % para serem declaradas

    return indice;
}

int FuncaoHashSegundoPasso(int chave,int tamanhoTabelaHash){

    int indice = (1+(chave % (tamanhoTabelaHash)));
    return indice;

}

int FuncaoReHash(int i , int k, int tamanhoTabelaHash){
    int indice = (i+k) % tamanhoTabelaHash;
    return indice;
}

int inserirNaTabelaHash(int TabelaHash[], int chave, int tamanhoTabelaHash){

    int indice,i,k;
    i = FuncaoHash(chave,tamanhoTabelaHash);
    k - FuncaoHashSegundoPasso(chave,tamanhoTabelaHash);
    indice = FuncaoReHash(i,k,tamanhoTabelaHash);

     while(TabelaHash[indice] != -1){
        if(indice == tamanhoTabelaHash){ // Esta linha e responsavel por fazer a comparação de quando a tabela estiver cheia ela parar
            indice = -2; 
            break;
        }

        if(TabelaHash[indice] == chave){ // Quando for digitado uma chave ja existente o comando para 
            indice = -1;
            break;
        }

        indice++;
    }

    if(indice >= 0){ // Esta linha e responsavel por armazenar a chave na posição livre quando ela for encontrada (exeto = -1 ou -2)
        TabelaHash[indice] = chave;
    }

    return indice;

}


int ProcurarNaTabelaHash(int TabelaHash[],int chave, int tamanhoTabelaHash){

    int indice;
    int i;
    int k;
    i = FuncaoHash(chave,tamanhoTabelaHash);
    k - FuncaoHashSegundoPasso(chave,tamanhoTabelaHash);
    indice = FuncaoReHash(i,k,tamanhoTabelaHash);

    while(TabelaHash[indice] != chave){ // Esta linha sera a responsavel por procurar a chave que vai estar na posição i

        if(TabelaHash[indice] == -1){ // Se a comparação nao achar a chave ela retornara uma posição vazia
            indice = -1;
            break;
        }
        

        if(indice == tamanhoTabelaHash){ // Retornara um resultado pois a comparação chegou ao final da tabela e nao encontrou a chave
            indice = -2;
            break;
        }

        indice++;

    }

    return indice; 
}

void imprimirTabelaHash(int TabelaHash[], int tamanhoTabelaHash){

    for(int i = 0; i < tamanhoTabelaHash; i++){
        printf("[%d] %d", i, TabelaHash[i]);
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
                printf(" -- Chave ja existe -- \n");
              }
        }

        printf(" Buscar na tabela Hash \n");
        chave = 0;

        while(chave != -1){

            printf("Digite a chave que voce deseja procurar: \n");
            cin >> chave;

            resultado = ProcurarNaTabelaHash(TabelaHash,chave,tamahoTabelaHash);
            if(resultado >= 0){
                printf("A chave procurada esta no indice %d \n",resultado);
                imprimirTabelaHash(TabelaHash,tamahoTabelaHash);
            }else printf("Chave nao localizada \n");

        }

        return 1;
        }

