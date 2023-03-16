/* 
 * Implementação do módulo: [Lista com vetores]
 * Autor: [José Augusto da Silva / 20210094705] 
 * Data de Criação:  [15/03/2023]
 * Última alteração: [16/03/2023]
 * Descrição Geral: [Implementar biblioteca de lista dinâmica para trabalho ED] 

*/



#ifndef _LISTA_H_
#define _LISTA_H_

///Testar enumerate e criar tipo booleano



typedef struct lista Lista; // Assinatura do tipo Lista

Lista* CriarLista(void); //Cria uma lista vazia 

int ListaVazia(Lista *l); //Retorna 1 se a lista estiver vazia e 0 caso contrário

int GetTamanho(Lista *l); //Retorna o tamanho da lista

int GetElemento(Lista *l, int pos); //Retorna o elemento que estiver na posição pos

Lista* GetPosicao(Lista *l, int elem); //Retorna todas as posições em que o elemento aparece

Lista* SetElemento(Lista *l, int pos, int elem); //Altera o elemento que estiver na posição pos

Lista* InserirElemento(Lista *l, int pos, int elem); //Insere o elemento elem na posição pos

Lista* InserirInicio(Lista *l, int elem); //Insere o elemento elem no início da lista

Lista* InsereMeio(Lista *l, int pos, int elem); //Insere o elemento elem no meio da lista

Lista* InserirFim(Lista *l, int elem); //Insere o elemento elem no final da lista


Lista* RemoverElemento(Lista *l, int pos); //Remove o elemento que estiver na posição pos

Lista* RemoverInicio(Lista *l); //Remove o elemento que estiver no início da lista

Lista* RemoverMeio(Lista *l, int pos); //Remove o elemento que estiver no meio da lista

Lista* RemoverFim(Lista *l); //Remove o elemento que estiver no final da lista


void MostrarLista(Lista *l); //Mostra todos os elementos da lista

void Menu(); //Mostra o menu de opções



#endif