//Criar string = char* nome;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Validador de expressões

#include "Estruturas_de_dados\PilhaDinamica\Pilha.c"

int ExpressaoValida(char* nome)
{
    Pilha* p = cria_pilha();
    int i = 0;
    while(nome[i] != '\0')
    {
        if(nome[i] == '(')
        {
            push(p, '(');
        }
        else if(nome[i] == ')')
        {
            if(pilha_vazia(p))
            {
                return 0;
            }
            else
            {
                pop(p);
            }
        }
        
        else if(nome[i] == '[')
        {
            push(p, '[');
        }
        else if(nome[i] == ']')
        {
            if(pilha_vazia(p))
            {
                return 0;
            }
            else
            {
                pop(p);
            }
        }
        
        else if(nome[i] == '{')
        {
            push(p, '{');
        }
        else if(nome[i] == '}')
        {
            if(pilha_vazia(p))
            {
                return 0;
            }
            else
            {
                pop(p);
            }
        }
        
        i++;
    }
    if(pilha_vazia(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char* nome;
    int i = 0;
    nome = (char*) malloc(50*sizeof(char));
    printf("Digite uma expressão: ");
    scanf("%s", nome);
    
    
    nome = (char*) realloc(nome, strlen(nome)*sizeof(char));

   
    free(nome);
    return 0;
}