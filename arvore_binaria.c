#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int content;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int new_value){

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

void liberar_arvore(Node* root) {

    if (root == NULL) {
        return;
    }

    liberar_arvore(root->left);
    liberar_arvore(root->right);
    free(root);
}

int main(){

    Node* root = NULL;
    int amount_nodes;
    int root_value;
    int is_first = 1; 

    scanf("%d ", &amount_nodes);
    scanf("%d ", &root_value);

    root = insert_node(root, root_value);

    for(int i = 1; i < amount_nodes; i++){

        int next_value;
        scanf(" %d", &next_value);
        insert_node(root, next_value);
    }

    printf("Pre order : ");
    is_first = 1;
    preOrder(root, &is_first);   

    printf("\nIn order  : ");
    is_first = 1;
    inOrder(root, &is_first);

    printf("\nPost order: ");
    is_first = 1;
    posOrder(root, &is_first);

    printf("\n");

    liberar_arvore(root);
    root = NULL;

    return 0;
}