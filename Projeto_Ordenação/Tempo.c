/*FEITO EM DUPLA

AUTORES: ARTUR DARTAGNAN e JOSÉ AUGUSTO

*/


#include "Tempo.h"


void  InicioTemporizador(){

    
    Tempo = clock();

}


double CravarCronometro(){


    Tempo = clock() - Tempo;

    //return ((float)Tempo) / CLOCKS_PER_SEC;
    return ((double)Tempo)/((CLOCKS_PER_SEC/1000));
}