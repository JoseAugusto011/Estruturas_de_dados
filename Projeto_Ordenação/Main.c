/*FEITO EM DUPLA

AUTORES: ARTUR DARTAGNAN e JOSÉ AUGUSTO

*/



#include "Ordenar.h"
#include <stdio.h>


#define FILE_NAME "couting.txt"  //Caso testar outra instancia troque a macro de pré processamento

int main(){

    
    
    /*  TESTES 1

    int v[TAM] =  {2,7,0,5,2,0,2,3,1,5,2,7};

    InicioTemporizador();

    printf("\n\t\tOrdenacao em Bolha\n");

    Imprimir_vetor(bubble_sort(v,TAM),TAM);

    printf("\tTempo Bubble: %f",CravarCronometro());
   

    int u[TAM] = {2,7,0,5,2,0,2,3,1,5,2,7};

    InicioTemporizador();

    printf("\n\t\tOrdernacao por selecao\n");

    Imprimir_vetor(selection_sort(u,TAM),TAM);

    printf("\tTempo Selection: %f",CravarCronometro());    

    int w[TAM] = {2,7,0,5,2,0,2,3,1,5,2,7};

    InicioTemporizador();

    printf("\n\t\tOrdenacao por insercao\n");

    Imprimir_vetor(inserction_sort(w,TAM),TAM);

    printf("\tTempo Inserction: %f",CravarCronometro());

    int t[TAM] = {2,7,0,5,2,0,2,3,1,5,2,7};

    InicioTemporizador();

    printf("\n\t\tOrdenacao por uniao\n");

    Imprimir_vetor(merge_sort(0,TAM,t),TAM);

    printf("\tTempo Merge: %f",CravarCronometro());
    
    int z[TAM] = {2,7,0,5,2,0,2,3,1,5,2,7};

    InicioTemporizador();

    printf("\n\t\tOrdenacao rapida\n");

    Imprimir_vetor(quick_sort(0,TAM,z),TAM);

    printf("\tTempo Quick: %f",CravarCronometro());

    */


  // Menu();   // Caso queira testar com instancia menores




  int* instancia_teste;
  instancia_teste = Le_arquivo(FILE_NAME);
  Teste_Instancia(instancia_teste,TamVetor(FILE_NAME));      

  return 0;
}