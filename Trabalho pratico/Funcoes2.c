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

/**
 * .
 * @brief Função para exportar dados da lista de operações.
 * \param lista - endereço da lista de operações a exportar
 */
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
			fprintf(file, "operação%d, máquina %d, tempo %d\n", aux->cod, aux2->nextM->cod, aux2->nextM->und);
			aux2 = aux2->nextM;
		}
		aux = aux->nextOp;

		fclose(file);
	}
}

/**
 * Função para exportar dados completo da árvore para um ficheiro.
 * 
 * \param root - endereço da árvore
 */

void ficheiroArvoreInOrder(job* root)
{
	FILE* file;
	job* auxLista = root;
	operacao* aux = NULL;
	//operacao* aux2 = NULL;
	maquina* aux2 = NULL;

	if (root == NULL) return;
	ficheiroArvoreInOrder(root->left);

	file = fopen("ProcessPlanCompleto.txt", "a");
	fprintf(file, "\nJob %d\n", root->cod);
	fclose(file);

	aux = auxLista->ope;

	while (aux != NULL)
	{
		aux2 = aux->nextM;
		file = fopen("ProcessPlanCompleto.txt", "a");
		fprintf(file, "\n");
		while (aux2 != NULL)
		{
			fprintf(file, "operação %d, máquina %d, tempo %d\n", aux->cod, aux2->cod, aux2->und);
			aux2 = aux2->nextm;
		}
		aux = aux->nextOp;

		fclose(file);
	}

	ficheiroArvoreInOrder(root->right);
}


/**
 * .
 * @brief Função para exportar dados da árvore gerada com os menores tempos das operações.
 * \param root
 */
void ficheiroArvoreMinimoTempo(job* root)
{
	FILE* file;
	job* auxLista = root;
	operacao* aux = NULL;
	//operacao* aux2 = NULL;
	maquina* aux2 = NULL;

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
		aux2 = aux->nextM;
		file = fopen("jobMinimo.txt", "a");
		
		while (aux2 != NULL)
		{
			fprintf(file, "%d\t%d\t%d\t%d\t",auxLista->cod, aux->cod, aux2->cod, aux2->und);
			aux2 = aux2->nextm;
			fprintf(file, "\n");
		}
		aux = aux->nextOp;

		fclose(file);
	}

	ficheiroArvoreMinimoTempo(root->right);
}

//Função em desenvolvimento
/**
 * .
 * @brief Função para gerar arquivo tipo csv com os dados do planeamento gerado.
 * \param p
 */
void gravaDadosPlaneamento(Cel p[][T])
{
	FILE* file;
	int maq = 0;
	int col = 0;
	int maqAux = 0;
	int t = 0;

	//if (p[maq][col].idOpe == -1) return;

	file = fopen("planeamento.csv", "a");

	for (maq = 0; maq < 1; maq++)
	{
		fprintf(file, "---------- ,");
		for (col = 0; col < T; col++)
		{
			t++;
			fprintf(file, " T%d,", t);
		}
		fprintf(file, "\n");
	}

	for (maq = 0; maq < M; maq++)
	{
		col = 0;
		fprintf(file, "Máquina %d: ,", maq);

		//for (int l = 0; l < M; l++)
		for (int col = 0; col < T; col++) {
			if (p[maq][col].idJob == -1)
			{
				fprintf(file, "     ,");
			}
			else
			{
				fprintf(file, "J%dO%d,", p[maq][col].idJob, p[maq][col].idOpe);
			}
		}
		fprintf(file, "\n");
	}
	fclose(file);

}

#pragma endregion


#pragma region Escalonamento

/**
 * .
 * @brief Função para iniciar e formatar a matriz para o escalonamento
 * \param p
 * \param codJob
 * \param codOper
 */
void IniciaPlano(Cel p[][T], int codJob, int codOper) {

	for (int l = 0; l < M; l++)
		for (int col = 0; col < T; col++) {
			p[l][col].idJob = codJob;
			p[l][col].idOpe = codOper;
		}
}

/**
 * .
 * @brief Função para verificar espaço livre que caiba a operação completa do Job na matriz
 * \param p
 * \param coluna
 * \param tempototal
 * \param maq
 * \return 
 */
bool verificarEspaco(Cel p[][T], int coluna, int tempototal, int maq) {

	for (; coluna < tempototal; coluna++) {
		if (p[maq][coluna].idJob != -1) {
			return true;
		}
	}
	return false;
}

/**
 * .
 * @brief Função para escrever na matriz as opereçõs dos Jobs nas linhas das máquinas
 * \param p
 * \param nomeFicheiro
 */
void OcupaPlanoDados(Cel p[][T], char* nomeFicheiro) {

	FILE* fp;
	int colFim = 0;
	int col = 0;
	int auxJob = 0;

	//Dados importados do ficheiro gerado com as operações de menor tempo do Job.
	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	dados aux;
	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF)
	{
		sscanf(c, "%d\t%d\t%d\t%d\n", &aux.job, &aux.ope, &aux.maq, &aux.und);


		//Fase 1: inicia depois da última operação.
		if (auxJob == aux.job)
		{
			col = colFim;
		}
		else col = 0;

		//Fase 2: Encontrar posição de inicio | percorre a linha até achar posição livre, pré definida como -1
		while (p[aux.maq][col].idJob != -1)
			col++;

		//Fase 3 - Teste usando função para verificar espaço suficiente para escrever a operação inteira do Job.
		int auxColFim = col + aux.und;
	repeat:
		colFim = col + aux.und;
		if (verificarEspaco(p, col, colFim, aux.maq) == true) {
			col++;			//espaço ocupado passa para a frente
			colFim++;		// o total tambem tem de passar para a frente
			goto repeat;	//Processo repete-se até teste devolver resultado falso, não há nada diferente de -1.
		}
		else
		{
			//Fase 4 - Ocupa a partir da posição livre encontrada

			//Ciclo for para preencher a quantidade de colunas da respectiva operação
			for (; col < colFim; col++) {
				p[aux.maq][col].idJob = aux.job;		//escrita do código do Job lido e armazenado em aux
				p[aux.maq][col].idOpe = aux.ope;		//escrita do código da operação lida e armazenada em aux
			}
		}
		auxJob = aux.job;
	}
}

#pragma endregion



#pragma region FuncoesEmDesenvolvimento
/*
//Função em desenvolvimento
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
*/
#pragma endregion

