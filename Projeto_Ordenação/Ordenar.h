/*FEITO EM DUPLA

AUTORES: ARTUR DARTAGNAN e JOSÉ AUGUSTO

*/



#ifndef _Ordenar_H_
#define _Ordenar_H_
#include <stdio.h>
#include <stdlib.h>
#include "Tempo.h"

int* bubble_sort(int *v, int n);
int* selection_sort(int *v, int n);
int* inserction_sort(int *v, int n);
int* merge(int inicio, int meio,int fim,int* vetor);
int* merge_sort(int inicio, int fim, int* vetor);
int* partition(int inicio, int fim, int* vetor);
int* quick_sort(int inicio, int fim, int* vetor);
int* count_sort(int* vetor,int n);
void Imprimir_vetor(int *v, int n);
int TamVetor(char* file_name);
int* Le_arquivo(char* file_name);
void Teste_Instancia(int* ordenar, int tamVetor);
void Menu();

#endif