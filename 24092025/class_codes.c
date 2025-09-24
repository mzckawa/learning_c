#include <stdio.h>
#define i 3
#define j 4

// creating the matrix 

double Matrix[i][j];

// inserting values in the matrix

void CreatMatrix(){

    for (int a = 0; a < i; a++){
        for (int b = 0; b < j; b++){
            
            printf("Insert a value for the position [%d][%d]: ", a, b);
            scanf("%lf", &Matrix[a][b]);

        }
        
    }
}

void PrintMatrix(){

    for (int a = 0; a < i, a++){
        
        for (int b = 0; b < j; b++){

            printf("%.2f ", Matrix[a][b]);
        }
    }
}

int main(){
CreatMatrix();
PrintMatrix();
}
