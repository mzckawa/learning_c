// Problem statement: "Make a program that reads a matrix and prints its transpose"
// The following code was made with the help of Copilot. After finishing it, I deactivated the autocomplete mode, so that I could test whether I was able to make the same code all by myself or not. But, before that, I will write down my teacher's resolution to the problem.
// #include <stdio.h>
// #define i 2
// #define j 2

// // creating the matrix 

// double Matrix[i][j];
// double TransposeMatrix[i][j];

// // inserting values in the matrix

// void CreatMatrix(){

//     for (int a = 0; a < i; a++){
//         for (int b = 0; b < j; b++){
            
//             printf("Insert a value for the position [%d][%d]: ", a, b);
//             scanf("%lf", &Matrix[a][b]);

//         }
        
//     }
// }

// void PrintMatrix(double ChosenMatrix[i][j]){

//     for (int a = 0; a < i; a++){
        
//         for (int b = 0; b < j; b++){

//             printf("%.2f ", ChosenMatrix[a][b]);
//         }
        
//     printf("\n");
//     }
// }

// void TransposingMatrix(double Matrix1[i][j], double Matrix2[i][j]){

//     for (int a = 0; a < i; a++){

//         for (int b = 0; b < j; b++){

//             Matrix2[b][a] = Matrix1[a][b];
//         }
//     }
// }
// int main(){
// CreatMatrix();
// PrintMatrix(Matrix);
// printf("\n");
// TransposingMatrix(Matrix, InvertedMatrix);
// PrintMatrix(TransposeMatrix);
// }

// My teacher's resolution to the problem:

#include <stdio.h>;
#define L 2
#define C 3

void leMatriz(int m[L][C]) {

    for (int i = 0; i < L; i ++){
        for (int j = 0; j < C; j ++)
            scanf("%d", &m[i][j]);
    }
    
}

void transposta(int m [L][C], int mT[C][L]) {

    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            mT[j][i] = m[i][j];

}

void imprimeMatriz(int mT[C][L]) {

    for (int i = 0; i < C; i ++){
        for (int j = 0; j < L; j ++)
            printf("%5d", mT[i][j]);

        printf("\n");
    
}
