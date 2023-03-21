#include"Lista.h"
#include<stdio.h>
#include<stdlib.h>


int main(void){

    

    LISTA *l;
    
    l = newList(l);

    Menu(l);

    free(l);
    
    return 0;
}