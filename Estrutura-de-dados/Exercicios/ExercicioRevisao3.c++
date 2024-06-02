/*Elabore um algoritmo que leia o nome e a idade de um nadador,
classifique-o em uma das seguintes categorias, de acordo com a
seguinte Função Hash.
Idade Categoria
5 até 7 anos Infantil A
8 até 10 anos Infantil B
11 até 13 anos Juvenil A
14 até 17 anos Juvenil B
Maiores de 18
anos
Adulto
O programa deverá apresentar os dados dos nadadores que estão em
cada uma das categorias da Tabela Hash (Alocação Dinâmica).*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct noFila
{
  int idade;
  struct noFila *noProximo;
  struct noFila *noAnterior;
};

int
funcaoHash (int valor)
{
  int indice_endereco;
  if ((valor >= 5) && (valor <= 7))
	indice_endereco = 0;
  else if ((valor >= 8) && (valor <= 10))
	indice_endereco = 1;
  else if ((valor >= 11) && (valor <= 13))
	indice_endereco = 2;
  else if ((valor >= 14) && (valor <= 17))
	indice_endereco = 3;
  else if (valor >= 18)
	indice_endereco = 4;
  else
	printf ("O nadador nao possui idade valida");

  return indice_endereco;
}

void
imprimirFila (struct noFila *InicioFila)
{
  struct noFila *NoAtual = InicioFila;

  while (NoAtual != NULL)
	{
	  printf ("\n Idade: %d ", NoAtual->idade);
	  NoAtual = NoAtual->noProximo;
	}
  printf ("\n --- Fim da Lista --- ");
}

struct noFila *
InserirNaFila (struct noFila *InicioFila, int idade)
{
  struct noFila *PercorreFila = InicioFila;
  struct noFila *novoNo = (struct noFila *) malloc (sizeof (struct noFila));

  if (PercorreFila != NULL)
	{
	  while (PercorreFila->noProximo != NULL)
		{
		  PercorreFila = PercorreFila->noProximo;
		}

	  PercorreFila->noProximo = novoNo;
	}
  novoNo->noAnterior = PercorreFila;
  novoNo->idade = idade;
  novoNo->noProximo = NULL;

  if (InicioFila == NULL)
	return novoNo;
  else
	return InicioFila;
}


int
main ()
{
  struct noFila *TabelaHash[5];

  for (int i = 0; i < 5; i++)
	{
	  TabelaHash[i] = NULL;
	}

  int idade = 0;
  int indice;

  while (idade != -1)
	{
	  cout << "\nDigite a idade do aluno:";
	  cin >> idade;
	  if (idade == -1)
		break;


	  indice = funcaoHash (idade);
	  TabelaHash[indice] = InserirNaFila (TabelaHash[indice], idade);
	  cout << "\n";
	  cout << "\n **** Conteudo da Tabela Hash **** ";

	  for (int i = 0; i < 5; i++)
		{
		  if (i == 0)
			cout << "\n ## O aluno esta no  " << i << " Infantil A\n";
		  else if (i == 1)
			cout << "\n ## O aluno esta no " << i << " Infantil B\n";
		  else if (i == 2)
			cout << "\n ##  O aluno esta no  " << i << " Juvenil A \n";
		  else if (i == 3)
			cout << "\n ##  O aluno esta no  " << i << " Juvenil B \n";
		  else if (i == 4)
            cout << "\n ##  O aluno esta no  " << i << " Adulto \n";
            


			imprimirFila (TabelaHash[i]);
		}
	}
}
