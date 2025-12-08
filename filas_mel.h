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