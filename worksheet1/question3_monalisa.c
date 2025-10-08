
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// definindo as funções de cada aspecto da previsão

void Amor(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

int res = dia1 + dia2 + mes1 + mes2 + ano1 + ano2;
res = (res * 7) % 101; // não é divisão; res permanece inteiro após essas operações

// printando a porcentagem

printf("Amor: %d%% ", res);

// printando a mensagem adicional
if(res < 20){
printf("Pessimo dia para se apaixonar.\n");
}

else if (res >= 20 && res <= 40){
printf("Melhor manter o coracao <3 longe de perigo.\n");
}

else if (res >= 41 && res <= 69){
printf("Se o papo e as ideias baterem, esta liberado pensar em algo.\n");
}

else if (res >= 70 && res <= 80){
printf("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.\n");
}

else if (res > 80){
printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.\n");
}
}

void Sorte(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int dif_anos;
    
    int res = 9 * (dia1 + dia2 + mes1 + mes2);

    if (ano1 >= ano2){
        dif_anos = ano1 - ano2;
    }

    else{

        dif_anos = ano2 - ano1;
    }

    res += dif_anos;
    res %= 101;
    
    printf("Sorte: %d%% ", res);

    // printando a mensagem adicional
    if(res < 30){
    printf("Nem jogue moedas pra cima hoje. Sem tigrinho nem jogos de azar, por favor!\n");
    }

    else if (res >= 30 && res <= 50){
    printf("Melhor nao arriscar. Sem tigrinho nem jogos de azar, por favor!\n");
    }

    else if (res >= 51 && res <= 79){
    printf("Por sua conta em risco. Sem tigrinho nem jogos de azar, por favor!\n");
    }

    else if (res >= 80 && res <= 90){
    printf("Hoje vale a pena arriscar. Sem tigrinho nem jogos de azar, por favor!\n");
    }

    else if (res > 90){
    printf("Nao tenha medo de virar cartas hoje. Sem tigrinho nem jogos de azar, por favor!\n");
    }
}


void Trabalho(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int res = (ano1 + ano2) - 8*(dia1 + dia2 + mes1 + mes2);
    res %= 101;

    printf("Trabalho: %d%% ", res);

    // printando a mensagem adicional
    if(res < 40){
    printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.\n");
    }

    else if (res >= 40 && res <= 50){
    printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.\n");
    }

    else if (res >= 51 && res <= 69){
    printf("Um dia proveitoso com certeza, leve sua simpatia consigo.\n");
    }

    else if (res >= 70 && res <= 84){
    printf("Boas vibracoes hoje, chances podem estar ao seu redor.\n");
    }

    else if (res > 85){
    printf("Use do maximo de networking possível hoje, dia bom para negocios.\n");
    }
}

void Cor(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int res = dia1*dia1 + mes1*mes1 + ano1*ano1 + dia2*dia2 + mes2*mes2 + ano2*ano2;
    res %= 11;

    switch(res){

        case 0:
        printf("Cor: Cinza.\n");
        break;

        case 1:
        printf("Cor: Vermelho.\n");
        break;

        case 2:
        printf("Cor: Laranja.\n");
        break;

        case 3:
        printf("Cor: Amarelo.\n");
        break;

        case 4:
        printf("Cor: Verde.\n");
        break;

        case 5:
        printf("Cor: Azul.\n");
        break;

        case 6:
        printf("Cor: Roxo.\n");
        break;

        case 7:
        printf("Cor: Marrom.\n");
        break;

        case 8:
        printf("Cor: Rosa.\n");
        break;

        case 9:
        printf("Cor: Preto.\n");
        break;

        case 10:
        printf("Cor: Branco.\n");
        break;
    }
}


int main(){

    int d1;
    int m1;
    int a1; 
    int d2;
    int m2;
    int a2;

    scanf("%d/%d/%d %d/%d/%d", &d1, &m1, &a1, &d2, &m2, &a2);

    Amor(d1, m1, a1, d2, m2, a2);
    Sorte(d1, m1, a1, d2, m2, a2);
    Trabalho(d1, m1, a1, d2, m2, a2);
    Cor(d1, m1, a1, d2, m2, a2);

    return 0;
}