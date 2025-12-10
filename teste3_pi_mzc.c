#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Inicializando a Pilha
Stack* initStack() {

    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;

    return stack;
}

// Verificar se está Vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Verificar se está Cheia
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Operação Push
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    //printf("Pushed: %d\n", value);
}

// Operação Pop
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Operação Top
int top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}

int len_string(char expressao[]){

    int len = 0;
    int i = 0;

    while(expressao[i] != '\0'){
        len++;
        i++;
    }
    return len;
}

int len_array_int(int expressao[]){

    int len = 0;
    int i = 0;

    while(expressao[i] != '\0'){
        len++;
        i++;
    }
    return len;
}

int main() {

    char expressao_atual[101];
    char variaveis_definidas[101];
    Stack* operandos_expressao_atual = initStack();
    int valor_variaveis_definidas[101];
    int qtd_variaveis_definidas = 0;
    int qtd_operandos_expressao_atual = 0;
    int i = 0;
    int flag_esta_na_lista = 0;
    int operando1;
    int operando2;
    int res;
    int tamanho_expressao_atual = len_string(expressao_atual);

    scanf(" %s[\\^;]", expressao_atual);

    while(strcmp(expressao_atual, "EOF") != 0){

        // printf("Qtd variaveis definidas ao entrar no while %d\n", qtd_variaveis_definidas);
    for(int i = 0; i<tamanho_expressao_atual; i++){

        // printf("Entrou no for!\n");

        char* carac_atual = &expressao_atual[i];

        // printf("Caractere atual: %c\n", *carac_atual);

        if(*carac_atual == ';'){
            break; // passa para o print da expressão, fora do laço for
        }

        if(isalpha(*carac_atual) != 0){ // conferindo se é uma letra (ou seja, é uma variável)

            int idx_lista;

            for(int i = 0; i<qtd_variaveis_definidas; i++){ // conferindo se ela já está na lista
                if(variaveis_definidas[i] == *carac_atual){
                    flag_esta_na_lista = 1;
                    idx_lista = i;
                    break;
                }
            }

            if(flag_esta_na_lista == 0){ // se ela não está na lista, damos o push 

                variaveis_definidas[qtd_variaveis_definidas] = *carac_atual;
                qtd_variaveis_definidas++;

            }

            else if(flag_esta_na_lista){ // se está na lista, vamos colocá-la na pilha de operandos, substituindo pelo seu já conhecido valor
                
                push(operandos_expressao_atual, valor_variaveis_definidas[idx_lista]);
                qtd_operandos_expressao_atual++;
                flag_esta_na_lista = 0;
                //printf("%c já estava na lista! nao precisamos adicionar\n", *carac_atual);

            }
            
        }

        else if (*carac_atual != '+' && *carac_atual != '*' && *carac_atual != '-' && *carac_atual != '='){ // se entrar aqui, é porque é um inteiro
    
            int operando = atoi(carac_atual);
            //printf("Encontramos número %d\n", operando);
            push(operandos_expressao_atual, operando);
            qtd_operandos_expressao_atual++;

        }

        // caso o elemento seja um operador

        else if(*carac_atual != '=' && *carac_atual != ' '){

            // se houver mais do que dois operandos, vamos fazer a conta entre eles
            if(qtd_operandos_expressao_atual >=2){

                operando1 = pop(operandos_expressao_atual);
                operando2 = pop(operandos_expressao_atual);

                int res;

                if(*carac_atual == '+'){

                    res = operando1 + operando2;
                    push(operandos_expressao_atual, res);
                }

                else if(*carac_atual == '-'){

                    res = operando1 - operando2;
                    push(operandos_expressao_atual, res);
                }

                else if(*carac_atual == '*'){

                    res = operando1 * operando2;
                    push(operandos_expressao_atual, res);
                }
            }

            else{
                printf("Não há operandos suficientes para fazer a operação.\n");
            }
        }

    } // fim do for(int i = 0; i<tamanho_expressao_atual; i++)

    if(qtd_operandos_expressao_atual == 1){
        res = operandos_expressao_atual->items[operandos_expressao_atual->top];
        //printf("O resultado da última operação é %d\n", res);
    }

    //printf("Saiu do for!\n");

    //printf("Qtd variaveis definidas após sair do for %d\n", qtd_variaveis_definidas);

    // acabada a expressão, vamos colocar o resultado das operações como o valor da última variável nova encontrada 
    valor_variaveis_definidas[qtd_variaveis_definidas - 1] = res;

    printf("%c = %d\n", variaveis_definidas[qtd_variaveis_definidas - 1], valor_variaveis_definidas[qtd_variaveis_definidas - 1]);

    scanf(" %s", expressao_atual); // lendo a próxima linha

    } // fim do while(strcmp(expressao_atual, "EOF") == 0)

return 0;
} 