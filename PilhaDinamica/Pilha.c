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
        // return l;
        printf("\n\tElemento Removido: %d\n", aux->info);
        return aux;
        free(aux);
    }
}

void FreeStack(Stack *l)
{
    if (emptyList(l))
    {
        printf("\n\tPilha Vazia!\n");
        return;
    }

    else
    {

        NO *aux = l->head;
        while (aux != NULL)
        {
            NO *aux2 = aux->prox;
            free(aux);
            aux = aux2;
        }
        free(l);
        printf("\n\tPilha Liberada!\n");
    }
}

void Menu()
{

    int op = -1, elem;
    Stack *l = newList(l);

    do
    {
        printf("\n\tMenu de Opcoes\n");
        printf("\n\t1 - Insere Elemento na Pilha");
        printf("\n\t2 - Remove Elemento da Pilha");
        printf("\n\t3 - Mostra Elemento do Topo da Pilha");
        printf("\n\t4 - Mostra Tamanho da Pilha");
        printf("\n\t0 - Sair");

        printf("\n\n\tOpcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n\tDigite o elemento a ser inserido: ");
            scanf("%d", &elem);
            l = Push(l, elem);
            break;
        case 2:
            Pop(&l);
            break;

        case 3:

            printf("\n\tElemento do Topo da Pilha: %d\n", Top(l));
            break;

        case 4:
            printf("\n\tTamanho da Pilha: %d\n", getLenght(l));
            break;

        case 0:

            printf("\n\tSaindo...\n");
            FreeStack(l);
            break;

        default:

            printf("\n\tOpção Invalida!\n");
            break;
        }
    } while (op != 0);
}