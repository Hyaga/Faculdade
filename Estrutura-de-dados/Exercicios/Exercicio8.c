/*
Criar uma Lista para armazenar os seguintes números, inserindo
sempre no início da Lista:
 Início
Em seguida, realizar as seguintes operações:
• Imprimir apenas o primeiro elemento da lista.
• Imprimir apenas o último elemento da lista.
• Imprimir a lista completa.
• Retornar a quantidade de números existentes na lista
*/

#include <stdio.h>
#include<stdlib.h>

struct noLista {
    struct noLista *noProximo;
    int informacao;
    struct noLista *noAnterior;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista, int NovoNumero)
{

    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));
    novoNo-> informacao = NovoNumero;
    novoNo -> noProximo = InicioDaLista;
    return novoNo;
};


void imprimirInicio(struct noLista *InicioLista)
{
    
    if(InicioLista != NULL){
        printf("O inicio da Lista e %d \n",InicioLista -> informacao);
    }
}

void imprimirFinal(struct noLista *InicioLista){
    struct noLista *PercorreLista = InicioLista;
   
    if(PercorreLista != NULL){

        while(PercorreLista -> noProximo != NULL){
            PercorreLista = PercorreLista -> noProximo;
        }
    printf("O final da lista e %d \n",PercorreLista -> informacao);
        
    }
}
void ImprimirLista(struct noLista *InicioLista){
    struct noLista *NoAtual = InicioLista;
    printf(" -- Conteudo da Lista --");
    while(NoAtual != NULL){
        printf("%d -> ",NoAtual ->informacao );
        NoAtual = NoAtual-> noProximo;
    }
    printf("-> NULL \n");
} 

struct noLista *inserirFinalLista(struct noLista* InicioLista, int NovoNumero){
    struct noLista *PercorreLista = InicioLista;
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));

    if(PercorreLista != NULL){

        while(PercorreLista -> noProximo != NULL){
            PercorreLista = PercorreLista -> noProximo;
        }
        novoNo -> informacao = NovoNumero;// Esta linha e responsavel por inserir informaçoes aos nós
        novoNo -> noProximo = PercorreLista -> noProximo;
        PercorreLista -> noProximo = novoNo;

    }else {
        novoNo -> informacao = NovoNumero;// Esta linha e responsavel por inserir informaçoes aos nós
        novoNo -> noProximo  = InicioLista;
        InicioLista = novoNo;
     }

     return InicioLista; 

};

int main (){
    struct noLista *PrimeiroNoDaLista = NULL;

    printf("\nInserindo o numero 13 no inicio da lista\n");
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,13);
    ImprimirLista(PrimeiroNoDaLista);
    printf("Inserindo o numero 21 no inicio da lista\n");
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,21);
    ImprimirLista(PrimeiroNoDaLista);
    printf("Inserindo o numero 33 no final da lista\n");
    PrimeiroNoDaLista = inserirFinalLista(PrimeiroNoDaLista,33);
    imprimirFinal(PrimeiroNoDaLista);
    imprimirInicio(PrimeiroNoDaLista);
    printf("A lista completa e :");
    ImprimirLista(PrimeiroNoDaLista);
    

}
