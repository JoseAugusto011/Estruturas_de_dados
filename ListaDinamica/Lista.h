#ifndef _LISTA_H
#define _LISTA_H

// Lista =  Agrupamento de nós
// Nó =  Elemento da lista

typedef struct no NO;
typedef struct Lista LISTA;


// Cria uma lista vazia, composta por um nó cabeça
LISTA *newList(LISTA *l);

// Ver informações lista

// Verifica se a lista está vazia
int emptyList(LISTA *l);
// Retorna o tamanho da lista
int getLenght(LISTA *l);
// Mostra a lista
void showList(LISTA *l);

// Get's

// Retorna o nó cabeça da lista
int getHead(LISTA *l);
// Retorna elemento da posição enviada
int getElement(LISTA *l, int pos);
// Retorna a posições em que  elemento enviado está
int *getPosition(LISTA *l, int elem);

// Set's

// Insere elemento na posição enviada
LISTA *setElement(LISTA *l, int pos, int elem);
// Insere elemento na cabeça da lista
LISTA *setHead(LISTA *l, int elem);

// Insert´s

// Insere elemento na cabeça da lista
LISTA *insertHead(LISTA *l, int elem);
// Insere Elemento no Meio da lista
LISTA *insertMiddle(LISTA *l, int pos, int elem);
// Insere elemento no final da lista
LISTA *insertEnd(LISTA *l, int elem);
//Insere elemento em ordem crescente
LISTA *insertSorted(LISTA *l, int elem);
// Insere elemento na posição enviada
LISTA *insertElement(LISTA *l, int pos, int elem);

// Remove's

// Remove elemento da cabeça da lista
LISTA *removeHead(LISTA *l);
// Remove elemento do meio da lista
LISTA *removeMiddle(LISTA *l, int pos);
// Remove elemento do final da lista
LISTA *removeEnd(LISTA *l);
// Remove elemento da posição enviada
LISTA *removeElement(LISTA *l, int pos);

//Menu de opções
void Menu(LISTA *l);

#endif