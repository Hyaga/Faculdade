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

    while (NoAtual != NULL){ // percorre a fila ate encontrar o ultimo nó = NULL
        printf("\n Nome: %s Idade: %d",NoAtual -> nome,NoAtual->idade); // mostra a informação do nó
        NoAtual = NoAtual -> noProximo; // aponta para o proximo no da fila
    }
    printf("\n --- Fim da Lista --- ");
}

struct noFila *InserirNaFila(struct noFila *InicioFila,int idade, char *nome){

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
    novoNo -> idade = idade; //Esta linha e responsavel por colocar as informações nos nos
    novoNo -> noProximo = NULL; // Esta linha vai fazer o novoNo ser o ultimo da Fila
    novoNo -> nome = nome; //Esta linha e responsavel por colocar as informações no no 

    if(InicioFila == NULL)// A fila estava vazia
    return novoNo;
    else return InicioFila;
        
}

int main(){

    struct noFila *TabelaHash[3]; // Esta linha e responsavel por definir a Tabela Hash e o numero de endereços que sera alocado a ela 

    for(int i = 0; i< 3; i++){ // Esta linha sera responsavel por iniciar como NULL todos os endereços da tabela Hash
        TabelaHash[i] = NULL;
    }

    int idade = 0;
    char *nome;
    int indice;

    while(idade != -1){ // Esse while sera responsavel por inserir os dados ate que o usuario digite -1 "esse numero voce que decide"
     cout << "\nDigite a idade do aluno:"; // Lembrando que cout e uma outra alternativa de escrever printf ,ja que usando printf o resultado e o mesmo
     cin >> idade; // Sim poderia ser substituido pelo scanf
     if(idade == -1)
        break; // Se idade for -1 encerra o programa    

    nome = (char *) malloc(sizeof(char) * 30);//Esta linha esta sendo responsavel por alocar memoria para um nome de ate 30 caracteres
    cout << "Digite o nome do aluno:";
    cin >> nome;

    indice = funcaoHash(idade); // Esta linha sera a responsavel por porcurar um endereço hash para armazenar uma nova informação 
    
    TabelaHash[indice] = InserirNaFila(TabelaHash[indice], idade,nome); // Esta linha e responsavel por inserir dados na tabela hash

    cout << "\n\n";
    cout << "\n **** Conteudo da Tabela Hash **** ";

    for(int i = 0; i< 3; i++){ // Este for sera responsavel por imprimir todos os endereços da tabela hash

        if(i == 0)
            cout << "\n ## Endereco" << i << ": idade < 30 anos \n\n"; // Esta linha esta servindo como um printf numa comparação de ifs
            else if(i == 1)
                cout << "\n ## Endereco" << i << ": idade entre 30 e 50 anos \n\n";
                else 
                    cout << "\n ## Endereco" << i << ": idade maior que 50 anos \n\n";
   
        imprimirFila(TabelaHash[i]); // E assim que se imprime uma tabela hash
    }

    }


}