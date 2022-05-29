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
	int cod;
	struct operacao* nextOp;
	struct maquina* nextM;
}operacao;

//Estrutura para iniciar a lista de operações
typedef struct {
	operacao* inicio;
	int tam;
}ListaOperacao;

//Estrutura para criar job com o número do código de sua referência
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

//Função para alocar memória e criar máquina
maquina* CriarMaquina(int cod, int tempo);
 
maquina* inserirMaqInicio2(maquina* h, maquina* nova);

//Função para inserir máquina no inicio da lista
void inserirMaqInicio(ListaMaquina* lista, int valor, int tempo, int operacao, int job);

//Função para inserir máquina no final da lista
void inserirMaqFim(ListaMaquina* lista, int valor, int tempo, int operacao, int job);
maquina* inserirMaqFim2(ListaMaquina* lista, int valor, int tempo, int operacao, int job);

//Função para remover máquina da lista
void RemoverMaq(ListaMaquina* lista, int valor);
void RemoverMaq2(maquina* lista, int valor);

//Função para percorrer lista e devolver máquina com menor tempo
maquina* maquinaMenorTempo(maquina* lista);

#pragma endregion

#pragma region StructFuncoesProcedimentosJobs

//Função para criar Job
job* criarJob(int cod);


//Função para inserir Job no início da estrutura
void inserirJobInicio(ListaJob* lista, int valor);
job* inserirJobInicio2(job* h, job* novo);

//Função para inserir Job no final da estrutura
void inserirJobFim(ListaJob* lista, int valor);
job* inserirJobFim2(ListaJob* listaj, int valor);

//Função para remover determinado Job da estrutura
void RemoverJob(ListaJob* lista, int valor);

//Função arvore de Job em teste
job* inserirJobArvore(job* root, job* novo);

//Função para procurar Job na árvore
job* procurarJobArvore(job* root, int cod);

#pragma endregion

#pragma region StructFuncoesProcedimentosOperacoes

//Função para criar operação
operacao* CriarOperacao(int cod);

//Função para inserir operações no inicio da lista
void inserirOpeInicio(ListaOperacao* listaop, int valor);
operacao* inserirOpeInicio2(operacao* h, operacao* nova);

//Função para inserir operações sempre ao final da lista
void inserirOpeFim(ListaOperacao* listaOp, int valor);

//Função para remover operações da lista
void removerOpe(ListaOperacao* listaop, int valor);

//Imprimir relação de operações cadastradas
void imprimirOp(ListaOperacao* listaOp);
void listarCrescenteOpe(operacao* inicio);

//Função para procurar operação na lista original de operações
operacao* procurarOp(operacao* listaOperacao, int cod);

//Inserir lista de operação na lista de Job
job* inserirOpenoJob(job* listajob, operacao* listaOp, int codJob);

//Cria lista auxiliar com as máquinas de menor tempo de um Job
operacao* menorTempoOpe(operacao* lista);

//Inserir máquina na lista de operação
void InserirMaqnaOpe(operacao* h, int codOp, maquina* nova);

//Listar operações e suas máquinas cadastradas
void listarOpeComMaq(operacao* inicio);



#pragma endregion

#pragma region	ProcedimentosImpressoes

//Imprimir relação de máquinas cadastradas
void imprimirMaq(ListaMaquina* lista);
void imprimirMaq2(maquina* lista);

//Imprimir relação de Jobs cadastrados
void imprimirJob(ListaJob* listaj);

//Imprimir lista de determinado Job com suas operações e máquinas cadastrados.
void imprimirListaPorJob(ListaMaquina* lista, int j);

//Imprimir árvore de Jobs Pre Order
void listarArvorePreOrder(job* root);

//Imprimir árvore de Jobs InOrder
void listarArvoreInOrder(job* root);

//Imprimir árvore de Jobs com operações e máquinas In Order
void listarArvoreJobOpeInOrder(job* root);

#pragma endregion

#pragma region ManipulacaoDados

void gravarDadosFicheiro(operacao* lista);

#pragma endregion

#pragma region FuncoesEmTestes

void montarListaJobs(ListaMaquina* lista, ListaMaquina* listaaux, int j);

//Funções e procedimentos em testes
void imprimirRelatorioJob(ListaJob* listaj, ListaMaquina* lista, ListaOperacao* listaOp, int valor);
maquina* copiarbloco(ListaMaquina* lista);

//Listar Job com suas respectivas operações e Jobs
//Função em desenvolvimento, corrigir pesquisa e apontador de Job para operações
void listarJobCompleto(job* inicio, int codJob);

//Função para calcular menor tempo disponível para efetuar um Job
//Em desenvolvimento, corrigir erro de loop na verificação da lista de operações
void ListarJobMenorTempo(operacao* lista);


void gravarDadosFicheiro2(operacao* lista);


void ficheiroArvoreInOrder(job* root);

//Teste de função para ler e montar árvore de Jobs do ficheiro. Teste ok.
job* lerFicheiroJobs(char* nomeFicheiro);

//Teste de função para ler e montar a lista de operações de um determinado Job.
operacao* lerFicheiroOperacao(char* nomeFicheiro);


maquina* lerFicheiroMaquinas(char* nomeFicheiro, operacao* rootOpe);

//teste de estratégia de escalonamento
void ficheiroArvoreMinimoTempo(job* root);
#pragma endregion


#pragma region CodigosProfessorJoao
//Listar máquinas em ordem decrescente
void listarDecrescenteMaq(maquina* lista);

//Listar máquinas em ordem crescente
void listarCrescenteMaq(maquina* inicio);

//Listar Jobs em ordem crescente
void listarCrescenteJob(job* listaj);

maquina* inserirInicioM(maquina* inicio, int cod, int tempo, int operacao, int job);
job* inserirInicioJ(job* head, int cod);
#pragma endregion