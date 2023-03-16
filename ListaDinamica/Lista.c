#include "Lista.h"
#include <stdlib.h>

typedef struct Lista {
    int info;
    Lista *prox;
    int TamAtual;   // Tamanho atual da lista
}Lista;


Lista* CriarLista() {
    return NULL;
}

int ListaVazia(Lista *l) {
    return (l == NULL);
}

int GetTamanho(Lista *l) {
    return l->TamAtual;
}

Lista* GetPosicao(Lista *l, int elem) {
    Lista *p = l; //Iterador
    Lista *Posicoes = CriarLista();
    
    if (ListaVazia(l)) {
        return NULL;
    }

    else{
        for (int i = 0; i < GetTamanho(l); i++) {
            if (p->info == elem) {
                InsereInicio(Posicoes, i);
            }
            p = p->prox;
        }
    }
}


int GetElemento(Lista *l, int pos) {
    Lista *p = l; //Iterador

    if (ListaVazia(l)) {
        return NULL;
    }

    else {
        for (int i = 0; i < GetTamanho(l); i++) {
            if (i == pos) {
                return p->info;
            }
            p = p->prox;
        }
    }
}



Lista* SetElemento(Lista *l, int pos, int elem) {
    Lista *p = l; //Iterador

    if (ListaVazia(l)) {
        return NULL;
    }

    else {
        for (int i = 0; i < GetTamanho(l); i++) {
            if (i == pos) {
                p->info = elem;
            }
            p = p->prox;
        }
    }
}




Lista* InserirElemento (Lista *l, int pos, int elem){

    if ((vazia()) && (pos == 0)) return NULL;

    if (pos == 1){ // insercao no inicio da lista
        return InsereInicio(l, elem); 
    }
    else if (pos == GetTamanho(l) + 1){ // inserção no fim
        return InserirFim(l, elem); 
    }
    else{ // inserção no meio da lista
        return InsereMeio(l, pos, elem);
    }
}

Lista* InsereInicio(Lista *l, int elem) {
   
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = elem;
    novo->prox = l;
    l->TamAtual++;
    return novo;

    Lista *novo= new No();
    // Insere novo elemento na cabeca da lista
    novoNo.setConteudo(valor);
    novoNo.setProx(cabeca);
    cabeca = novoNo;
    tamanho++;
    return true;
}



Lista* InsereMeio(Lista *l, int pos, int elem){

    Lista *novo = (Lista*)malloc(sizeof(Lista));
    Lista *p = l; //Iterador

    for (int i = 0; i < pos - 2; i++) {
        p = p->prox;
    }

    novo->info = elem;
    novo->prox = p->prox;
    p->prox = novo;
    l->TamAtual++;
    return l;


    int cont = 1;
    No novoNo = new No(); // Aloca memoria para novo no
    novoNo.setConteudo(dado);
    // Localiza a pos. onde será inserido o novo nó
    No aux = cabeca;
    while ((cont < pos-1) && (aux != null)){
    aux = aux.getProx();
    cont++;
    }
    if (aux == null) return false;
    novoNo.setProx(aux.getProx());
    aux.setProx(novoNo);
    tamanho++;
    return true;
}











void MostrarLista(Lista *l) {
    Lista *p = l; //Iterador

    if (ListaVazia(l)) {
        printf("Lista Vazia!");
    }

    else {
        for (int i = 0; i < GetTamanho(l); i++) {
            printf("%d ", p->info);
            p = p->prox;
        }
    }
}



void Menu(){}