/* 
 * Implementação do módulo: [Lista com vetores]
 * Autor: [José Augusto da Silva / 20210094705] 
 * Data de Criação: [09/03/2023]
 * Última alteração: [09/03/2023]
 * Descrição Geral: [Implementar biblioteca de lista com vetores para o trabalho de ED] 

*/



#ifndef _Lista_H_
#define _Lista_H_

#define TAM_MAX 100

typedef struct{
    
    int vetor[TAM_MAX];
    int TamanhoAtual;

}Lista;



void CriarLista(Lista *l); //Cria uma lista vazia 

int ListaVazia(Lista *l); //Retorna 1 se a lista estiver vazia e 0 caso contrário

int ListaCheia(Lista *l); //Retorna 1 se a lista estiver cheia e 0 caso contrário

int GetTamanho(Lista *l); //Retorna o tamanho da lista

int GetElemento(Lista *l, int pos); //Retorna o elemento que estiver na posição pos

int* GetPosicao(Lista *l, int elem); //Retorna todas as posições em que o elemento aparece

int SetElemento(Lista *l, int pos, int elem); //Altera o elemento que estiver na posição pos

int InserirElemento(Lista *l, int pos, int elem); //Insere o elemento elem na posição pos

int RemoverElemento(Lista *l, int pos); //Remove o elemento que estiver na posição pos

void MostrarLista(Lista *l); //Mostra todos os elementos da lista






#endif
