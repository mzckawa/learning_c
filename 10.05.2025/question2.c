#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float MediaFinal(float array[], int tamanho){

    int i;
    float soma = 0;
    float media;
    float arrayfinal[tamanho - 2];
    float menor_valor = array[0]; // colocando um valor arbitrário do array como referência
    float segundo_menor = array[1];

    
    for (i = 0; i < tamanho; i++){

        if (array[i] < menor_valor){
            menor_valor = array[i]; // identificando o menor valor
        }
        else if (array[i] != menor_valor && array[i] < segundo_menor){
            segundo_menor = array[i]; // identificando o segundo menor
        }
    }

    // passando os valores de array para arrayfinal, excluindo o menor

    int contador = 0;

    for (i = 0; i < tamanho; i++){

        if (array[i] != menor_valor && array[i] != segundo_menor){
            arrayfinal[contador] = array[i];
        }
    }

    for (i = 0; i < tamanho - 2; i++){

        soma += arrayfinal[i];

    }

    // saindo do laço da soma, calculemos a média

    media = soma / (tamanho - 2);

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

    printf("A média é %f", MediaFinal(array_valores, N));
    
    return 0;
}