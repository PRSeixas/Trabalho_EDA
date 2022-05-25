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
* @brief Operações para criar um novo Job, inserir em lista e listagem para teste
*/
#pragma region Jobs

/**
*@brief aloca espaço de memória e cria um novo Job
* @param [in] int cod	            código do número do Job
*/
job* criarJob(int cod) {
	job* novo = (job*)malloc(sizeof(job));
	novo->cod = cod;
	novo->nextJ = NULL;
	novo->ope = NULL;
	novo->left = NULL;
	novo->right = NULL;

	return novo;
}

/**
*@brief função para inserir Job no inicio da lista
* @param [in] endereço da lista de Jobs
* @param [in] endereço de memória do novo Job com seus dados
*/
job* inserirJobInicio2(job* h, job* novo) {
	if (h == NULL)
	{
		h = novo;
	}
	else
	{
		novo->nextJ = h;
		h = novo;
	}
}

//Inserir Job em uma árvore binária
job* inserirJobArvore(job* root, job* novo) {
	if (root == NULL)
	{
		root = novo;
	}
	else
	{
		if (root->cod > novo->cod)
		{
			root->left = inserirJobArvore(root->left, novo);
		}
		else
		{
			if (root->cod < novo->cod)
			{
				root->right = inserirJobArvore(root->right, novo);
			}
		}
	}
	return root;
}

//Procurar Job em uma árvore binária
//Função em desenvolvimento e teste
job* procurarJobArvore(job* root, int cod) {
	if (root == NULL)
	{
		return NULL;
	}
	if (root->cod == cod)
	{
		return root;
	}
	else
	{
		if (root->cod > cod) return (procurarJobArvore(root->left, cod));
		else return (procurarJobArvore(root->right, cod));

	}
}

/**
*@brief Inserir lista de operações em um determinado Job
* @param [in] endereço da árvore de Jobs
* @param [in] endereço da lista de operações de um Job
* @param [in] int codJob, código do Job para pesquisar na lista o bloco de memória do Job correspondente da lista de operações
*/
job* inserirOpenoJob(job* listajob, operacao* listaOp, int codJob) {
	job* a = NULL;
	job* aux = NULL;
	operacao* auxOp = listaOp;

	aux = procurarJobArvore(listajob, codJob);

	aux->ope = listaOp;

	/*
	while (aux != NULL)
	{
		if (aux->cod == codJob)
		{
			a = aux;
		}
		aux = aux->nextJ;
	}
	a->ope = listaOp->nextOp;
	*/
	return aux;
}

/**
*@brief função para lisar Jobs cadastrados
* @param [in] endereço da lista de Jobs
*/
void listarCrescenteJob(job* listaj)
{
	if (listaj != NULL)
	{
		listarCrescenteJob(listaj->nextJ);
		printf("Job %d\n", listaj->cod);
	}
}

//Listar jobs da árvore Pre Order
void listarArvorePreOrder(job* root)
{
	if (root == NULL) return;
	printf("Job %d\n", root->cod);
	listarArvorePreOrder(root->left);
	listarArvorePreOrder(root->right);
}

//Listar jobs da árvore In Order
void listarArvoreInOrder(job* root)
{
	if (root == NULL) return;
	listarArvoreInOrder(root->left);
	printf("Job %d\n", root->cod);
	listarArvoreInOrder(root->right);
}

//Listar jobs da árvore com as operações e máquinas
void listarArvoreJobOpeInOrder(job* root)
{
	if (root == NULL) return;
	listarArvoreJobOpeInOrder(root->left);
	printf("Job %d\n", root->cod);
	listarOpeComMaq(root->ope);
	listarArvoreJobOpeInOrder(root->right);
}

#pragma endregion