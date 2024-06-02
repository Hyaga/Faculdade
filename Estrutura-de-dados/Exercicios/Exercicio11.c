/*Escreva um programa para ler e armazenar as informações de 5 
clientes e armazenar em uma Fila, a qual será a ordem de 
atendimento no setor de RH:
• O código do cliente (inteiro);
• A idade;
• O salário.
Em seguida, as seguintes operações devem ser realizadas:
• Relatório contendo todos os dados de todos os clientes 
cadastrados. 
• Mostrar qual é o cliente que está na primeira posição da 
fila de atendimento;
• Solicitar ao usuário que digite o código de um cliente e 
verificar se tal cliente encontra-se cadastrado, ou seja, se o 
código informado está presente na Fila. Caso afirmativo, o 
programa deverá mostrar todos os dados do cliente 
consultado. Caso contrário, o programa deverá mostrar 
uma mensagem informando que o cliente não está 
cadastrado.*/

#include <stdio.h>
#include<stdlib.h>

struct noFila {
    struct noFila *proximoNo;
    int codCliente;
    int idade;
    float salario;
    struct noFila *noAnterior;
};

struct noFila *InserirNaFila(struct noFila *InicioFila, int codCliente,int idade,float salario){
    struct noFila *PercorreFila = InicioFila; // Esta linha e responsavel por copiar o inicio da fila
    struct noFila *novoNo = (struct noFila*) malloc(sizeof(struct noFila)); // verifica a memoria a ser alocada

    if(PercorreFila != NULL){ // Se a fila não estiver vazia

        while (PercorreFila -> proximoNo != NULL) // Esta linha vai ser responsavel por percorrer toda a fila ate encontrar o ultimo no
        {
            PercorreFila = PercorreFila -> proximoNo;
        }

        PercorreFila -> proximoNo = novoNo; // Esta linha e responsavel por fazer o ultimo no se trasformar em penultimo apontar para o novoNo
    
    }
    novoNo -> noAnterior = PercorreFila; // Esta linha e responsavel por apontar o campo noAnterior para o no PercorreFila
    novoNo -> codCliente = codCliente; //Esta linha e responsavel por colocar as informações nos nos
    novoNo -> idade = idade; //Esta linha e responsavel por colocar as informações nos nos
    novoNo -> salario = salario; //Esta linha e responsavel por colocar as informações nos nos
    novoNo -> proximoNo = NULL; // Esta linha vai fazer o novoNo ser o ultimo da Fila

    if(InicioFila == NULL)// A fila estava vazia
    return novoNo;
    else return InicioFila;

}

void ImprimirFila(struct noFila *InicioFila){
    struct noFila *noAtual = InicioFila;
    
    while(noAtual != NULL){
        printf("[O codigo do cliente e:%d] - [A idade do cliente e: %d] - [O salario do cliente e: %.2f]\n",noAtual -> codCliente,noAtual -> idade, noAtual ->salario); // Esta linha e responsavel por mostrar as informaçao do nó
        noAtual = noAtual-> proximoNo; // Esta linha e responsavel por apontar para o proximo no da fila
   
    }
    printf("NULL\n");
    
}

void imprimirFinalDaFila(struct noFila *InicioFila) // Esta função sera responsavel por imprimir o final da fila 
{
    
    if(InicioFila != NULL){
        printf("O inicio da Fila e %d \n",InicioFila -> codCliente);
    }
}

struct noFila *procurarElementosDFila(struct noFila *InicioFila,int ProcurarElemento){
    struct noFila *PercorreFila;
    PercorreFila = InicioFila; // copia o inicio da lista 

        while(PercorreFila != NULL){ // enquanto existir um NO na lista o while ira funcionar 
            if(PercorreFila -> idade == ProcurarElemento) // se o percorreLista estiver apontando para o conteudo do ProcurarElemento significa que ele encontrou o No desejado 
                return PercorreFila;  // e a linha responsavel por retornar o No encontrado
                else PercorreFila = PercorreFila -> proximoNo ; // se o Percorre lista nao estiver apontando para o conteudo do ProcurarElemento ele continuara buscando o No na lista 
        }
            return NULL; // caso o codigo saia do while significa que o NO não foi encontrado na lista o que resultara no returno de um dado NULL
};

int main(){

    struct noFila *InicioFila = NULL;

    int idade;
    int procuraCod;
    int codCliente;
    float salario;
    int decisao;

    for(int i=0; i<5;i++){

    printf("Digite o codigo do cliente:");
    scanf("%d",&codCliente);
    printf("Digite a idade do cliente:");
    scanf("%d",&idade);
    printf("Agora digite quanto esse cliente recebe de salario:");
    scanf("%f",&salario);
    InicioFila = InserirNaFila(InicioFila,codCliente,salario,idade);

    }

    printf("\n---------------\n");
    printf("Agora o que voce deseja fazer?");
    printf("\n1- Mostrar os dados de todos os clientes da Fila");
    printf("\n2- Mostrar quem e o cliente que esta em primeiro na fila");
    printf("\n3- Validade se o codigo do cliente existe.");
    scanf("%d",&decisao);

    if(decisao == 1){
        ImprimirFila(InicioFila);
    }else if(decisao == 2){
        imprimirFinalDaFila(InicioFila);
     }else if(decisao == 3){
        printf("Digite o codigo do cliente que voce deseja procurar:");
        scanf("%d",&procuraCod);
             if(procurarElementosDFila(InicioFila,procuraCod) == NULL){
                printf("O codigo nao foi encontrado");
             }else{
                printf("O codigo foi encontrado");
              }
      }else{
        printf("Numero invalido");
       }
}