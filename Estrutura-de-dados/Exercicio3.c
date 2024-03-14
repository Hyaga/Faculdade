/*Implemente um programa que insira 2 números no início de uma
Lista Encadeada e 1 número no fim desta Lista. Em seguida,
imprima a lista.*/

#include <stdio.h>
#include<stdlib.h>

struct noLista{
    int informacao;
    struct noLista *proximoNo;
};


struct noLista *inserirInicioLista(struct noLista *InicioDaLista, int NovoNumero)
{
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista)); // verifica a memoria a ser alocada
    novoNo-> informacao = NovoNumero;
    novoNo -> proximoNo = InicioDaLista;

    return novoNo;
};

struct noLista *inserirFinalDaLista(struct noLista* InicioLista, int NovoNumero){
    struct noLista *PercorreLista = InicioLista;
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));

    if(PercorreLista != NULL){

        while(PercorreLista -> proximoNo != NULL){
            PercorreLista = PercorreLista -> proximoNo;
        }
        novoNo -> informacao = NovoNumero;
        novoNo -> proximoNo = PercorreLista -> proximoNo;
        PercorreLista -> proximoNo = novoNo;

    }else {
        novoNo -> informacao = NovoNumero;
        novoNo -> proximoNo  = InicioLista;
        InicioLista = novoNo;
     }

     return InicioLista; 

    };
void ImprimirLista(struct noLista *InicioDaLista){
    struct noLista *NoAtual = InicioDaLista;
    printf("\n -- Conteudo da Lista --");
    while(NoAtual != NULL){
        printf("%d -> ",NoAtual ->informacao );
        NoAtual = NoAtual-> proximoNo;
    }
    printf("NULL");
} 


int main (){
    struct noLista *PrimeiroNoDaLista = NULL;

    printf("\nInserindo o numero 13 no inicio da lista");
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,13);
    ImprimirLista(PrimeiroNoDaLista);
    printf("\nInserindo o numero 21 no inicio da lista");
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,21);
    ImprimirLista(PrimeiroNoDaLista);
    printf("\nInserindo o numero 22 no final da lista");
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,22);
    ImprimirLista(PrimeiroNoDaLista);

}