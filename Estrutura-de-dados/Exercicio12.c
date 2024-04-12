/*9) Escreva um programa para ler e armazenar as informações 
diversos clientes em uma PILHA ou FILA:
• O código do cliente (inteiro);
• A idade (inteiro);
• O salário (float).
As informações devem ser armazenadas em structs. Para fazer a 
inserção de dados, o usuário deverá escolher a opção no Menu:
• A opção 1 deverá fazer a leitura das informações (código, idade e 
salário) e inserir (empilhar) na PILHA
• A opção 2 deverá remover (desempilhar) um elemento da PILHA. 
• A opção 3 deverá imprimir todo o conteúdo PILHA.
• A opção 4 deverá mostrar a quantidade de elementos da PILHA.
• A opção 5 deverá procurar um código na PILHA;
• A opção 6 deverá fazer a leitura das informações (código, idade e 
salário) e inserir na FILA
• A opção 7 deverá remover um elemento da FILA . 
• A opção 8 deverá imprimir todo o conteúdo FILA.
• A opção 9 procurar um código na FILA.
• A opção 10 deverá encerrar o programa.*/

#include <stdio.h>
#include<stdlib.h>

struct noPilha { // struct que cria a Pilha
    struct noPilha *noProximo;
    int informacao;
    int codCliente;
    int idade;
    float salario;
    struct noPilha *noAnterior;
};

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

struct noFila *procurarElementosFila(struct noFila *InicioFila,int ProcurarElemento){
    struct noFila *PercorreFila;
    PercorreFila = InicioFila; // copia o inicio da lista 

        while(PercorreFila != NULL){ // enquanto existir um NO na lista o while ira funcionar 
            if(PercorreFila -> idade == ProcurarElemento) // se o percorreLista estiver apontando para o conteudo do ProcurarElemento significa que ele encontrou o No desejado 
                return PercorreFila;  // e a linha responsavel por retornar o No encontrado
                else PercorreFila = PercorreFila -> proximoNo ; // se o Percorre lista nao estiver apontando para o conteudo do ProcurarElemento ele continuara buscando o No na lista 
        }
            return NULL; // caso o codigo saia do while significa que o NO não foi encontrado na lista o que resultara no returno de um dado NULL
};

struct noPilha *Empilhar(struct noPilha *InicioPilha, int novoNumero,int codCliente, int idade,float salario){ 

    struct noPilha *novoNo = (struct noPilha*) malloc(sizeof(struct noPilha)); // verifica a memoria a ser alocada
    novoNo -> noAnterior = NULL; // Esta linha e responsavel por fazer o noAnterior será NULL, pois agora ele será o primeiro da pilha
    novoNo -> informacao = novoNumero; //Esta linha e responsavel por Inserir as informação para um novo nó
    novoNo -> codCliente = codCliente; 
    novoNo -> idade= idade;
    novoNo -> salario = salario;
    novoNo -> noProximo = InicioPilha; // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local que o InicioPilha apontava


    if(InicioPilha != NULL) // Esta linha e responvavel por fazer a decisão que se a pilha não estiver vazia, ela liga o nó anterior do inicio da pilha ao um novo nó
        InicioPilha ->noAnterior = novoNo;
    return novoNo;
};

struct noPilha *Desempilhar(struct noPilha *topoPilha){
    
    struct noPilha *PercorrePilha = topoPilha; //  Esta linha e responsavel por fazer uma copia o inicio da pilha
    
        if(PercorrePilha == NULL) // Esta linha e responsavel por falar que não tem elemento para ser removido
            return topoPilha; // Esta linha e responsavel por retornar o primeiro nó da  Pilha

    topoPilha = PercorrePilha -> noProximo; // Esta linha e responsavel por atualizar o inicio da Pilha
    topoPilha -> noAnterior = NULL; // Esta linha e responsavel por fazer que o primeiro da pilha aponte para o NULL
    free(PercorrePilha); // Esta linha e responsavel por liberar a região de memoria do nó que foi removido
    
    return topoPilha;
}

int contarElementos(struct noPilha *InicioPilha){
    struct noPilha *noAtual =InicioPilha; // Esta linha e responsavel por copiar o endereço do primeiro no da Pilha
    int contador = 0;
    
    while (noAtual != NULL){ // Esta linha e responsavel por percorrer a pilha até encontrar o ultimo nó que sera = NULL
        contador++; // Esta linha e responsavel por incrementa o contador de elementos
        noAtual = noAtual->noProximo; // Esta linha e responsavel por apontar para o proximo nó da pilha
    }
    return contador;
}

