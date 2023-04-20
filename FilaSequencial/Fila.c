#include "Filla.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct fila{
    int vetor[MAX];
    int inicio;
    int fim;
    int TamAtual;
}Fila;

void criaFila(Fila *f){

    f->inicio = 0;
    f->fim = 0;
    f->TamAtual = 0;

}

//Metodos relacionados ao espaço da fila

int filaVazia(Fila *f){

    f->TamAtual == 0 ? 0 : 1;    

}

int filaCheia(Fila *f){

    f->TamAtual == MAX ? 0 : 1;

}


int tamanhoFila(Fila *f){

    return f->TamAtual;

}

//Get's

int primeiroFila(Fila *f){

    return f->vetor[f->inicio];

}

int ultimoFila(Fila *f){

    return f->vetor[f->fim];

}

//Metodos de  inserção e remoção

void insereFila(Fila *f, int valor){ //Inserção no final da fila

    if(filaCheia(f) == 0){
        printf("Fila cheia");
        return;
    }

    else {

        f->vetor[f->fim] = valor;
        f->fim = (f->fim + 1) % MAX;
        f->TamAtual++;

    }

    

}


int removeFila(Fila *f){ //Remoção no inicio da fila

    if(filaVazia(f) == 0){
        printf("Fila vazia");
        return;
    }

    else {

        int valor = f->vetor[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        f->TamAtual--;
        return valor;

    }

}

void imprimeFila(Fila *f){

    int i;

    for(i = f->inicio; i < f->fim; i++){
        printf("%d ", f->vetor[i]);
    }

}