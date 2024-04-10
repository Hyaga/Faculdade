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

struct noFila *removerDaFila(struct noFila *InicioFila){
    struct noFila *PercorreFila = InicioFila;

    if(PercorreFila == NULL)
        return InicioFila;
    //Para remover o primeiro da Fila
    InicioFila = PercorreFila -> proximoNo; // Esta linha e responsavel por atualizar o inicio da lista 
    InicioFila -> noAnterior = NULL; //Faz com que o primeiro da fila aponte para NULL 
    free(PercorreFila); // Esta linha sera responsavel por liberar a regiao de memoria do no removido

    return InicioFila;

};  

void ImprimirFila(struct noFila *InicioFila){
    struct noFila *noAtual = InicioFila;
    
    while(noAtual != NULL){
        printf("[O codigo do cliente e:%d] - [A idade do cliente e: %d] - [O salario do cliente e: %.2f]\n",noAtual -> codCliente,noAtual -> idade, noAtual ->salario); // Esta linha e responsavel por mostrar as informaçao do nó
        noAtual = noAtual-> proximoNo; // Esta linha e responsavel por apontar para o proximo no da fila
   
    }
    printf("NULL\n");
    
}

int contarElementos(struct noFila *InicioFila){
    struct noFila *noAtual =InicioFila; // Esta linha e responsavel por copiar o endereço do primeiro no da Pilha
    int contador = 0;
    
    while (noAtual != NULL){ // Esta linha e responsavel por percorrer a pilha até encontrar o ultimo nó que sera = NULL
        contador++; // Esta linha e responsavel por incrementa o contador de elementos
        noAtual = noAtual->proximoNo; // Esta linha e responsavel por apontar para o proximo nó da pilha
    }
    return contador;
}

