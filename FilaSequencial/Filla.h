/*
    * Fila.h
    *
    *  Creado 31 de Março de 2023
    *  Autor: José Augusto da Silva Barbosa
    * 
    * Interface:
    * 
     Criar uma fila vazia;
     Testar se a fila está vazia;
     Verificar se a fila está cheia;
     Obter o tamanho da fila;
     Consultar o elemento da frente da fila;
     Inserir um novo elemento no fundo da fila;
     Remover o elemento da frente da fila.

*/



#ifndef _FILA_H_
#define _FILA_H_

#include <stdlib.h>

#define MAX 100


typedef struct fila Fila;

void criarFila(Fila *f);

int filaVazia(Fila *f);

int filaCheia(Fila *f);

int tamanhoFila(Fila *f);

int primeiroFila(Fila *f);

int ultimoFila(Fila *f);

void inserirFila(Fila *f, int x);

int removeFila(Fila *f);

void imprimirFila(Fila *f);


#endif // _FILA_H_