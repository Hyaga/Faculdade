/*Lista encadeada*/

#include <stdio.h>
#include<stdlib.h>

struct noLista{
    int informacao;
    struct noLista *proximoNo;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista, int NovoNumero)
{
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));
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
     struct noLista *NoAtual   = InicioDaLista;

    while(NoAtual != NULL){
        printf("%d -> ",NoAtual->informacao);
        NoAtual = NoAtual ->proximoNo;
        
    }
    printf("NULL");
}

int main(){

    struct noLista *PrimeiroNoDaLista = NULL;
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,10);
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,20);
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,30);
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,55);
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,90);
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,80);
    ImprimirLista(PrimeiroNoDaLista);
}

