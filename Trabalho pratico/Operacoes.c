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
 * .
 * @brief aloca espa�o de mem�ria e cria uma nova opera��o
 * \param cod		c�digo da opera��o
 * \return 
 */
operacao* CriarOperacao(int cod) {
	operacao* nova = (operacao*)malloc(sizeof(operacao));
	nova->cod = cod;
	nova->nextM = NULL;
	nova->nextOp = NULL;
}

/**
 * .
 * @brief Fun��o para inserir opera��o no in�cio da lista
 * \param h			lista a inserir a opera��o
 * \param nova		nova opera��o
 * \return 
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
 * .
 * @brief Procurar oper���o em uma lista
 * \param listaOperacao
 * \param cod
 * \return 
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
 * .
 * @brief Fun��o para inserir m�quinas em uma lista de opera��es
 * \param h
 * \param codOp
 * \param nova
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
 * @brief Fun��o para gerar uma nova lista com as opera��es de menor tempo
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
 * .
 * @brief Fun��o para imprimir opera��es de uma lista em ordem crescente
 * \param inicio
 */
void listarCrescenteOpe(operacao* inicio) {

	if (inicio != NULL)
	{
		listarCrescenteOpe(inicio->nextOp);
		printf("Opera��o %d\n", inicio->cod);
	}
}

/**
 * .
 * @brief Fun��o para imprimir a lista de opera��es completas com suas m�quinas
 * \param inicio
 */
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

/**
 * .
 * @brief Fun��o para inserir opera��o no final de uma lista, usado apenas na primeira fase.
 * \param listaOp
 * \param valor
 */
void inserirOpeFim(ListaOperacao* listaOp, int valor) {
	operacao* novo = (operacao*)malloc(sizeof(operacao));
	operacao* aux = (operacao*)malloc(sizeof(operacao));

	novo->cod = valor;              //Valor inteiro referente ao n�mero da opera��o
	novo->nextOp = NULL;            //Novo bloco aponta para NULL pois ocupar� o final da lista
	novo->nextM = NULL;            //Novo bloco aponta para NULL ou para a lista das m�quinas da sua opera��o

	if (listaOp->inicio == NULL) {
		listaOp->inicio = novo;
	}
	else
	{
		aux->nextOp = listaOp->inicio;
		while (aux->nextOp != NULL)
		{
			aux = aux->nextOp;
		}
		aux->nextOp = novo;
	}
	listaOp->tam++;
}

/**
 * .
 * @brief Fun��o para remover uma opera��o de uma lista simples.
 * \param listaOp
 * \param valor
 */
void removerOpe(ListaOperacao* listaOp, int valor) {
	operacao* inicio = (operacao*)malloc(sizeof(operacao));
	operacao* removerOperacao = NULL;

	inicio->nextOp = listaOp->inicio;

	if (inicio != NULL && listaOp->inicio->cod == valor)
	{
		removerOperacao = listaOp->inicio;
		listaOp->inicio = removerOperacao->nextOp;
	}
	else
	{
		while (inicio != NULL && inicio->nextOp && inicio->nextOp->cod != valor)
		{
			inicio = inicio->nextOp;
		}
		if (inicio != NULL && inicio->nextOp != NULL)
		{
			removerOperacao = inicio->nextOp;
			inicio->nextOp = removerOperacao->nextOp;
		}
	}
	if (removerOperacao != NULL)
	{
		free(removerOperacao);
	}
}

/**
 * .
 * @brief Fun��o para montar lista de opera��es a partir de um ficheiro
 * \param nomeFicheiro
 * \return 
 */
operacao* lerFicheiroOperacao(char* nomeFicheiro)
{
	FILE* fp;
	operacao* root = NULL;
	operacao* novo;


	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	operacao auxOpe;
	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF) {
		sscanf(c, "%d\n", &auxOpe.cod);

		novo = CriarOperacao(auxOpe.cod);
		root = inserirOpeInicio2(root, novo);
	}

	fclose(fp);
	return root;
}

#pragma endregion