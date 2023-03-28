#ifndef _Stack_H
#define _Stack_H

// Stack =  Agrupamento de nós
// Nó =  Elemento da Stack

typedef struct no NO;
typedef struct Stack Stack;

// Cria uma Stack vazia, composta por um nó cabeça
Stack *newStack(Stack *l);

// Ver informações Stack

// Verifica se a Stack está vazia
int emptyStack(Stack *l);
// Retorna o tamanho da Stack
int getLenght(Stack *l);
// Mostra a Stack


// Get's

// Retorna o nó cabeça da Stack
int Top(Stack *l);


// Set's


// Insert´s

// Insere elemento na cabeça da Stack
Stack *Push(Stack *l, int elem);



// Remove's

// Remove elemento da cabeça da Stack
NO *Pop(Stack **l);

void FreeStack(Stack *l);

//Menu de opções
void Menu();

#endif