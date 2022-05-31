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
* @brief Operações para criar uma nova operação, inserir em lista e listagem para teste
*/
#pragma region Operacoes

/**
 * .
 * @brief aloca espaço de memória e cria uma nova operação
 * \param cod		código da operação
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
 * @brief Função para inserir operação no início da lista
 * \param h			lista a inserir a operação
 * \param nova		nova operação
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
 * @brief Procurar operãção em uma lista
 * \param listaOperacao
 * \param cod
 * \return 
 */
operacao* procurarOp(operacao* listaOperacao, int cod) {
	operacao* auxOp = NULL;
	operacao* auxOp2 = NULL;

	auxOp2 = listaOperacao;

	int valor = cod;            //Valor do código da operação a procurar

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
 * @brief Função para inserir máquinas em uma lista de operações
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
 * @brief Função para gerar uma nova lista com as operações de menor tempo
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
 * @brief Função para imprimir operações de uma lista em ordem crescente
 * \param inicio
 */
void listarCrescenteOpe(operacao* inicio) {

	if (inicio != NULL)
	{
		listarCrescenteOpe(inicio->nextOp);
		printf("Operação %d\n", inicio->cod);
	}
}

/**
 * .
 * @brief Função para imprimir a lista de operações completas com suas máquinas
 * \param inicio
 */
void listarOpeComMaq(operacao* inicio) {

	if (inicio != NULL)
	{
		listarOpeComMaq(inicio->nextOp);
		printf("Lista de máquinas da operação %d\n", inicio->cod);
		if (inicio->nextM->cod != NULL)
		{
			listarCrescenteMaq(inicio->nextM);
			printf("\n");
		}
	}
}

/**
 * .
 * @brief Função para inserir operação no final de uma lista, usado apenas na primeira fase.
 * \param listaOp
 * \param valor
 */
void inserirOpeFim(ListaOperacao* listaOp, int valor) {
	operacao* novo = (operacao*)malloc(sizeof(operacao));
	operacao* aux = (operacao*)malloc(sizeof(operacao));

	novo->cod = valor;              //Valor inteiro referente ao número da operação
	novo->nextOp = NULL;            //Novo bloco aponta para NULL pois ocupará o final da lista
	novo->nextM = NULL;            //Novo bloco aponta para NULL ou para a lista das máquinas da sua operação

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
 * @brief Função para remover uma operação de uma lista simples.
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
 * @brief Função para montar lista de operações a partir de um ficheiro
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