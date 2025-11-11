#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){

    int pre_chave;
    int chave = 0; // that is, the number of factors
    char string_buffer[1024];
    char alfabeto1[27] = "abcdefghijklmnopqrstuvwxyz";
    char alfabeto2[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int verif_letter = 0;

    scanf(" %d", &pre_chave);
    scanf(" %[^\n]", string_buffer);

    int tamanho_array_fatores = pre_chave/2;
    
    char *message = malloc(strlen(string_buffer) + 1); 

    if(message == NULL){
        printf("Alocação de memória falhou!");
        exit(1);

    }

    else{
        strcpy(message, string_buffer);
        //printf("%s", message); // debugging print
    }

    // obtaining pre_chave's prime factors
    // first, obtaining all the 2 factors (since 2 is the only even prime)

    if(pre_chave == 0){
        chave=0;
    }

    else{

    while(pre_chave%2 == 0){
        chave++;
        pre_chave /= 2;
    }

    for(long long i=3; i*i<=pre_chave; i+=2){ // testing all the odd numbers equal or smaller than the square root of pre_chave; long long to prevent integer overflow

        while(pre_chave%i == 0){
        
            pre_chave = pre_chave/i;
            chave++;

        }
        
    }

    if(pre_chave>2){
        chave++; // if, after all the loops above, pre_chave is still greater than two, then pre_chave is necessarily a prime number (bigger than the square root of pre_chave)
    }
    }

    for(int i=0; message[i] != '\0'; i++){ // verifying whether there is any letter in the received message

        if(isalpha(message[i])){
            verif_letter = 1;
            break;
        }
    }

    // encrypting the message (under the condition of existing letters)
    if(verif_letter == 1){

        int qtd_letras = 0;

        for(int i=0; message[i] != '\0'; i++){

            for(int j = 0; j<26; j++){ // looking for the current letter in the alphabet array

                if(alfabeto1[j] == message[i]){

                    message[i] = alfabeto1[(j + chave + qtd_letras) % 26]; // the change in i is already a arithmetic progression whose common difference is 1 
                    qtd_letras++;
                    break; // to stop the for loop as soon as message[i] is replaced
                }

                else if(alfabeto2[j] == message[i]){
                    message[i] = alfabeto2[(j + chave + qtd_letras) % 26]; 
                    qtd_letras++;
                    break; 
                }
            }
        
        }
    }

    // printing the key and the enctrypted message 

    printf("%d\n", chave);
    printf("%s", message);

free(message);

return 0;

}