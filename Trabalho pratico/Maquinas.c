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
* @brief Operações para criar uma nova máquina com seus parâmetros, inserir em lista e listagem para teste
*/
#pragma region Maquinas

/**
 * .
 * @brief aloca espaço de memória e cria uma nova máquina
 * \param cod		código da máquina
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
 * @brief função para inserir máquina no início da lista
 * \param h			endereço da lista
 * \param nova		nova máquina criada
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
 * @brief Função para remover máquina da lista
 * \param lista
 * \param valor		código da máquina
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
 * Função para devolver a máquina com menor tempo de uma operação
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
 * @brief Função para imprimiar uma lista de máquinas
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
 * @brief Função para inserir máquina no final da lista, usado na fase um apenas.
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
	novo->cod = valor;             //Valor do código da nova máquina
	novo->und = tempo;             //Valor de unidade de tempo
	novo->op = operacao;           //Valor da operação cadastrada
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
 * @brief Função para imprimir uma lista simples de máquinas, usado na primeira fase apenas.
 * \param lista
 */
void imprimirMaq2(maquina* lista) {
	maquina* inicio = lista->nextm;
	while (inicio != NULL)
	{
		printf("Maquina %d\n", inicio->cod);
		printf("Unidade de tempo %d\n", inicio->und);
		printf("Operação a que pertence:%d\n", inicio->op);
		printf("Job a que pertence:%d\n\n", inicio->job);
		inicio = inicio->nextm;
	}
	printf("\n");
}

//Teste de funcionamento ok. Efetuar alocação na aba correspondente e comentar
/**
 * .
 * @brief Função para inserir máquinas na lista de operações a partir de um ficheiro.
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