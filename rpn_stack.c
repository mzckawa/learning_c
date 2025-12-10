#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 405

typedef struct {
    char items[MAX];
    int topo;
} Stack;

void push(Stack* pilha, char c){

    if(pilha->topo == -1){
        return '\0'; // retornando o \0 se a pilha estiver vazia
    }

    // se chegou até aqui, é porque a pilha não está vazia 
    pilha->topo++; // crescendo o topo da pilha
    pilha->items[pilha->topo] = c;
}

char pop(Stack* pilha){

    char c;

    if(pilha->topo == -1){
        return '\0';
    }

    c = pilha->items[pilha->topo];
    pilha->topo--;
    return c;
  
}

char peek(Stack* pilha){ // mesma coisa que o pop, mas a gente não vai tirar o elemento, só vai ver qual é

    char c;

    if(pilha->topo == -1){
        return '\0';
    }

    c = pilha->items[pilha->topo];
    return c;

}

int prioridade(Stack* pilha, char operador){

    if(pilha->topo == -1){
        return '\0';
    }

    if(operador == '^'){
        return 3;
    }

    else if(operador == '*' || operador == '/'){
        return 2;
    }

    else if(operador == '+' || operador == '-'){
        return 1;
    }

    return 0;
}

void transformar_em_rpn(Stack* pilha){

    if(pilha->topo == -1){
        printf("Expressão vazia!\n");
    }

    else{

        if(isalnum(pilha->items[pilha->topo])){
            printf("%c", )
        }
    }
}
