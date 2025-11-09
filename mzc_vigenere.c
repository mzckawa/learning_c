#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_prime(int num){

    for(int i = 2; i<num; i++){ // because of this condition, i will not be neither 1 nor num 
        if(num % i == 0){
            return 0;
        }
    }
    return 1; // it will only reach this line if all of the divisions by numbers different than 1 and itself are not exact  
}

int main(){

    int pre_chave;
    int qtd_fatores = 0; // that is, the criptography key
    char string_buffer[1024];
    char alfabeto1[27] = "abcdefghijklmnopqrstuvwxyz";
    char alfabeto2[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int verif_letter = 0;

    scanf(" %d", &pre_chave);
    scanf(" %[^\n]", string_buffer);

    int tamanho_array_fatores = pre_chave/2;
    int *fatores_pre_chave = malloc(tamanho_array_fatores * sizeof(int)); // allocating memory dinamically because we don't know how many prime factors does pre_chave have
    
    char *message = malloc(strlen(string_buffer) + 1); 

    if(message == NULL){
        printf("Alocação de memória falhou!");
        exit(1);

    }

    else{
        strcpy(message, string_buffer);
        //printf("%s", message); // debugging print
    }

    if(fatores_pre_chave == NULL){

        printf("Alocação da lista de divisores falhou!");
        exit(1);

    }

    else{

        int pre_chave_orig = pre_chave;

        // obtaining pre_chave's prime factors
        for(int i=pre_chave; i>1; i--){

            if(is_prime(i) == 1){ // we found a prime that is smaller than or equal to pre_chave! 

                while(pre_chave%i == 0){
                
                    pre_chave = pre_chave/i;

                    if (qtd_fatores == tamanho_array_fatores){

                        tamanho_array_fatores *= 2;
                        int *fatores_aux = realloc(fatores_pre_chave, tamanho_array_fatores * sizeof(int));
                        
                        // verifying the success of the reallocation
                        if(fatores_aux == NULL){
                            printf("Falha na realocação.\n");
                            free(fatores_pre_chave);
                            exit(1);
                        }

                        else{
                            fatores_pre_chave = fatores_aux;
                        }

                    }
                    fatores_pre_chave[qtd_fatores] = i;
                    qtd_fatores++;

                }
            }
        }

        for(int i=0; i<strlen(message); i++){ // verifying whether there is any letter in the received message

            if(isalpha(message[i])){
                verif_letter = 1;
            }
        }

        // encrypting the message (under the condition of existing letters)
        if(verif_letter == 1){
            for(int i=0; i<strlen(message); i++){

                for(int j = 0; j<52; j++){ // looking for the current letter in the alphabet array
                    if(alfabeto[j] == message[i]){
                        message[i] = alfabeto[(j + qtd_fatores + i) % 52]; // the change in i is already a arithmetic progression whose common difference is 1 
                        break; // to stop the for loop as soon as message[i] is replaced
                    }
                }
            }
        }

        // printing the key and the enctrypted message 

        printf("%d\n", qtd_fatores);

        if(verif_letter == 0){
            printf("A mensagem não foi encriptada, pois não haviam letras nela!\n");
        }

        else{
            printf("%s", message);
        }


        // debugging prints below 
        // printf("Os %d valores encontrados na fatoração de %d foram: ", qtd_fatores, pre_chave_orig);
        // for(int i = 0; i<qtd_fatores; i++){
        //     printf("%d ", fatores_pre_chave[i]);
        // }
        // printf("\n");

    }

    free(fatores_pre_chave);
    free(message);

    return 0;

}