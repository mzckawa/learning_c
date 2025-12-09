#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    int points;
    char nome[8]; // porque sabemos que o len(N) <= 7
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int new_value, char* new_name){

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->points=new_value;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

Node* insert_node(Node* origin, int new_value, char* new_name){

    if(origin == NULL){
        return create_node(new_value, new_name);
    }

    else{
        if(origin->points > new_value){
            origin->left = insert_node(origin->left, new_value, new_name); // colocando à esquerda da origem se for menor do que o conteúdo dela
        }

        else{
            origin->right = insert_node(origin->right, new_value, new_name); // colocando à direita da origem se for maior do que o conteúdo dela
        }

        return origin;
    }
}

// encontrando o nó correspondente a um determinado jogador, de forma a saber quantos pontos ele fez
int find_player(Node* root, char* name){

    int pontos; 

    if(root == NULL){
        return -1; // código de erro
    }
    
    // se achou, retorna o que estiver em root->points
    if(strcmp(root->nome,name) == 0){
    pontos = root->points;
    return pontos;
    }

    // se chegar até aqui, é porque a comparação das strings não bateu
    // logo, vamos procurar nas subárvores à esquerda
    pontos = find_player(root->left, name);
    
    // se entrar nesse if, é porque achou o nó com o nome correspondente
    // logo, podemos sair da função, retornando a quantidade de pontos do jogador
    if(pontos != -1){
    return pontos;
    }

    // se chegar aqui, é porque a busca nas árvores da esquerda falhou
    // vamos, então, procurar nas da direita
    // o resultado final disso é o que iremos querer lá na main, seja ele a quantidade de pontos real ou -1 (que, segundo a questão, não ocorre), mas pomos por precaução
    return find_player(root->right, name);
    
}

char* encontrar_antecessor(Node* root, int pontos){

    Node* antecessor = NULL;

    if(root->left != NULL){
        
        if(root->left->points > antecessor->points){
            antecessor = root->left;
        }

        encontrar_antecessor(root->left, pontos);
    }



}

char* encontrar_sucessor(Node* root, int pontos){

}


