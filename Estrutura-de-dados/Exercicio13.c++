/*Implemente um programa que leia o peso e a altura 
de varias pessoas e armazene essas informações em uma 
Tabela Hash, de acordo com a Função Hash onde 
0 - "Peso Ideal", caso o IMC esteja entre 18.5 e 25
1-  "Voce esta acima do peso ideal" caso o IMC for > 25
2 - "Voce esta abaixo do peso ideal" caso o IMC < que 18.5
IMC = peso / altura elevado por 2 
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct noFila {
    float peso;
    float altura;
    struct noFila *noProximo;
    struct noFila *noAnterior;
};

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

int funcaoHash(float valor) {
    int indice_endereco;
    if ((valor >= 18.5) && (valor < 25)) 
        indice_endereco = 0;
    else if (valor > 25)
        indice_endereco = 1;
    else 
        indice_endereco = 2;

    return indice_endereco;                
}

void imprimirFila(struct noFila *InicioFila) {
    struct noFila *NoAtual = InicioFila;

    while (NoAtual != NULL) {
        printf("\n Peso: %f Altura: %f", NoAtual -> peso, NoAtual->altura);
        NoAtual = NoAtual -> noProximo;
    }
    printf("\n --- Fim da Lista --- ");
}

struct noFila *InserirNaFila(struct noFila *InicioFila, float peso, float altura ) {
    struct noFila *PercorreFila = InicioFila;
    struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));

    if (PercorreFila != NULL) {
        while (PercorreFila -> noProximo != NULL) {
            PercorreFila = PercorreFila -> noProximo;
        }

        PercorreFila -> noProximo = novoNo; 
    }
    novoNo -> noAnterior = PercorreFila; 
    novoNo -> peso = peso; 
    novoNo -> noProximo = NULL; 
    novoNo -> altura = altura; 

    if (InicioFila == NULL)
        return novoNo;
    else 
        return InicioFila;
}

int main() {
    struct noFila *TabelaHash[3];

    for (int i = 0; i < 3; i++) {
        TabelaHash[i] = NULL;
    }

    float peso = 0;
    float altura;
    int indice;
    float imc;

    while (peso != -1) {
        cout << "\nDigite o peso do aluno:"; 
        cin >> peso; 
        if (peso == -1)
            break; 

        cout << "Digite a altura do aluno:";
        cin >> altura;

        float imc = calcularIMC(peso, altura); // Calcula o IMC usando a função calcularIMC()

        indice = funcaoHash(imc); 
        TabelaHash[indice] = InserirNaFila(TabelaHash[indice], peso, altura); 

        cout << "\n\n";
        cout << "\n **** Conteudo da Tabela Hash **** ";

        for (int i = 0; i < 3; i++) { 
            if (i == 0)
                cout << "\n ## O aluno esta com " << i << " kilos que e o peso ideal\n\n"; 
            else if (i == 1)
                cout << "\n ## O aluno esta com " << i << " kilos, ele esta acima do peso ideal \n\n";
            else 
                cout << "\n ##  O aluno esta com " << i << " kilos, ele esta abaixo do peso ideal \n\n";

            imprimirFila(TabelaHash[i]); 
        }
    }
}
