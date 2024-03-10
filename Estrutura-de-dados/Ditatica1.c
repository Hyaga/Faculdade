/*Lista encadeada*/

#include <stdio.h>
#include<stdlib.h>

struct noLista{
    int informacao;
    struct noLista *proximoNo;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista, int NovoNumero)
{
    struct noLista* novoNo = (struct noLista*) malloc(sizeof(struct noLista));
    novoNo-> informacao = NovoNumero;
    novoNo -> proximoNo = InicioDaLista;

    return novoNo;
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

    ImprimirLista(PrimeiroNoDaLista);
}

