/*Didatica de tabelas hash*/

#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

/*Usando a biblioteca iostream e uma biblioteca que facilita a entrada e saida de dados
os comandos de entrada (scanf) podem ser utilizados como cin >>
os comandos de saida (printf) podem ser usados como cout << 

Usarei essa biblioteca para facilitar a criação de tabelas hash, porem usando printf e scanf o resultado e o mesmo*/

struct noFila {
    int codCliente;
    int idade;
    char *nome;
    struct noFila *noProximo;
    struct noFila *noAnterior;
};

int funcaoHash(int valor){

    int indice_endereco;
    if(valor < 30) // aqui definimos o indice de enderaçemento de acordo com a função hash
        indice_endereco = 0;
        else if ((valor >=30) && (valor< 50))
                    indice_endereco = 1;
                    else indice_endereco = 2;

    return indice_endereco;                
}

void imprimirFila(struct noFila *InicioFila){
    struct noFila *NoAtual = InicioFila; // copia o endereço do primeiro no

    while (NoAtual != NULL){
        printf("\n Nome: %s Idade: %d",NoAtual -> nome,NoAtual->idade);
        NoAtual = NoAtual -> noProximo;
    }
    printf("\n --- Fim da Lista --- ");
}