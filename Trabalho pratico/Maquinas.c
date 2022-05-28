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
*@brief aloca espaço de memória e cria uma nova máquina
* @param [in] int cod	            código do número da máquina
* @param [in] int cod	            quantidade de unidade de tempo
*/
maquina* CriarMaquina(int cod, int tempo) {
	maquina* nova = (maquina*)malloc(sizeof(maquina));
	nova->cod = cod;
	nova->und = tempo;
	nova->nextm = NULL;
	return nova;
}

/**
*@brief função para inserir máquina no inicio da lista
* @param [in] endereço da lista de máquinas
* @param [in] endereço de memória da nova máquina com seus dados
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

//Função para remover máquina da lista
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
*@brief função para lisar máquinas cadastradas
* @param [in] endereço da lista de máquinas
*/
void listarCrescenteMaq(maquina* inicio)
{
	if (inicio != NULL)
	{
		listarCrescenteMaq(inicio->nextm);
		printf("Maquina %d e unidade de tempo %d\n", inicio->cod, inicio->und);
	}
}


#pragma endregion