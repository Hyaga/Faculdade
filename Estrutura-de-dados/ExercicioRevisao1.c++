/*Faça um programa que receba o preço de um produto, descrição e o
seu código e armazene as informações em uma Tabela Hash (Alocação
Dinâmica), seguindo a Função Hash:
Código de origem Procedência
1 Sul
2 Norte
3 Leste
4 Oeste
5 ou 6 Nordeste
7 ou 8 ou 9 Sudeste
10 a 20 Centro-oeste
21 a 30 Nordeste
Página 4 de 4
Em seguida, o programa deve mostrar quais são os produtos que estão
em cada uma das regiões de procedência.*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct noFila {
    float preco;
    int codigo;
    char *descricao;
    struct noFila *noProximo;
    struct noFila *noAnterior;
};

void imprimirTabela(struct noFila *InicioFila) {
    struct noFila *NoAtual = InicioFila;

    while (NoAtual != NULL) {
        printf("\n A descricao do item e: %s Codigo: %d e o preco do produto e: %.2f ", NoAtual -> descricao, NoAtual->codigo,NoAtual -> preco);
        NoAtual = NoAtual -> noProximo;
    }
    printf("\n --- Fim da Lista --- ");
}

int funcaoHash(int valor){

    int indice_endereco;
    if(valor == 1){// aqui definimos o indice de enderaçemento de acordo com a função hash
        indice_endereco = 0;
    }else if(valor == 2){
        indice_endereco = 1;
      }else if(valor == 3){
         indice_endereco = 2;
        }else if(valor == 4){
            indice_endereco == 3;
         }else if(valor == 5 && valor == 6){
            indice_endereco = 4;
          }else if(valor == 7 && valor == 8 && valor == 9){
            indice_endereco = 5;
           }else if(valor >= 10 ||  valor <= 20){
            indice_endereco = 6;
            }else if(valor >= 21 ||  valor <= 30){
                indice_endereco = 7;
             }

    return indice_endereco;                
}

struct noFila *InserirNaTabela(struct noFila *InicioFila,int codigo, char *descricao,float preco){

    struct noFila *PercorreFila = InicioFila; // copia o inicio da fila
    struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila)); // aloca memoria para o novo no

    if(PercorreFila != NULL){ // se a fila não estiver vazia 
        while (PercorreFila -> noProximo != NULL) // Esta linha vai ser responsavel por percorrer toda a fila ate encontrar o ultimo no
        {
            PercorreFila = PercorreFila -> noProximo;
        }

        PercorreFila -> noProximo = novoNo; // Esta linha e responsavel por fazer o ultimo no se trasformar em penultimo apontar para o novoNo
    
    }
    novoNo -> noAnterior = PercorreFila; // Esta linha e responsavel por apontar o campo noAnterior para o no PercorreFila
    novoNo -> codigo = codigo;
    novoNo -> descricao = descricao; //Esta linha e responsavel por colocar as informações no no 
    novoNo -> preco = preco; //Esta linha e responsavel por colocar as informações nos nos
    novoNo -> noProximo = NULL; // Esta linha vai fazer o novoNo ser o ultimo da Fila

    if(InicioFila == NULL)// A fila estava vazia
    return novoNo;
    else return InicioFila;
        
}

int main(){

    struct noFila *TabelaHash[7]; // Esta linha e responsavel por definir a Tabela Hash e o numero de endereços que sera alocado a ela 

    for(int i = 0; i< 7; i++){ // Esta linha sera responsavel por iniciar como NULL todos os endereços da tabela Hash
        TabelaHash[i] = NULL;
    }

    float preco;
    int codigo = 0;
    char *descricao;
    int indice;

    cout << "1 - Sul, 2 - Norte , 3 - Leste , 4 - Oeste , 5 e 6 - Nordeste , 7 8 e  9 - Sudeste, 10 a 20 - Centro - Oeste, 21 a 30 - Nordeste \n";

    do{
    cout <<"Digite o codigo do produto \n";
    cin >> codigo; // Sim poderia ser substituido pelo scanf
     if(codigo == -1)
        break; // Se idade for -1 encerra o programa    
    

    descricao = (char *) malloc(sizeof(char) * 30);//Esta linha esta sendo responsavel por alocar memoria para um nome de ate 30 caracteres
    cout << "Digite a descricao do produto:";
    cin >> descricao;

    cout << "\nDigite agora o preco do produto:";
    cin >> preco;

    indice = funcaoHash(codigo);

    TabelaHash[indice] = InserirNaTabela(TabelaHash[indice], codigo,descricao,preco); // Esta linha e responsavel por inserir dados na tabela hash

    cout << "\n\n";
    cout << "\n **** Conteudo da Tabela Hash **** ";

        for(int i = 0; i< 7; i++){ // Este for sera responsavel por imprimir todos os endereços da tabela hash

        if(i == 0)
            cout << "\n ## Endereco:" << i << " Os produtos do Sul sao: \n"; // Esta linha esta servindo como um printf numa comparação de ifs
            else if(i == 1){
                cout << "\n ## Endereco:" << i << "\nOs produtos do Norte  sao: \n";
            }else if(i == 2){
                cout << "\n ## Endereco:" << i << "\nOs produtos do Leste sao: \n";
             }else if(i == 3){
                cout << "\n ## Endereco:" << i << "\nOs produtos do Oeste  sao: \n";
              }else if(i == 4){
                cout << "\n ## Endereco:" << i << "\nOs produtos do Nordeste sao: \n";
               }else if(i == 5){
                 cout << "\n ## Endereco:" << i << "\nOs produtos do Suldeste sao: \n";
                }else if(i == 6){
                 cout << "\n ## Endereco:" << i << "\nOs produtos do Centro - Oeste sao: \n";
                 }else if(i == 7){
                   cout << "\n ## Endereco:" << i << "\nOs produtos do Nordeste sao: \n";
                   }
        
        
        
        imprimirTabela(TabelaHash[i]); // E assim que se imprime uma tabela hash
    }

    }while (codigo != 0);

}