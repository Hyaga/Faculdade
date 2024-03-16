/*Escreva um programa para cadastrar os dados idade e o salário de
vários funcionários em uma Lista Encadeada. O usuário deverá
informar a quantidade de funcionários que será cadastrado e, em
seguida, fazer a inserção dos dados. Após a inserção dos dados,
imprimir a Lista Encadeada. */

#include <stdio.h>
#include<stdlib.h>

struct noLista{

    struct noLista *proximoNo;
    int idade;
    float salario;
};

struct noLista *inserirInicioLista(struct noLista *InicioDaLista, int idade,float salario){

    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista)); // verifica a memoria a ser alocada
    novoNo -> idade   = idade;
    novoNo -> salario = salario;
    novoNo -> proximoNo = InicioDaLista;

    return novoNo;
};

struct noLista *inserirFinalDaLista(struct noLista* InicioLista, int idade,float salario){

    struct noLista *PercorreLista = InicioLista; // essa linha e responsavel por copiar o inicio da lista
    struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));

    if(PercorreLista != NULL){

        while(PercorreLista -> proximoNo != NULL){ // esse while e responsavel por percorrer toda a lista ate achar o ultimo no
            PercorreLista = PercorreLista -> proximoNo;
        }

        novoNo -> idade = idade; // insere a nova informação e para isso temos que declarar na função  
        novoNo -> salario = salario;
        novoNo -> proximoNo = PercorreLista -> proximoNo;
        PercorreLista -> proximoNo = novoNo;

    }else{

        novoNo -> idade = idade;
        novoNo -> salario = salario;
        novoNo -> proximoNo  = InicioLista;
        InicioLista = novoNo;
     }

     return InicioLista; 

};

void ImprimirLista(struct noLista *InicioDaLista){
    struct noLista *NoAtual = InicioDaLista;
    printf("\n -- Conteudo da Lista --");
    while(NoAtual != NULL){
        printf("A idade do funcionario e:%d - O salario do funcionario e :%.2f ",NoAtual -> idade, NoAtual -> salario );
        NoAtual = NoAtual-> proximoNo;
    }
    printf(" -> NULL");
} 


int main(){

    struct noLista *primeiroNoDaLista = NULL;
    int quantidadeDePessoasCadastradas;
    int lugarNaLista;
    int idade;
    float salario;

    printf("Quantos funcionarios serao cadastrados ?\n");
    scanf("%d",&quantidadeDePessoasCadastradas);

    for(int i= 0; i<quantidadeDePessoasCadastradas; i++){

        printf("Digite a idade do seu funcionario:");
        scanf("%d",&idade);
        printf("\nDigite o salario desse funcionario:");
        scanf("%f",&salario);
        printf("\nAgora escolha aonde o seu funcionario estara localizado na lista 1(inicio da lista) 2(final da lista):");
        scanf("%d",&lugarNaLista);
    }

    if(lugarNaLista == 1){
        primeiroNoDaLista = inserirInicioLista(primeiroNoDaLista,idade,salario);
    }else if(lugarNaLista == 2){
            primeiroNoDaLista = inserirFinalDaLista(primeiroNoDaLista,idade,salario);
     }else{
                printf("Digite um valor valido por favor digite os numeros pedido !");
      }

      ImprimirLista(primeiroNoDaLista);
}
