#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

void CriarPilha(Pilha **l)
{
    
    (*l)->Topo = -1;
}

int PilhaVazia(Pilha **l)
{
    if ((*l)->Topo  == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int PilhaCheia(Pilha **l)
{
    if ((*l)->Topo == TAM_MAX - 1) //topo começa em -1 e Tam Max comrça em zero
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GetTamanho(Pilha **l)
{
    return (*l)->Topo+1; // topo começa em -1 por acresecemos +1 ao resultado, pois se não tivermos nenhum elmento seu tamanho será 0 e não -1
}

int Top(Pilha **l)
{
    if (PilhaVazia(l) || PilhaCheia(l) )
    {
        printf("Posicao invalida");
        return -1;
    }
    else
    {
        return (*l)->vetor[(*l)->Topo];
    }
}



int Push(Pilha **l, int elem)
{
    if (PilhaCheia(l))
    {
        printf("Tamanho esgotado!\n");
        return -1;
    }
    else
    {
        
        (*l)->vetor[(*l)->Topo + 1] = elem;
        (*l)->Topo++;
        return 1;
    }
}

int Pop(Pilha **l)
{
    if (PilhaVazia(l))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    else
    {
        int elem = (*l)->vetor[(*l)->Topo];
        (*l)->Topo--;
        return elem;
    }
}

void LiberaPilha(Pilha **l)
{
    if (l != NULL)
    {
        free(l);
    }
    else{
        for (int i = 0; i<GetTamanho(l); i++){
            Pop(l);
        }
    }
}


void Menu(){

    int opcao, elem, pos;
    opcao = 1;

    Pilha *l = (Pilha *)malloc(sizeof(Pilha));

    CriarPilha(&l);

    while(opcao != 0){

        printf("\n\tMenu de opcoes\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Mostrar elemento do topo\n");
        printf("4 - Mostrar tamanho da Pilha\n");
        printf("0 - Sair\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &elem);
            Push(&l, elem);
            break;
        case 2:
            
            printf("Elemento removido: %d", Pop(&l));

        case 3:
            printf("Elemento do topo: %d", Top(&l));
            break;
        case 4:
            printf("Tamanho da Pilha: %d", GetTamanho(&l));
            break;
        case 0:
            printf("Saindo...");
            LiberaPilha(&l);

            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    }
}

