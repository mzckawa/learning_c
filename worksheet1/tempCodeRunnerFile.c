void  Cor(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int res = pow(dia1, 2) + pow(mes1, 2) + pow(ano1, 2) + pow(dia2, 2) + pow(mes2, 2) + pow(ano2, 2);
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

Cor(1, 1, 2001, 29, 9, 2025);

    return 0;
}