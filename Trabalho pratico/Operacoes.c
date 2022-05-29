/**
* Autor: Pedro Seixas
* E-mail: a21872@alunos.ipca.pt
* Data: 25/05/2022
*
* Colocar outros contribuintes aqui abaixo:
*
*
*/

//Biblioteca nativa de C
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/**
* @brief Opera��es para criar uma nova opera��o, inserir em lista e listagem para teste
*/
#pragma region Operacoes

/**
*@brief aloca espa�o de mem�ria e cria uma nova Opera��o
* @param [in] int cod, c�digo do n�mero da opera��o
*/
operacao* CriarOperacao(int cod) {
	operacao* nova = (operacao*)malloc(sizeof(operacao));
	nova->cod = cod;
	nova->nextM = NULL;
	nova->nextOp = NULL;
}

/**
*@brief fun��o para inserir opera��o no inicio da lista
* @param [in] endere�o da lista de opera��es
* @param [in] endere�o de mem�ria da nova opera��o
*/
operacao* inserirOpeInicio2(operacao* h, operacao* nova) {

	if (h == NULL)
	{
		h = nova;
	}
	else
	{
		nova->nextOp = h;
		h = nova;
	}
}

/**
*@brief Procurar opera��o na lista
* @param [in] endere�o da lista de opera��es
* @param [in] int cod, c�digo do n�mero da opera��o
*/
operacao* procurarOp(operacao* listaOperacao, int cod) {
	operacao* auxOp = NULL;
	operacao* auxOp2 = NULL;

	auxOp2 = listaOperacao;

	int valor = cod;            //Valor do c�digo da opera��o a procurar

	if (auxOp2->nextOp == NULL)
	{
		auxOp = auxOp2;
	}

	while (auxOp2->nextOp != NULL)
	{
		if (auxOp2->cod == valor)
		{
			auxOp = auxOp2;
		}
		auxOp2 = auxOp2->nextOp;
	}
	return auxOp;
}

/**
*@brief Inserir m�quinas em lista de opera��es
* @param [in] endere�o da lista de opera��es
* @param [in] int cadOp, c�digo da opera��o para pesquisar na lista de opera��es
* @param [in] int cadMaq, c�digo da m�quina que ser� informado para a fun��o CriarMaquina
* @param [in] int tempo, unidade de tempo da m�quina que ser� informado para a fun��o CriarMaquina
*/
void InserirMaqnaOpe(operacao* h, int codOp, maquina* nova) {
	operacao* a = NULL;
	operacao* auxO = NULL;

	auxO = h;

	while (auxO != NULL)
	{
		if (auxO->cod == codOp)
		{
			a = auxO;
		}
		auxO = auxO->nextOp;
	}

	a->nextM = inserirMaqInicio2(a->nextM, nova);
}

/**
 * .
 * 
 * \param lista
 * \return 
 */
operacao* menorTempoOpe(operacao* lista)
{
	operacao* aux = lista;
	operacao* novaoperacao = NULL;
	operacao* novaLista = NULL;
	maquina* nova = NULL;

	if (aux == NULL)
	{
		return NULL;
	}

	while (aux != NULL)
	{

		nova = maquinaMenorTempo(aux->nextM);
		novaoperacao = CriarOperacao(aux->cod);
		novaLista = inserirOpeInicio2(novaLista, novaoperacao);

		InserirMaqnaOpe(novaLista, aux->cod, nova);

		aux = aux->nextOp;
	}
	return novaLista;
}

/**
*@brief fun��o para lisar opera��es cadastradas
* @param [in] endere�o da lista de opera��es
*/
void listarCrescenteOpe(operacao* inicio) {

	if (inicio != NULL)
	{
		listarCrescenteOpe(inicio->nextOp);
		printf("Opera��o %d\n", inicio->cod);
	}
}

//Listar as opera��es e suas m�quinas cadastradas
void listarOpeComMaq(operacao* inicio) {

	if (inicio != NULL)
	{
		listarOpeComMaq(inicio->nextOp);
		printf("Lista de m�quinas da opera��o %d\n", inicio->cod);
		if (inicio->nextM->cod != NULL)
		{
			listarCrescenteMaq(inicio->nextM);
			printf("\n");
		}
	}
}
#pragma endregion