void ImprimirPilha(struct noPilha *topoPilha){
    struct noPilha *noAtual = topoPilha;
    
    while(noAtual != NULL){
        printf("[%d Codigo cliente: %d Idade cliente:%d  Salario cliente:%.2f] ->",noAtual -> informacao,noAtual -> codCliente,noAtual -> idade, noAtual -> salario ); // Esta linha e responsavel por mostrar as informaçao do nó
        noAtual = noAtual-> noProximo; // Esta linha e responsavel por apontar para o proximo no da Pilha
   
    }
    printf("\nNULL");
    
}

struct noPilha *procurarElementosDaPilha(struct noPilha *InicioPilha,int ProcurarElemento){
    struct noPilha *PercorrePilha;
    PercorrePilha = InicioPilha; // copia o inicio da lista 

        while(PercorrePilha != NULL){ // enquanto existir um NO na lista o while ira funcionar 
            if(PercorrePilha -> codCliente == ProcurarElemento) // se o percorreLista estiver apontando para o conteudo do ProcurarElemento significa que ele encontrou o No desejado 
                return PercorrePilha;   // e a linha responsavel por retornar o No encontrado
                else PercorrePilha = PercorrePilha -> noProximo ; // se o Percorre lista nao estiver apontando para o conteudo do ProcurarElemento ele continuara buscando o No na lista 
        }
            return NULL; // caso o codigo saia do while significa que o NO não foi encontrado na lista o que resultara no returno de um dado NULL
};

int main(){

struct noPilha *topoPilha = NULL;
struct noFila *InicioFila = NULL;

int numero;
int lugarNaLista;
int procuraCod;
int idade;
float salario;
int codCliente;
int qtde = contarElementos(topoPilha);

 do{ // Esta linha e responsavel por criar um laço que so ira parar se a condição imposta no while for quebrada
    
    printf("O que voce deseja fazer agora ? \n");
    printf("1 - Inserir (Empilhar) no inicio da Pilha\n");
    printf("2 - Remover (Desempilhar) da pilha \n");
    printf("3 - Imprimir Pilha\n");
    printf("4 - Quantidade de elementos na pilha\n");
    printf("5 - Procurar um codigo de cliente na pilha\n");
    printf("6 - Insira na Fila\n");
    printf("7 - Remover da Fila\n");
    printf("8 - Imprimir toda a Fila\n");
    printf("9 - Procurar codigo na Fila\n");
    printf("10 - Encerrar programa\n");
    scanf("%d",&lugarNaLista);
        if(lugarNaLista == 1 ){
            printf("Digite o numero:");
            scanf("%d",&numero);
            printf("Qual e o codigo do cliente:");
            scanf("%d",&codCliente);
            printf("Digite a idade do seu funcionario:");
            scanf("%d",&idade);
            printf("Digite o salario desse funcionario:");
            scanf("%f",&salario);
            printf("-----------------------\n");
            topoPilha = Empilhar(topoPilha,numero,codCliente,idade,salario);
        }else if(lugarNaLista == 2){
           topoPilha = Desempilhar(topoPilha);
         }else if(lugarNaLista == 3){
             ImprimirPilha(topoPilha);
          }else if(lugarNaLista == 4){
             qtde = contarElementos(topoPilha);
            printf("\nQuantidade de elementos da pilha e :%d \n",qtde);
           }else if(lugarNaLista == 5){
                printf("Digite o codigo do cliente que voce deseja procurar:");
                scanf("%d",&procuraCod);
                    if(procurarElementosDaPilha(topoPilha,procuraCod) == NULL){
                        printf("O codigo nao foi encontrado\n");
                    }else{
                        printf("O codigo foi encontrado\n");
                    }
             }else if(lugarNaLista == 6){
                printf("Digite o codigo do cliente:");
                scanf("%d",&codCliente);
                printf("Digite a idade do cliente:");
                scanf("%d",&idade);
                printf("Agora digite quanto esse cliente recebe de salario:");
                scanf("%f",&salario);
                InicioFila = InserirNaFila(InicioFila,codCliente,salario,idade);
               }else if(lugarNaLista == 7){
                    InicioFila =removerDaFila(InicioFila);
                 }else if(lugarNaLista == 8){
                     ImprimirFila(InicioFila);
                  }else if(lugarNaLista == 9){
                        printf("Digite o codigo do cliente que voce deseja procurar:");
                        scanf("%d",&procuraCod);
                            if(procurarElementosFila(InicioFila,procuraCod) == NULL){
                                printf("O codigo nao foi encontrado");
                            }else{
                                printf("O codigo foi encontrado");
                             }
                   }else if(lugarNaLista == 10){
                    printf("Programa encerrado");
                    }

    }while(lugarNaLista != 10);
           
}