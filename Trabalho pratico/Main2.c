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
	 * .
	 * @param inicio da árvore de Jobs
	 * \return 
	 */
	job* arvoreJobInicioFicheiro = NULL;
	job* arvoreJobMenorTempo = NULL;

	/**
	 * .
	 * @param ficheiro com os dados dos Jobs
	 * \return 
	 */
	arvoreJobInicioFicheiro = lerFicheiroJobs("jobs.txt");
	arvoreJobMenorTempo = lerFicheiroJobs("jobs.txt");

	#pragma endregion


	/**
	* @brief Operações para criar e montar uma nova lista de operações
	*/
	#pragma region ListaOperacoes

	/**
	 * .
	 * @param lista de operações de um determinado Job
	 * @param ficheiro com os dados das operações de um determinado Job
	 * \return 
	 */
	operacao* listaOperacaoJob1 = NULL;
	listaOperacaoJob1 = lerFicheiroOperacao("operacoes//operacoesJob1.txt");

	operacao* listaOperacaoJob2 = NULL;
	listaOperacaoJob2 = lerFicheiroOperacao("operacoes//operacoesJob2.txt");

	operacao* listaOperacaoJob3 = NULL;
	listaOperacaoJob3 = lerFicheiroOperacao("operacoes//operacoesJob3.txt");

	operacao* listaOperacaoJob4 = NULL;
	listaOperacaoJob4 = lerFicheiroOperacao("operacoes//operacoesJob4.txt");

	operacao* listaOperacaoJob5 = NULL;
	listaOperacaoJob5 = lerFicheiroOperacao("operacoes//operacoesJob5.txt");

	operacao* listaOperacaoJob6 = NULL;
	listaOperacaoJob6 = lerFicheiroOperacao("operacoes//operacoesJob6.txt");

	operacao* listaOperacaoJob7 = NULL;
	listaOperacaoJob7 = lerFicheiroOperacao("operacoes//operacoesJob7.txt");

	operacao* listaOperacaoJob8 = NULL;
	listaOperacaoJob8 = lerFicheiroOperacao("operacoes//operacoesJob8.txt");

	#pragma endregion


	/**
	* @brief Operações para inserir máquinas nas operações
	*/
	#pragma region InserirMaquinasOperacoes

	/**
	 * .
	 * Inserir informações de máquinas de um ficheiro para uma lista de operações
	 * \return 
	 */

	#pragma region MaquinasJob1

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job1
	 * @param lista de operações do Job1
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob1.txt", listaOperacaoJob1);

	#pragma endregion

	#pragma region MaquinasJob2

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job2
	 * @param lista de operações do Job2
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob2.txt", listaOperacaoJob2);
	
	#pragma endregion

	#pragma region MaquinasJob3

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job3
	 * @param lista de operações do Job3
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob3.txt", listaOperacaoJob3);

	#pragma endregion

	#pragma region MaquinasJob4

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job4
	 * @param lista de operações do Job4
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob4.txt", listaOperacaoJob4);

	#pragma endregion

	#pragma region MaquinasJob5

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job5
	 * @param lista de operações do Job5
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob5.txt", listaOperacaoJob5);

	#pragma endregion

	#pragma region MaquinasJob6

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job6
	 * @param lista de operações do Job6
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob6.txt", listaOperacaoJob6);

	#pragma endregion

	#pragma region MaquinasJob7

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job7
	 * @param lista de operações do Job7
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob7.txt", listaOperacaoJob7);

	#pragma endregion

	#pragma region MaquinasJob8

	/**
	 * .
	 * @param ficheiro com os dados das máquinas para operações do Job8
	 * @param lista de operações do Job8
	 * \return 
	 */
	lerFicheiroMaquinas("maquinas//maquinasJob8.txt", listaOperacaoJob8);

	#pragma endregion

	#pragma endregion

	#pragma region InserirOperacoesJobs
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob1, 1);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob2, 2);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob3, 3);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob4, 4);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob5, 5);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob6, 6);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob7, 7);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob8, 8);

	#pragma endregion

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
	
	//teste de estratégia para o escalonamento.
	Job1MenorTempo = menorTempoOpe(listaOperacaoJob1);
	Job2MenorTempo = menorTempoOpe(listaOperacaoJob2);
	Job3MenorTempo = menorTempoOpe(listaOperacaoJob3);
	Job4MenorTempo = menorTempoOpe(listaOperacaoJob4);
	Job5MenorTempo = menorTempoOpe(listaOperacaoJob5);
	Job6MenorTempo = menorTempoOpe(listaOperacaoJob6);
	Job7MenorTempo = menorTempoOpe(listaOperacaoJob7);
	Job8MenorTempo = menorTempoOpe(listaOperacaoJob8);
	/*
	listarOpeComMaq(Job1MenorTempo);
	listarOpeComMaq(Job2MenorTempo);
	listarOpeComMaq(Job3MenorTempo);
	listarOpeComMaq(Job4MenorTempo);
	listarOpeComMaq(Job5MenorTempo);
	listarOpeComMaq(Job6MenorTempo);
	listarOpeComMaq(Job7MenorTempo);
	listarOpeComMaq(Job8MenorTempo);
	*/

	inserirOpenoJob(arvoreJobMenorTempo, Job1MenorTempo, 1);
	inserirOpenoJob(arvoreJobMenorTempo, Job2MenorTempo, 2);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 3);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 4);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 5);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 6);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 7);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 8);


	#pragma endregion

	#pragma region ManipulacaoDados

	//Teste ok
	//ficheiroArvoreInOrder(arvoreJobInicioFicheiro);
	//Teste para estratégia de escalonamento
	ficheiroArvoreMinimoTempo(arvoreJobMenorTempo);

	#pragma region Planeamento

	Cel plano[M][T];

	IniciaPlano(plano, -1, -1);

	OcupaPlanoDados(plano, "jobMinimo.txt");

	gravaDadosPlaneamento(plano);

	#pragma endregion
	
	#pragma endregion
}