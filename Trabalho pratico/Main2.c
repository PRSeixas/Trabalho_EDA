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

	//printf("Listagem teste de inserção de máquina\n");
	//listarCrescenteMaq(listaInicio);
	
	#pragma endregion

	/**
	* @brief Operações para criar um novo Job
	*/
	#pragma region ListaJobs
	/**
	* @param [in] endereço listajInicio		Inicio da Lista
	*/
	job* listajInicio;
	listajInicio = NULL;

	job* arvoreJobInicio;
	arvoreJobInicio = NULL;

	/**
	* @brief Criar novo Job para posterior inserção em lista de Jobs
	* @param [in] código do Job
	*/
	job* novo;
	novo = criarJob(4);
	// listajInicio = inserirJobInicio2(listajInicio, novo);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(5);
	// listajInicio = inserirJobInicio2(listajInicio, novo);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(3);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(2);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(7);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(6);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(1);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);

	novo = criarJob(8);
	arvoreJobInicio = inserirJobArvore(arvoreJobInicio, novo);


	//printf("\n");
	//listarCrescenteJob(listajInicio); //Teste de visualização da lista de Job

	#pragma endregion

	/**
	* @brief Operações para criar e montar uma nova lista de operações
	*/
	#pragma region ListaOperacoes

	/**
	* @param [in] endereço listaOperacao		Inicio da Lista
	* @param [in] código da operação
	*/
	#pragma region ListaOperacoesJob1
	operacao* listaOperacaoJob1;
	listaOperacaoJob1 = NULL;

	operacao* novaOperacao;
	novaOperacao = CriarOperacao(1);
	listaOperacaoJob1 = inserirOpeInicio2(listaOperacaoJob1, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob1 = inserirOpeInicio2(listaOperacaoJob1, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob1 = inserirOpeInicio2(listaOperacaoJob1, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob1 = inserirOpeInicio2(listaOperacaoJob1, novaOperacao);

	#pragma endregion

	#pragma region ListaOperacoesJob2
	operacao* listaOperacaoJob2;
	listaOperacaoJob2 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);
	novaOperacao = CriarOperacao(5);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);
	novaOperacao = CriarOperacao(6);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);
	novaOperacao = CriarOperacao(7);
	listaOperacaoJob2 = inserirOpeInicio2(listaOperacaoJob2, novaOperacao);

	#pragma endregion

	#pragma region ListaOperacoesJob3
	operacao* listaOperacaoJob3;
	listaOperacaoJob3 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob3 = inserirOpeInicio2(listaOperacaoJob3, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob3 = inserirOpeInicio2(listaOperacaoJob3, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob3 = inserirOpeInicio2(listaOperacaoJob3, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob3 = inserirOpeInicio2(listaOperacaoJob3, novaOperacao);
	novaOperacao = CriarOperacao(5);
	listaOperacaoJob3 = inserirOpeInicio2(listaOperacaoJob3, novaOperacao);

	#pragma endregion

	#pragma region	ListaOperacoesJob4

	operacao* listaOperacaoJob4;
	listaOperacaoJob4 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob4 = inserirOpeInicio2(listaOperacaoJob4, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob4 = inserirOpeInicio2(listaOperacaoJob4, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob4 = inserirOpeInicio2(listaOperacaoJob4, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob4 = inserirOpeInicio2(listaOperacaoJob4, novaOperacao);

	#pragma endregion

	#pragma region ListaOperacoesJob5
	operacao* listaOperacaoJob5;
	listaOperacaoJob5 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob5 = inserirOpeInicio2(listaOperacaoJob5, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob5 = inserirOpeInicio2(listaOperacaoJob5, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob5 = inserirOpeInicio2(listaOperacaoJob5, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob5 = inserirOpeInicio2(listaOperacaoJob5, novaOperacao);
	novaOperacao = CriarOperacao(5);
	listaOperacaoJob5 = inserirOpeInicio2(listaOperacaoJob5, novaOperacao);

	#pragma endregion

	#pragma region ListaOperacoesJob6
	operacao* listaOperacaoJob6;
	listaOperacaoJob6 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob6 = inserirOpeInicio2(listaOperacaoJob6, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob6 = inserirOpeInicio2(listaOperacaoJob6, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob6 = inserirOpeInicio2(listaOperacaoJob6, novaOperacao);

	#pragma endregion

	#pragma region ListaOperacoesJob7

	operacao* listaOperacaoJob7;
	listaOperacaoJob7 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob7 = inserirOpeInicio2(listaOperacaoJob7, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob7 = inserirOpeInicio2(listaOperacaoJob7, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob7 = inserirOpeInicio2(listaOperacaoJob7, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob7 = inserirOpeInicio2(listaOperacaoJob7, novaOperacao);
	novaOperacao = CriarOperacao(5);
	listaOperacaoJob7 = inserirOpeInicio2(listaOperacaoJob7, novaOperacao);

	#pragma endregion

	#pragma region ListaOperacoesJob8

	operacao* listaOperacaoJob8;
	listaOperacaoJob8 = NULL;

	novaOperacao = CriarOperacao(1);
	listaOperacaoJob8 = inserirOpeInicio2(listaOperacaoJob8, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacaoJob8 = inserirOpeInicio2(listaOperacaoJob8, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacaoJob8 = inserirOpeInicio2(listaOperacaoJob8, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacaoJob8 = inserirOpeInicio2(listaOperacaoJob8, novaOperacao);
	novaOperacao = CriarOperacao(5);
	listaOperacaoJob8 = inserirOpeInicio2(listaOperacaoJob8, novaOperacao);

	#pragma endregion

	//printf("\n");
	//listarCrescenteOpe(listaOperacaoJob1); //Teste de visualização da lista de Operações

	#pragma endregion


	/**
	* @brief Operações para inserir máquinas nas operações
	*/
	#pragma region InserirMaquinasOperacoes

	/**
	* @brief Criar e inserir máquina em operação pré definida na lista de operações
	* @param [in] lista de operações
	* @param [in] código da operação
	* @param [in] nova máquina criada
	*/
	#pragma region MaquinasJob1
	//Inserir máquinas na lista de operações do Job1.
	nova = CriarMaquina(1, 4);
	InserirMaqnaOpe(listaOperacaoJob1, 1, nova);
	nova = CriarMaquina(3, 5);
	InserirMaqnaOpe(listaOperacaoJob1, 1, nova);
	nova = CriarMaquina(2, 4);
	InserirMaqnaOpe(listaOperacaoJob1, 2, nova);
	nova = CriarMaquina(4, 5);
	InserirMaqnaOpe(listaOperacaoJob1, 2, nova);
	nova = CriarMaquina(3, 5);
	InserirMaqnaOpe(listaOperacaoJob1, 3, nova);
	nova = CriarMaquina(5, 6);
	InserirMaqnaOpe(listaOperacaoJob1, 3, nova);
	nova = CriarMaquina(4, 5);
	InserirMaqnaOpe(listaOperacaoJob1, 4, nova);
	nova = CriarMaquina(5, 5);
	InserirMaqnaOpe(listaOperacaoJob1, 4, nova);
	nova = CriarMaquina(6, 4);
	InserirMaqnaOpe(listaOperacaoJob1, 4, nova);
	nova = CriarMaquina(7, 5);
	InserirMaqnaOpe(listaOperacaoJob1, 4, nova);
	nova = CriarMaquina(8, 9);
	InserirMaqnaOpe(listaOperacaoJob1, 4, nova);
	
	#pragma endregion

	#pragma region MaquinasJob2
	//Inserir máquinas na lista de operações do Job2.
	nova = CriarMaquina(1, 1);
	InserirMaqnaOpe(listaOperacaoJob2, 1, nova);
	nova = CriarMaquina(3, 5);
	InserirMaqnaOpe(listaOperacaoJob2, 1, nova);
	nova = CriarMaquina(5, 7);
	InserirMaqnaOpe(listaOperacaoJob2, 1, nova);
	nova = CriarMaquina(4, 5);
	InserirMaqnaOpe(listaOperacaoJob2, 2, nova);
	nova = CriarMaquina(8, 4);
	InserirMaqnaOpe(listaOperacaoJob2, 2, nova);
	nova = CriarMaquina(4, 1);
	InserirMaqnaOpe(listaOperacaoJob2, 3, nova);
	nova = CriarMaquina(6, 6);
	InserirMaqnaOpe(listaOperacaoJob2, 3, nova);
	nova = CriarMaquina(4, 4);
	InserirMaqnaOpe(listaOperacaoJob2, 4, nova);
	nova = CriarMaquina(7, 4);
	InserirMaqnaOpe(listaOperacaoJob2, 4, nova);
	nova = CriarMaquina(8, 7);
	InserirMaqnaOpe(listaOperacaoJob2, 4, nova);
	nova = CriarMaquina(4, 1);
	InserirMaqnaOpe(listaOperacaoJob2, 5, nova);
	nova = CriarMaquina(6, 2);
	InserirMaqnaOpe(listaOperacaoJob2, 5, nova);
	nova = CriarMaquina(1, 5);
	InserirMaqnaOpe(listaOperacaoJob2, 6, nova);
	nova = CriarMaquina(6, 6);
	InserirMaqnaOpe(listaOperacaoJob2, 6, nova);
	nova = CriarMaquina(8, 4);
	InserirMaqnaOpe(listaOperacaoJob2, 6, nova);
	nova = CriarMaquina(4, 4);
	InserirMaqnaOpe(listaOperacaoJob2, 7, nova);

	#pragma endregion

	#pragma region MaquinasJob3
	//Inserir máquinas na lista de operações do Job3.
	nova = CriarMaquina(2, 7);
	InserirMaqnaOpe(listaOperacaoJob3, 1, nova);
	nova = CriarMaquina(3, 6);
	InserirMaqnaOpe(listaOperacaoJob3, 1, nova);
	nova = CriarMaquina(8, 8);
	InserirMaqnaOpe(listaOperacaoJob3, 1, nova);
	nova = CriarMaquina(4, 7);
	InserirMaqnaOpe(listaOperacaoJob3, 2, nova);
	nova = CriarMaquina(8, 7);
	InserirMaqnaOpe(listaOperacaoJob3, 2, nova);
	nova = CriarMaquina(3, 7);
	InserirMaqnaOpe(listaOperacaoJob3, 3, nova);
	nova = CriarMaquina(5, 8);
	InserirMaqnaOpe(listaOperacaoJob3, 3, nova);
	nova = CriarMaquina(7, 7);
	InserirMaqnaOpe(listaOperacaoJob3, 3, nova);
	nova = CriarMaquina(4, 7);
	InserirMaqnaOpe(listaOperacaoJob3, 4, nova);
	nova = CriarMaquina(6, 8);
	InserirMaqnaOpe(listaOperacaoJob3, 4, nova);
	nova = CriarMaquina(1, 1);
	InserirMaqnaOpe(listaOperacaoJob3, 5, nova);
	nova = CriarMaquina(2, 4);
	InserirMaqnaOpe(listaOperacaoJob3, 5, nova);

	#pragma endregion

	#pragma region MaquinasJob4
	//Inserir máquinas na lista de operações do Job4
	nova = CriarMaquina(1, 4);
	InserirMaqnaOpe(listaOperacaoJob4, 1, nova);
	nova = CriarMaquina(3, 3);
	InserirMaqnaOpe(listaOperacaoJob4, 1, nova);
	nova = CriarMaquina(5, 7);
	InserirMaqnaOpe(listaOperacaoJob4, 1, nova);
	nova = CriarMaquina(2, 4);
	InserirMaqnaOpe(listaOperacaoJob4, 2, nova);
	nova = CriarMaquina(8, 4);
	InserirMaqnaOpe(listaOperacaoJob4, 2, nova);
	nova = CriarMaquina(3, 4);
	InserirMaqnaOpe(listaOperacaoJob4, 3, nova);
	nova = CriarMaquina(4, 5);
	InserirMaqnaOpe(listaOperacaoJob4, 3, nova);
	nova = CriarMaquina(6, 6);
	InserirMaqnaOpe(listaOperacaoJob4, 3, nova);
	nova = CriarMaquina(7, 7);
	InserirMaqnaOpe(listaOperacaoJob4, 3, nova);
	nova = CriarMaquina(5, 3);
	InserirMaqnaOpe(listaOperacaoJob4, 4, nova);
	nova = CriarMaquina(6, 5);
	InserirMaqnaOpe(listaOperacaoJob4, 4, nova);
	nova = CriarMaquina(8, 5);
	InserirMaqnaOpe(listaOperacaoJob4, 4, nova);

	#pragma endregion

	#pragma region MaquinasJob5
	//Inserir máquinas na lista de operações Job5
	nova = CriarMaquina(1, 3);
	InserirMaqnaOpe(listaOperacaoJob5, 1, nova);
	nova = CriarMaquina(2, 4);
	InserirMaqnaOpe(listaOperacaoJob5, 2, nova);
	nova = CriarMaquina(4, 5);
	InserirMaqnaOpe(listaOperacaoJob5, 2, nova);
	nova = CriarMaquina(3, 4);
	InserirMaqnaOpe(listaOperacaoJob5, 3, nova);
	nova = CriarMaquina(8, 4);
	InserirMaqnaOpe(listaOperacaoJob5, 3, nova);
	nova = CriarMaquina(5, 3);
	InserirMaqnaOpe(listaOperacaoJob5, 4, nova);
	nova = CriarMaquina(6, 3);
	InserirMaqnaOpe(listaOperacaoJob5, 4, nova);
	nova = CriarMaquina(8, 3);
	InserirMaqnaOpe(listaOperacaoJob5, 4, nova);
	nova = CriarMaquina(4, 5);
	InserirMaqnaOpe(listaOperacaoJob5, 5, nova);
	nova = CriarMaquina(6, 4);
	InserirMaqnaOpe(listaOperacaoJob5, 5, nova);

	#pragma endregion

	#pragma region MaquinasJob6
	//Inserir máquinas na lista de operações Job6
	nova = CriarMaquina(1, 3);
	InserirMaqnaOpe(listaOperacaoJob6, 1, nova);
	nova = CriarMaquina(2, 5);
	InserirMaqnaOpe(listaOperacaoJob6, 1, nova);
	nova = CriarMaquina(3, 6);
	InserirMaqnaOpe(listaOperacaoJob6, 1, nova);
	nova = CriarMaquina(4, 7);
	InserirMaqnaOpe(listaOperacaoJob6, 2, nova);
	nova = CriarMaquina(5, 8);
	InserirMaqnaOpe(listaOperacaoJob6, 2, nova);
	nova = CriarMaquina(3, 9);
	InserirMaqnaOpe(listaOperacaoJob6, 3, nova);
	nova = CriarMaquina(6, 8);
	InserirMaqnaOpe(listaOperacaoJob6, 3, nova);

	#pragma endregion

	#pragma region MaquinasJob7
	//Inserir máquinas na lista de operações Job7
	nova = CriarMaquina(3, 4);
	InserirMaqnaOpe(listaOperacaoJob7, 1, nova);
	nova = CriarMaquina(5, 5);
	InserirMaqnaOpe(listaOperacaoJob7, 1, nova);
	nova = CriarMaquina(6, 4);
	InserirMaqnaOpe(listaOperacaoJob7, 1, nova);
	nova = CriarMaquina(4, 4);
	InserirMaqnaOpe(listaOperacaoJob7, 2, nova);
	nova = CriarMaquina(7, 6);
	InserirMaqnaOpe(listaOperacaoJob7, 2, nova);
	nova = CriarMaquina(8, 4);
	InserirMaqnaOpe(listaOperacaoJob7, 2, nova);
	nova = CriarMaquina(1, 3);
	InserirMaqnaOpe(listaOperacaoJob7, 3, nova);
	nova = CriarMaquina(3, 3);
	InserirMaqnaOpe(listaOperacaoJob7, 3, nova);
	nova = CriarMaquina(4, 4);
	InserirMaqnaOpe(listaOperacaoJob7, 3, nova);
	nova = CriarMaquina(5, 5);
	InserirMaqnaOpe(listaOperacaoJob7, 3, nova);
	nova = CriarMaquina(4, 4);
	InserirMaqnaOpe(listaOperacaoJob7, 4, nova);
	nova = CriarMaquina(6, 6);
	InserirMaqnaOpe(listaOperacaoJob7, 4, nova);
	nova = CriarMaquina(8, 5);
	InserirMaqnaOpe(listaOperacaoJob7, 4, nova);
	nova = CriarMaquina(1, 3);
	InserirMaqnaOpe(listaOperacaoJob7, 5, nova);
	nova = CriarMaquina(3, 3);
	InserirMaqnaOpe(listaOperacaoJob7, 5, nova);

	#pragma endregion

	#pragma region MaquinasJob8
	//Inserir máquinas na lista de operações Job8
	nova = CriarMaquina(1, 3);
	InserirMaqnaOpe(listaOperacaoJob8, 1, nova);
	nova = CriarMaquina(2, 4);
	InserirMaqnaOpe(listaOperacaoJob8, 1, nova);
	nova = CriarMaquina(6, 4);
	InserirMaqnaOpe(listaOperacaoJob8, 1, nova);
	nova = CriarMaquina(4, 6);
	InserirMaqnaOpe(listaOperacaoJob8, 2, nova);
	nova = CriarMaquina(5, 5);
	InserirMaqnaOpe(listaOperacaoJob8, 2, nova);
	nova = CriarMaquina(8, 4);
	InserirMaqnaOpe(listaOperacaoJob8, 2, nova);
	nova = CriarMaquina(3, 4);
	InserirMaqnaOpe(listaOperacaoJob8, 3, nova);
	nova = CriarMaquina(7, 5);
	InserirMaqnaOpe(listaOperacaoJob8, 3, nova);
	nova = CriarMaquina(4, 4);
	InserirMaqnaOpe(listaOperacaoJob8, 4, nova);
	nova = CriarMaquina(6, 6);
	InserirMaqnaOpe(listaOperacaoJob8, 4, nova);
	nova = CriarMaquina(7, 1);
	InserirMaqnaOpe(listaOperacaoJob8, 5, nova);
	nova = CriarMaquina(8, 2);
	InserirMaqnaOpe(listaOperacaoJob8, 5, nova);

	#pragma endregion

	/*
	printf("\n");
	listarOpeComMaq(listaOperacaoJob1); //Teste de visualização da lista de Operações
	listarOpeComMaq(listaOperacaoJob2);
	listarOpeComMaq(listaOperacaoJob3);
	listarOpeComMaq(listaOperacaoJob4);
	listarOpeComMaq(listaOperacaoJob5);
	listarOpeComMaq(listaOperacaoJob6);
	listarOpeComMaq(listaOperacaoJob7);
	listarOpeComMaq(listaOperacaoJob8);
	*/

	#pragma endregion


	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob1, 1);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob2, 2);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob3, 3);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob4, 4);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob5, 5);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob6, 6);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob7, 7);
	inserirOpenoJob(arvoreJobInicio, listaOperacaoJob8, 8);

	listarArvorePreOrder(arvoreJobInicio);

	printf("\n");

	listarArvoreInOrder(arvoreJobInicio);

	printf("\n");

	//teste de método
	listarArvoreJobOpeInOrder(arvoreJobInicio);

	#pragma region ManipulacaoDados

	//gravarDadosFicheiro(listaOperacao);

	#pragma endregion
}