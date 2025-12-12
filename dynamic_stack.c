#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

typedef struct Pilha{
    No* topo;
} Pilha;

void iniciarPilha(Pilha* pilha){
    pilha->topo = NULL;
}

void push(Pilha* pilha, int valor){

    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->dado = valor;
    novo_no -> proximo = pilha -> topo;
    pilha -> topo = novo_no;
}

int pop(Pilha* pilha){

    No* topo_temp = pilha -> topo; // guardando o topo em uma variável temporária, para não perder a referência a ela com a exclusão e ocnseguirmos dar free adequadamente
    int temp_dado_topo = topo_temp->dado;
    pilha->topo = topo_temp->proximo; // fazendo o topo, agora, corresponder ao nó que estava "embaixo"
    free(topo_temp); 
    return temp_dado_topo;

}

void imprime_pilha(Pilha* p) {
    No* atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->dado); 
        atual = atual->proximo;
    }
    printf("\n");
}

void distorcao_temporal(Pilha* pilha){

    // caso a pilha esteja vazia ou só tenha um elemento, nada é feito

    if(pilha->topo == NULL || pilha->topo->proximo == NULL){
        return;
    }

    No* anterior = NULL;
    No* atual = pilha -> topo;
    No* proximo = NULL;

    while(atual != NULL){
        proximo = atual -> proximo; // atualizando o endereço, para não o perdermos
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    pilha->topo = anterior;
    
}

void corrupcao_energetica(Pilha* pilha){

    No* atual = pilha->topo;

    while(atual != NULL){

        if(atual->dado % 2 == 0 && atual->dado>0){ // atual->dado > 0 para não tornar positivas ondas que já são negativas
            atual->dado = atual->dado * (-1);
        }

        atual = atual->proximo;
    }
}

void anulacao_repetidas(Pilha* pilha){

    // condicao para tirarmos anularmos um par de elementos: eles existirem, estarem um ao lado do outro, estarem no topo da pilha e serem iguais
    while(pilha->topo != NULL && pilha->topo->proximo == NULL && pilha->topo->dado == pilha->topo->proximo->dado){
        pop(pilha);
        pop(pilha);
    }
}

int main(){

    Pilha* pilha_ataques = (Pilha*) malloc(sizeof(Pilha));
    int vida_vecna;
    int qtd_ataques;
    int ataque;

    initStack(pilha_ataques); 

    scanf(" %d %d", &vida_vecna, &qtd_ataques);

    for(int i = 0; i < qtd_ataques; i++){
        scanf("%d", &ataque);
        push(pilha_ataques, ataque);
    }

    imprime_pilha(pilha_ataques);

    distorcao_temporal(pilha_ataques);  
    corrupcao_energetica(pilha_ataques); 
    anulacao_repetidas(pilha_ataques);

    imprime_pilha(pilha_ataques);

    int dano_total = 0;
    No* atual = pilha_ataques->topo;
    
    while(atual != NULL){
        dano_total += atual->dado;
        atual = atual->proximo;
    }

    if (dano_total >= vida_vecna) {
        printf("Atravessou o Mundo Invertido com %d pontos. Vecna foi derrotado!\n", dano_total);
    } else {
        printf("Atravessou o Mundo Invertido com %d pontos. Hawkins esta condenada...\n", dano_total);
    }

    free(pilha_ataques); 

    return 0;
}





