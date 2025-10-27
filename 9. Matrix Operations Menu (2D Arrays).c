#include <stdio.h>
#define N 2

void addMatrix(int A[][N], int B[][N], int C[][N]) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            C[i][j] = A[i][j] + B[i][j];
    printf("Matrices added.\n");
}

void transpose(int A[][N], int T[][N]) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            T[j][i] = A[i][j];
    printf("Matrix transposed.\n");
}

void printMatrix(int A[][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];
    int choice;
    
    printf("Matrix A:\n"); printMatrix(A);
    printf("Matrix B:\n"); printMatrix(B);

    do {
        printf("\nMATRIX MENU\n1. Add A+B\n2. Transpose A\n3. Print C\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMatrix(A, B, C); break;
            case 2: transpose(A, C); break;
            case 3: printMatrix(C); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid.\n"); break;
        }
    } while (choice != 4);
    return 0;
}