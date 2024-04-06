/*- Escreva um programa para ler e armazenar as informações diversos
clientes em uma Lista Encadeada:
• O código do cliente (inteiro);
• A idade (inteiro);
• O salário (float).
As informações devem ser armazenadas em structs e inseridas em
uma Lista Encadeada. Para fazer a inserção de dados, o usuário
deverá escolher a opção no Menu:
1– Inserir no início da Lista
2 – Inserir no fim da Lista
3 – Imprimir a Lista
4 – Sair
• A opção 1 deverá fazer a leitura das informações (código,
idade e salário) e armazenar no INÍCIO da Lista Encadeada.
• A opção 2 deverá fazer a leitura das informações (código,
idade e salário) e armazenar no FINAL da Lista Encadeada.
• A opção 3 deverá imprimir todo o conteúdo da Lista
Encadeada.
• A opção 4 deverá encerrar o programa*/
#include <stdio.h>
#include<stdlib.h>

struct noLista {
    struct noLista *proximoNo;
    int codCliente;
    int idade;
    float salario;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista,int codCliente, int idade,float salario){

    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista)); // verifica a memoria a ser alocada
    novoNo -> codCliente = codCliente; // Esta linha e responsavel por inserir as informaçoes ao nó
    novoNo -> idade= idade; // Esta linha e responsavel por inserir as informaçoes ao nó
    novoNo -> salario = salario; // Esta linha e responsavel por inserir as informaçoes ao nó
    novoNo -> proximoNo = InicioDaLista; // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local que o InicioDaLista apontava

    return novoNo;
};

struct noLista *inserirFinalDaLista(struct noLista* InicioLista,int codCliente, int idade,float salario){

    struct noLista *PercorreLista = InicioLista; // essa linha e responsavel por copiar o inicio da lista
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));

    if(PercorreLista != NULL){

        while(PercorreLista -> proximoNo != NULL){ // esse while e responsavel por percorrer toda a lista ate achar o ultimo no
            PercorreLista = PercorreLista -> proximoNo;
        }

        novoNo -> codCliente = codCliente;// insere a nova informação e para isso temos que declarar na função
        novoNo -> idade = idade; // Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> salario = salario; // Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> proximoNo = PercorreLista -> proximoNo; // Esta linha e responsavel por apontar para o proxino nó que o ultimo estava apontando que e = NULL
        PercorreLista -> proximoNo = novoNo; // Esta linha e responsavel por fazer com que o ultimo nó que agora é penultimo aponte para o novo nó

    }else{

        novoNo -> codCliente = codCliente; // Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> idade = idade;// Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> salario = salario;// Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> proximoNo  = InicioLista; // Esta linha e responsavel por apontar o o campo proximo do novo no para o local que o InicioLista apontava
        InicioLista = novoNo; // Esta linha e responsavel por apontar o inicio da lista para o novo nó
     }

     return InicioLista; 

};


void ImprimirLista(struct noLista *InicioDaLista){
    struct noLista *NoAtual = InicioDaLista; // Esta linha e responsavel por copiar o endereço do primeiro no da lista
    printf("\n -- Conteudo da Lista --");
    while(NoAtual != NULL){
        printf("[Codigo cliente: %d  Salario cliente:%.2f] ->",NoAtual -> codCliente, NoAtual -> salario );// Esta linha e responsavel por mostrar as informaçao do nó
        NoAtual = NoAtual-> proximoNo; // Esta linha e responsavel por apontar para o proximo no
    }
    printf("NULL\n");
} 

int main(){

struct noLista *PrimeiroDaLista = NULL;
int quantidadeCadastrada;
int lugarNaLista;
int idade;
float salario;
int codCliente;

printf("Quantos clientes voce deseja cadastrar ");
scanf("%d",&quantidadeCadastrada);
do{
 for(int i = 0; i < quantidadeCadastrada; i++ ){
        printf("Qual e o codigo do cliente:");
        scanf("%d",&codCliente);
        printf("Digite a idade do seu funcionario:");
        scanf("%d",&idade);
        printf("Digite o salario desse funcionario:");
        scanf("%f",&salario);
        printf("-----------------------\n");
        printf("O que voce deseja fazer agora ? \n");
        printf("1 - Armazenar no inicio da lista\n");
        printf("2 - Armazenar no final da lista \n");
        printf("3 - Imprimir a lista inteira\n");
        printf("4 - Sair do programa\n");
        scanf("%d",&lugarNaLista);
        if(lugarNaLista == 1 ){
            PrimeiroDaLista = inserirInicioLista(PrimeiroDaLista,codCliente,idade,salario);
        }else if(lugarNaLista == 2){
            PrimeiroDaLista = inserirFinalDaLista(PrimeiroDaLista,codCliente,idade,salario);
         }else if(lugarNaLista == 3){
             ImprimirLista(PrimeiroDaLista);
          }else{
              printf("Voce saiu do programa");
           }

 }

}while (lugarNaLista != 4);




}