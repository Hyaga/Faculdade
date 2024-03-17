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

struct noLista *remove(struct noLista *InicioLista, int ElementoParaRemover){ // remove algo da lista

    struct noLista *NoAnterior = NULL; // aponta para o ponteiro anterior
    struct noLista *PercorreLista = InicioLista; // faz uma copia do inicio da lista para a variavel percorrer

        while(PercorreLista != NULL && PercorreLista -> proximoNo){
            NoAnterior = PercorreLista; // armazena a memoria do no anterior 
            PercorreLista = PercorreLista -> proximoNo; // e a linha que percorre a lista 
        }

        if(PercorreLista == NULL) // quando o PercorreLista for igual a NULL significa que não a mais nada na lista
            return InicioLista;

        if(PercorreLista == NULL){ // quando o PercorreLista for igual a NULL ele retornara para o Inicio da lista 
            InicioLista = PercorreLista -> proximoNo; // e quando isso acontecer declaramos que o inicio da lista apontara para o proximoNo para atualizarmos a lista
        }else{
            NoAnterior -> proximoNo = PercorreLista -> proximoNo; // essa linha liga o NO anterior com o elemento que sera removido
         }

    free(PercorreLista); // a função free libera o espaço de memoria do NO que sera removido "Apaga o NO da memoria"

    return InicioLista;
}

struct noLista *procurarElementosDaLista(struct noLista *InicioLista,int ProcurarElemento){
    struct noLista *PercorreLista;
    PercorreLista = InicioLista; // copia o inicio da lista 

        while(PercorreLista != NULL){ // enquanto existir um NO na lista o while ira funcionar 
            if(PercorreLista -> informacao == ProcurarElemento) // se o percorreLista estiver apontando para o conteudo do ProcurarElemento significa que ele encontrou o No desejado 
                return PercorreLista;   // e a linha responsavel por retornar o No encontrado
                else PercorreLista = PercorreLista -> proximoNo ; // se o Percorre lista nao estiver apontando para o conteudo do ProcurarElemento ele continuara buscando o No na lista 
        }
            return NULL; // caso o codigo saia do while significa que o NO não foi encontrado na lista o que resultara no returno de um dado NULL
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

