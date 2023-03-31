#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

void CriarLista(Lista *l)
{
    l->TamanhoAtual = 0;
}

int ListaVazia(Lista *l)
{
    if (l->TamanhoAtual == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ListaCheia(Lista *l)
{
    if (l->TamanhoAtual == TAM_MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GetTamanho(Lista *l)
{
    return l->TamanhoAtual;
}

int GetElemento(Lista *l, int pos)
{
    if (pos <= 0 || pos > l->TamanhoAtual)
    {
        printf("Posicao invalida");
        return -1;
    }
    else
    {
        return l->vetor[pos - 1];
    }
}

int *GetPosicao(Lista *l, int elemento)
{

    // Retorne todas as posicoes em que o elemento aparece

    int *posicoes = (int *)malloc(sizeof(int) * l->TamanhoAtual); /// Continuar daqui!
    int i, j = 0;

    for (i = 0; i < l->TamanhoAtual; i++)
    {
        if (l->vetor[i] == elemento)
        {
            posicoes[j] = i + 1;
            j++;
        }
    }

    return posicoes;
    free(posicoes);
}

int SetElemento(Lista *l, int pos, int elem)
{
    if (pos <= 0 || pos > l->TamanhoAtual)
    {
        printf("Posicao invalida");
        return -1;
    }
    else
    {
        l->vetor[pos - 1] = elem; // Posicao 1 da lista é a posicao 0 do vetor
        return 1;
    }
}

// 1 4 5 6 3 -
//           i
// Inserir(2, 7)

int InserirElemento(Lista *l, int pos, int elem)
{
    if (pos <= 0 || pos > l->TamanhoAtual + 1 || ListaCheia(l))
    {
        printf("Posicao invalida");
        return -1;
    }
    else
    {
        int i;
        for (i = l->TamanhoAtual; i >= pos; i--)
        {                                  // i começa no final da lista
            l->vetor[i] = l->vetor[i - 1]; // Desloca todos os elementos para a direita --> espaço vazio
        }
        l->vetor[pos - 1] = elem;
        l->TamanhoAtual++;
        return 1;
    }
}

int InserirOrdenado(Lista *l, int elem)
{
    if (ListaCheia(l))
    {
        printf("Lista cheia");
        return -1;
    }
    else if (ListaVazia(l))
    {
        InserirElemento(l, 1, elem);
        return 1;
    }
    else
    {
        int i;
        for (i = 0; i < l->TamanhoAtual; i++)
        {
            if (l->vetor[i] > elem)
            {
                InserirElemento(l, i + 1, elem);
                return 1;
            }
        }
        InserirElemento(l, l->TamanhoAtual + 1, elem);
        return 1;
    }
}

int RemoverElemento(Lista *l, int pos)
{
    if (pos <= 0 || pos >= l->TamanhoAtual)
    {
        printf("Posicao invalida");
        return -1;
    }
    else
    {
        int i;
        for (i = pos - 1; i < l->TamanhoAtual; i++)
        {                                  // i começa na posição do elemento a ser removido
            l->vetor[i] = l->vetor[i + 1]; // Desloca todos os elementos para a esquerda --> espaço vazio
        }
        l->TamanhoAtual--;
        return 1;
    }
}

void DestruirLista(Lista *l)
{
    l->TamanhoAtual = 0;
}

void MostrarLista(Lista *l)
{
    int i;
    printf("Lista: ");
    for (i = 0; i < l->TamanhoAtual; i++)
    {
        printf("%d ", l->vetor[i]);
    }
    printf("\n");
}

void Menu()
{

    Lista l;
    CriarLista(&l);
    int opcao = -1, valor, posicao, elemento, i; //  *posicoes = retorno da funcao GetPosicao(Pode ser um vetor de inteiros, ou apenas um inteiro)
    int *posicoes;

    printf("\t\tMENU LISTA:\n\n");

    while (opcao != 0)
    {
        printf("\n\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Mostrar lista\n");
        printf("4 - Mostrar tamanho da lista\n");
        printf("5 - Mostrar elemento de uma posicao\n");
        printf("6 - Mostrar posicoes de um elemento\n");
        printf("7 - Alterar elemento de uma posicao\n");
        printf("8 - Inserir elemento de forma ordenada\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a posicao: ");
            scanf("%d", &posicao);
            printf("Digite o elemento: ");
            scanf("%d", &elemento);
            InserirElemento(&l, posicao, elemento);
            break;
        case 2:
            printf("Digite a posicao: ");
            scanf("%d", &posicao);
            RemoverElemento(&l, posicao);
            break;
        case 3:
            MostrarLista(&l);
            break;
        case 4:
            printf("Tamanho da lista: %d", GetTamanho(&l));
            break;
        case 5:
            printf("Digite a posicao: ");
            scanf("%d", &posicao);
            printf("Elemento: %d", GetElemento(&l, posicao));
            break;
        case 6:
            printf("Digite o elemento: ");
            scanf("%d", &elemento);
            posicoes = (int *)malloc(sizeof(int) * sizeof(GetPosicao(&l, elemento)));
            posicoes = GetPosicao(&l, elemento);
            printf("Posicoes: ");
            for (i = 0; i < l.TamanhoAtual; i++)
            {
                printf("%d ", posicoes[i]);
            }
            free(posicoes);
            break;
        case 7:
            printf("Digite a posicao: ");
            scanf("%d", &posicao);
            printf("Digite o elemento: ");
            scanf("%d", &elemento);
            SetElemento(&l, posicao, elemento);
        case 8:
            printf("Digite o elemento: ");
            scanf("%d", &elemento);
            InserirOrdenado(&l, elemento);

            break;
        case 0:
            printf("\nFINALIZANDO PROGRAMA...\n");
            DestruirLista(&l);
            break;
        default:
            printf("\nOPCAO INVALIDA!\n");
            break;
        }
    }
}