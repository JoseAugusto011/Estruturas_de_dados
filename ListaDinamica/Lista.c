#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    NO *prox;
} NO;

typedef struct Lista
{
    NO *head;
    int lenght;
} LISTA;

LISTA *newList(LISTA *l)
{

    l = (LISTA *)malloc(sizeof(LISTA)); // Aloca memória para a lista
    l->head = NULL;
    l->lenght = 0;

    printf("\n\tLista Criada com Sucesso!\n");

    return l;
}

int emptyList(LISTA *l)
{

    return l->lenght == 0 ? 1 : 0;
}

int getLenght(LISTA *l)
{

    return l->lenght;
}

void showList(LISTA *l)
{

    if (emptyList(l))
    {
        printf("\n\tLista Vazia!\n");
        return;
    }

    else
    {

        NO *iterator = l->head;

        printf("\n\tLista: ");

        while (iterator != NULL)
        {
            printf("%d ", iterator->info);
            iterator = iterator->prox;
        }

        printf("\n");
    }
}

int getHead(LISTA *l)
{
    if (emptyList(l))
    {
        printf("\n\tLista Vazia!\n");
        return -1;
    }
    else
        return l->head->info;
}

int getElement(LISTA *l, int pos)
{

    if (pos > l->lenght || pos <= 0)
    {

        printf("\n\tPosição Inválida!\n");
        return -1;
    }
    else
    {

        NO *iterator = l->head;

        for (int i = 0; i < pos; i++)
        {
            iterator = iterator->prox;
        }
        return iterator->info;
    }
}

int *getPosition(LISTA *l, int elem)
{
    if (emptyList(l))
    {
        printf("\n\tLista Vazia!\n");
        return NULL;
    }
    else
    {

        NO *iterator = l->head;
        int *pos = (int *)malloc(sizeof(int) * l->lenght);
        
        int i = 0;

        while (iterator != NULL)
        {
            if (iterator->info == elem)
            {
                pos[i] = i;
                i++;
            }
            
            iterator = iterator->prox;
        }

        
        //retorno deverá ser um vetor de inteiros com o tamanho i
        int *retorno;
        retorno = (int *)malloc(sizeof(int) * i);
        
        retorno = pos;

        return retorno;
        free(pos);
        
    }
}

LISTA *setElement(LISTA *l, int pos, int elem)
{

    if (pos > l->lenght || pos <= 0)
    {
        printf("\n\tPosição Inválida!\n");
        return l;
    }
    else
    {

        NO *iterator = l->head;

        while (pos > 1)
        {
            iterator = iterator->prox;
            pos--;
        }
        iterator->info = elem;
        return l;
    }
}

LISTA *setHead(LISTA *l, int elem)
{

    if (emptyList(l))
    {
        printf("\n\tLista Vazia!\n");
        return l;
    }
    else
    {
        l->head->info = elem;
        return l;
    }
}

LISTA *insertHead(LISTA *l, int elem)
{

    NO *new = (NO *)malloc(sizeof(NO));
    new->info = elem;
    new->prox = l->head;
    l->head = new;
    l->lenght++;

    return l;
    free(new);
}

LISTA *insertMiddle(LISTA *l, int pos, int elem)
{

    if (pos > l->lenght || pos <= 0)
    {
        printf("\n\tPosição Inválida!\n");
        return l;
    }
    else
    {

        NO *new, *iterator;

        int counter;

        iterator = l->head;
        counter = 0;
        new = (NO *)malloc(sizeof(NO));
        new->info = elem;
        new->prox = NULL;

        while ((counter < pos - 1) && (iterator != NULL))
        { // Encontra o nó anterior ao que será inserido
            iterator = iterator->prox;
            counter++;
        }

        if (iterator == NULL)
            return l;
        else
        {
            new->prox = iterator->prox;
            iterator->prox = new;
            l->lenght++;
            return l;
        }

        free(new);
    }
}

