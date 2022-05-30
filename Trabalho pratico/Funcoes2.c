/**
* Autor: Pedro Seixas
* E-mail: a21872@alunos.ipca.pt
* Data: 26/03/2022
*
* Colocar outros contribuintes aqui abaixo:
*
*
*/

//Biblioteca nativa de C
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


#pragma region ManipulacaoDados

//Fun��o para gravar os dados das opera��es de um Job em um ficheiro txt
void gravarDadosFicheiro(operacao* lista) {

	FILE* file;
	operacao* aux = lista;
	operacao* aux2 = NULL;

	if (lista == NULL)
	{
		file = fopen("trabalho.txt", "w");
		fprintf(file, "Lista vazia");
	}

	while (aux != NULL)
	{
		aux2 = aux;
		file = fopen("trabalho.txt", "a");
		fprintf(file, "\n");
		while (aux2->nextM != NULL)
		{
			fprintf(file, "opera��o%d, m�quina %d, tempo %d\n", aux->cod, aux2->nextM->cod, aux2->nextM->und);
			aux2 = aux2->nextM;
		}
		aux = aux->nextOp;

		fclose(file);
	}
}

/**
 * Fun��o para exportar dados completo da �rvore para um ficheiro.
 * 
 * \param root - endere�o da �rvore
 */
void ficheiroArvoreInOrder(job* root)
{
	FILE* file;
	job* auxLista = root;
	operacao* aux = NULL;
	operacao* aux2 = NULL;

	if (root == NULL) return;
	ficheiroArvoreInOrder(root->left);

	file = fopen("trabalho.txt", "a");
	fprintf(file, "\nJob %d\n", root->cod);
	fclose(file);

	aux = auxLista->ope;

	while (aux != NULL)
	{
		aux2 = aux;
		file = fopen("trabalho.txt", "a");
		fprintf(file, "\n");
		while (aux2->nextM != NULL)
		{
			fprintf(file, "opera��o %d, m�quina %d, tempo %d\n", aux->cod, aux2->nextM->cod, aux2->nextM->und);
			aux2 = aux2->nextM;
		}
		aux = aux->nextOp;

		fclose(file);
	}

	ficheiroArvoreInOrder(root->right);
}

void ficheiroArvoreMinimoTempo(job* root)
{
	FILE* file;
	job* auxLista = root;
	operacao* aux = NULL;
	operacao* aux2 = NULL;

	if (root == NULL) return;
	ficheiroArvoreMinimoTempo(root->left);
	/*
	file = fopen("jobMinimo.txt", "a");
	fprintf(file, "\n%d\t", root->cod);
	fclose(file);
	*/
	aux = auxLista->ope;

	while (aux != NULL)
	{
		aux2 = aux;
		file = fopen("jobMinimo.txt", "a");
		
		while (aux2->nextM != NULL)
		{
			fprintf(file, "%d\t%d\t%d\t%d\t",auxLista->cod, aux->cod, aux2->nextM->cod, aux2->nextM->und);
			aux2 = aux2->nextM;
			fprintf(file, "\n");
		}
		aux = aux->nextOp;

		fclose(file);
	}

	ficheiroArvoreMinimoTempo(root->right);
}
#pragma endregion


#pragma region FuncoesEmDesenvolvimento


//Listar Job com suas respectivas opera��es e Jobs
//Fun��o em desenvolvimento, corrigir pesquisa e apontador de Job para opera��es
void listarJobCompleto(job* inicio, int codJob) {
	
	operacao* a = NULL;
	
	if (inicio->cod == NULL)
	{
		printf("Lista de Jobs vazia");
	}
	else
	{
		if (inicio->cod == codJob)
		{
			a->nextOp = inicio->ope;

			while (a->nextOp != NULL)
			{
				listarOpeComMaq(a);
				a = a->nextOp;
			}
		}
	}
}

//Fun��o para calcular menor tempo dispon�vel para efetuar um Job
//Em desenvolvimento, corrigir erro de loop na verifica��o da lista de opera��es
void ListarJobMenorTempo(operacao* lista) {
	operacao* a = NULL;
	operacao* auxNext = lista;
	int menor = 0;
	int menor2 = 0;
	int cod = 4;
	if (lista == NULL)
	{
		printf("Lista vazia");
	}
	while (lista->nextOp != NULL)
	{
		while (auxNext != NULL)
		{
			if (auxNext->cod == cod)
			{
				a = auxNext;
			}
			auxNext = auxNext->nextOp;
		}

		while (a->nextM != NULL && a->nextM->nextm != NULL)
		{
			if (a->nextM->und < a->nextM->nextm->und)
			{
				menor = a->nextM->und;
				//printf("%d %d\n", menor, a->nextM->cod);
			}
			else
			{
				menor = a->nextM->nextm->und;
				//printf("%d %d\n", menor, a->nextM->nextm->cod);
			}
			if (menor != 0 && menor2 == 0)
			{
				menor2 = menor;
			}
			if (menor < menor2)
			{
				menor2 = menor;
			}
			a = a->nextM;
		}
		printf("%d", menor2); //Apenas para teste de visualiza��o
		lista = lista->nextOp;
		cod--;
	}
	/*
	if (lista == NULL)
	{
		printf("Lista Vazia, sem opera��es para calcular tempo");
	}
	else
	{
		auxNext = lista;	
		while (lista->nextOp != NULL)
		{
			
			while (lista->nextOp->nextM != NULL)
			{


				if (lista->nextM->und < auxNext->nextM->nextm->und)
				{
					menor = lista->nextM->und;
					printf("%d\n", lista->nextM->cod);
				}
				else
				{
					menor = auxNext->nextM->nextm->und;
					printf("%d\n", auxNext->nextM->nextm->cod);
				}
				lista->nextOp->nextM = lista->nextOp->nextM->nextm;
			}
			printf("%d\n", menor);

			lista = lista->nextOp;
		}
	}*/
}


