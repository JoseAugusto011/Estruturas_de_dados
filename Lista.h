/* 
 * Implementação do módulo: [Lista com vetores]
 * Autor: [José Augusto da Silva / 20210094705] 
 * Data de Criação: [09/03/2023]
 * Última alteração: [09/03/2023]
 * Descrição Geral: [Implementar biblioteca de lista com vetores para o trabalho de ED] 

*/



#ifndef _Lista_H_
#define _Lista_H_

typedef struct lista Lista;


void CriarLista(Lista *l);

int ListaVazia(Lista *l);

int ListaCheia(Lista *l);

Lista Append(Lista *l, int elem);

int GetTamanho(Lista *l);

int GetElemento(Lista *l, int pos);

int* GetPosicao(Lista *l, int elem);

int SetElemento(Lista *l, int pos, int elem);

int InserirElemento(Lista *l, int pos, int elem);

int RemoverElemento(Lista *l, int pos);








#endif
