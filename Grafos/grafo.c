/*
    Autor: José Augusto da Silva Barbosa
    Data : 21/04/2023
    Objetivo: Implementar algoritmos de grafos
    Disciplina: Estrutura de Dados

*/

#ifndef _GRAFOS_H_
#define _GRAFOS_H_

// Inicluir bibliotecas de estruturas de dados

// #include "../ListaDinamica/Lista.h"
#include "Lista.h"
// #include "../PilhaDinamica/Pilha.h"
// #include "../FilaDinamica/Fila.h"

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

// definir Macros de pré-compilação

#define INFINITO 999999
#define BRANCO 1
#define CINZA 2
#define PRETO 3

// Lista

// definir estruturas de dados Grafos

typedef struct // estrutura de dados para representar um grafo
{
    int n;           // número de vértices
    LISTA **ListaAdj; // lista de adjacência

    int **Matrizadj; // matriz de adjacência
    int *Distancias; // distância do vértice
    int *tamAdj;     // tamanho das sub-lista de adjacência

} Grafo;

Grafo *criaGrafo(int n)
{

    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    
    LISTA **l;


    g->n = n;

    g->ListaAdj = (LISTA **)malloc(g->n * sizeof(LISTA*));
   
    l = g->ListaAdj;

    (*l)->head = NULL;
    (*l)->lenght = 0;
    g->ListaAdj = l;
    
    printf("Aqui\n");
    g->Matrizadj = (int **)malloc(g->n * sizeof(int *));
   
    g->Distancias = (int *)malloc(g->n * sizeof(int));
    
    g->tamAdj = (int *)malloc(g->n * sizeof(int));
    
    

    if (g == NULL || g->ListaAdj == NULL || g->Matrizadj == NULL || g->Distancias == NULL || g->tamAdj == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    
     
    
    for (int i = 0; i < n; i++)
    {
        g->Matrizadj[i] = (int *)malloc(n * sizeof(int));
        g->ListaAdj[i] = newList(g->ListaAdj[i]);


        g->Distancias[i] = INFINITO;
        g->tamAdj[i] = 0;
        
        for (int j = 0; j < n; j++)
        {
            g->Matrizadj[i][j] = 0;
            g->ListaAdj[i] = insertHead(g->ListaAdj[i], 0);          
            
            
        }
    }


    return g;
}

void liberaGrafo(Grafo *g)
{

    for (int i = 0; i < g->n; i++)
    {
        free(g->Matrizadj[i]);
    }

    free(g->Matrizadj);

    for (int i = 0; i < g->n; i++)
    {
        free(g->ListaAdj[i]);
    }

    free(g->ListaAdj);

    free(g->Distancias);

    free(g);
}

void imprimeGrafo(Grafo *g)
{
    int sublista = 0;

    printf("\n\tGrafo\n");

    printf("Numero de Vertices: %d\n", g->n);

    printf("Matriz de Adjacencia\n");

    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            printf("%d ", g->Matrizadj[i][j]);
        }
        printf("\n");
    }

    printf("\nLista de Adjacencia\n");

    for (int i = 0; i < g->n; i++)
    {

        printf("Vertice %d: ", i);
        for (int j = 0; j < g->tamAdj[i]; j++)
        {
            showList(g->ListaAdj[i]);
        }
    }

    printf("\n\nDistancias\n");

    for (int i = 0; i < g->n; i++)
    {
        printf("%d ", g->Distancias[i]);
    }
    printf("\n");
}

Grafo *LeitorArquivo(char *nomeArquivo)
{
    

    FILE *arquivo = fopen(nomeArquivo, "r");
    int i, j;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    int n, h, NaoNulo = 0;
    fscanf(arquivo, "%d", &n); // Ler o numero de vertices
    printf("Numero de vertices: %d\n", n);
    Grafo *g = criaGrafo(n);   // Cria o grafo
    printf("Grafo criado\n");
    
    

    // Ler a matriz de adjacencia, tirando espaço e quebra de linha
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            
            fscanf(arquivo, "%d", &h);
            
            if (h != 0)
            {
                g->Matrizadj[i][j] = h;
                printf("antes do insert\n");
                g->ListaAdj[i] = insertHead(g->ListaAdj[i], j);
                printf("\nparte critica\n");

            }
            
        }
    }



    //imprimeGrafo(g);

    fclose(arquivo);

    printf("%d\n", g->ListaAdj[0]->lenght);

    return g;
}

void BFS(Grafo *g, int s) // Busca em largura
{

    int cor[g->n];
    for (int i = 0; i < g->n; i++)
    {
        cor[i] = BRANCO;
    }

    cor[s] = CINZA;
    g->Distancias[s] = 0;
}

int main()
{

    printf("\n\tGrafos - Main\n");

    Grafo *g;

    g = LeitorArquivo("pcv4.txt");

    imprimeGrafo(g);

    liberaGrafo(g);

    return 0;
}

#endif // _GRAFOS_H_
