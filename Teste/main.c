/*

#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"


int main(){
    Menu();
    return 0;
}


*/


#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"


int main(){

    int Crescente[10];
    int Decrescente[10];
    printf("INICIOALGORITMO\n");


    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    CriarPilha(&pilha);
    printf("Tamanho da pilha: %d\n", GetTamanho(&pilha));
    
    for (int i = 0; i < 10; i++)
    {
        Crescente[i] = i;
        printf("%d ", Crescente[i]);
    }
    printf("Crescente: \n");
    //Reordenar usando vetor
    for (int i = 0; i < 10; i++)
    {
        Push(&pilha, Crescente[i]);
    }
    printf("Tamanho da pilha: %d\n", GetTamanho(&pilha));
    printf("POOP\n");
    for (int i = 0; i < 10; i++)
    {
        Decrescente[i] = Pop(&pilha);
    }
    printf("Decrescente: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", Decrescente[i]);
    }
    printf("FIMALGORITMO\n");

    




    return 0;
}

