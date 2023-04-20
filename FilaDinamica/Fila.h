/*
 *  Fila.h
 *  Fila
 *
 *   // Autor: José Augusto da Silva Barbosa
 *  // Data: 02/03/2023
 * // Disciplina: Estrutura de Dados
 *
 */

#ifndef FILA_H
#define FILA_H


typedef struct no NO;
typedef struct fila FILA;


FILA *CriaFila(FILA *f); // Cria uma fila vazia

int FilaVazia(FILA *f); // Verifica se a fila está vazia
int TamFila(FILA *f);   // Retorna o tamanho da fila

NO *FilaInicio(FILA *f); // Retorna o primeiro elemento da fila
NO *FilaFinal(FILA *f);  // Retorna o último elemento da fila

void Push(FILA *f, int x); // Insere um elemento no final da fila
NO *Pop(FILA *f);         // Remove o primeiro elemento da fila

void LiberaFila(FILA *f); // Libera a memória alocada para a fila
void ImprimeFila(FILA *f); // Imprime a fila

void Menu(FILA *f); // Menu de opções

#endif
