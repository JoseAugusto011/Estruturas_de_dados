/* 
 * Implementação do módulo: [Pilha com vetores]
 * Autor: [José Augusto da Silva / 20210094705] 
 * Data de Criação: [09/03/2023]
 * Última alteração: [09/03/2023]
 * Descrição Geral: [Implementar biblioteca de Pilha com vetores para o trabalho de ED] 

*/



#ifndef _Pilha_H_
#define _Pilha_H_

#define TAM_MAX 100

typedef struct{
    
    int vetor[TAM_MAX];
    int TamanhoAtual;
    int Topo;


}Pilha;



void CriarPilha(Pilha **l); //Cria uma Pilha vazia 

int PilhaVazia(Pilha **l); //Retorna 1 se a Pilha estiver vazia e 0 caso contrário

int PilhaCheia(Pilha **l); //Retorna 1 se a Pilha estiver cheia e 0 caso contrário

int GetTamanho(Pilha **l); //Retorna o tamanho da Pilha

int Top(Pilha **l); //Retorna o elemento que estiver no topo

int Push(Pilha **l, int elem); //Insere o elemento elem na posição pos

int Pop(Pilha **l); //Remove o elemento que estiver na posição pos

//void MostrarPilha(Pilha *l); //Mostra todos os elementos da Pilha

void Menu(); //Mostra o menu de opções

void LiberaPilha(Pilha **l); //Libera a Pilha




#endif
