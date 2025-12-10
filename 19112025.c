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

int main(){

int command;
int objeto;
Stack stack = begin(stack);

printf("----MENU----\n");
printf("0 = break\n");
printf("1 = isEmpty\n");
printf("2 = isFull\n");
printf("3 = push\n");
printf("4 = pop\n");
printf("5 = top\n");
printf("------------\n");

printf("Qual o proximo comando? ");
    scanf(" %d", &command);
    printf("\n");

while(command != 0){
    switch (command){

        case 0:
            break;

        case 1:
            if(isEmpty(stack)){
                printf("Stack vazia!\n");
            }
            else{
                printf("Stack nao vazia!\n");
            }
            break;

        case 2:
            if(isFull(stack)){
                printf("Stack cheia!\n");
            }
            else{
                printf("Stack nao cheia!\n");
            }
            break;

        case 3:
            printf("Qual inteiro voce quer inserir na stack? ");
            scanf(" %d", &objeto);
            printf("\nInserindo numero %d na stack!\n", objeto);
            stack = push(stack, objeto);
            printf("Numero inserido!\n");
            break;

        case 4:
            if (stack.topo >= 0){
            printf("Retirando elemento da pilha!\n");
            stack = pop(stack);
            }
            else{
                printf("Pilha vazia!\n");
            }
            break;

        case 5:
            if (stack.topo >= 0){
            printf("Valor do topo da pilha: %d\n", top(stack));
            }
            else{
                printf("Pilha vazia!\n");
            }
            break;
    }

    printf("\nQual o proximo comando? ");
    scanf(" %d", &command);
    printf("\n");

}

printf("Encerrando o programa!\n");

}


