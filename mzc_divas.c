#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int amp_crem;
    int freq_crem;
    float ener_crem;
    char str_periodico_crem[6];
    int e_periodico_crem;
    int amp_inim;
    int freq_inim;
    float ener_inim;
    char str_periodico_inim[6];
    int capacidade = 5;
    int qtd_inim = 0;
    int pts_crem = 0;
    int pts_inim = 0;
    int *pontuacoes_inim = malloc(capacidade * sizeof(int));
    int *pontuacoes_crem = malloc(capacidade * sizeof(int));
    char *vencedor = malloc(capacidade * sizeof(char));

    // checking the success of the memory allocation for pontuacoes_inim and pontuacoes_crem

    if(pontuacoes_inim == NULL){

        printf("Falha na alocação de memória para o array de armazenamento das pontuações dos inimigos. O programa será encerrado.\n");
        exit(1);

    }

    if(pontuacoes_crem == NULL){

        printf("Falha na alocação de memória para o array de armazenamento das pontuações da Princesa Cremosa. O programa será encerrado.\n");
        exit(1);

    }

    if(vencedor == NULL){

        printf("Falha na alocação de memória para o array de armazenamento do vencedor de cada rodada. O programa será encerrado.\n");
        exit(1);

    }

    // reading Princesa Cremosa's info
    scanf(" %d %d %f %s", &amp_crem, &freq_crem, &ener_crem, str_periodico_crem);

    // reading the enemies' info until EOF
    while(scanf(" %d %d %f %s", &amp_inim, &freq_inim, &ener_inim, str_periodico_inim) != EOF){

        pts_crem = 0;
        pts_inim = 0;

        // allocating more memory to store the points of each enemy 

        if((qtd_inim + 1 ) == capacidade){

            capacidade *= 2;
            int *lista_aux = realloc(pontuacoes_inim, capacidade * sizeof(int));

            if(lista_aux == NULL){

                printf("Falha na realocação da lista de pontuações. Todos os ponteiros serão liberados e o programa será encerrado.\n");
                free(pontuacoes_inim);
                exit(1);
            }

            else{
                pontuacoes_inim = lista_aux;
            }
        }

        // comparing the amplitudes

        if(amp_crem > amp_inim){
            pts_crem++;
        }

        else if(amp_inim > amp_crem){
            pts_inim++;
        }

        // comparing the frequencies

        if(freq_crem == freq_inim){
            pts_crem++;
            pts_inim++;
        }

        else if(freq_crem % freq_inim == 0){
            pts_crem++;
        }

        else if(freq_inim % freq_crem == 0){
            pts_inim++;
        }

        // comparing the energies

        if(ener_crem > ener_inim){
            pts_crem++;
        }

        else if(ener_inim > ener_crem){
            pts_inim++;
        }

        if(strcmp(str_periodico_crem, "TRUE") == 0 && strcmp(str_periodico_inim, "FALSE") == 0){
            pts_crem++;
        }

        else if(strcmp(str_periodico_inim, "TRUE") == 0 && strcmp(str_periodico_crem, "FALSE") == 0){
            pts_inim++;
        }

        pontuacoes_crem[qtd_inim] = pts_crem;
        pontuacoes_inim[qtd_inim] = pts_inim;

        if(pontuacoes_crem[qtd_inim] > pontuacoes_inim[qtd_inim]){
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
    //     printf("%d ", pontuacoes_crem[i]);
    //     printf("\n");

    // }

    // for(int i = 0; i < qtd_inim; i++){

    //     printf("Pontuações inimigos: ");
    //     printf("%d ", pontuacoes_inim[i]);
    //     printf("\n");
    // }

    // for(int i = 0; i < qtd_inim; i++){

    //     printf("Vencedor: ");
    //     printf("%c ", vencedor[i]);
    //     printf("\n");
    // }

    free(pontuacoes_inim);

    return 0;
}