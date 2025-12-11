#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Inicializando a Pilha
void initStack(Stack *s) {
    s->top = -1;
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
    printf("Pushed: %d\n", value);
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


int main() {
    Stack s;
    initStack(&s); // Inicializa

    char expressao_atual[101];
    char variaveis_definidas[101];
    Stack* operandos_expressao_atual;
    int valor_variaveis_definidas[101];
    int tamanho_expressao_atual = 0;
    int qtd_operandos_expressao_atual = 0;
    int i = 0;

    scanf(" %s", expressao_atual);

    int tamanho_expressao_atual = len_string(expressao_atual);

    for(int i = 0; i<tamanho_expressao_atual; i++){

        char carac_atual = expressao_atual[i];

        if(isalpha(carac_atual) != 0){ // conferindo se é uma letra (ou seja, é uma variável)
            push_str(variaveis_definidas, carac_atual);
        }

        else if (carac_atual != '+' && carac_atual != '*' && carac_atual != '-' && carac_atual != '='){ // se entrar aqui, é porque é um inteiro
            push_int(operandos_expressao_atual, carac_atual);
        }

        }

        // caso o elemento seja um operador

        else if(carac_atual != '=' && carac_atual != ' '){

        }
    }
    return 0;
}