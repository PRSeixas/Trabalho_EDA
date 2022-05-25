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
*@brief aloca espaço de memória e cria uma nova Operação
* @param [in] int cod, código do número da operação
*/
operacao* CriarOperacao(int cod) {
	operacao* nova = (operacao*)malloc(sizeof(operacao));
	nova->cod = cod;
	nova->nextM = NULL;
	nova->nextOp = NULL;
}

/**
*@brief função para inserir operação no inicio da lista
* @param [in] endereço da lista de operações
* @param [in] endereço de memória da nova operação
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
*@brief Procurar operação na lista
* @param [in] endereço da lista de operações
* @param [in] int cod, código do número da operação
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
*@brief Inserir máquinas em lista de operações
* @param [in] endereço da lista de operações
* @param [in] int cadOp, código da operação para pesquisar na lista de operações
* @param [in] int cadMaq, código da máquina que será informado para a função CriarMaquina
* @param [in] int tempo, unidade de tempo da máquina que será informado para a função CriarMaquina
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
*@brief função para lisar operações cadastradas
* @param [in] endereço da lista de operações
*/
void listarCrescenteOpe(operacao* inicio) {

	if (inicio != NULL)
	{
		listarCrescenteOpe(inicio->nextOp);
		printf("Operação %d\n", inicio->cod);
	}
}

//Listar as operações e suas máquinas cadastradas
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

#pragma endregion