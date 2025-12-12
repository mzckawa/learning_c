/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int num_cartao;
    int qtd_digitos = 1;
    int ultimo_digito;
    int num_cartao_copia;
    int soma_impares = 0;
    int soma_pares = 0;
    
    scanf(" %d", &num_cartao);
    num_cartao_copia = num_cartao;
    
    while(num_cartao_copia >= 10){
        
        ultimo_digito = num_cartao_copia % 10;
        
        if(qtd_digitos % 2){
            
            soma_impares += ultimo_digito;
            printf("A soma de dígitos ímpares agora é %d\n", soma_impares);
            
        }
        else{
            soma_pares += ultimo_digito;
            printf("A soma de dígitos pares agora é %d\n", soma_pares);
        }
        
        num_cartao_copia /= 10;
        qtd_digitos++;
        printf("Agora vamos trabalhar com o %do dígito de %d\n", qtd_digitos, num_cartao_copia);
        
    }
    
    // somando o último dígito
    if(qtd_digitos%2){
        soma_impares += num_cartao_copia;
    }
    
    else{
        soma_pares += num_cartao_copia;
    }
    
    
    printf("A soma de dígitos ímpares é %d\n", soma_impares);
    printf("A soma de dígitos pares é %d\n", soma_pares);

    return 0;
}

