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
* @brief Opera��es para criar um novo Job, inserir em lista e listagem para teste
*/
#pragma region Jobs

/**
 * .
 * @brief aloca espa�o de mem�ria e cria um novo Job
 * \param cod
 * \return 
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
 * .
 * @brief Fun��o para inserir Job no in�cio da lista.
 * \param h
 * \param novo
 * \return 
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

/**
 * .
 * @brief Fun��o para inserir Job no final de uma lista.
 * \param listaj
 * \param valor
 * \return 
 */
job* inserirJobFim2(ListaJob* listaj, int valor) {
	job* novo = (job*)malloc(sizeof(job));
	job* aux = (job*)malloc(sizeof(job));
	novo->cod = valor;
	novo->nextJ = NULL;
	novo->ope = NULL;

	if (listaj->inicio == NULL)
	{
		listaj->inicio = novo;
	}
	else
	{
		aux->nextJ = listaj->inicio;
		while (aux->nextJ != NULL)
		{
			aux = aux->nextJ;
		}
		aux->nextJ = novo;
		listaj->tam++;
	}
};

/**
 * .
 * @brief Fun��o para remover um Job de uma lista simples
 * \param listaj
 * \param valor
 */
void RemoverJob(ListaJob* listaj, int valor) {
	job* inicio = (job*)malloc(sizeof(job));
	job* jobremover = NULL;

	inicio->nextJ = listaj->inicio;

	if (inicio != NULL && listaj->inicio->cod == valor)
	{
		jobremover = listaj->inicio;
		listaj->inicio = jobremover->nextJ;
	}
	else
	{
		while (inicio != NULL && inicio->nextJ != NULL && inicio->nextJ->cod != valor)
		{
			inicio = inicio->nextJ;
		}
		if (inicio != NULL && inicio->nextJ != NULL)
		{
			jobremover = inicio->nextJ;
			inicio->nextJ = jobremover->nextJ;
		}
	};
	if (jobremover != NULL)
	{
		free(jobremover);
		//listaj->tam--;
	}
};

/**
 * .
 * @brief Fun��o para inserir um Job em uma �rvore bin�ria
 * \param root
 * \param novo
 * \return root
 */
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

/**
 * .
 * @brief Fun��o para procurar um Job em uma �rvore bin�ria
 * \param root
 * \param cod
 * \return 
 */
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
 * .
 * @brief Fun��o para inserir lista de opera��es de um Job na �rvore de Jobs.
 * \param listajob
 * \param listaOp
 * \param codJob
 * \return 
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
 * .
 * @brief Gerar �rvore de Jobs a partir de um ficheiro.
 * \param nomeFicheiro
 * \return 
 */
job* lerFicheiroJobs(char* nomeFicheiro)
{
	FILE* fp;
	job* root = NULL;
	job* novo;

	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	job auxJobs;
	int z = 0;
	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF) {
		sscanf(c, "%d\n", &auxJobs.cod);

		novo = criarJob(auxJobs.cod);
		root = inserirJobArvore(root, novo);
	}

	fclose(fp);
	return root;

}

/**
 * .
 * @brief Fun��o para imprimir uma lista de Jobs simples
 * \param listaj
 */
void listarCrescenteJob(job* listaj)
{
	if (listaj != NULL)
	{
		listarCrescenteJob(listaj->nextJ);
		printf("Job %d\n", listaj->cod);
	}
}

/**
 * .
 * @brief Fun��o para imprimir a �rvore de Jobs pre ordenada.
 * \param root
 */
void listarArvorePreOrder(job* root)
{
	if (root == NULL) return;
	printf("Job %d\n", root->cod);
	listarArvorePreOrder(root->left);
	listarArvorePreOrder(root->right);
}

/**
 * .
 * @brief Fun��o para imprimir a �rvore de Jobs de forma ordenada
 * \param root
 */
void listarArvoreInOrder(job* root)
{
	if (root == NULL) return;
	listarArvoreInOrder(root->left);
	printf("Job %d\n", root->cod);
	listarArvoreInOrder(root->right);
}

/**
 * .
 * @brief Fun��o para imprmir a �rvore completa com suas opera��es e m�quinas.
 * \param root
 */
void listarArvoreJobOpeInOrder(job* root)
{
	if (root == NULL) return;
	listarArvoreJobOpeInOrder(root->left);
	printf("Job %d\n", root->cod);
	listarOpeComMaq(root->ope);
	listarArvoreJobOpeInOrder(root->right);
}

/**
 * .
 * @brief Fun��o para imprmir lista simples de Jobs com as opera��es.
 * \param listaj
 */
void imprimirJob(ListaJob* listaj) {
	job* inicio = listaj->inicio;
	printf("O tamanho da lista e %d\n", listaj->tam);
	while (inicio != NULL)
	{
		printf("Job %d\n", inicio->cod);
		inicio = inicio->nextJ;
		if (listaj->inicio->ope != NULL)
		{
			printf("As opera��es desse Jobs s�o: %d", inicio->ope);
			inicio = inicio->ope;
		}
	}
	printf("\n");
}

#pragma endregion