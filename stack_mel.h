#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int topo;
} Stack;

Stack begin(Stack pilha){
    
    for(int i = 0; i<MAX; i++){
        pilha.items[i] = 0;
    }
    pilha.topo = -1;
    return pilha;
}

int isEmpty(Stack pilha){

    if(pilha.topo < 0){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Stack pilha){

    if(pilha.topo == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}

Stack push(Stack pilha, int obj){

    pilha.topo++;
    pilha.items[pilha.topo] = obj;

    return pilha;
    
}

Stack pop(Stack pilha){

    pilha.topo--;

    if(pilha.topo > 0){

        int pilha_aux[pilha.topo + 1];

        for(int i=0; i<(pilha.topo+1); i++){ // transferindo até o penúltimo elemento da pilha original para a pilha auxiliar 
        pilha_aux[i] = pilha.items[i];
        }

        for(int i=0; i<(pilha.topo+1); i++){
        pilha.items[i] = pilha_aux[i];
        }
    }

    return pilha;
}

int top(Stack pilha){
    return pilha.items[pilha.topo];
}