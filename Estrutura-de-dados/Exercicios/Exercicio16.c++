/*Mapa associativo com listas*/

#include <iostream>
#include <map>
using namespace std;

struct Materias{ // Lista para declararmos os valores a serem inseridos
    string codigo;
    string disciplina;
};

int main(){

    map<int , Materias> MapaLista; // Esta linha e a responsavel por criar o mapa com a lista
    Materias mat; // Esta linha e resposavel por informar os dados para a associação
    mat.codigo = "103";
    mat.disciplina = "Estrutura de dados\n";
    MapaLista[1] = mat;
    // Para inserimos os dados as variaveis chamando eles como classes por meio do mat.__  
    
    mat.codigo = "203";
    mat.disciplina = "Sistemas Operacionais\n";
    MapaLista[2] = mat; 

    int chave;
    printf("\nInforme a chave da disciplina\n");
    cin >> chave;

        if(MapaLista.find(chave) == MapaLista.end()) // procurar se a chave existe
            cout << "\nNao foi encontrado\n" << endl;
            else{
                cout << " O codigo foi encontrado = > " << MapaLista[chave].codigo << " Disciplina :" << MapaLista[chave].disciplina;
             }

    printf("Adicione uma nova disciplina\n");
    printf("Informe a chave da disciplina: \n");
    cin >> chave;

        if(MapaLista.find(chave) == MapaLista.end()){ // Verifica se a chave nao existe
            // E informa os dados para a associacao caso a chave nao exista

            string codigo, disciplina;

            printf("Informe o codigo da disciplina \n");
            cin >> codigo;
            printf("Informe a disciplina \n");
            cin >> disciplina;

            mat.codigo = codigo; // Insere os dados no mapa associativo
            mat.disciplina = disciplina; // Insere os dados no mapa associativo
            MapaLista[chave] = mat;  // Insere os dados no mapa associativo

            // Imprime na tela os dados inseridos 
            cout << "Disciplina inserida com sucesso\n";
            cout << "O Codigo : " + MapaLista[chave].codigo + " Disciplina : " + MapaLista[chave].disciplina + "\n";
        
        }else{
            cout << " \nChave ja existe \n" << endl;
         }

    

// Remocação das chaves
    printf("Informe a chave para a remocao\n");
    cin >> chave;
        if(MapaLista.find(chave) == MapaLista.end()){
            cout << "Chave nao existente\n";
        }else{
            MapaLista.erase(MapaLista.find(chave)); // Remove a associação da chave indormada pelo usuario
         }

// Imprimir dados
    map<int, Materias > :: iterator item; // esta variavel percorre as chaves do mapa
    for(item = MapaLista.begin(); item != MapaLista.end(); item ++){
        int posicao = item -> first; // acessa a posicao da chave do item (item -> first)
        cout << MapaLista[posicao].codigo << " => " << MapaLista[posicao].disciplina << "\n";
    }

    return 0;
}
