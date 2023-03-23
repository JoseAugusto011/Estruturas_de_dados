#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    NO *prox;
} NO;

typedef struct Stack
{
    NO *head;
    int lenght;
} Stack;

Stack *newList(Stack *l)
{

    l = (Stack *)malloc(sizeof(Stack)); // Aloca memória para a Pilha
    l->head = NULL;
    l->lenght = 0;

    printf("\n\tPilha Criada com Sucesso!\n");

    return l;
}

int emptyList(Stack *l)
{

    return l->lenght == 0 ? 1 : 0;
}

int getLenght(Stack *l)
{

    return l->lenght;
}

int Top(Stack *l)
{
    if (emptyList(l))
    {
        printf("\n\tPilha Vazia!\n");
        return -1;
    }
    else
        return l->head->info;
}


Stack *Push(Stack *l, int elem)
{

    NO *new = (NO *)malloc(sizeof(NO));
    new->info = elem;
    new->prox = l->head;
    l->head = new;
    l->lenght++;

    return l;
    free(new);
}






NO *Pop(Stack **l)
{

    if (emptyList(*(l)))
    {
        printf("\n\tPilha Vazia!\n");
        return NULL;
    }
    else
    {
        NO *aux = (*l)->head;
        (*l)->head = (*l)->head->prox;
        (*l)->lenght--;
        //return l;
        printf("\n\tElemento Removido: %d\n", aux->info);
        return aux;
        free(aux);
    }
}


/*

void Menu(Stack *l)
{

    int op, elem, pos;
    int *posicoes;
    op = -1;

    while (op != 0)
    {
        printf("\n\tMenu de Opcoes: \n");
        printf("\n\t1 - Inserir Elemento na Stack");
        printf("\n\t2 - Remover Elemento da Stack");
        printf("\n\t3 - Imprimir Stack");
        printf("\n\t4 - Retornar Elemento na Stack ");
        printf("\n\t5 - Retornar Elemento Inicial da Stack");
        printf("\n\t6 - Retornar index's de um elemento da Stack");
        printf("\n\t7 - Alterar Elemento da Stack");
        printf("\n\t8 - Alterar Elemento Inicial da Stack");
        printf("\n\t9 - Retornar Tamanho da Stack");
        printf("\n\t0 - Sair");

        printf("\n\tSelecione uma Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n\tDigite o elemento a ser inserido: ");
            scanf("%d", &elem);
            printf("\n\tDigite a posicao do elemento: ");
            scanf("%d", &pos);
            l = insertElement(l, pos, elem);
            break;
        case 2:
            printf("\n\tDigite a posicao do elemento a ser removido: ");
            scanf("%d", &pos);
            l = removeElement(l, pos);
            break;

        case 3:

            showList(l);
            break;
        case 4:
            printf("\n\tDigite a posicao do elemento a ser retornado: ");
            scanf("%d", &pos);
            printf("\n\tElemento na posicao %d: %d\n", pos, getElement(l, pos));
            break;

        case 5:
            printf("\n\tElemento Inicial da Stack: %d\n", getHead(l));
            break;
        case 6:

            printf("\n\tDigite o elemento a ser procurado: ");
            scanf("%d", &elem);
            int tam = sizeof(getPosition(l, elem));
            posicoes = (int *)malloc(sizeof(int) * tam);
            posicoes = getPosition(l, elem);

            

            for (int i = 0; i < tam; i++)
            {
                printf("\n\tPosicao do elemento %d: %d\n", elem, posicoes[i] + 1);
            }
            break;

        case 7:
            printf("\n\tDigite o elemento a ser alterado: ");
            scanf("%d", &elem);
            printf("\n\tDigite a posicao do elemento a ser alterado: ");
            scanf("%d", &pos);
            l = setElement(l, pos, elem);
            break;

        case 8:
            printf("\n\tDigite o elemento a ser alterado: ");
            scanf("%d", &elem);
            l = setHead(l, elem);
            break;
        case 9:
            printf("\n\tTamanho da Stack: %d\n", getLenght(l));
            break;

        case 0:
            printf("\n\tSaindo...\n");
            break;

        default:
            printf("\n\tOpcao Invalida!\n");
            break;
        }
    }
}
*/

