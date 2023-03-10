#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{

    Lista l;

    CriarLista(&l);

    printf("\nLista cria com sucesso!\n");

    printf("\nVerificando se a lista esta cheia, ou se tem espaco para inserir elementos...\n");
    printf("Lista Cheia ? ", ListaCheia(&l));

    printf("\nTamanho antes de inserir elementos: %d\n", GetTamanho(&l));
    printf("Inserindo elementos na lista...\n");

    for (int i = 0; i < 10; i++)
    {
        InserirElemento(&l, i + 1, i);
    }
    printf("\n\nTamanho depois de inserir elementos: %d\n", GetTamanho(&l));

    MostrarLista(&l);

    printf("\nElemento na posicao 5: %d\n", GetElemento(&l, 5));

    printf("\nO elemento com Valor 5 esta na posicao: ", GetPosicao(&l, 5));

    printf("\nLista antes de alterar o elemento na posicao 5: \n");

    MostrarLista(&l);

    SetElemento(&l, 5, 100);

    printf("\nLista depois de alterar o elemento na posicao 5: \n");

    MostrarLista(&l);

    printf("\nRemovendo o elemento da posicao 5: \n");

    RemoverElemento(&l, 5);

    printf("\nLista depois de remover o elemento na posicao 5: \n");

    MostrarLista(&l);

    printf("\nFINALIZANDO PROGRAMA...\n");

    return 0;
}