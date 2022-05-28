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
* @brief Opera��es para criar uma nova m�quina com seus par�metros, inserir em lista e listagem para teste
*/
#pragma region Maquinas

/**
*@brief aloca espa�o de mem�ria e cria uma nova m�quina
* @param [in] int cod	            c�digo do n�mero da m�quina
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
*@brief fun��o para inserir m�quina no inicio da lista
* @param [in] endere�o da lista de m�quinas
* @param [in] endere�o de mem�ria da nova m�quina com seus dados
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

//Fun��o para remover m�quina da lista
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
*@brief fun��o para lisar m�quinas cadastradas
* @param [in] endere�o da lista de m�quinas
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