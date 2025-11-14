#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char **array_strings = NULL; 
    int curr_size = 1;
    int total_of_strings = 0;
    char string_buffer[1024]; // creating an array that will be used as a place to temporarily store the information received (buffer)

    printf("Para encerrar o programa, basta mandar um sinal de EOF para o terminal. No Linux/MacOS, esse sinal é mandado pelo atalho ctrl+D. Pelo Windows, é ctrl+Z. Divirta-se!\n");
    printf("\n");
    while(scanf(" %s", string_buffer) == 1){

        total_of_strings++;

        // checking whether we have reached the size limit 
        if(curr_size <= total_of_strings){

            printf("\n");
            printf("Limite do espaço atingido. Vamos fazer realocação de memória.\n");
            printf("\n");
            curr_size *= 2;
            
            char **array_string_aux = realloc(array_strings, curr_size * sizeof(char*));

            // verifying whether the reallocation worked out or not 

            if (array_string_aux == NULL){

                printf("\n");
                printf("Realocação falhou! Vamos liberar a memória que já fora preenchida e encerrar o programa.\n");
                printf("\n");

                for(int i=0; i<(total_of_strings-1); i++){
                    free(array_strings[i]); // freeing the string individually
                }

                free(array_strings); // freeing the double pointer
                exit(1); // terminating the program
            }

            else{
            array_strings = array_string_aux;
            }
        }
                
            // allocating memory to correctly store the info that is in the buffer now 

            char *new_string = malloc(strlen(string_buffer) + 1); 

            if(new_string == NULL){

                printf("\n");
                printf("Alocação de memória falhou!");
                printf("\n");

                for(int i=0; i<(total_of_strings-1); i++){
                    free(array_strings[i]); 
                }

                free(array_strings); 
                exit(1);

            }

            else{
                
                strcpy(new_string, string_buffer);
                array_strings[total_of_strings - 1] = new_string;
            }

    }

    // printing each stored string 

    printf("\n");
    printf("Loop concluído! As strings recebidas foram:\n");
    printf("\n");

    for(int i=0; i<total_of_strings; i++){
        printf("%s\n", array_strings[i]); 
    }

    printf("\n");
    printf("Encerrando o programa, vamos liberar o espaço!\n");

    for(int i=0; i<total_of_strings; i++){
        free(array_strings[i]); // freeing the string individually
    }

    free(array_strings); // freeing the double pointer

}