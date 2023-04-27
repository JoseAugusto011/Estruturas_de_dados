/*
    Autor: José Augusto da Silva Barbosa
    Data : 21/04/2023
    Objetivo: Implementar algoritmos de grafos
    Disciplina: Estrutura de Dados

*/

#ifndef _GRAFOS_H_
#define _GRAFOS_H_


// Inicluir bibliotecas de estruturas de dados

#include "../ListaDinamica/Lista.h"
#include "../PilhaDinamica/Pilha.h"
#include "../FilaDinamica/Fila.h"

//definir Macros de pré-compilação

#define INFINITO 999999
#define BRANCO 1
#define CINZA 2
#define PRETO 3

//definir estruturas de dados Grafos

typedef struct //estrutura de dados para representar um grafo
{
    int n; //número de vértices
    //int **Listaadj; //lista de adjacência
    int **Listaadj; //lista de adjacência
    int **Matrizadj; //matriz de adjacência
    int *Distancias; //distância do vértice
    int *tamAdj; //tamanho das sub-lista de adjacência

}Grafo;



//definir funções de manipulação de grafos

Grafo *criaGrafo(int n); //cria um grafo com n vértices
void  liberaGrafo(Grafo *g); //libera a memória de um grafo
Grafo* LeitorArquivo(char *nomeArquivo); //le um arquivo e cria um grafo
void  imprimeGrafo(Grafo *g); //imprime um grafo

//definir funções de Procura em Largura e Profundidade

void BFS(Grafo *g, int s); //procura em largura
void DFS(Grafo *g); //procura em profundidade


#endif // _GRAFOS_H_
