#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{

    int items[MAX];
    int front;
    int rear;
    int size;
} Queue;

Queue begin(Queue queue){
    
    for(int i = 0; i<MAX; i++){
        queue.items[i] = 0;
    }
    queue.front = -1;
    queue.rear = -1;
    queue.size = 0;
    return queue;
}

int isEmpty(Queue queue){

    if(queue.rear < 0){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Queue queue){

    if(queue.rear == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}

Queue enqueue(Queue queue, int obj){

    if(queue.size == 0){
        queue.front = 0;
        queue.rear = 0;
    }

    queue.rear++;
    queue.size++;
    queue.items[queue.rear] = obj; 

    return queue;
    
}

Queue dequeue(Queue queue){

    queue.size--;

    if(queue.rear > 0){

        int queue_aux[queue.rear + 1];

        for(int i=1; i<(queue.rear+1); i++){ 
        queue_aux[i-1] = queue.items[i];
        }

        for(int i=0; i<(queue.rear+1); i++){
        queue.items[i] = queue_aux[i];
        }
    }

    return queue;
}

int front(Queue queue){
    return queue.items[queue.front];
}

int main(){

    int command;
    int objeto;
    Queue Queue = begin(Queue);

    printf("----MENU----\n");
    printf("0 = break\n");
    printf("1 = isEmpty\n");
    printf("2 = isFull\n");
    printf("3 = enqueue\n");
    printf("4 = dequeue\n");
    printf("5 = front\n");
    printf("------------\n");

    printf("Qual o proximo comando? ");
        scanf(" %d", &command);
        printf("\n");

    while(command != 0){
        switch (command){

            case 0:
                break;

            case 1:
                if(isEmpty(Queue)){
                    printf("Queue vazia!\n");
                }
                else{
                    printf("Queue nao vazia!\n");
                }
                break;

            case 2:
                if(isFull(Queue)){
                    printf("Queue cheia!\n");
                }
                else{
                    printf("Queue nao cheia!\n");
                }
                break;

            case 3:
                printf("Qual inteiro voce quer inserir na Queue? ");
                scanf(" %d", &objeto);
                printf("\nInserindo numero %d na Queue!\n", objeto);
                Queue = enqueue(Queue, objeto);
                printf("Numero inserido!\n");
                break;

            case 4:
                if (Queue.size >= 0){
                printf("Retirando elemento da fila!\n");
                Queue = dequeue(Queue);
                }
                else{
                    printf("fila vazia!\n");
                }
                break;

            case 5:
                if (Queue.size >= 0){
                printf("Valor do front da fila: %d\n", front(Queue));
                }
                else{
                    printf("fila vazia!\n");
                }
                break;

                
        }

        printf("\nQual o proximo comando? ");
        scanf(" %d", &command);
        printf("\n");

    }

    printf("Encerrando o programa!\n");
 
}
