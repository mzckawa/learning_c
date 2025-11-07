#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    
    char c = 'a';
    char* pc = &c;

    printf("a) O endereço de c é %p e valor de c é %c.\n", pc, c);
    printf("b) O ponteiro pc armazena o valor %p e o valor guardado no endereço apontado por ele é %c.\n", pc, *pc);
    printf("c) O endereço do ponteiro pc é %p.\n", &pc);
    printf("%p\n", &*pc);
    printf("%p\n", *&pc);
    printf("d) O endereço apontado por pc - ou o valor armazenado pelo ponteiro pc - é o endereço de c, ou seja, *pc mostra exatamente aquilo que c mostrar. Assim, *pc = c. Logo, o endereço de *pc é o mesmo endereço de c, isto é, &*pc = &c.\nJá o endereço de pc (&pc) guarda um certo valor, e, sendo pc um ponteiro, esse valor guardado é o endereço da variável para o qual ele aponta, que, no caso, é o endereço de c. Para extrairmos esse endereço, precisamos apontar para ele, ou seja, utilizarmos *&pc. \nCom base nesse raciocínio, percebemos que ""&*pc"" e ""*&pc"" são equivalentes, com ambos se referindo ao endereço de c, como se vê abaixo:\n""&c"": %p\n""&*p"": %p\n""*&p"": %p", &c, &*pc, *&pc);
    
    return 0;
}