#include <stdlib.h>
#include <stdio.h>

typedef struct Node{

    int points;
    char nome[1024];
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int new_value, *char){

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->content=new_value;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

Node* insert_node(Node* origin, int new_value){

    if(origin == NULL){
        return create_node(new_value);
    }

    else{
        if(origin->content > new_value){
            origin->left = insert_node(origin->left, new_value); // colocando à esquerda da origem se for menor do que o conteúdo dela
        }

        else{
            origin->right = insert_node(origin->right, new_value); // colocando à direita da origem se for maior do que o conteúdo dela
        }

        return origin;
    }
}

void preOrder(Node* root, int* flag_first){

    if(root != NULL){ // condição de parada

        if(*flag_first == 0){ // flag adicionada para que o último elemento não tenha, após ele, um espaço em branco
            printf(" ");
        }
        printf("%d", root->content);
        *flag_first = 0;

        preOrder(root->left, flag_first);
        preOrder(root->right, flag_first);
    }
}

void inOrder(Node* root, int* flag_first){

    if(root != NULL){

        inOrder(root->left, flag_first);

        if(*flag_first == 0){ 
            printf(" ");
        }
        printf("%d", root->content);
        *flag_first = 0;

        inOrder(root->right, flag_first);
    }
}

void posOrder(Node* root, int* flag_first){

    if(root != NULL){
        posOrder(root->left, flag_first);
        posOrder(root->right, flag_first);

        if(*flag_first == 0){ 
        }
        *flag_first = 0;

        printf("%d ", root->content);
    }
}
