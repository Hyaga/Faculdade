/*Implemente um programa que leia 15 números. Para cada 
número lido, verifique se é ele é par: se for, inserir em uma Pilha. 
Ao final da leitura dos números, mostrar a quantidade de elementos 
da Pilha. Em seguida, desempilhar todos os números e mostrar na 
tela.*/


#include <stdio.h>
#include<stdlib.h>


struct noPilha{
    struct noPilha *proximoNo;
    int numero;
    struct noPilha *noAnterior;
};

struct noPilha *Empilhar(struct noPilha *InicioPilha, int numero){
    struct noPilha *novoNo = (struct noPilha*) malloc(sizeof(struct noPilha)); // verifica a memoria a ser alocada
    novoNo -> noAnterior = NULL;
    novoNo -> numero = numero;
    novoNo -> proximoNo = InicioPilha; // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local

    if(InicioPilha != NULL) // Esta linha e responvavel por fazer a decisão que se a pilha não estiver vazia, ela liga o nó anterior do inicio da pilha ao um novo nó
        InicioPilha ->noAnterior = novoNo;
    return novoNo;

};

struct noPilha *Desempilhar(struct noPilha *topoPilha){
    
    struct noPilha *PercorrePilha = topoPilha; //  Esta linha e responsavel por fazer uma copia o inicio da pilha
    
        if(PercorrePilha == NULL) // Esta linha e responsavel por falar que não tem elemento para ser removido
            return topoPilha; // Esta linha e responsavel por retornar o primeiro nó da  Pilha

    topoPilha = PercorrePilha -> proximoNo; // Esta linha e responsavel por atualizar o inicio da Pilha
    topoPilha -> noAnterior = NULL; // Esta linha e responsavel por fazer que o primeiro da pilha aponte para o NULL
    free(PercorrePilha); // Esta linha e responsavel por liberar a região de memoria do nó que foi removido
    
    return topoPilha;
}


void ImprimirPilha(struct noPilha *topoPilha){
    struct noPilha *noAtual = topoPilha;
    
    while(noAtual != NULL){
        printf(" %d  -->",noAtual -> numero); // Esta linha e responsavel por mostrar as informaçao do nó
        noAtual = noAtual-> proximoNo; // Esta linha e responsavel por apontar para o proximo no da Pilha
   
    }
    printf("NULL\n");
    
}

int contarElementos(struct noPilha *InicioPilha){
    struct noPilha *noAtual =InicioPilha; // Esta linha e responsavel por copiar o endereço do primeiro no da Pilha
    int contador = 0;
    
    while (noAtual != NULL){ // Esta linha e responsavel por percorrer a pilha até encontrar o ultimo nó que sera = NULL
        contador++; // Esta linha e responsavel por incrementa o contador de elementos
        noAtual = noAtual->proximoNo; // Esta linha e responsavel por apontar para o proximo nó da pilha
    }
    return contador;
}

int main(){
struct noPilha *topoPilha = NULL;
int numero;
int contador = 0;
int qtde = contarElementos(topoPilha);
    
    printf("Digite os dados de 15 numeros.\n");
        while (contador <= 14)
        {
            printf("Digite um numero %d :",contador+1);
            scanf("%d",&numero);
                 if(numero % 2 == 0){ // Esta linha e responsavel por identificar qual numero e par e qual e impar 
                        topoPilha = Empilhar(topoPilha,numero); // Enquanto o numero for par ele sera empilhado
                 }
            qtde = contarElementos(topoPilha);
            
            contador ++;
        }
            printf("\nQuantidade de elementos da pilha e :%d \n",qtde);
            printf("Essa e uma Pilha com os numeros pares digitados:\n");
            ImprimirPilha(topoPilha);
            Desempilhar(topoPilha);

}