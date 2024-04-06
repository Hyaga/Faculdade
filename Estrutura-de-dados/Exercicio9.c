/*Armazene numa Pilha os seguintes dados de 10 pessoas: idade
e altura. Após a leitura dos dados, imprima o conteúdo da Pilha.
Em seguida, desempilhe os dados e mostre apenas as informações
das pessoas do com idade maior do que 18 anos.*/

#include <stdio.h>
#include<stdlib.h>


struct noPilha{
    struct noPilha *proximoNo;
    int idade;
    float altura;
    struct noPilha *noAnterior;
};

struct noPilha *Empilhar(struct noPilha *InicioPilha, int idade ,float altura){
    struct noPilha *novoNo = (struct noPilha*) malloc(sizeof(struct noPilha)); // verifica a memoria a ser alocada
    novoNo -> noAnterior = NULL;
    novoNo -> idade = idade;   //Esta linha e responsavel por Inserir as informação para um novo nó
    novoNo -> altura = altura; //Esta linha e responsavel por Inserir as informação para um novo nó
    novoNo -> proximoNo = InicioPilha; // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local

    if(InicioPilha != NULL) // Esta linha e responvavel por fazer a decisão que se a pilha não estiver vazia, ela liga o nó anterior do inicio da pilha ao um novo nó
        InicioPilha ->noAnterior = novoNo;
    return novoNo;

};

void ImprimirPilha(struct noPilha *topoPilha){
    struct noPilha *noAtual = topoPilha;
    
    while(noAtual != NULL){
        printf("[ Idade cliente:%d  Salario altura:%.2f] ->",noAtual -> idade, noAtual -> altura ); // Esta linha e responsavel por mostrar as informaçao do nó
        noAtual = noAtual-> proximoNo; // Esta linha e responsavel por apontar para o proximo no da Pilha
   
    }
    printf("NULL\n");
    
}
struct noPilha *Desempilhar(struct noPilha *topoPilha){
    
    struct noPilha *PercorrePilha = topoPilha; //  Esta linha e responsavel por fazer uma copia o inicio da pilha
    
        if(PercorrePilha == NULL) // Esta linha e responsavel por falar que não tem elemento para ser removido
            return topoPilha; // Esta linha e responsavel por retornar o primeiro nó da  Pilha

    topoPilha = PercorrePilha -> proximoNo; // Esta linha e responsavel por atualizar o inicio da Pilha
    topoPilha -> noAnterior = NULL; // Esta linha e responsavel por fazer que o primeiro da pilha aponte para o NULL
    free(PercorrePilha); // Esta linha e responsavel por liberar a região de memoria do nó que foi removido
    
    return topoPilha;
}

struct noPilha *procurarElementosDaLista(struct noPilha *InicioPilha,int ProcurarElemento){
    struct noPilha *PercorrePilha;
    PercorrePilha = InicioPilha; // copia o inicio da lista 

        while(PercorrePilha != NULL){ // enquanto existir um NO na lista o while ira funcionar 
            if(PercorrePilha -> idade == ProcurarElemento) // se o percorreLista estiver apontando para o conteudo do ProcurarElemento significa que ele encontrou o No desejado 
                return PercorrePilha;   // e a linha responsavel por retornar o No encontrado
                else PercorrePilha = PercorrePilha -> proximoNo ; // se o Percorre lista nao estiver apontando para o conteudo do ProcurarElemento ele continuara buscando o No na lista 
        }
            return NULL; // caso o codigo saia do while significa que o NO não foi encontrado na lista o que resultara no returno de um dado NULL
};

int main(){
struct noPilha *topoPilha = NULL;
int idade;
float altura;
int contador = 0;
printf("Digite os dados de 10 pessoas.\n");

    while (contador <= 9)
    {
        printf("Digite a idade da %d pessoa:",contador+1);
        scanf("%d",&idade);
        printf("Agora digite a altura da %d pessoa:\n",contador+1);
        scanf("%f",&altura);
            if(idade >= 18){
                    topoPilha = Empilhar(topoPilha,idade,altura);

                    }
        
        contador ++;

    }
        printf("Essa e uma Pilha com as pessoas com idade maiores de 18 anos");
        ImprimirPilha(topoPilha);

}