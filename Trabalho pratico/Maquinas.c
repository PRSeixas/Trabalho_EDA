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
* @brief Opera��es para criar uma nova m�quina com seus par�metros, inserir em lista e listagem para teste
*/
#pragma region Maquinas

/**
 * .
 * @brief aloca espa�o de mem�ria e cria uma nova m�quina
 * \param cod		c�digo da m�quina
 * \param tempo		unidade de tempo
 * \return 
 */
maquina* CriarMaquina(int cod, int tempo) {
	maquina* nova = (maquina*)malloc(sizeof(maquina));
	nova->cod = cod;
	nova->und = tempo;
	nova->nextm = NULL;
	return nova;
}

/**
 * .
 * @brief fun��o para inserir m�quina no in�cio da lista
 * \param h			endere�o da lista
 * \param nova		nova m�quina criada
 * \return 
 */
maquina* inserirMaqInicio2(maquina* h, maquina* nova) {

	if (h == NULL)
	{
		h = nova;
	}
	else
	{
		nova->nextm = h;
		h = nova;
	}
}

/**
 * .
 * @brief Fun��o para remover m�quina da lista
 * \param lista
 * \param valor		c�digo da m�quina
 */
void RemoverMaq2(maquina* lista, int valor) {
	maquina* inicio = (maquina*)malloc(sizeof(maquina));
	maquina* maquinaremover = NULL;

	inicio->nextm = lista->nextm;

	if (inicio != NULL && lista->cod == valor)
	{
		maquinaremover = lista;
		lista->nextm = maquinaremover->nextm;
	}
	else
	{
		while (inicio != NULL && inicio->nextm != NULL && inicio->nextm->cod != valor)
		{
			inicio = inicio->nextm;
		}
		if (inicio != NULL && inicio->nextm != NULL)
		{
			maquinaremover = inicio->nextm;
			inicio->nextm = maquinaremover->nextm;
		}
	};
	if (maquinaremover != NULL)
	{
		free(maquinaremover);
	}
}

/**
 * .
 * Fun��o para devolver a m�quina com menor tempo de uma opera��o
 * \param lista
 * \return 
 */
maquina* maquinaMenorTempo(maquina* lista)
{
	maquina* aux = lista;

	if (aux == NULL)
	{
		return NULL;
	}

	maquina* minimo = aux;
	aux = aux->nextm;

	while (aux != NULL)
	{
		if (minimo->und > aux->und)
		{
			minimo = aux;
		}
		aux = aux->nextm;
	}
	minimo->nextm = NULL;

	return minimo;
}

/**
 * .
 * @brief Fun��o para imprimiar uma lista de m�quinas
 * \param inicio
 */
void listarCrescenteMaq(maquina* inicio)
{
	if (inicio != NULL)
	{
		listarCrescenteMaq(inicio->nextm);
		printf("Maquina %d e unidade de tempo %d\n", inicio->cod, inicio->und);
	}
}

/**
 * .
 * @brief Fun��o para inserir m�quina no final da lista, usado na fase um apenas.
 * \param lista
 * \param valor
 * \param tempo
 * \param operacao
 * \param job
 * \return 
 */
maquina* inserirMaqFim2(ListaMaquina* lista, int valor, int tempo, int operacao, int job) {
	maquina* novo = (maquina*)malloc(sizeof(maquina));
	maquina* aux = (maquina*)malloc(sizeof(maquina));
	novo->cod = valor;             //Valor do c�digo da nova m�quina
	novo->und = tempo;             //Valor de unidade de tempo
	novo->op = operacao;           //Valor da opera��o cadastrada
	novo->job = job;               //Valor do job pertencente
	novo->nextm = NULL;            //Novo bloco aponta para NULL pois encontra-se no final da lista.

	if (lista->inicio == NULL) {
		lista->inicio = novo;
	}
	else {
		aux->nextm = lista->inicio;
		while (aux->nextm != NULL)
		{
			aux = aux->nextm;
		}
		aux->nextm = novo;
		lista->tam++;
	}
}

/**
 * .
 * @brief Fun��o para imprimir uma lista simples de m�quinas, usado na primeira fase apenas.
 * \param lista
 */
void imprimirMaq2(maquina* lista) {
	maquina* inicio = lista->nextm;
	while (inicio != NULL)
	{
		printf("Maquina %d\n", inicio->cod);
		printf("Unidade de tempo %d\n", inicio->und);
		printf("Opera��o a que pertence:%d\n", inicio->op);
		printf("Job a que pertence:%d\n\n", inicio->job);
		inicio = inicio->nextm;
	}
	printf("\n");
}

//Teste de funcionamento ok. Efetuar aloca��o na aba correspondente e comentar
/**
 * .
 * @brief Fun��o para inserir m�quinas na lista de opera��es a partir de um ficheiro.
 * \param nomeFicheiro
 * \param rootOpe
 * \return 
 */
maquina* lerFicheiroMaquinas(char* nomeFicheiro, operacao* rootOpe)
{
	FILE* fp;
	maquina* root = NULL;
	maquina* nova;
	int codOpe;

	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	maquina auxMaq;
	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF) {
		sscanf(c, "%d\t%d\t%d\n", &codOpe, &auxMaq.cod, &auxMaq.und);

		nova = CriarMaquina(auxMaq.cod, auxMaq.und);
		InserirMaqnaOpe(rootOpe, codOpe, nova);
	}

	fclose(fp);
	return;
}

#pragma endregion