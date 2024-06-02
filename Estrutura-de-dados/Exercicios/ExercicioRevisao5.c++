/*Implementar um programa para inserção dos dados (idade, altura,
RG) de uma pessoa em uma Tabela Hash de 10 posições, utilizando a
técnica de Espalhamento Linear.Onde de para
• Cadastrar os dados da pessoa;
• Imprimir a Tabela Hash;
• Procurar um determinado RG na tabela Hash. Se for
encontrado, mostrar todos os dados da pessoa (idade, altura,
RG). Caso contrário, exibir mensagem: “RG não
encontrado”.*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Registro { // Essa struct vai ser responsavel por guardar as informações inseridas
    int chave;
    int idade;
    float salario;
};

int FuncaoHash(int chave) {
    int indice = chave % 10; // Esta linha e responsavel por criar uma tabela de 10 posições
    return indice;
}



int inserirNaTabelaHash(Registro TabelaHash[], int chave, int idade, float salario, int tamanhoTabelaHash) {
    int indice;
    indice = FuncaoHash(chave);

    while (TabelaHash[indice].chave != -1) { // Esta linha sera a responsavel por buscar a proxima posição livre
        if (indice == tamanhoTabelaHash) { // A tabela esta cheia
            indice = -2;
            break;
        }

        if (TabelaHash[indice].chave == chave) { // O elemento digitado ja existe 
            indice = -1;
            break;
        }

        indice++;
    }

    if (indice >= 0) { // Aqui usamos o conceito de classes para inserir a idade salario e chave nas posições livres (excetos no indice = -1 ou -2)
        TabelaHash[indice].chave = chave;
        TabelaHash[indice].idade = idade;
        TabelaHash[indice].salario = salario;
    }

    return indice;
}

int ProcurarNaTabelaHash(Registro TabelaHash[], int chave, int tamanhoTabelaHash) {
    int indice;
    indice = FuncaoHash(chave);

    while (TabelaHash[indice].chave != chave) { // Esta chave procura a chave a partir da posição i
        if (TabelaHash[indice].chave == -1) { // Não achou a chave pois existe uma posição vazia
            indice = -1;
            break;
        }

        if (indice == tamanhoTabelaHash) {
            indice = -2; // retorna pois chegou no final da tabela e nao encontrou uma chave
            break;
        }

        indice++;
    }

    return indice;
}

void imprimirTabelaHash(Registro TabelaHash[], int tamanhoTabelaHash) {
    for (int i = 0; i < tamanhoTabelaHash; i++) {
        printf("[%d] Chave: %d | Idade: %d | Salario: %.2f\n", i, TabelaHash[i].chave, TabelaHash[i].idade, TabelaHash[i].salario);
    }

    printf("Fim\n");
}

int main() {
    int tamanhoTabelaHash = 10;
    Registro *TabelaHash = (Registro *)malloc(sizeof(Registro) * tamanhoTabelaHash); // Aqui chamamos o registro para atribuir os dados salario idade e chave

    for (int i = 0; i < tamanhoTabelaHash; i++) {
        TabelaHash[i].chave = -1; // iniciamos a tabela com -1 (para indicar as posições vazias)
    }

    int chave = 0;
    int idade;
    float salario;
    int resultado;

    while (chave != -1) {
        printf("\nDigite a chave que deverá ser inserida (ou -1 para sair): ");
        cin >> chave;

        if (chave == -1) break;

        printf("Digite a idade correspondente à chave: ");
        cin >> idade;

        printf("Digite o salário correspondente à chave: ");
        cin >> salario;

        resultado = inserirNaTabelaHash(TabelaHash, chave, idade, salario, tamanhoTabelaHash);
        if (resultado >= 0) {
            printf("\n-- Registro inserido com sucesso --\n");
            imprimirTabelaHash(TabelaHash, tamanhoTabelaHash);
        } else if (resultado == -2) {
            printf("\n-- Não há espaço livre na tabela hash --\n");
        } else {
            printf("\n-- Chave já existe --\n");
        }
    }

    printf("\nBuscar na tabela Hash\n");
    chave = 0;

    while (chave != -1) {
        printf("\nDigite a chave que você deseja procurar (ou -1 para sair): ");
        cin >> chave;

        if (chave == -1) break;

        resultado = ProcurarNaTabelaHash(TabelaHash, chave, tamanhoTabelaHash);
        if (resultado >= 0) {
            printf("A chave procurada está no índice %d\n", resultado);
            imprimirTabelaHash(TabelaHash, tamanhoTabelaHash);
        } else {
            printf("Chave não localizada\n");
        }
    }

    free(TabelaHash);
    return 1;
}
