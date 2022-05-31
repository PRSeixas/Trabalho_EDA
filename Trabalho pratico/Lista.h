/**
* Autor: Pedro Seixas
* E-mail: a21872@alunos.ipca.pt
* Data: 26/03/2022
* 
* Colocar outros contribuintes aqui abaixo:
* 
* 
*/

//Bibliotecas nativas de C
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define M 9
#define T 75


#pragma region Structs

//Estrutura para criar máquinas com o número do código de sua referência e seus parâmetros
typedef struct maquina
{
	int cod;       //código da máquina
	int und;       //unidade de tempo
	int op;        //bloco de operação
	int job;       //Lista de Job a atribuir.
	struct maquina* nextm;
}maquina;

//Lista inicial para máquinas
typedef struct {
	maquina* inicio;
	int tam;
}ListaMaquina;

//Estrutura para criar um novo espaço na memória para cadastro de operações
typedef struct operacao {
	int cod;				   //Código da operação
	struct operacao* nextOp;   //Próxima operação
	struct maquina* nextM;     //Início da lista de máquinas da operação
}operacao;

//Estrutura para iniciar a lista de operações
typedef struct {
	operacao* inicio;
	int tam;
}ListaOperacao;

//Estrutura para criar job com o número do código de sua referência
typedef struct job
{
	int cod;                //Código do Job
	struct job* nextJ;      //Apontador usado na primeira fase para lista ligada simples
	struct job* left;       //Lado esquerdo da árvore
	struct job* right;      //Lado direito da árvore
	struct operacao* ope;   //Lista de operações do Job
}job;

//Lista inicial para Jobs
typedef struct {
	job* inicio;
	int tam;
}ListaJob, ListaJob1;

//Struct para auxiliar no escalonamento com os dados a exportar, Job, Operação, Máquina e Tempo
typedef struct dados
{
	int job;		//Código do Job
	int ope;		//Código da operação
	int maq;		//Código da máquina
	int und;		//unidade de tempo
}dados;

//Struct usada na matriz do escalonamento para guardar os valores do Job e Operação a exportar para o ficheiro
typedef struct Cel
{
	int idJob;		//Código do Job que será impresso na matriz
	int idOpe;		//Código da operação que será impresso na matriz
}Cel;

#pragma endregion

#pragma region FuncoesProcedimentosMaquinas

//Função para alocar memória e criar máquina
maquina* CriarMaquina(int cod, int tempo);
 
//Função para inserir máquina no início de uma lista
maquina* inserirMaqInicio2(maquina* h, maquina* nova);

//Função para remover máquina da lista
void RemoverMaq2(maquina* lista, int valor);

//Função para percorrer lista e devolver máquina com menor tempo
maquina* maquinaMenorTempo(maquina* lista);

//Listar máquinas em ordem crescente
void listarCrescenteMaq(maquina* inicio);

//Função para inserir máquina no final da lista, usado na fase um apenas.
maquina* inserirMaqFim2(ListaMaquina* lista, int valor, int tempo, int operacao, int job);

//Função para imprimir uma lista simples de máquinas, usado na primeira fase apenas.
void imprimirMaq2(maquina* lista);

//Função para inserir máquinas na lista de operações a partir de um ficheiro.
maquina* lerFicheiroMaquinas(char* nomeFicheiro, operacao* rootOpe);

#pragma endregion

#pragma region StructFuncoesProcedimentosJobs

//Função para criar Job
job* criarJob(int cod);

//Função para inserir Job no início da estrutura
job* inserirJobInicio2(job* h, job* novo);

//Função para inserir Job no final da estrutura
job* inserirJobFim2(ListaJob* listaj, int valor);

//Função para remover determinado Job de uma lista simples
void RemoverJob(ListaJob* lista, int valor);

//Função para inserir um Job em uma árvore binária
job* inserirJobArvore(job* root, job* novo);

//Função para procurar Job na árvore
job* procurarJobArvore(job* root, int cod);

//Função para inserir lista de operações de um Job na árvore de Jobs.
job* inserirOpenoJob(job* listajob, operacao* listaOp, int codJob);

//Gerar árvore de Jobs a partir de um ficheiro.
job* lerFicheiroJobs(char* nomeFicheiro);

//Função para imprimir uma lista de Jobs simples
void listarCrescenteJob(job* listaj);

//Função para imprimir a árvore de Jobs pre ordenada.
void listarArvorePreOrder(job* root);

//Função para imprimir a árvore de Jobs de forma ordenada
void listarArvoreInOrder(job* root);

//Função para imprmir a árvore completa com suas operações e máquinas.
void listarArvoreJobOpeInOrder(job* root);

//Função para imprmir lista simples de Jobs com as operações.
void imprimirJob(ListaJob* listaj);
#pragma endregion

#pragma region StructFuncoesProcedimentosOperacoes

//Função para criar operação
operacao* CriarOperacao(int cod);

//Função para inserir operação no final de uma lista, usado apenas na primeira fase.
void inserirOpeFim(ListaOperacao* listaOp, int valor);

//Função para inserir operações no inicio da lista
operacao* inserirOpeInicio2(operacao* h, operacao* nova);

//Função para remover operações da lista
void removerOpe(ListaOperacao* listaop, int valor);

//Função para procurar operação na lista original de operações
operacao* procurarOp(operacao* listaOperacao, int cod);

//Inserir máquina na lista de operação
void InserirMaqnaOpe(operacao* h, int codOp, maquina* nova);

//Cria lista auxiliar com as máquinas de menor tempo de um Job
operacao* menorTempoOpe(operacao* lista);

//Imprimir lista de operações
void listarCrescenteOpe(operacao* inicio);

//Listar operações e suas máquinas cadastradas
void listarOpeComMaq(operacao* inicio);

//Função para montar lista de operações a partir de um ficheiro
operacao* lerFicheiroOperacao(char* nomeFicheiro);

#pragma endregion

#pragma region ManipulacaoDados

//Exporta dados de uma lista de operações
void gravarDadosFicheiro(operacao* lista);

//Exporta dados completo da árvore de Job para um ficheiro
void ficheiroArvoreInOrder(job* root);

//Exporta dados da árvore gerada com os menores tempos das operações.
void ficheiroArvoreMinimoTempo(job* root);

//Função para gerar arquivo tipo csv com os dados do planeamento gerado.
void gravaDadosPlaneamento(Cel p[][T]);

#pragma endregion

#pragma region Escalonamento

//Função para iniciar e formatar a matriz para o escalonamento
void IniciaPlano(Cel p[][T], int codJob, int codOper);

//Função para verificar espaço livre que caiba a operação completa do Job na matriz
bool verificarEspaco(Cel p[][T], int coluna, int tempototal, int maq);

//Função para escrever na matriz as opereçõs dos Jobs nas linhas das máquinas
void OcupaPlanoDados(Cel p[][T], char* nomeFicheiro);

#pragma endregion

#pragma region FuncoesEmTestes

#pragma endregion
