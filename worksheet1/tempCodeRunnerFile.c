#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float CalcNota(float P, float G, float T){
    
    float nota = ((3 * P) + G + (2 * T))/6;
 
return nota;
 
}

int ContarLugares(char arr_nom[][50], float arr_not[], int len_arr){

    int i;
    int qtd_val = 0; // para contar quantos lugares há com nota igual ou maior do que 3.5
    
    for (i = 0; i < len_arr; i ++){
    if (arr_not[i] >= 3.5){
            qtd_val += 1;
    }
}
    return qtd_val;
}

int AvaliarArrays(char arr_nom[][50], float arr_not[], int len_arr){

    int i;
    float maior_nota = 0.0;
    int melhor_idx;
    
    for (i = 0; i < len_arr; i ++){
        
        if (arr_not[i] >= 3.5){

            if(arr_not[i] > maior_nota){ // atualizando o lugar com maior nota, se for o caso. Se tiver a mesma nota do que a maior nota, não entrará na condicional
                maior_nota = arr_not[i];
                melhor_idx = i;   
            }
        }    
    }
    return melhor_idx;
}

int main(){

    float P, G, T;
    int qtd_lugares;
    int j;
    float nota;

    scanf(" %d", &qtd_lugares);

    float array_notas[qtd_lugares];
    char array_nomes[qtd_lugares][50];

    // recebendo os locais, guardando os nomes em um array, calculando suas notas e pondo-as em outro array 

    for (j = 0; j < qtd_lugares; j++){
    scanf(" %s %f %f %f", array_nomes[j], &P, &G, &T);
    nota = CalcNota(P, G, T);
    array_notas[j] = nota; 
    }

    // completos os arrays, vejamos como ficará a viagem!

    int qtd_validos = ContarLugares(array_nomes, array_notas, qtd_lugares); 
    
    printf("Temos %d lugares pra visitar!\n", qtd_validos);
    
    if (qtd_validos){

        // se temos lugares visitáveis, vejamos qual será visitado primeiro

       int melhor_ind = AvaliarArrays(array_nomes, array_notas, qtd_lugares);

    char melhor_lugar[50];
    strncpy(melhor_lugar, array_nomes[melhor_ind], 50);
    printf("Devo comecar por %s", melhor_lugar);

    }

    else{
        printf("Puts. Melhor ficar em casa mesmo");
    }
    
    return 0;
}