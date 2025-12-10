#include <stdio.h>
#include <stdlib.h>

typedef struct CascaTesouro{

    int tesouro;
    struct CascaTesouro* onde_esta_tesouro_esquerda;
    struct CascaTesouro* onde_esta_tesouro_direita;
} CascaTesouro;

CascaTesouro* criarCascaTesouro(int meu_tesouro){

    CascaTesouro* casca = (CascaTesouro*) malloc(sizeof(CascaTesouro));
    casca->tesouro=meu_tesouro;
    casca->onde_esta_tesouro_esquerda=NULL;
    casca->onde_esta_tesouro_direita=NULL;
}

CascaTesouro* inserirCascaTesouro(CascaTesouro* onde_esta_casca_raiz, int novo_tesouro){

    if(onde_esta_casca_raiz == NULL){
        criarCascaTesouro(novo_tesouro);
    }

    else{
        if(novo_tesouro<(onde_esta_casca_raiz->tesouro)){
            onde_esta_casca_raiz->onde_esta_tesouro_esquerda=
        }
    }

}

