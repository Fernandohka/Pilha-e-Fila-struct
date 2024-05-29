#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int valor;
    struct Pilha *prev;
}Pilha;

void *push(int valor, Pilha *pilha){
    Pilha *novo = malloc(sizeof(Pilha));

    novo->valor = valor;
    novo->prev = pilha;
    return novo;
}

void *pop(Pilha *pilha){
    if(pilha->prev)
    {
        Pilha *temp = pilha->prev;
        free(pilha);
        return temp;
    }
    return pilha;
}

int top(Pilha *pilha){
    return pilha->valor;
}

int main(){
    Pilha *pilha, *temp;
    pilha = NULL;

    for(int i = 0; i < 10; i++)
    {
        pilha = push(i + 1, pilha);
        printf("%d ", top(pilha));
    }
    printf("\n");

    for(int i = 0; i < 15; i++)
    {
        pilha = pop(pilha);
        printf("%d ", top(pilha));
    }
    while(pilha)
    {
        temp = pilha->prev;
        free(pilha);
        pilha = temp;
    }
}
