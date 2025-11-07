#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    int vet[5] = {1, 2, 3, 4, 5};
    int *p = vet;

    printf("a) Endereco guardado em vet: %p\nEndereco guardado em p: %p.\n", vet, p);
    printf(" \n");
    
    printf("b) Imprimindo os valores de vet usando p com []:");

    for (int i = 0; i<5; i++){

        if (i < 4){
            printf(" %d,", p[i]);
        }

        else{
            printf(" %d.\n", p[i]);
        }
    }

    printf("\n");

    printf("c) Imprimindo os valores de vet usando p com *:");
    
    for (int i = 0; i<5; i++){

        if (i < 4){
            printf(" %d,", *(p + i));
        }

        else{
            printf(" %d.\n", *(p + i));
        }
    }

    printf("\n");

    printf("d) Imprimindo os valores de vet usando vet com []:");
    
    for (int i = 0; i<5; i++){

        if (i < 4){
            printf(" %d,", vet[i]);
        }

        else{
            printf(" %d.\n", vet[i]);
        }
    }

    printf("Imprimindo os valores de vet usando vet com *:");

    for (int i = 0; i<5; i++){

        if (i < 4){
            printf(" %d,", *(vet + i));
        }

        else{
            printf(" %d.\n", *(vet + i));
        }
    }

    printf("\n");

    return 0;
}
