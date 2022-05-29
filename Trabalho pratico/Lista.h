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
	int cod;
	struct operacao* nextOp;
	struct maquina* nextM;
}operacao;

//Estrutura para iniciar a lista de opera��es
typedef struct {
	operacao* inicio;
	int tam;
}ListaOperacao;

//Estrutura para criar job com o n�mero do c�digo de sua refer�ncia
typedef struct job
{
	int cod;
	struct job* nextJ;
	struct job* left;
	struct job* right;
	struct operacao* ope;
}job;

//Lista inicial para Jobs
typedef struct {
	job* inicio;
	int tam;
}ListaJob, ListaJob1;

typedef struct dados
{
	int job;
	int ope;
	int maq;
	int und;
}dados;

#pragma endregion

#pragma region FuncoesProcedimentosMaquinas

//Fun��o para alocar mem�ria e criar m�quina
maquina* CriarMaquina(int cod, int tempo);
 
maquina* inserirMaqInicio2(maquina* h, maquina* nova);

//Fun��o para inserir m�quina no inicio da lista
void inserirMaqInicio(ListaMaquina* lista, int valor, int tempo, int operacao, int job);

//Fun��o para inserir m�quina no final da lista
void inserirMaqFim(ListaMaquina* lista, int valor, int tempo, int operacao, int job);
maquina* inserirMaqFim2(ListaMaquina* lista, int valor, int tempo, int operacao, int job);

//Fun��o para remover m�quina da lista
void RemoverMaq(ListaMaquina* lista, int valor);
void RemoverMaq2(maquina* lista, int valor);

//Fun��o para percorrer lista e devolver m�quina com menor tempo
maquina* maquinaMenorTempo(maquina* lista);

#pragma endregion

#pragma region StructFuncoesProcedimentosJobs

//Fun��o para criar Job
job* criarJob(int cod);


//Fun��o para inserir Job no in�cio da estrutura
void inserirJobInicio(ListaJob* lista, int valor);
job* inserirJobInicio2(job* h, job* novo);

//Fun��o para inserir Job no final da estrutura
void inserirJobFim(ListaJob* lista, int valor);
job* inserirJobFim2(ListaJob* listaj, int valor);

//Fun��o para remover determinado Job da estrutura
void RemoverJob(ListaJob* lista, int valor);

//Fun��o arvore de Job em teste
job* inserirJobArvore(job* root, job* novo);

//Fun��o para procurar Job na �rvore
job* procurarJobArvore(job* root, int cod);

#pragma endregion

#pragma region StructFuncoesProcedimentosOperacoes

//Fun��o para criar opera��o
operacao* CriarOperacao(int cod);

//Fun��o para inserir opera��es no inicio da lista
void inserirOpeInicio(ListaOperacao* listaop, int valor);
operacao* inserirOpeInicio2(operacao* h, operacao* nova);

//Fun��o para inserir opera��es sempre ao final da lista
void inserirOpeFim(ListaOperacao* listaOp, int valor);

//Fun��o para remover opera��es da lista
void removerOpe(ListaOperacao* listaop, int valor);

//Imprimir rela��o de opera��es cadastradas
void imprimirOp(ListaOperacao* listaOp);
void listarCrescenteOpe(operacao* inicio);

//Fun��o para procurar opera��o na lista original de opera��es
operacao* procurarOp(operacao* listaOperacao, int cod);

//Inserir lista de opera��o na lista de Job
job* inserirOpenoJob(job* listajob, operacao* listaOp, int codJob);

//Cria lista auxiliar com as m�quinas de menor tempo de um Job
operacao* menorTempoOpe(operacao* lista);

//Inserir m�quina na lista de opera��o
void InserirMaqnaOpe(operacao* h, int codOp, maquina* nova);

//Listar opera��es e suas m�quinas cadastradas
void listarOpeComMaq(operacao* inicio);



#pragma endregion

#pragma region	ProcedimentosImpressoes

//Imprimir rela��o de m�quinas cadastradas
void imprimirMaq(ListaMaquina* lista);
void imprimirMaq2(maquina* lista);

//Imprimir rela��o de Jobs cadastrados
void imprimirJob(ListaJob* listaj);

//Imprimir lista de determinado Job com suas opera��es e m�quinas cadastrados.
void imprimirListaPorJob(ListaMaquina* lista, int j);

//Imprimir �rvore de Jobs Pre Order
void listarArvorePreOrder(job* root);

//Imprimir �rvore de Jobs InOrder
void listarArvoreInOrder(job* root);

//Imprimir �rvore de Jobs com opera��es e m�quinas In Order
void listarArvoreJobOpeInOrder(job* root);

#pragma endregion

#pragma region ManipulacaoDados

void gravarDadosFicheiro(operacao* lista);

#pragma endregion

#pragma region FuncoesEmTestes

void montarListaJobs(ListaMaquina* lista, ListaMaquina* listaaux, int j);

//Fun��es e procedimentos em testes
void imprimirRelatorioJob(ListaJob* listaj, ListaMaquina* lista, ListaOperacao* listaOp, int valor);
maquina* copiarbloco(ListaMaquina* lista);

//Listar Job com suas respectivas opera��es e Jobs
//Fun��o em desenvolvimento, corrigir pesquisa e apontador de Job para opera��es
void listarJobCompleto(job* inicio, int codJob);

//Fun��o para calcular menor tempo dispon�vel para efetuar um Job
//Em desenvolvimento, corrigir erro de loop na verifica��o da lista de opera��es
void ListarJobMenorTempo(operacao* lista);


void gravarDadosFicheiro2(operacao* lista);


void ficheiroArvoreInOrder(job* root);

//Teste de fun��o para ler e montar �rvore de Jobs do ficheiro. Teste ok.
job* lerFicheiroJobs(char* nomeFicheiro);

//Teste de fun��o para ler e montar a lista de opera��es de um determinado Job.
operacao* lerFicheiroOperacao(char* nomeFicheiro);


maquina* lerFicheiroMaquinas(char* nomeFicheiro, operacao* rootOpe);

//teste de estrat�gia de escalonamento
void ficheiroArvoreMinimoTempo(job* root);
#pragma endregion


#pragma region CodigosProfessorJoao
//Listar m�quinas em ordem decrescente
void listarDecrescenteMaq(maquina* lista);

//Listar m�quinas em ordem crescente
void listarCrescenteMaq(maquina* inicio);

//Listar Jobs em ordem crescente
void listarCrescenteJob(job* listaj);

maquina* inserirInicioM(maquina* inicio, int cod, int tempo, int operacao, int job);
job* inserirInicioJ(job* head, int cod);
#pragma endregion