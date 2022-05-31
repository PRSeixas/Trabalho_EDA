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

//Estrutura para criar m�quinas com o n�mero do c�digo de sua refer�ncia e seus par�metros
typedef struct maquina
{
	int cod;       //c�digo da m�quina
	int und;       //unidade de tempo
	int op;        //bloco de opera��o
	int job;       //Lista de Job a atribuir.
	struct maquina* nextm;
}maquina;

//Lista inicial para m�quinas
typedef struct {
	maquina* inicio;
	int tam;
}ListaMaquina;

//Estrutura para criar um novo espa�o na mem�ria para cadastro de opera��es
typedef struct operacao {
	int cod;				   //C�digo da opera��o
	struct operacao* nextOp;   //Pr�xima opera��o
	struct maquina* nextM;     //In�cio da lista de m�quinas da opera��o
}operacao;

//Estrutura para iniciar a lista de opera��es
typedef struct {
	operacao* inicio;
	int tam;
}ListaOperacao;

//Estrutura para criar job com o n�mero do c�digo de sua refer�ncia
typedef struct job
{
	int cod;                //C�digo do Job
	struct job* nextJ;      //Apontador usado na primeira fase para lista ligada simples
	struct job* left;       //Lado esquerdo da �rvore
	struct job* right;      //Lado direito da �rvore
	struct operacao* ope;   //Lista de opera��es do Job
}job;

//Lista inicial para Jobs
typedef struct {
	job* inicio;
	int tam;
}ListaJob, ListaJob1;

//Struct para auxiliar no escalonamento com os dados a exportar, Job, Opera��o, M�quina e Tempo
typedef struct dados
{
	int job;		//C�digo do Job
	int ope;		//C�digo da opera��o
	int maq;		//C�digo da m�quina
	int und;		//unidade de tempo
}dados;

//Struct usada na matriz do escalonamento para guardar os valores do Job e Opera��o a exportar para o ficheiro
typedef struct Cel
{
	int idJob;		//C�digo do Job que ser� impresso na matriz
	int idOpe;		//C�digo da opera��o que ser� impresso na matriz
}Cel;

#pragma endregion

#pragma region FuncoesProcedimentosMaquinas

//Fun��o para alocar mem�ria e criar m�quina
maquina* CriarMaquina(int cod, int tempo);
 
//Fun��o para inserir m�quina no in�cio de uma lista
maquina* inserirMaqInicio2(maquina* h, maquina* nova);

//Fun��o para remover m�quina da lista
void RemoverMaq2(maquina* lista, int valor);

//Fun��o para percorrer lista e devolver m�quina com menor tempo
maquina* maquinaMenorTempo(maquina* lista);

//Listar m�quinas em ordem crescente
void listarCrescenteMaq(maquina* inicio);

//Fun��o para inserir m�quina no final da lista, usado na fase um apenas.
maquina* inserirMaqFim2(ListaMaquina* lista, int valor, int tempo, int operacao, int job);

//Fun��o para imprimir uma lista simples de m�quinas, usado na primeira fase apenas.
void imprimirMaq2(maquina* lista);

//Fun��o para inserir m�quinas na lista de opera��es a partir de um ficheiro.
maquina* lerFicheiroMaquinas(char* nomeFicheiro, operacao* rootOpe);

#pragma endregion

#pragma region StructFuncoesProcedimentosJobs

//Fun��o para criar Job
job* criarJob(int cod);

//Fun��o para inserir Job no in�cio da estrutura
job* inserirJobInicio2(job* h, job* novo);

//Fun��o para inserir Job no final da estrutura
job* inserirJobFim2(ListaJob* listaj, int valor);

//Fun��o para remover determinado Job de uma lista simples
void RemoverJob(ListaJob* lista, int valor);

//Fun��o para inserir um Job em uma �rvore bin�ria
job* inserirJobArvore(job* root, job* novo);

//Fun��o para procurar Job na �rvore
job* procurarJobArvore(job* root, int cod);

//Fun��o para inserir lista de opera��es de um Job na �rvore de Jobs.
job* inserirOpenoJob(job* listajob, operacao* listaOp, int codJob);

//Gerar �rvore de Jobs a partir de um ficheiro.
job* lerFicheiroJobs(char* nomeFicheiro);

//Fun��o para imprimir uma lista de Jobs simples
void listarCrescenteJob(job* listaj);

//Fun��o para imprimir a �rvore de Jobs pre ordenada.
void listarArvorePreOrder(job* root);

//Fun��o para imprimir a �rvore de Jobs de forma ordenada
void listarArvoreInOrder(job* root);

//Fun��o para imprmir a �rvore completa com suas opera��es e m�quinas.
void listarArvoreJobOpeInOrder(job* root);

//Fun��o para imprmir lista simples de Jobs com as opera��es.
void imprimirJob(ListaJob* listaj);
#pragma endregion

#pragma region StructFuncoesProcedimentosOperacoes

//Fun��o para criar opera��o
operacao* CriarOperacao(int cod);

//Fun��o para inserir opera��o no final de uma lista, usado apenas na primeira fase.
void inserirOpeFim(ListaOperacao* listaOp, int valor);

//Fun��o para inserir opera��es no inicio da lista
operacao* inserirOpeInicio2(operacao* h, operacao* nova);

//Fun��o para remover opera��es da lista
void removerOpe(ListaOperacao* listaop, int valor);

//Fun��o para procurar opera��o na lista original de opera��es
operacao* procurarOp(operacao* listaOperacao, int cod);

//Inserir m�quina na lista de opera��o
void InserirMaqnaOpe(operacao* h, int codOp, maquina* nova);

//Cria lista auxiliar com as m�quinas de menor tempo de um Job
operacao* menorTempoOpe(operacao* lista);

//Imprimir lista de opera��es
void listarCrescenteOpe(operacao* inicio);

//Listar opera��es e suas m�quinas cadastradas
void listarOpeComMaq(operacao* inicio);

//Fun��o para montar lista de opera��es a partir de um ficheiro
operacao* lerFicheiroOperacao(char* nomeFicheiro);

#pragma endregion

#pragma region ManipulacaoDados

//Exporta dados de uma lista de opera��es
void gravarDadosFicheiro(operacao* lista);

//Exporta dados completo da �rvore de Job para um ficheiro
void ficheiroArvoreInOrder(job* root);

//Exporta dados da �rvore gerada com os menores tempos das opera��es.
void ficheiroArvoreMinimoTempo(job* root);

//Fun��o para gerar arquivo tipo csv com os dados do planeamento gerado.
void gravaDadosPlaneamento(Cel p[][T]);

#pragma endregion

#pragma region Escalonamento

//Fun��o para iniciar e formatar a matriz para o escalonamento
void IniciaPlano(Cel p[][T], int codJob, int codOper);

//Fun��o para verificar espa�o livre que caiba a opera��o completa do Job na matriz
bool verificarEspaco(Cel p[][T], int coluna, int tempototal, int maq);

//Fun��o para escrever na matriz as opere��s dos Jobs nas linhas das m�quinas
void OcupaPlanoDados(Cel p[][T], char* nomeFicheiro);

#pragma endregion

#pragma region FuncoesEmTestes

#pragma endregion
