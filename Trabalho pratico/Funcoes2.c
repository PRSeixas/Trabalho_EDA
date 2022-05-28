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

//Função para gravar os dados das operações de um Job em um ficheiro txt
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
	operacao* aux2 = NULL;

	if (root == NULL) return;
	ficheiroArvoreInOrder(root->left);

	file = fopen("trabalho.txt", "a");
	fprintf(file, "\nJob %d\n", root->cod);
	fclose(file);

	//printf("Job %d\n", root->cod);

	aux = auxLista->ope;

	while (aux != NULL)
	{
		aux2 = aux;
		file = fopen("trabalho.txt", "a");
		fprintf(file, "\n");
		while (aux2->nextM != NULL)
		{
			fprintf(file, "operação %d, máquina %d, tempo %d\n", aux->cod, aux2->nextM->cod, aux2->nextM->und);
			aux2 = aux2->nextM;
		}
		aux = aux->nextOp;

		fclose(file);
	}

	ficheiroArvoreInOrder(root->right);
}
#pragma endregion

#pragma region FuncoesEmDesenvolvimento


//Listar Job com suas respectivas operações e Jobs
//Função em desenvolvimento, corrigir pesquisa e apontador de Job para operações
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

//Função para calcular menor tempo disponível para efetuar um Job
//Em desenvolvimento, corrigir erro de loop na verificação da lista de operações
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
		printf("%d", menor2); //Apenas para teste de visualização
		lista = lista->nextOp;
		cod--;
	}
	/*
	if (lista == NULL)
	{
		printf("Lista Vazia, sem operações para calcular tempo");
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

		nova = maquinaMenorTempo(aux->nextM); //erro na segunda passagem da lista de maquina
		novaoperacao = CriarOperacao(aux->cod);
		novaLista = inserirOpeInicio2(novaLista, novaoperacao);

		InserirMaqnaOpe(novaLista, aux->cod, nova);
		
		aux = aux->nextOp; //verificar loop com erro, copia a informação apenas da primeira operação.
	}
	return novaLista;
}

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
				fprintf(file, "operação%d, máquina %d, tempo %d\n", aux->cod, aux2->nextM->cod, aux2->nextM->und);
				aux2 = aux2->nextM;
			}
			aux = aux->nextOp;

			fclose(file);
		}

		auxLista = auxLista->left;
	}
}

#pragma endregion

