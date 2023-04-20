#include "Fila.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    NO *prox;
} NO;

typedef struct fila
{
    NO *inicio;
    NO *fim;
    int Tam;

} FILA;

// Criação e verificação de fila
FILA *CriaFila(FILA *f)
{

    f = (FILA *)malloc(sizeof(FILA));

    if (f == NULL)
    {
        printf("Erro na alocação da fila");
        exit(1);
    }

    else
    {
        f->inicio = NULL;
        f->fim = NULL;
        f->Tam = 0;
    }

    return f;
}
int FilaVazia(FILA *f)
{

    return f->Tam == 0 ? 1 : 0;
}

// GEts
int TamFila(FILA *f)
{
    return f->Tam;
}
NO *FilaInicio(FILA *f)
{
    return f->inicio;
}
NO *FilaFim(FILA *f)
{
    return f->fim;
}

// Inserção e remoção

void Push(FILA *f, int x)
{

    NO *novo = (NO *)malloc(sizeof(NO));
    novo->info = x;
    novo->prox = NULL;

    if (FilaVazia(f))
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->Tam++;
}
NO *Pop(FILA *f)
{

    if (FilaVazia(f))
    {
        printf("Fila vazia");
        exit(1);
    }

    else if (f->inicio == f->fim)
    { // Se só tiver um elemento
        f->fim = NULL;
    }

    NO *aux = f->inicio;
    f->inicio = f->inicio->prox;
    f->Tam--;
    return aux;
}

// Impressão e liberação

void ImprimeFila(FILA *f)
{

    if (FilaVazia(f))
    {
        printf("Fila vazia");
        exit(1);
    }

    NO *aux = f->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void LiberaFila(FILA *f)
{

    if (FilaVazia(f))
    {
        printf("Fila vazia");
        exit(1);
    }

    NO *iterador = f->inicio;
    while (iterador != NULL)
    {
        NO *garbage = iterador->prox;
        free(iterador);
        iterador = garbage;
    }
    free(f);
}

void Menu(FILA *f)
{

    int opcao = -1;
    int x = 0;
    NO *aux = NULL;

    while (opcao != 0)
    {
        printf("\n\tMENU:\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Tamanho da lista\n");
        printf("4 - Inicio da fila\n");
        printf("5 - Fim da fila\n");
        printf("6 - Imprimir fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &x);
            Push(f, x);
            break;
        case 2:
            aux = Pop(f);
            printf("Valor removido: %d\n", aux->info);
            free(aux);
            break;
        case 3:
            printf("Tamanho da fila: %d\n", TamFila(f));
            break;
        case 4:
            aux = FilaInicio(f);
            printf("Inicio da fila: %d\n", aux->info);
            break;
        case 5:
            aux = FilaFim(f);
            printf("Fim da fila: %d\n", aux->info);
            break;
        case 6:
            ImprimeFila(f);
            break;
        case 0:
            LiberaFila(f);
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
}