#include <iostream>
#include <map>

using namespace std;

// Cria a struct para as matérias
struct Materias {
    string codigo;
    string disciplina;
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
    string codigo, disciplina;
    int opcao;

    do {
        cout << "\nMENU:" << endl;
        cout << "1. Adicionar disciplina" << endl;
        cout << "2. Imprimir disciplinas cadastradas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opçao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite a chave da disciplina: ";
                cin >> chave;
                cout << "Digite o código da disciplina: ";
                cin >> codigo;
                cout << "Digite a descrição da disciplina: ";
                cin >> disciplina;
                {
                    Materias mat;
                    mat.codigo = codigo;
                    mat.disciplina = disciplina;
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
                    cout << "Chave: " << item.first << ", Codigo: " << item.second.codigo << ", Disciplina: " << item.second.disciplina << "\n";
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
