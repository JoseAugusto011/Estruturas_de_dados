#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

void CriarPilha(Pilha *l)
{
    
    l->Topo = -1
}

int PilhaVazia(Pilha *l)
{
    if (l->Topo  == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int PilhaCheia(Pilha *l)
{
    if (l->Topo == TAM_MAX - 1) //topo começa em -1 e Tam Max comrça em zero
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GetTamanho(Pilha *l)
{
    return l->Topo+1; // topo começa em -1 por acresecemos +1 ao resultado, pois se não tivermos nenhum elmento seu tamanho será 0 e não -1
}

int Top(Pilha *l)
{
    if (PilhaVazia(l) || PilhaCheia(l) )
    {
        printf("Posicao invalida");
        return -1;
    }
    else
    {
        return l->vetor[l->Topo];
    }
}



int Push(Pilha *l, int elem)
{
    if (PilhaCheia(l))
    {
        printf("Tamanho esgotado!\n");
        return -1;
    }
    else
    {
        
        l->vetor[l->Topo + 1] = elem;
        l->Topo++;
        return 1;
    }
}

int RemoverElemento(Pilha *l, int pos)
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
/*

void Menu()
{

    Pilha l;
    CriarPilha(&l);
    int opcao = -1, valor, posicao, elemento, i; //  *posicoes = retorno da funcao GetPosicao(Pode ser um vetor de inteiros, ou apenas um inteiro)
    int *posicoes;

    printf("\t\tMENU Pilha:\n\n");

    while (opcao != 0)
    {
        printf("\n\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Mostrar Pilha\n");
        printf("4 - Mostrar tamanho da Pilha\n");
        printf("5 - Mostrar elemento de uma posicao\n");
        printf("6 - Mostrar posicoes de um elemento\n");
        printf("7 - Alterar elemento de uma posicao\n");
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
            MostrarPilha(&l);
            break;
        case 4:
            printf("Tamanho da Pilha: %d", GetTamanho(&l));
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
            break;
        case 0:
            printf("\nFINALIZANDO PROGRAMA...\n");
            break;
        default:
            printf("\nOPCAO INVALIDA!\n");
            break;
        }
    }
}

*/
