#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void Decripto(char palavra[51], int tam_palav, int key){

    char array_alfab[53] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    int recuo_cripto = key; // varivável que indicará o quanto precisaremos "recuar" para chegar na letra original
    int novo_idx;
    int qtd_espacos = 0;

    for (int j=0; j<tam_palav; j++){

        if (palavra[j] == ' '){ // verificando se o elemento é um espaço
            qtd_espacos++;
        }

        recuo_cripto += j + 1; // adicionando o índice da letra na palavra à chave de criptografia (adicionamos 1 porque a contagem do índice, para a criptografia, começa no 1)
        recuo_cripto -= qtd_espacos;
        
        for (int i=0; i<52; i++){

            if (palavra[j] == array_alfab[i]){
            
                novo_idx = (i - recuo_cripto) % 52;

                if (novo_idx < 0){
                    palavra[j] = array_alfab[52+novo_idx]; // ex: se novo_idx == -1, vai para array_alfab[52-1] = array_alfab[51], que é o último índice de array_alfab
                }

                else{
                    palavra[j] = array_alfab[novo_idx];
                }
                break;
            }  
        }
    recuo_cripto = key; // resetando o recuo 
    }

}

int main(){

    char palavra[51];
    int chave_cripto;

    scanf(" %d", &chave_cripto);
    scanf(" %[^\n]", palavra);

    while (strcmp(palavra, "FIM") != 0){

        Decripto(palavra, strlen(palavra), chave_cripto);
        printf("%s\n", palavra);
        scanf(" %[^\n]", palavra);
    }
    
    return 0;
}

