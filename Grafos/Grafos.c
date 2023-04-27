
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Grafos.h"

Grafo *criaGrafo(int n)
{

    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->n = n;
    g->Matrizadj = (int **)malloc(n * sizeof(int *));
    g->Listaadj = (int **)malloc(n * sizeof(int *));
    g->Distancias = (int *)malloc(n * sizeof(int));
    g->tamAdj = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        g->Matrizadj[i] = (int *)malloc(n * sizeof(int));
        g->Listaadj[i] = (int *)malloc(n * sizeof(int));
        g->Distancias[i] = INFINITO;
        g->tamAdj[i] = 0;

        for (int j = 0; j < n; j++)
        {
            g->Matrizadj[i][j] = 0;
            g->Listaadj[i][j] = 0;
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
        free(g->Listaadj[i]);
    }

    free(g->Listaadj);

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
            printf("%d ", g->Listaadj[i][j]);
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

    int n, h;
    fscanf(arquivo, "%d", &n); // Ler o numero de vertices
    Grafo *g = criaGrafo(n);   // Cria o grafo
    int NaoNulo = 0;

    // Ler a matriz de adjacencia, tirando espaço e quebra de linha
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(arquivo, "%d", &h);
            g->Matrizadj[i][j] = h;
            if (g->Matrizadj[i][j] != 0)
            {
                // Se houver uma aresta, adiciona na lista de adjacência
                g->Listaadj[i][j] = h;
                NaoNulo++;
            }
        }
    }

    // Apagar os zeros da lista de adjacência e reajustar o tamanho

    for (i = 0; i < n; i++)
    {
        int k = 0;
        for (j = 0; j < n; j++)
        {
            if (g->Listaadj[i][j] != 0)
            {
                g->Listaadj[i][k] = g->Listaadj[i][j];
                k++;
            }
        }
        // realocar
        g->tamAdj[i] = k;
        g->Listaadj[i] = (int *)realloc(g->Listaadj[i], k * sizeof(int));
        printf("tamAdj[%d] = %d\n", i, sizeof(g->Listaadj[i]));
    }

    fclose(arquivo);

    return g;
}

void BFS(Grafo *g, int s) // Busca em largura
{

    int cor[g->n] ; 
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

    Grafo *g = LeitorArquivo("pcv4.txt");

    imprimeGrafo(g);

    liberaGrafo(g);

    return 0;
}