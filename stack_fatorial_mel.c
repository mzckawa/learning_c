#include <stdio.h>
#include <stdlib.h>
#include <stack_mel.h>

int fatorial(Stack pilha){

    printf("Entrou no fatorial!\n");
    int resultado = 1;
    int topo_orig = pilha.items[pilha.topo];
    for (int i = pilha.topo; i>0; i--){

        resultado *= pilha.items[pilha.topo]; // multiplicando pelo atual último elemento da pilha
        pilha = pop(pilha); // retirando esse elemento da pilha
        
    }

    printf("Fatorial calculado! Vamos imprimi-lo!\n");
    printf("O fatorial de %d é %d", topo_orig, resultado);

    //return resultado;
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
    printf("6 = fatorial\n");
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

            case 6:
                if (stack.topo >= 0){
                printf("Valor do topo da pilha: %d\n", top(stack));
                }
                else{
                    printf("Pilha vazia!\n");
                }
                break;

            case 5:
                printf("vamos entrar no fatorial!\n");
                //fatorial(stack);
                //printf("Passamos do fatorial!\n");
                //break;
                
        }

        printf("\nQual o proximo comando? ");
        scanf(" %d", &command);
        printf("\n");

    }

    printf("Encerrando o programa!\n");
 
}