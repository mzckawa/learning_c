#include <stdio.h>
#include <math.h>

/*
int Soma(int x1, int x2){

    return (x1 + x2);
}

int Subtração(int x1, int x2){

    return (x1 - x2);
}

int Produto(int x1, int x2){

    return (x1 * x2);
}

float Divisão(float x1, float x2){

    return (x1 / x2);
}
*/

void Calculadora(){

    char operacao;
    int a;
    int b;

    printf("Digite um número: ");
    scanf(" %d", &a);

    printf("Digite outro número: ");
    scanf(" %d", &b);
     
    printf("Qual operação você deseja realizar? Digite O = Soma; U = Subtração; P = Produto; D = Divisão");
    scanf(" %c", &operacao);
    
    int res; 

    switch(operacao){

        case 'O':
        res = a + b;
        return (res);

        case 'U':
        res = a - b;
        return (res);

        case 'P':
        res = a * b;
        return (res);

        case 'D':
        res = a / b;
        return (res);
    }

    printf(" %d", res);

}

int main(){Calculadora();}