LISTA *insertEnd(LISTA *l, int elem)
{

    NO *new, *iterator;

    iterator = l->head;
    new = (NO *)malloc(sizeof(NO));
    new->info = elem;
    new->prox = NULL;

    while (iterator->prox != NULL)
    {
        iterator = iterator->prox;
    }
    iterator->prox = new;
    l->lenght++;
    return l;

    free(new);
}

LISTA *insertElement(LISTA *l, int pos, int elem)
{

    if (pos > l->lenght + 1 || pos <= 0)
    {
        printf("\n\tPosição Inválida!\n");
        return l;
    }
    else
    {

        if (pos == 1)
        {
            l = insertHead(l, elem);
        }
        else if (pos == l->lenght + 1)
        {
            l = insertEnd(l, elem);
        }
        else
        {
            l = insertMiddle(l, pos, elem);
        }
        return l;
    }
}

LISTA *removeHead(LISTA *l)
{

    if (emptyList(l))
    {
        printf("\n\tLista Vazia!\n");
        return l;
    }
    else
    {
        NO *aux = l->head;
        l->head = l->head->prox;
        l->lenght--;
        return l;
        printf("\n\tElemento Removido: %d\n", aux->info);
        free(aux);
    }
}

LISTA *removeMiddle(LISTA *l, int pos)
{

    if (pos > l->lenght || pos <= 0 || emptyList(l))
    {
        printf("\n\tPosição Inválida!\n");
        return l;
    }
    else
    {

        NO *iterator, *aux;
        int counter;

        iterator = l->head;
        counter = 0;

        while ((counter < pos - 1) && (iterator != NULL))
        { // Encontra o nó anterior ao que será removido
            iterator = iterator->prox;
            counter++;
        }

        if (iterator == NULL)
            return l;
        else
        {
            aux = iterator->prox;
            iterator->prox = aux->prox;
            l->lenght--;
            printf("\n\tElemento Removido: %d\n", aux->info);
            free(aux);
            return l;
        }
    }
}

LISTA *removeEnd(LISTA *l)
{

    if (emptyList(l))
    {
        printf("\n\tLista Vazia!\n");
        return l;
    }
    else
    {

        NO *iterator, *aux;

        iterator = l->head;

        while (iterator->prox->prox != NULL) // Encontra penúltimo nó
        {
            iterator = iterator->prox;
        }

        aux = iterator->prox;
        iterator->prox = NULL;
        l->lenght--;
        printf("\n\tElemento Removido: %d\n", aux->info);
        free(aux);
        return l;
    }
}

LISTA *removeElement(LISTA *l, int pos)
{

    if (pos > l->lenght || pos < 0 || emptyList(l))
    {
        printf("\n\tPosição Inválida!\n");
        return l;
    }
    else
    {

        if (pos == 1)
        {
            l = removeHead(l);
        }
        else if (pos == l->lenght)
        {
            l = removeEnd(l);
        }
        else
        {
            l = removeMiddle(l, pos);
        }
        return l;
    }
}

void Menu(LISTA *l)
{

    int op, elem, pos;
    int *posicoes;
    op = -1;

    while (op != 0)
    {
        printf("\n\tMenu de Opcoes: \n");
        printf("\n\t1 - Inserir Elemento na Lista");
        printf("\n\t2 - Remover Elemento da Lista");
        printf("\n\t3 - Imprimir Lista");
        printf("\n\t4 - Retornar Elemento na Lista ");
        printf("\n\t5 - Retornar Elemento Inicial da Lista");
        printf("\n\t6 - Retornar index's de um elemento da Lista");
        printf("\n\t7 - Alterar Elemento da Lista");
        printf("\n\t8 - Alterar Elemento Inicial da Lista");
        printf("\n\t9 - Retornar Tamanho da Lista");
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
            printf("\n\tElemento Inicial da Lista: %d\n", getHead(l));
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
            printf("\n\tTamanho da Lista: %d\n", getLenght(l));
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