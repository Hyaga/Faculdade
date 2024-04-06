/*Lista encadeada*/

#include <stdio.h>
#include<stdlib.h>

struct noLista{ // Esta linha e responsavel por criar uma lista
    int informacao;
    struct noLista *proximoNo;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista, int NovoNumero) // Esta linha e responsavel por criar uma função para inserir um item no inicio da lista 
{
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista)); // Esta linha e responsavel por verificar a memoria alocada
    novoNo-> informacao = NovoNumero; // Esta linha e responsavel por inserir informaçoes aos nós
    novoNo -> proximoNo = InicioDaLista;  // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local que o InicioDaLista apontava

    return novoNo;
};

struct noLista *inserirFinalDaLista(struct noLista* InicioLista, int NovoNumero){ 
    struct noLista *PercorreLista = InicioLista; // essa linha e responsavel por copiar o inicio da lista
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista)); // Esta linha e responsavel por verificar a memoria alocada

    if(PercorreLista != NULL){ // Enquanto a lista não for vazia 

        while(PercorreLista -> proximoNo != NULL){ // esse while e responsavel por percorrer toda a lista ate achar o ultimo no
            PercorreLista = PercorreLista -> proximoNo;
        }
        novoNo -> informacao = NovoNumero; // Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> proximoNo = PercorreLista -> proximoNo;// Esta linha e responsavel por apontar para o proxino nó que o ultimo estava apontando que e = NULL
        PercorreLista -> proximoNo = novoNo;// Esta linha e responsavel por fazer com que o ultimo nó que agora é penultimo aponte para o novo nó 

    }else {
        novoNo -> informacao = NovoNumero; // Esta linha e responsavel por  inserir as informaçoes ao nó
        novoNo -> proximoNo  = InicioLista;// Esta linha e responsavel por apontar o o campo proximo do novo no para o local que o InicioLista apontava
        InicioLista = novoNo; // Esta linha e responsavel por apontar o inicio da lista para o novo nó
     }

     return InicioLista; 


};

struct noLista *remove(struct noLista *InicioDaLista, int ElementoParaRemover){ // remove algo da lista

    struct noLista *NoAnterior = NULL; // aponta para o ponteiro anterior
    struct noLista *PercorreLista = InicioDaLista; // faz uma copia do inicio da lista para a variavel percorrer

        while(PercorreLista != NULL && PercorreLista -> proximoNo){
            NoAnterior = PercorreLista; // armazena a memoria do no anterior 
            PercorreLista = PercorreLista -> proximoNo; // e a linha que percorre a lista 
        }

        if(PercorreLista == NULL) // quando o PercorreLista for igual a NULL significa que não a mais nada na lista
            return InicioDaLista;

        if(PercorreLista == NULL){ // quando o PercorreLista for igual a NULL ele retornara para o Inicio da lista 
            InicioDaLista = PercorreLista -> proximoNo; // e quando isso acontecer declaramos que o inicio da lista apontara para o proximoNo para atualizarmos a lista
        }else{
            NoAnterior -> proximoNo = PercorreLista -> proximoNo; // essa linha liga o NO anterior com o elemento que sera removido
         }

    free(PercorreLista); // a função free libera o espaço de memoria do NO que sera removido "Apaga o NO da memoria"

    return InicioDaLista;
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
     struct noLista *NoAtual   = InicioDaLista; // Esta linha e responsavel por copiar o endereço do primeiro no da lista

    while(NoAtual != NULL){
        printf("%d -> ",NoAtual->informacao);// Esta linha e responsavel por mostrar as informaçao do nó
        NoAtual = NoAtual ->proximoNo; // Esta linha e responsavel por apontar para o proximo no
        
    }
    printf("NULL");
}

void imprimirInicio(struct noLista *InicioDaLista)
{
    
    if(InicioDaLista != NULL){
    
        printf("O inicio da Lista e %d \n",InicioDaLista -> informacao); // Esta linha e responsavel por mostrar apenas o primeiro item de uma lista
    }
}

void imprimirFinal(struct noLista *InicioDaLista){
    struct noLista *PercorreLista = InicioDaLista;
   
    if(PercorreLista != NULL){

        while(PercorreLista -> proximoNo != NULL){
            PercorreLista = PercorreLista -> proximoNo;
        }
    printf("O final da lista e %d \n",PercorreLista -> informacao);
        
    }
}


int main(){

    struct noLista *PrimeiroNoDaLista = NULL;
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,10);
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,20);
    PrimeiroNoDaLista = inserirInicioLista(PrimeiroNoDaLista,30);
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,55);
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,90);
    PrimeiroNoDaLista = inserirFinalDaLista(PrimeiroNoDaLista,80);
    imprimirInicio(PrimeiroNoDaLista);
    remove(PrimeiroNoDaLista,30);
    imprimirFinal(PrimeiroNoDaLista);
    ImprimirLista(PrimeiroNoDaLista);
}