void gravarDadosFicheiro2(job* root) {

	FILE* file;
	job* auxLista = root;
	operacao* aux = NULL;
	operacao* aux2 = NULL;

	if (root == NULL)
	{
		file = fopen("trabalho.txt", "w");
		fprintf(file, "Lista vazia");
	}
	while (root != NULL)
	{
		aux = auxLista->ope;
		file = fopen("trabalho.txt", "a");
		fprintf(file, "Job %d\n", auxLista->cod);
		fclose(file);

		while (aux != NULL)
		{
			aux2 = aux;
			file = fopen("trabalho.txt", "a");
			fprintf(file, "\n");
			while (aux2->nextM != NULL)
			{
				fprintf(file, "opera��o%d, m�quina %d, tempo %d\n", aux->cod, aux2->nextM->cod, aux2->nextM->und);
				aux2 = aux2->nextM;
			}
			aux = aux->nextOp;

			fclose(file);
		}

		auxLista = auxLista->left;
	}
}

//Teste de funcionamento ok. Efetuar aloca��o na aba correspondente e comentar.
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

//Teste de funcionamento ok. Efetuar aloca��o na aba correspondente e comentar
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

//Teste de funcionamento ok. Efetuar aloca��o na aba correspondente e comentar
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

//fun��o em desenvolvimento
dados* lerFicheiroDados(char* nomeFicheiro)
{
	FILE* fp;
	dados* root = NULL;
	dados* nova;
	int codJob;
	int codOpe;
	int codMaq;
	int tempo;

	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;
	
	dados auxDados;
	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF)
	{
		sscanf(c, "%d\t%d\t%d\t%d\n", &auxDados.job, &auxDados.ope, &auxDados.maq, &auxDados.und);

	}

}

//Fun��o em desenvolvimento
//Verificar loop e funcionalidade
job* arvoreJobMin(job* root)
{
	job* aux = root;
	job* novaLista = NULL;
	operacao* minOpe = NULL;

	if (root == NULL)  return NULL;
	
	novaLista = lerFicheiroJobs("jobs.txt");

	while (aux != NULL) {
		minOpe = menorTempoOpe(aux->ope);
		inserirOpenoJob(novaLista, minOpe, aux->cod);
		
		aux = aux->left;
	}

	while (aux != NULL) {
		
		minOpe = menorTempoOpe(aux->ope);
		inserirOpenoJob(novaLista, minOpe, aux->cod);

		aux = aux->right;
	}

	return novaLista;
}

//Fun��o em desenvolvimento
void IniciaPlano(Cel p[][T], int codJob, int codOper) {

	for (int l = 0; l < M; l++)
		for (int col = 0; col < T; col++) {
			p[l][col].idJob = codJob;
			p[l][col].idOpe = codOper;
		}
}

//Fun��o em desenvolvimento
void OcupaVarios(Cel p[][T], int mId, int totTempo, Cel* c) {

	//Fase 1: Procurar a primeira "casa" livre
	int col = 0;
	while (p[mId][col].idJob != -1)
		col++;

	//Fase 1 - Ocupa a partir da posi��o livre encontrada
	totTempo += col;	//porqu�?
	for (; col < totTempo; col++) {
		p[mId][col].idJob = c->idJob;
		p[mId][col].idOpe = c->idOpe;
		//p[mId][col] = *c;
	}

	//Fase 2 - Procurar quando a opera��o anterior

	//Fase 3 - Verficar se ap�s posi��o livre existe tempo suficiente...
}

//Fun��o em desenvolvimento
void OcupaPlanoDados(Cel p[][T], char* nomeFicheiro) {

	FILE* fp;
	int codJob = 0;
	int codOpe = 0;
	int codMaq = 0;
	int tempo = 0;

	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	dados aux;
	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF)
	{
		sscanf(c, "%d\t%d\t%d\t%d\n", &aux.job, &aux.ope, &aux.maq, &aux.und);


		//Fase 1: Procurar a primeira "casa" livre
		int col = 0;
		while (p[aux.maq][col].idJob != -1)
			col++;

		//Fase 2 - Verficar se ap�s posi��o livre existe tempo suficiente...

		//Fase 3 - Procurar quando a opera��o anterior

		//Fase 4 - Ocupa a partir da posi��o livre encontrada
		int colFim;
		colFim = col + aux.und;
		for (; col < colFim; col++) {
			p[aux.maq][col].idJob = aux.job;
			p[aux.maq][col].idOpe = aux.ope;
		}
	}
}

//Fun��o em desenvolvimento
void gravaDadosPlaneamento(Cel p[][T])
{
	FILE* file;
	int maq = 0;
	int col = 0;
	int maqAux = 0;

	//if (p[maq][col].idOpe == -1) return;

	file = fopen("planeamento.txt", "a");

	for (maq = 0; maq < M; maq++)
	{
		maqAux = maq + 1;
		col = 0;
		fprintf(file, "M�quina %d: ", maq);

		while (p[maq][col].idJob != -1)
		{
			fprintf(file, " J%d O%d | ", p[maq][col].idJob, p[maq][col].idOpe);
			col++;	
		}
		fprintf(file, "\n");
	}
	fclose(file);

}
#pragma endregion

