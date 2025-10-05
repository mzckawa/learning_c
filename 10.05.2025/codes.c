#include <stdio.h>
#include <string.h>
#include <math.h>

float CalcNota(int P, int G, int T){
    
    float nota = (3 * P + G + 2 * T)/6;
 
return nota;
 
}

int CriarArrays(N){

    int i;
    int N;

    int nomes[N];
    float notas[N];

    return nomes, notas;

}

int ManipularArrays(int *arrnomes[], float arrnotas[], int nome, float nota, int contador){

    arrnomes[contador] = nome;
    arrnotas[contador] = nota;

    return arrnomes, arrnotas;
}

int AvaliarArrays(char *arr_nom[], float arr_not[], int len_arr){

    int i;
    float maior_nota = 0.0;
    int melhor_idx;


    for (i = 0; i < len_arr; i ++){
        
        if (arr_not[i] > maior_nota){
            
            maior_nota = arr_not[i];
            melhor_idx = i;
        }
    }

}


int main(){

    char * nome_lugar;
    int P, G, T;
    int qtd_lugares;
    int j;
    float nota;

    scanf(" %d\n", &qtd_lugares);
    CriarArrays(qtd_lugares);

    for (j = 0; j < qtd_lugares; j++){
    scanf(" %s %d %d %d\n", &nome_lugar, &P, &G, &T);
    nota = CalcNota(P, G, T);


}

}