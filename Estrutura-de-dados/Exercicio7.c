/*Escreva um porgrama para ler e armazenas as informações
dos clientes em uma pilha:
- O codigo do cliente (inteiro)
- Idade (inteiro)
- Salario (float)
Depois crie um menu onde o usario possa escolher as opções
1 - Inserir (Empilhar) na Pilha
2 - Remover (Desempilhar) da Pilha
3 - Imprimir a Pilha
4 - Quantidade de elementos da Pilha
5 - Sair do menu*/

#include <stdio.h>
#include<stdlib.h>

struct noPilha { // struct que cria a Pilha
    struct noPilha *noProximo;
    int informacao;
    int codCliente;
    int idade;
    float salario;
    struct noPilha *noAnterior;
};

struct noPilha *Empilhar(struct noPilha *InicioPilha, int novoNumero,int codCliente, int idade,float salario){ 

    struct noPilha *novoNo = (struct noPilha*) malloc(sizeof(struct noPilha)); // verifica a memoria a ser alocada
    novoNo -> noAnterior = NULL; // Esta linha e responsavel por fazer o noAnterior será NULL, pois agora ele será o primeiro da pilha
    novoNo -> informacao = novoNumero; //Esta linha e responsavel por Inserir as informação para um novo nó
    novoNo -> codCliente = codCliente; 
    novoNo -> idade= idade;
    novoNo -> salario = salario;
    novoNo -> noProximo = InicioPilha; // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local que o InicioPilha apontava


    if(InicioPilha != NULL) // Esta linha e responvavel por fazer a decisão que se a pilha não estiver vazia, ela liga o nó anterior do inicio da pilha ao um novo nó
        InicioPilha ->noAnterior = novoNo;
    return novoNo;
};

struct noPilha *Desempilhar(struct noPilha *topoPilha){
    
    struct noPilha *PercorrePilha = topoPilha; //  Esta linha e responsavel por fazer uma copia o inicio da pilha
    
        if(PercorrePilha == NULL) // Esta linha e responsavel por falar que não tem elemento para ser removido
            return topoPilha; // Esta linha e responsavel por retornar o primeiro nó da  Pilha

    topoPilha = PercorrePilha -> noProximo; // Esta linha e responsavel por atualizar o inicio da Pilha
    topoPilha -> noAnterior = NULL; // Esta linha e responsavel por fazer que o primeiro da pilha aponte para o NULL
    free(PercorrePilha); // Esta linha e responsavel por liberar a região de memoria do nó que foi removido
    
    return topoPilha;
}

int contarElementos(struct noPilha *InicioFila){
    struct noPilha *noAtual =InicioFila; // Esta linha e responsavel por copiar o endereço do primeiro no da Pilha
    int contador = 0;
    
    while (noAtual != NULL){ // Esta linha e responsavel por percorrer a pilha até encontrar o ultimo nó que sera = NULL
        contador++; // Esta linha e responsavel por incrementa o contador de elementos
        noAtual = noAtual->noProximo; // Esta linha e responsavel por apontar para o proximo nó da pilha
    }
    return contador;
}

void ImprimirPilha(struct noPilha *topoPilha){
    struct noPilha *noAtual = topoPilha;
    
    while(noAtual != NULL){
        printf("[%d Codigo cliente: %d Idade cliente:%d  Salario cliente:%.2f] ->",noAtual -> informacao,noAtual -> codCliente,noAtual -> idade, noAtual -> salario ); // Esta linha e responsavel por mostrar as informaçao do nó
        noAtual = noAtual-> noProximo; // Esta linha e responsavel por apontar para o proximo no da Pilha
   
    }
    printf("\nNULL");
    
}
int main(){

struct noPilha *topoPilha = NULL;
int numero;
int lugarNaLista;
int idade;
float salario;
int codCliente;
int qtde = contarElementos(topoPilha);

 do{ // Esta linha e responsavel por criar um laço que so ira parar se a condição imposta no while for quebrada
    
    printf("O que voce deseja fazer agora ? \n");
    printf("1 - Inserir (Empilhar) no inicio da Pilha\n");
    printf("2 - Remover (Desempilhar) da pilha \n");
    printf("3 - Imprimir Pilha\n");
    printf("4 - Quantidade de elementos na pilha\n");
    printf("5 - Sair do Menu\n");
    scanf("%d",&lugarNaLista);
        if(lugarNaLista == 1 ){
            printf("Digite o numero:");
            scanf("%d",&numero);
            printf("Qual e o codigo do cliente:");
            scanf("%d",&codCliente);
            printf("Digite a idade do seu funcionario:");
            scanf("%d",&idade);
            printf("Digite o salario desse funcionario:");
            scanf("%f",&salario);
            printf("-----------------------\n");
            topoPilha = Empilhar(topoPilha,numero,codCliente,idade,salario);
        }else if(lugarNaLista == 2){
           topoPilha = Desempilhar(topoPilha);
         }else if(lugarNaLista == 3){
             ImprimirPilha(topoPilha);
          }else if(lugarNaLista == 4){
             qtde = contarElementos(topoPilha);
            printf("\n\n Quantidade de elementos da pilha e %d",qtde);;
           }else{
               printf("Voce saiu do programa");
             }

    }while(lugarNaLista != 5);
           
}