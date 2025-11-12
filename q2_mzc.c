#include <stdio.h>
#include <stdlib.h>

int main(){

    int vet[5] = {1,2,3,4,5};
    int *p = vet;

    printf("a) O endereço guardado em vet é %p e o endereço guardado em p é %p\n", &vet, p);
    printf("b) Os valores de vet, utilizando p com [], são: vet[0] = p[0] = %d, vet[1] = p[1] = %d, vet[2] = p[2] = %d, vet[3] = p[3] = %d e vet[4] = p[4] = %d.\n", p[0], p[1], p[2], p[3], p[4]);
    printf("c)) Os valores de vet, utilizando p com *, são: vet[0] = *(p + 0) = *p = %d, são: vet[1] = *(p + 1) = %d, são: vet[2] = *(p + 2) = %d, são: vet[3] = *(p + 3) = %d, são: vet[4] = *(p + 4) = %d.\n", *p, *(p+1), *(p+2), *(p+3), *(p+4));
    printf("d) Fazendo o mesmo dos itens b) e c), mas com vet no lugar de p, temos:\n");
    printf("-> Os valores de vet, utilizando vet com [], são: vet[0] = %d, vet[1] = %d, vet[2] = %d, vet[3] = %d e vet[4] = %d.\n", vet[0], vet[1], vet[2], vet[3], vet[4]);
    printf("-> Os valores de vet, utilizando vet com *, são: vet[0] = *(vet + 0) = *vet = %d, são: vet[1] = *(vet + 1) = %d, são: vet[2] = *(vet + 2) = %d, são: vet[3] = *(vet + 3) = %d, são: vet[4] = *(vet + 4) = %d.\n", *p, *(vet+1), *(vet+2), *(vet+3), *(vet+4));
    return 0;
}