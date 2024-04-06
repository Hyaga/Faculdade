/*Escreva um programa para cadatrar o codigo e salario de um funcionario em uma lista
- O usuario deve informar a quantidade de funcionarios que será cafastrada
- Apos a inserção dos dados imprima a lista
- Depois o usuario deve informar um codigo de cliente para verificar se ele existe na lista ou nao
- O usuario devera informar um codigo para remover da lista
- Imprima a lista depois  */

#include <stdio.h>
#include<stdlib.h>

struct noLista {
    struct noLista *proximoNo;
    int codCliente;
    float salario;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista,int codCliente,float salario){

    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista)); // verifica a memoria a ser alocada
    novoNo -> codCliente = codCliente; // Esta linha e responsavel por inserir informaçoes ao nó
    novoNo -> salario = salario; // Esta linha e responsavel por  inserir as informaçoes ao nó
    novoNo -> proximoNo = InicioDaLista; // Esta linha e responsavel por apontar o campo "proximo" do novo nó para o local que o InicioPilha apontava

    return novoNo;
};

struct noLista *inserirFinalDaLista(struct noLista* InicioLista,int codCliente,float salario){

    struct noLista *PercorreLista = InicioLista; // essa linha e responsavel por copiar o inicio da lista
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));

    if(PercorreLista != NULL){

        while(PercorreLista -> proximoNo != NULL){ // esse while e responsavel por percorrer toda a lista ate achar o ultimo no
            PercorreLista = PercorreLista -> proximoNo;
        }

        novoNo -> codCliente = codCliente;// Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> salario = salario; // Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> proximoNo = PercorreLista -> proximoNo; // Esta linha e responsavel por apontar para o proxino nó que o ultimo estava apontando que e = NULL
        PercorreLista -> proximoNo = novoNo; // Esta linha e responsavel por fazer com que o ultimo nó que agora é penultimo aponte para o novo nó 

    }else{

        novoNo -> codCliente = codCliente; // Esta linha e responsavel por  inserir as informaçoes ao nó
        novoNo -> salario = salario; // Esta linha e responsavel por inserir as informaçoes ao nó
        novoNo -> proximoNo  = InicioLista; // Esta linha e responsavel por apontar o o campo proximo do novo no para o local que o InicioLista apontava
        InicioLista = novoNo; // // Esta linha e responsavel por apontar o inicio da lista para o novo nó
     }

     return InicioLista; 

};
struct noLista *removeCod(struct noLista *InicioLista, int ElementoParaRemover){ // remove algo da lista

    struct noLista *NoAnterior = NULL; // aponta para o ponteiro anterior
    struct noLista *PercorreLista = InicioLista; // faz uma copia do inicio da lista para a variavel percorrer

        while(PercorreLista != NULL && PercorreLista -> codCliente != ElementoParaRemover){
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
            if(PercorreLista -> codCliente == ProcurarElemento) // se o percorreLista estiver apontando para o conteudo do ProcurarElemento significa que ele encontrou o No desejado 
                return PercorreLista;   // e a linha responsavel por retornar o No encontrado
                else PercorreLista = PercorreLista -> proximoNo ; // se o Percorre lista nao estiver apontando para o conteudo do ProcurarElemento ele continuara buscando o No na lista 
        }
            return NULL; // caso o codigo saia do while significa que o NO não foi encontrado na lista o que resultara no returno de um dado NULL
};

void ImprimirLista(struct noLista *InicioDaLista){
    struct noLista *NoAtual = InicioDaLista;
    printf("\n -- Conteudo da Lista --");
    while(NoAtual != NULL){
        printf("[Codigo cliente: %d  Salario cliente:%.2f] ->",NoAtual -> codCliente, NoAtual -> salario );// Esta linha e responsavel por mostrar as informaçao do nó
        NoAtual = NoAtual-> proximoNo; // Esta linha e responsavel por apontar para o proximo no
    }
    printf("NULL\n");
} 

int main(){

struct noLista *PrimeiroDaLista = NULL;
int quantidadeCadastrada;
int lugarNaLista;
float salario;
int codCliente;
int procurarCodigo;
int removerCodigo;

printf("Quantos clientes voce deseja cadastrar:\n ");
scanf("%d",&quantidadeCadastrada);
 for(int i = 0; i < quantidadeCadastrada; i++ ){
        printf("Qual e o codigo do cliente:");
        scanf("%d",&codCliente);
        printf("Digite o salario desse funcionario:\n");
        scanf("%f",&salario);
        printf("Agora escolha aonde o seu funcionario estara localizado na lista 1(inicio da lista) 2(final da lista):\n");
        scanf("%d",&lugarNaLista);
        if(lugarNaLista == 1){
            PrimeiroDaLista = inserirInicioLista(PrimeiroDaLista,codCliente,salario);
        }else if(lugarNaLista == 2){
                PrimeiroDaLista = inserirFinalDaLista(PrimeiroDaLista,codCliente,salario);
          }else{
                    printf("Digite um valor valido por favor digite os numeros pedido !");
            }

 }
ImprimirLista(PrimeiroDaLista);
printf("Qual e o codigo que voce deseja procurar:\n");
scanf("%d",&procurarCodigo);
    if(procurarElementosDaLista(PrimeiroDaLista,procurarCodigo) == NULL){
        printf("Codigo nao encontrado\n");
    }else{
        printf("O codigo vou encontrado");
    }
ImprimirLista(PrimeiroDaLista);
printf("\nAgora digite o codigo que voce deseja remover:");
scanf("%d",&removerCodigo);
PrimeiroDaLista = removeCod(PrimeiroDaLista,removerCodigo);
ImprimirLista(PrimeiroDaLista);

}