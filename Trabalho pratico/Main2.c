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
#include <locale.h>
#include "Lista.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	/**
	* @brief Operações para criar uma nova máquina com seus parâmetros
	*/
	#pragma region CriarMaquina
	/**
	* @param [in] endereço listaInicio		Inicio da Lista
	*/
	maquina* listaInicio;
	listaInicio = NULL;

	/**
	* @brief Criar nova máquina para posterior inserção em lista de operações
	* @param [in] código da máquina
	* @param [in] unidade de tempo
	*/
	maquina* nova;
	nova = CriarMaquina(1, 4);
	listaInicio = inserirMaqInicio2(listaInicio, nova);

	printf("Listagem teste de inserção de máquina\n");
	listarCrescenteMaq(listaInicio);

	#pragma endregion

	/**
	* @brief Operações para criar um novo Job
	*/
	#pragma region CriarJob
	/**
	* @param [in] endereço listajInicio		Inicio da Lista
	*/
	job* listajInicio;
	listajInicio = NULL;

	/**
	* @brief Criar novo Job para posterior inserção em lista de Jobs
	* @param [in] código do Job
	*/
	job* novo;
	novo = criarJob(1);
	listajInicio = inserirJobInicio2(listajInicio, novo);
	novo = criarJob(2);
	listajInicio = inserirJobInicio2(listajInicio, novo);

	printf("\n");
	listarCrescenteJob(listajInicio); //Teste de visualização da lista de Job

	#pragma endregion

	/**
	* @brief Operações para criar uma nova operação
	*/
	#pragma region CriarOperacao

	/**
	* @param [in] endereço listaOperacao		Inicio da Lista
	*/
	operacao* listaOperacao;
	listaOperacao = NULL;

	/**
	* @brief Criar nova operação para posterior inserção em lista de operações
	* @param [in] código da operação
	*/
	operacao* novaOperacao;
	novaOperacao = CriarOperacao(1);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);

	printf("\n");
	listarCrescenteOpe(listaOperacao); //Teste de visualização da lista de Operações

	#pragma endregion

	/**
	* @brief Operações para inserir máquinas nas operações
	*/
	#pragma region InserirMaquinaOperacao

	/**
	* @brief Criar e inserir máquina em operação pré definida na lista de operações
	* @param [in] código da operação
	* @param [in] código da máquina
	* @param [in] quantidade de unidade de tempo para execução da operação na máquina
	*/
	//Função procura a respectiva operação na lista e adiciona a máquina com seus parâmetros.
	InserirMaqnaOpe(listaOperacao, 1, 1, 4);
	InserirMaqnaOpe(listaOperacao, 1, 3, 5);
	InserirMaqnaOpe(listaOperacao, 2, 2, 4);
	InserirMaqnaOpe(listaOperacao, 2, 4, 5);
	InserirMaqnaOpe(listaOperacao, 3, 3, 5);
	InserirMaqnaOpe(listaOperacao, 3, 5, 6);
	InserirMaqnaOpe(listaOperacao, 4, 4, 5);
	InserirMaqnaOpe(listaOperacao, 4, 5, 5);
	InserirMaqnaOpe(listaOperacao, 4, 6, 4);
	InserirMaqnaOpe(listaOperacao, 4, 7, 5);
	InserirMaqnaOpe(listaOperacao, 4, 8, 9);

	printf("\n");
	listarOpeComMaq(listaOperacao); //Teste de visualização da lista de Operações

	#pragma endregion


	#pragma region ManipulacaoDados

	gravarDadosFicheiro(listaOperacao);

	#pragma endregion
}