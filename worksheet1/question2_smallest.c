#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float MediaFinal(float array[], int tamanho){

    int i;
    float soma = 0;
    float media;
    float arrayinter[tamanho - 1]; // array intermediário
    float arrayfinal[tamanho - 2]; // array final, sem os dois menores valores do array original
    int idx_menor = 0; 

    
    for (i = 0; i < tamanho; i++){

        if (array[i] < array[idx_menor]){
            idx_menor = i; // identificando o índice do menor valor
        }
    }

    // passando os valores de array para arrayintermediário, excluindo o menor

    int contador = 0;

    for (i = 0; i < tamanho; i++){

        if (i != idx_menor){
            arrayinter[contador] = array[i];
            contador++;
        }
    }

    tamanho -= 1; // atualizando a variável tamanho, para se adaptar ao novo array
    idx_menor = 0; // atualizando o índice arbitrário do menor valor, para não correr o risco de conflitar com o tamanho do novo array
    contador = 0; // reiniciando o contador, para uso futuro

    // repetindo o processo com o array intermediário, para tirar o segundo menor valor 

    for (i = 0; i < tamanho; i++){

        if (arrayinter[i] < arrayinter[idx_menor]){
            idx_menor = i; // identificando o índice do segundo menor valor
        }
    }

    // passando os valores de arrayinter para arrayfinal, excluindo o menor valor 

    for (i = 0; i < tamanho; i++){

        if (i != idx_menor){
            arrayfinal[contador] = arrayinter[i];
            contador++;
        }
    }

    tamanho -= 1; // atualizando a variável tamanho, para se adaptar ao novo array

    // somando os valores do array final, para conseguirmos calcular a média 

    for (i = 0; i < tamanho; i++){

        soma += arrayfinal[i];

    }

    // saindo do laço da soma, calculemos a média

    media = soma / tamanho;

    return media;
}

int main(){

    int N;
    scanf(" %d", &N);

    float array_valores[N];
    int i = 0;

    // para ler os inputs vindos de uma linha só, vamos usar um laço que verifica se ainda é possível ler um novo valor
    while (scanf("%f", &array_valores[i]) == 1){
        i++;
    }

    if (N<3){
    printf("Numero de notas insuficiente.");
    }

    else{
    printf("%.2f", MediaFinal(array_valores, N));
    }
    
    return 0;
}