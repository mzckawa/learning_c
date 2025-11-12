#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DadosCombatente{
    int amp;
    int freq;
    float ener;
    char str_periodico[6];
    int pts;
    int *pontuacoes;

} Combatente;

typedef Combatente cremosa;
typedef Combatente inimigo;

int main(){

    cremosa cremosa;
    inimigo inimigo;
    int capacidade = 5;
    int qtd_inim = 0;

    cremosa.pontuacoes = malloc(capacidade * sizeof(int));
    inimigo.pontuacoes = malloc(capacidade * sizeof(int));

    char *vencedor = malloc(capacidade * sizeof(char));

    // checking the success of the memory allocation for inimigo.pontuacoes and cremosa.pontuacoes

    if(inimigo.pontuacoes == NULL){

        printf("Falha na alocação de memória para o array de armazenamento das pontuações dos inimigos. O programa será encerrado.\n");
        exit(1);

    }

    if(cremosa.pontuacoes == NULL){

        printf("Falha na alocação de memória para o array de armazenamento das pontuações da Princesa Cremosa. O programa será encerrado.\n");
        exit(1);

    }

    if(vencedor == NULL){

        printf("Falha na alocação de memória para o array de armazenamento do vencedor de cada rodada. O programa será encerrado.\n");
        exit(1);

    }

    // reading Princesa Cremosa's info
    scanf(" %d %d %f %s", cremosa.amp, cremosa.ener, cremosa.freq, cremosa.str_periodico);

    // reading the enemies' info until EOF
    while(scanf(" %d %d %f %s", inimigo.amp, inimigo.ener, inimigo.freq, inimigo.str_periodico) != EOF){

        cremosa.pts = 0;
        inimigo.pts = 0;

        // allocating more memory to store the points of each enemy 

        if((qtd_inim + 1) == capacidade){

            capacidade *= 2;
            int *lista_aux = realloc(inimigo.pontuacoes, capacidade * sizeof(int));

            if(lista_aux == NULL){

                printf("Falha na realocação da lista de pontuações. Todos os ponteiros serão liberados e o programa será encerrado.\n");
                free(inimigo.pontuacoes);
                exit(1);
            }

            else{
                inimigo.pontuacoes = lista_aux;
            }
        }

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

        cremosa.pontuacoes[qtd_inim] = cremosa.pts;
        inimigo.pontuacoes[qtd_inim] = inimigo.pts;

        if(cremosa.pontuacoes[qtd_inim] > inimigo.pontuacoes[qtd_inim]){
            vencedor[qtd_inim] = 'c';
        }

        else{
            vencedor[qtd_inim] = 'i';
        }

        qtd_inim++;

    } // end of while loop


    // debugging prints
    // for(int i = 0; i < qtd_inim; i++){

    //     printf("Pontuações Cremosa: ");
    //     printf("%d ", cremosa.pontuacoes[i]);
    //     printf("\n");

    // }

    // for(int i = 0; i < qtd_inim; i++){

    //     printf("Pontuações inimigos: ");
    //     printf("%d ", inimigo.pontuacoes[i]);
    //     printf("\n");
    // }

    // for(int i = 0; i < qtd_inim; i++){

    //     printf("Vencedor: ");
    //     printf("%c ", vencedor[i]);
    //     printf("\n");
    // }

    free(inimigo.pontuacoes);

    return 0;
}