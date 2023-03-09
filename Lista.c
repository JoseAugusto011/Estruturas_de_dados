#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>


#define TAM_MAX 100

typedef struct{
    
    int vetor[TAM_MAX];
    int TamanhoAtual;

}Lista;

void CriarLista(Lista *l){
    l->TamanhoAtual = 0;  

}

int ListaVazia(Lista *l){
    if(l->TamanhoAtual == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int ListaCheia(Lista *l){
    if(l->TamanhoAtual == TAM_MAX){
        return 1;
    }
    else{
        return 0;
    }
}

Lista Append(Lista *l, int elemento){
    if(ListaCheia(l) == 1){
        printf("Lista cheia");
    }
    else{
        l->vetor[l->TamanhoAtual] = elemento;
        l->TamanhoAtual++;
    }
    return *l;
}


int getTamanho(Lista *l){
    return l->TamanhoAtual;
}


int GetElemento(Lista *l, int pos){
    if(pos <= 0 || pos >= l->TamanhoAtual){
        printf("Posicao invalida");
        return -1;
    }
    else{
        return l->vetor[pos - 1];
    }
}

int* GetPosicao(Lista *l, int elemento){
   
    //Retorne todas as posicoes em que o elemento aparece

    int *posicoes = (int*) malloc(sizeof(int) * l->TamanhoAtual); ///Continuar daqui!

}