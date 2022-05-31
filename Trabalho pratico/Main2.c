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
	* @brief Operações para criar um novo Job
	*/
	#pragma region ListaJobs
	
	//Inicio da árvore de Jobs
	job* arvoreJobInicioFicheiro = NULL;
	job* arvoreJobMenorTempo = NULL;

	//Montagem da árvore a partir do dados de um ficheiro
	arvoreJobInicioFicheiro = lerFicheiroJobs("jobs.txt");
	arvoreJobMenorTempo = lerFicheiroJobs("jobs.txt");

	#pragma endregion


	/**
	* @brief Operações para criar e montar uma nova lista de operações
	*/
	#pragma region ListaOperacoes

	//Montagem das listas de operações dos Jobs a partir de um ficheiro
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
	* @brief Operações para inserir as informações das máquinas de um ficheiro nas listas de operações
	*/
	#pragma region InserirMaquinasOperacoes

	//Acrescentar máquinas nas listas de operações de um determinado Job
	#pragma region MaquinasJob1

	lerFicheiroMaquinas("maquinas//maquinasJob1.txt", listaOperacaoJob1);
	#pragma endregion

	#pragma region MaquinasJob2

	lerFicheiroMaquinas("maquinas//maquinasJob2.txt", listaOperacaoJob2);
	#pragma endregion

	#pragma region MaquinasJob3

	lerFicheiroMaquinas("maquinas//maquinasJob3.txt", listaOperacaoJob3);
	#pragma endregion

	#pragma region MaquinasJob4

	lerFicheiroMaquinas("maquinas//maquinasJob4.txt", listaOperacaoJob4);
	#pragma endregion

	#pragma region MaquinasJob5

	lerFicheiroMaquinas("maquinas//maquinasJob5.txt", listaOperacaoJob5);
	#pragma endregion

	#pragma region MaquinasJob6

	lerFicheiroMaquinas("maquinas//maquinasJob6.txt", listaOperacaoJob6);
	#pragma endregion

	#pragma region MaquinasJob7

	lerFicheiroMaquinas("maquinas//maquinasJob7.txt", listaOperacaoJob7);
	#pragma endregion

	#pragma region MaquinasJob8

	lerFicheiroMaquinas("maquinas//maquinasJob8.txt", listaOperacaoJob8);
	#pragma endregion

	#pragma endregion

	/**
	 * .
	 * @brief Inserção das listas de operações no seu Job correspondente
	 * \return 
	 */
	#pragma region InserirOperacoesJobs

	//Inserir as lists de operações montadas nos Jobs
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob1, 1);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob2, 2);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob3, 3);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob4, 4);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob5, 5);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob6, 6);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob7, 7);
	inserirOpenoJob(arvoreJobInicioFicheiro, listaOperacaoJob8, 8);

	#pragma region JobMenorTempo

	//Listas de operações que receberão as máquinas com menor tempo
	operacao* Job1MenorTempo = NULL;
	operacao* Job2MenorTempo = NULL;
	operacao* Job3MenorTempo = NULL;
	operacao* Job4MenorTempo = NULL;
	operacao* Job5MenorTempo = NULL;
	operacao* Job6MenorTempo = NULL;
	operacao* Job7MenorTempo = NULL;
	operacao* Job8MenorTempo = NULL;
	
	Job1MenorTempo = menorTempoOpe(listaOperacaoJob1);
	Job2MenorTempo = menorTempoOpe(listaOperacaoJob2);
	Job3MenorTempo = menorTempoOpe(listaOperacaoJob3);
	Job4MenorTempo = menorTempoOpe(listaOperacaoJob4);
	Job5MenorTempo = menorTempoOpe(listaOperacaoJob5);
	Job6MenorTempo = menorTempoOpe(listaOperacaoJob6);
	Job7MenorTempo = menorTempoOpe(listaOperacaoJob7);
	Job8MenorTempo = menorTempoOpe(listaOperacaoJob8);

	//Árvore de jobs atualizada com as máquinas com menor tempo em cada operação.
	inserirOpenoJob(arvoreJobMenorTempo, Job1MenorTempo, 1);
	inserirOpenoJob(arvoreJobMenorTempo, Job2MenorTempo, 2);
	inserirOpenoJob(arvoreJobMenorTempo, Job3MenorTempo, 3);
	inserirOpenoJob(arvoreJobMenorTempo, Job4MenorTempo, 4);
	inserirOpenoJob(arvoreJobMenorTempo, Job5MenorTempo, 5);
	inserirOpenoJob(arvoreJobMenorTempo, Job6MenorTempo, 6);
	inserirOpenoJob(arvoreJobMenorTempo, Job7MenorTempo, 7);
	inserirOpenoJob(arvoreJobMenorTempo, Job8MenorTempo, 8);

	#pragma endregion

	#pragma endregion

	/**
	 * .
	 * @brief Exporta ficheiros com os dados gerados a partir da árvore de Jobs.
	 * \return 
	 */
	#pragma region ManipulacaoDados

	//Exportar ficheiro com a informação completa da árvore de Jobs.
	ficheiroArvoreInOrder(arvoreJobInicioFicheiro);

	//Exportar ficheiro com a informação das operações com menor tempo de execução.
	ficheiroArvoreMinimoTempo(arvoreJobMenorTempo);

	#pragma endregion

	/**
	 * .
	 * @brief Planeamento da execução das operações com as máquinas de menor tempo.
	 * \return 
	 */
	#pragma region Planeamento

	Cel plano[M][T];  //Declaração da matriz que receberá o planeamento da execução dos Jobs.

	//Inicialização da matriz com todos os valores -1, servirá de parâmetro.
	IniciaPlano(plano, -1, -1);

	//Preenchimento da matriz com os dados gerados pela árvore de Jobs com os menores tempos nas operações.
	OcupaPlanoDados(plano, "jobMinimo.txt");

	//Exportar matriz preenchida para um arquivo do tipo "csv"
	gravaDadosPlaneamento(plano);

	#pragma endregion
	
}