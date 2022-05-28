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
	* @brief Opera��es para criar uma nova m�quina com seus par�metros
	*/
	#pragma region CriarMaquina
	/**
	* @param [in] endere�o listaInicio		Inicio da Lista
	*/
	maquina* listaInicio;
	listaInicio = NULL;

	/**
	* @brief Criar nova m�quina para posterior inser��o em lista de opera��es
	* @param [in] c�digo da m�quina
	* @param [in] unidade de tempo
	*/
	
	maquina* nova;
	nova = CriarMaquina(1, 4);
	listaInicio = inserirMaqInicio2(listaInicio, nova);

	//printf("Listagem teste de inser��o de m�quina\n");
	//listarCrescenteMaq(listaInicio);
	
	#pragma endregion

	/**
	* @brief Opera��es para criar um novo Job
	*/
	#pragma region ListaJobs
	/**
	* @param [in] endere�o listajInicio		Inicio da Lista
	*/
	job* listajInicio;
	listajInicio = NULL;

	job* arvoreJobInicio;
	arvoreJobInicio = NULL;

	/**
	* @brief Criar novo Job para posterior inser��o em lista de Jobs
	* @param [in] c�digo do Job
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
	//listarCrescenteJob(listajInicio); //Teste de visualiza��o da lista de Job

	#pragma endregion

	/**
	* @brief Opera��es para criar e montar uma nova lista de opera��es
	*/
	#pragma region ListaOperacoes

	/**
	* @param [in] endere�o listaOperacao		Inicio da Lista
	* @param [in] c�digo da opera��o
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
	//listarCrescenteOpe(listaOperacaoJob1); //Teste de visualiza��o da lista de Opera��es

	#pragma endregion


	/**
	* @brief Opera��es para inserir m�quinas nas opera��es
	*/
	#pragma region InserirMaquinasOperacoes

	/**
	* @brief Criar e inserir m�quina em opera��o pr� definida na lista de opera��es
	* @param [in] lista de opera��es
	* @param [in] c�digo da opera��o
	* @param [in] nova m�quina criada
	*/
	#pragma region MaquinasJob1
	//Inserir m�quinas na lista de opera��es do Job1.
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
	//Inserir m�quinas na lista de opera��es do Job2.
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
	//Inserir m�quinas na lista de opera��es do Job3.
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
	//Inserir m�quinas na lista de opera��es do Job4
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
	//Inserir m�quinas na lista de opera��es Job5
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
	//Inserir m�quinas na lista de opera��es Job6
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
	//Inserir m�quinas na lista de opera��es Job7
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
	//Inserir m�quinas na lista de opera��es Job8
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
	listarOpeComMaq(listaOperacaoJob1); //Teste de visualiza��o da lista de Opera��es
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

	//listarArvorePreOrder(arvoreJobInicio);

	//printf("\n");

	//listarArvoreInOrder(arvoreJobInicio);

	//printf("\n");

	//teste de m�todo
	//listarArvoreJobOpeInOrder(arvoreJobInicio);

	#pragma region JobMenorTempo

	operacao* Job1MenorTempo;
	Job1MenorTempo = NULL;

	operacao* Job2MenorTempo;
	Job2MenorTempo = NULL;

	operacao* Job3MenorTempo;
	Job3MenorTempo = NULL;

	operacao* Job4MenorTempo;
	Job4MenorTempo = NULL;

	operacao* Job5MenorTempo;
	Job5MenorTempo = NULL;

	operacao* Job6MenorTempo;
	Job6MenorTempo = NULL;

	operacao* Job7MenorTempo;
	Job7MenorTempo = NULL;

	operacao* Job8MenorTempo;
	Job8MenorTempo = NULL;

	//teste de estrat�gia para o escalonamento.
	Job1MenorTempo = menorTempoOpe(listaOperacaoJob1);
	Job2MenorTempo = menorTempoOpe(listaOperacaoJob2);
	Job3MenorTempo = menorTempoOpe(listaOperacaoJob3);
	Job4MenorTempo = menorTempoOpe(listaOperacaoJob4);
	Job5MenorTempo = menorTempoOpe(listaOperacaoJob5);
	Job6MenorTempo = menorTempoOpe(listaOperacaoJob6);
	Job7MenorTempo = menorTempoOpe(listaOperacaoJob7);
	Job8MenorTempo = menorTempoOpe(listaOperacaoJob8);

	listarOpeComMaq(Job1MenorTempo);
	listarOpeComMaq(Job2MenorTempo);
	listarOpeComMaq(Job3MenorTempo);
	listarOpeComMaq(Job4MenorTempo);
	listarOpeComMaq(Job5MenorTempo);
	listarOpeComMaq(Job6MenorTempo);
	listarOpeComMaq(Job7MenorTempo);
	listarOpeComMaq(Job8MenorTempo);

	#pragma endregion

	#pragma region ManipulacaoDados

	//Teste ok
	//ficheiroArvoreInOrder(arvoreJobInicio);

	#pragma endregion
}