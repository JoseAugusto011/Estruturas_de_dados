#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>



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



int GetTamanho(Lista *l){
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
    int i, j = 0;

    for(i = 0; i < l->TamanhoAtual; i++){
        if(l->vetor[i] == elemento){
            posicoes[j] = i + 1;
            j++;
        }
    }   

    return posicoes;
    free(posicoes);

}

int SetElemento(Lista *l, int pos, int elem){
    if(pos <= 0 || pos >= l->TamanhoAtual){
        printf("Posicao invalida");
        return -1;
    }
    else{
        l->vetor[pos - 1] = elem; //Posicao 1 da lista é a posicao 0 do vetor
        return 1;
    }
}

// 1 4 5 6 3 -
//           i
//Inserir(2, 7)

int InserirElemento(Lista *l, int pos, int elem){
    if(pos <= 0 || pos > l->TamanhoAtual + 1){
        printf("Posicao invalida");
        return -1;
    }
    else{
        int i;
        for(i = l->TamanhoAtual; i >= pos; i--){ //i começa no final da lista
            l->vetor[i] = l->vetor[i - 1]; //Desloca todos os elementos para a direita --> espaço vazio
        }
        l->vetor[pos - 1] = elem;
        l->TamanhoAtual++;
        return 1;
    }
}

int RemoverElemento(Lista *l, int pos){
    if(pos <= 0 || pos >= l->TamanhoAtual){ 
        printf("Posicao invalida");
        return -1;
    }
    else{
        int i;
        for(i = pos - 1; i < l->TamanhoAtual; i++){ //i começa na posição do elemento a ser removido
            l->vetor[i] = l->vetor[i + 1];//Desloca todos os elementos para a esquerda --> espaço vazio
        }
        l->TamanhoAtual--;
        return 1;
    }
}

void MostrarLista(Lista *l){
    int i;
    printf("Lista: ");
    for(i = 0; i < l->TamanhoAtual; i++){
        printf("%d ", l->vetor[i]);
    }
    printf("\n");
}