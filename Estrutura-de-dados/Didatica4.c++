/*Didatica de como fazer uma lista de Tabela Hash perfeita*/

/*Função de Expalhamento Linear*/

#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int FuncaoHash(int chave){
    int indice = chave % 10; // Esta linha e responsavel por definir as posiçoes da tabela Hash que necessitam da % para serem declaradas
}

int inserirNaTabelaHash(int tabelaHash[], int chave, int tamanhoTabelaHash){
    int indice;
    indice = FuncaoHash(chave);

    while(tabelaHash[indice] != 1){
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