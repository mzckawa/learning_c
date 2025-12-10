#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    int points;
    char nome[20]; // sabemos que o len(N) <= 7, mas deixamos uma margem de segurança
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int new_value, char* new_name){

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->points=new_value;
    new_node->left=NULL;
    new_node->right=NULL;
    strcpy(new_node->nome, new_name);

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

/*

Função para se precisasse procurar pelo nome (por desatenção, achei que fosse o que a questão pedia, então acabei fazendo - vou deixar para fins de reaproveitamento futuro)
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

*/

int buscar_pontuacao(Node* root, int pontos){

    if(root == NULL){
        return 1; // serve como retorno quando não acha e para o programa não crashar se a árvore ainda estiver vazia
    }

    if(root->points == pontos){
        return 0;
    }

    else{

        if(root->points > pontos){
            return buscar_pontuacao(root->left, pontos);
        }

        else{
            return buscar_pontuacao(root->right, pontos);
        }
    }
}

char* encontrar_antecessor(Node* root, int pontos_alvo) {
    
    Node* antecessor = NULL; 
    Node* atual = root; 

    while (atual != NULL) {
        
        if (atual->points < pontos_alvo) {
            
            antecessor = atual; 
            
            atual = atual->right;
        } 
        
        else {
            atual = atual->left;
        }
    }

    if (antecessor != NULL) {
        return antecessor->nome;
    } else {
        return NULL; 
    }
}

char* encontrar_sucessor(Node* root, int pontos_alvo) {
    
    Node* sucessor = NULL; 
    Node* atual = root; 

    while (atual != NULL) {
        
        if (atual->points > pontos_alvo) {
            sucessor = atual; 
            atual = atual->left;
        } 
        
        else {
            atual = atual->right;
        }
    }

    if (sucessor != NULL) {
        return sucessor->nome;
    } else {
        return NULL; 
    }
}

char* buscar_nome_por_pontos(Node* root, int pontos_alvo) {
    if (root == NULL) {
        return NULL; 
    }

    if (root->points == pontos_alvo) {
        return root->nome; 
    }

    if (pontos_alvo < root->points) {
        return buscar_nome_por_pontos(root->left, pontos_alvo);
    } else {
        return buscar_nome_por_pontos(root->right, pontos_alvo);
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
    int K;
    char instrucao[10];
    char nome_referencia[20];
    char* nome_antecessor;
    char* nome_sucessor;
    int pontos;

    scanf(" %d", &K);

    for(int i = 0; i<K; i++){

        scanf("%s", instrucao);
        

        if(strcmp("ADD", instrucao) == 0){

            scanf(" %s", nome_referencia);
            scanf(" %d", &pontos);

            if(buscar_pontuacao(root, pontos) == 0){ // informando se a pessoa já está ou não
                printf("%s ja esta no sistema.\n", nome_referencia);
            }

            else{
            root = insert_node(root, pontos, nome_referencia);
            printf("%s inserido com sucesso!\n", nome_referencia);
            }
        }

        else if(strcmp("PROX", instrucao) == 0){

            scanf(" %d", &pontos);

            strcpy(nome_referencia, buscar_nome_por_pontos(root, pontos));

            //nome_referencia = 
            nome_antecessor = encontrar_antecessor(root, pontos);
            nome_sucessor = encontrar_sucessor(root, pontos);

            if(nome_antecessor == NULL){

                if(nome_sucessor == NULL){
                    printf("Apenas %s existe no sistema...\n", nome_referencia);
                }

                else{
                    printf("%s e o menor! e logo apos vem %s\n", nome_referencia, nome_sucessor);
                }
            }

            else if (nome_sucessor == NULL){
                printf("%s e o maior! e logo atras vem %s\n", nome_referencia, nome_antecessor);
            }

            else{ // quando tem os dois vizinhos

                printf("%s vem apos %s e antes de %s\n", nome_referencia, nome_antecessor, nome_sucessor);

            }
        }

    }

    liberar_arvore(root);
    root = NULL;

    return 0;
}