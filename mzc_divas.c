#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct DadosCombatente{
    int amp;
    int freq;
    float ener;
    char str_periodico[6];
    int pts;

} Combatente;

typedef Combatente cremosa;
typedef Combatente inimigo;

int main(){

    int capacidade = 5;
    int qtd_inim = 0;
    int cremosa_venceu = 0; // flag that indicates if Princesa Cremosa had any victories

    cremosa cremosa;
    inimigo inimigo;
    Combatente *dados_inimigos = malloc(capacidade * sizeof(inimigo));

    int *cremosa_pontuacoes = malloc(capacidade * sizeof(int));
    int *inimigo_pontuacoes = malloc(capacidade * sizeof(int));

    char *vencedor = malloc(capacidade * sizeof(char));

    if(dados_inimigos == NULL){

        printf("Falha na alocação de memória para o array de armazenamento dos dados dos inimigos. O programa será encerrado.\n");
        free(cremosa_pontuacoes);
        free(inimigo_pontuacoes);
        exit(1);

    }

    if(inimigo_pontuacoes == NULL){

        printf("Falha na alocação de memória para o array de armazenamento das pontuações dos inimigos. O programa será encerrado.\n");
        free(dados_inimigos);
        free(cremosa_pontuacoes);
        exit(1);

    }

    if(cremosa_pontuacoes == NULL){

        printf("Falha na alocação de memória para o array de armazenamento das pontuações da Princesa Cremosa. O programa será encerrado.\n");
        free(dados_inimigos);
        free(inimigo_pontuacoes);
        exit(1);

    }

    if(vencedor == NULL){

        printf("Falha na alocação de memória para o array de armazenamento do vencedor de cada rodada. O programa será encerrado.\n");
        exit(1);

    }

    // reading Princesa Cremosa's info
    scanf(" %d %d %f %s", &cremosa.amp, &cremosa.freq, &cremosa.ener,  cremosa.str_periodico);

    // reading the enemies' info until EOF
    while(scanf(" %d %d %f %s", &inimigo.amp, &inimigo.freq, &inimigo.ener, inimigo.str_periodico) != EOF){

        cremosa.pts = 0;
        inimigo.pts = 0;

        // allocating more memory to store the points of each enemy 

        if((qtd_inim + 1) == capacidade){

            capacidade *= 2;
            int *lista_aux_int = realloc(inimigo_pontuacoes, capacidade * sizeof(int));

            // reallocating inimigos_pontuacoes
            if(lista_aux_int == NULL){

                printf("Falha na realocação da lista de pontuações dos inimigos. Todos os ponteiros serão liberados e o programa será encerrado.\n");
                free(inimigo_pontuacoes);
                free(cremosa_pontuacoes);
                free(vencedor);
                free(dados_inimigos);
                exit(1);
            }

            else{
                inimigo_pontuacoes = lista_aux_int;
            }

            lista_aux_int = realloc(cremosa_pontuacoes, capacidade * sizeof(int));

            // reallocating cremosa_pontuacoes
            if(lista_aux_int == NULL){

                printf("Falha na realocação da lista de pontuações da Princesa Cremosa. Todos os ponteiros serão liberados e o programa será encerrado.\n");
                free(inimigo_pontuacoes);
                free(cremosa_pontuacoes);
                free(vencedor);
                free(dados_inimigos);
                exit(1);
            }

            else{
                cremosa_pontuacoes = lista_aux_int;
            }

            // reallocating vencedor
            char *lista_aux_char = realloc(vencedor, capacidade * sizeof(char));

            if(lista_aux_char == NULL){

                printf("Falha na realocação da lista dos vencedores de cada rodada. Todos os ponteiros serão liberados e o programa será encerrado.\n");
                free(inimigo_pontuacoes);
                free(cremosa_pontuacoes);
                free(vencedor);
                free(dados_inimigos);
                exit(1);
            }

            else{
                vencedor = lista_aux_char;
            }
            
            // reallocating dados_inimigos
            Combatente *lista_aux_comb = realloc(dados_inimigos, capacidade * sizeof(inimigo));

            if(lista_aux_comb == NULL){

                printf("Falha na realocação da lista dos dados de todos os inimigos. Todos os ponteiros serão liberados e o programa será encerrado.\n");
                free(inimigo_pontuacoes);
                free(cremosa_pontuacoes);
                free(vencedor);
                free(dados_inimigos);
                exit(1);
            }

            else{
                dados_inimigos = lista_aux_comb;
            }
            
            } // end of the if (qtd_inim + 1) == capacidade statement

        // comparing the amplitudes

        if(cremosa.amp > inimigo.amp){
            cremosa.pts++;
        }

        else if(inimigo.amp > cremosa.amp){
            inimigo.pts++;
        }

        // comparing the frequencies

        if(cremosa.freq == inimigo.freq){
            cremosa.pts++;
            inimigo.pts++;
        }

        else if(cremosa.freq % inimigo.freq == 0){
            cremosa.pts++;
        }

        else if(inimigo.freq % cremosa.freq == 0){
            inimigo.pts++;
        }

        // comparing the energies

        if(cremosa.ener > inimigo.ener){
            cremosa.pts++;
        }

        else if(inimigo.ener > cremosa.ener){
            inimigo.pts++;
        }

        if(strcmp(cremosa.str_periodico, "TRUE") == 0 && strcmp(inimigo.str_periodico, "FALSE") == 0){
            cremosa.pts++;
        }

        else if(strcmp(inimigo.str_periodico, "TRUE") == 0 && strcmp(cremosa.str_periodico, "FALSE") == 0){
            inimigo.pts++;
        }

        cremosa_pontuacoes[qtd_inim] = cremosa.pts;
        inimigo_pontuacoes[qtd_inim] = inimigo.pts;

        if(cremosa_pontuacoes[qtd_inim] > inimigo_pontuacoes[qtd_inim]){
            vencedor[qtd_inim] = 'c';
            cremosa_venceu++;
        }

        else{
            vencedor[qtd_inim] = 'i';
        }

        dados_inimigos[qtd_inim] = inimigo;
        qtd_inim++;

    } // end of while loop

    // ordering the battles by descending enemy score (selection sort algorithm)
    
    if(qtd_inim > 1){

        for(int i=0; i<qtd_inim-1; i++){

        // assuming the current position holds the greatest element
        int idx_max = i;

        // comparing with the unsorted portion, to see if idx_max is actually correct
        for(int j = i + 1; j<qtd_inim; j++){

            if(inimigo_pontuacoes[j] > inimigo_pontuacoes[idx_max]){
                idx_max = j;
            }
        }

        // updating inimigo_pontuacoes
        int aux_int = inimigo_pontuacoes[i];
        inimigo_pontuacoes[i] = inimigo_pontuacoes[idx_max];
        inimigo_pontuacoes[idx_max] = aux_int;

        // updating cremosa_pontuacoes
        aux_int = cremosa_pontuacoes[i];
        cremosa_pontuacoes[i] = cremosa_pontuacoes[idx_max];
        cremosa_pontuacoes[idx_max] = aux_int;

        // updating vencedor
        char aux_char = vencedor[i];
        vencedor[i] = vencedor[idx_max];
        vencedor[idx_max] = aux_char;

        // updating dados_inimigos

        Combatente aux_comb = dados_inimigos[i];
        dados_inimigos[i] = dados_inimigos[idx_max];
        dados_inimigos[idx_max] = aux_comb; 

        } // end of for(int i=0; i<qtd_inim -1; i++)
    } // end of if(qtd_inim > 1)

    // building the final print!

    // first, Princesa Cremosa's data 

    int max_idx_crem = 0;

    for(int i=0; i<qtd_inim;i++){

        if(cremosa_pontuacoes[i] > cremosa_pontuacoes[max_idx_crem]){
            max_idx_crem = i;
        }
    }

    printf("%d %d %.2f %d", cremosa.amp, cremosa.freq, cremosa.ener, cremosa_pontuacoes[max_idx_crem]);
    
    if(cremosa_venceu >= 1){
    printf(" WINNER ( ");
    for(int i = 0; i<qtd_inim;i++){
    if(vencedor[i] == 'c'){
        printf("%d ", i+1);
    }
    }
    printf(")\n---\n");
    }

    else{
    printf("\n---\n");
    }

    // second, the enemies' data

    for(int i=0; i<qtd_inim;i++){

        printf("%d %d %.2f %d", dados_inimigos[i].amp, dados_inimigos[i].freq, dados_inimigos[i].ener, dados_inimigos[i].pts);
        
        if(vencedor[i] == 'i'){
            printf(" WINNER\n");
        }

        else{
            printf("\n");
        }
    }

    if(cremosa_venceu == qtd_inim){
        printf("FLAWLESS VICTORY!\n");
    }

    free(cremosa_pontuacoes);
    free(inimigo_pontuacoes);
    free(dados_inimigos);
    free(vencedor);

    return 0;
}