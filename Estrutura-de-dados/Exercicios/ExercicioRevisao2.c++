/*4) Implementar um programa que utilize Mapa Associativo com
Espalhamento e alocação Dinâmica, com tamanho máximo de
10 posições. Cadastre o RG e o salário dos funcionários de uma
empresa:
Chave (CPF) RG Salário (R$)
123521 10336 3500,00
42036 203325 1456,00
6952 303562 8520,00
212589 405524 3256,89
... ... ....
O programa deverá ter um MENU com as seguintes opções para
o usuário:
• Cadastrar um novo funcionário uma nova disciplina;
• Imprimir todos os funcionários cadastrados e os respectivos
salários.
Página 3 de 4
• Sair.
Obs.: O programa só deverá ser encerrado quando o usuário
escolher a opção Sair.
*/

#include <iostream>
#include <map>

using namespace std;

// Cria a struct para as matérias
struct Materias {
    string codigo;
    float salario;
};

// Definição da função hash customizada
unsigned int funcaoHash(int tamanho, int chave) {
    unsigned int indice = chave;
    // Calcula o índice da tabela hash
    indice = ((indice >> 3) * 2654435761) % tamanho;
    return indice;
}

int main() {
    map<int, Materias> MapaLista;
    const int TamanhoTabela = 10;
    int chave;
    string codigo;
    float salario;
    int opcao;

    do {
        cout << "\nMENU:" << endl;
        cout << "1. Adicionar disciplina" << endl;
        cout << "2. Imprimir disciplinas cadastradas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite a chave (CPF): ";
                cin >> chave;
                cout << "Digite o RG: ";
                cin >> codigo;
                cout << "Digite o salario da pessoa: ";
                cin >> salario;
                {
                    Materias mat;
                    mat.codigo = codigo;
                    mat.salario = salario;
                    auto it = MapaLista.find(chave);
                    if (it != MapaLista.end()) {
                        cout << "\nA chave já foi inserida." << endl;
                    } else {
                        MapaLista[chave] = mat;
                    }
                }
                break;
            case 2:
                for (const auto& item : MapaLista) {
                    cout << "Chave (CPF): " << item.first << ", RG: " << item.second.codigo << ", Salario: " << item.second.salario << "\n";
                }
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opçao inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}