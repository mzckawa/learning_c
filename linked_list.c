#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No{
    char valor;
    struct No* proximo;
} No;

typedef struct {

    No* inicio;
    No* fim;
    int tamanho;

} Lista;

void inicializar (Lista* lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
} 

char inserirInicio(Lista* lista, int valor){

    No* novo;

    if((novo = (No*) malloc(sizeof(No))) == NULL){
    return -1;
    }

    novo-> valor = valor;

    if(lista->inicio == NULL){
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }

    else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->tamanho++;
    return 0;
}

// inserindo um nó logo após o nó "pivô"
void inserirDepois(Lista* lista, No* pivo, char valor){

    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        return;
    }
    novo->valor = valor;

    // o próximo do novo é o que está depois do pivô
    novo->proximo = pivo->proximo;
    // agora, o pivô aponta para o novo valor
    pivo->proximo = novo;

    // se não há ninguém depois, estamos no fim, ou seja, vamos atualizar o fim da lista encadeada
    if(novo->proximo == NULL){
        lista->fim = novo;
    }
}

void imprime(Lista* lista){
    No* atual = lista->inicio;
    while(atual != NULL){
        printf("%c", atual ->valor);
        atual = atual->proximo;
    }
}

int main(){

    Lista* lista = (Lista*) malloc(sizeof(Lista));
    char caractere_atual;
    No* cursor = NULL; // ponteiro de Nó que vai nos ajudar a apontar para o lugar correto da lista!

    inicializar(lista); // para zerar os ponteiros

    while(scanf(" %c", &caractere_atual) != EOF && caractere_atual != '\n'){

        if(caractere_atual == '['){ // encontramos a tecla home, logo, precisamos ir para o início da lista
        cursor = NULL;
        }

        else if(caractere_atual == ']'){
            cursor = lista->fim;
        }

        else{ // se encontrou letra, precisamos inseri-la onde o cursor indicar; quer no início, quer no fim da lista, e sempre atualizar o cursor!!!

            if(cursor == NULL){
                inserirInicio(lista, caractere_atual);
                cursor = lista->inicio;
            }

            else{
                inserirDepois(lista, cursor, caractere_atual);
                cursor = cursor->proximo; 
            }
        }
    }

    imprime(lista);

    free(lista);

    return 0;
}
