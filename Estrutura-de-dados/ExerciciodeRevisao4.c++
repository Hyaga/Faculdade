/*Implementar um programa para inserção dos dados (idade, salário,
código) de uma funcionário em uma Tabela Hash de 12 posições,
utilizando a técnica de Espalhamento Duplo. Considere que a chave
seja o Código da pessoa. O programa deverá ter um MENU com as
seguintes opções:
• Cadastrar um funcionário;
• Imprimir a Tabela Hash;
• Procurar um determinado Código do funcionário na tabela
Hash. Se for encontrado, mostrar todos os dados do
funcionário (idade, salário, código). Caso contrário, exibir
mensagem: “Funcionário inexistente”.
• Sair.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Registro {// Essa struct vai ser responsavel por guardar as informações inseridas
    int chave;
    int idade;
    float salario;
};

int FuncaoHash(int chave, int tamanhoTabelaHash) {
    int indice = chave % tamanhoTabelaHash;// Esta linha e responsavel por criar uma tabela e atribuir ela a uma var
// esta variavel vai declarar o tamanho da tabela no main   
    return indice;
}

int FuncaoHashSegundoPasso(int chave, int tamanhoTabelaHash) {
    int indice = (1 + (chave % (tamanhoTabelaHash)));//Esta linha sera responsavel por criar um novo indice  para a tabela hash
    // este novo indice ira somar +1 no indice usando como base a chave e a variavel tamanho Tabela
    return indice;
}

int FuncaoReHash(int i, int k, int tamanhoTabelaHash) {
    int indice = (i + k) % tamanhoTabelaHash;// Esta linha sera responsavel por criar um novo indice  para a tabela hash
    // este novo indice ira somar +1 no indice usando como base a funçãoHash e a funçãohash segundo passo
    return indice;
}

int inserirNaTabelaHash(Registro TabelaHash[], int chave, int idade, float salario, int tamanhoTabelaHash) {
    int indice, i, k;
    i = FuncaoHash(chave, tamanhoTabelaHash);
    k = FuncaoHashSegundoPasso(chave, tamanhoTabelaHash);
    indice = FuncaoReHash(i, k, tamanhoTabelaHash);

    while (TabelaHash[indice].chave != -1) {// Esta linha sera a responsavel por buscar a proxima posição livre
        if (indice == tamanhoTabelaHash) {// A tabela esta cheia
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
    int i, k;
    i = FuncaoHash(chave, tamanhoTabelaHash);
    k = FuncaoHashSegundoPasso(chave, tamanhoTabelaHash);
    indice = FuncaoReHash(i, k, tamanhoTabelaHash);

    while (TabelaHash[indice].chave != chave) {// Esta chave procura a chave a partir da posição i
        if (TabelaHash[indice].chave == -1) { // Não achou a chave pois existe uma posição vazia
            indice = -1;
            break;
        }

        if (indice == tamanhoTabelaHash) {// retorna pois chegou no final da tabela e nao encontrou uma chave
            indice = -2;
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
    Registro *TabelaHash = (Registro *)malloc(sizeof(Registro) * tamanhoTabelaHash);// Aqui chamamos o registro para atribuir os dados salario idade e chave

    for (int i = 0; i < tamanhoTabelaHash; i++) {// iniciamos a tabela com -1 (para indicar as posições vazias)
        TabelaHash[i].chave = -1;
    }

    int escolha = 0;

    while (escolha != 4) {
        printf("\nMENU:\n");
        printf("1. Cadastrar um funcionario\n");
        printf("2. Imprimir a Tabela Hash\n");
        printf("3. Procurar um codigo do funcionario na tabela Hash\n");
        printf("4. Sair\n");

        printf("\nEscolha uma opcao: ");
        cin >> escolha;

        switch (escolha) {
            case 1: {
                int chave, idade;
                float salario;

                printf("\nDigite a chave que devera ser inserida: ");
                cin >> chave;

                printf("Digite a idade correspondente a chave: ");
                cin >> idade;

                printf("Digite o salario correspondente a chave: ");
                cin >> salario;

                inserirNaTabelaHash(TabelaHash, chave, idade, salario, tamanhoTabelaHash);
                break;
            }
            case 2:
                imprimirTabelaHash(TabelaHash, tamanhoTabelaHash);
                break;
            case 3: {
                int chave;
                printf("\nDigite a chave que voce deseja procurar: ");
                cin >> chave;
                int resultado = ProcurarNaTabelaHash(TabelaHash, chave, tamanhoTabelaHash);
                if (resultado >= 0) {
                    printf("A chave procurada esta no indice %d\n", resultado);
                    printf("Idade: %d | Salario: %.2f\n", TabelaHash[resultado].idade, TabelaHash[resultado].salario);
                } else {
                    printf("Funcionario inexistente\n");
                }
                break;
            }
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }

    free(TabelaHash);
    return 0;
}