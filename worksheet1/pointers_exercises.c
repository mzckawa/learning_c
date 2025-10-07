#include <stdio.h>

int main(){

    int a = 10;
    int b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;
    int *ptr3;

    *ptr1 = 30;
    ptr3 = ptr1;
    *ptr2 = *ptr1 + 5;
    ptr1 = &b;
    *ptr3 = *ptr1 - 10;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("*ptr1 = %d\n", *ptr1);
    printf("*ptr2 = %d\n", *ptr2);
    printf("*ptr3 = %d\n", *ptr3);
    
}