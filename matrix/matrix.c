//normal
#include <stdio.h>
#include<time.h>

clock_t start, end; 
double CPU_time_uesd;

void print(int P[][100], int rs, int cs) {
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < cs; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }
}

void multiply(int r1, int c1, int r2, int c2, int A1[][100], int A2[][100]) {
    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Number of columns of matrix 1 must be equal to the number of rows of matrix 2.\n");
        return;
    }
    
    int c[100][100];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {  
            c[i][j] = 0;
            for (int k = 0; k < c1; k++) {  
                c[i][j] += A1[i][k] * A2[k][j];
            }
        }
    }
    printf("Matrix multiplied.\n");
    print(c, r1, c2);
}
int main() {
    int r1, r2, c1, c2;
    // matrix 1
    printf("\nEnter the number of rows of matrix1: ");
    scanf("%d", &r1);
    printf("Enter the number of columns of matrix1: ");
    scanf("%d", &c1);
    int A1[100][100];
    printf("Enter the elements of the 1st matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("A1[%d][%d] = ", i, j);
            scanf("%d", &A1[i][j]);
        }
    }
    // matrix 2
    printf("\nEnter the number of rows of matrix2: ");
    scanf("%d", &r2);
    printf("Enter the number of columns of matrix2: ");
    scanf("%d", &c2);
    int A2[100][100];
    printf("Enter the elements of the 2nd matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("A2[%d][%d] = ", i, j);
            scanf("%d", &A2[i][j]);
        }
    }
    //first matrix

    
    printf("\nFirst matrix:\n");
    print(A1, r1, c1);
    //second matrix
    printf("Second matrix:\n");
    print(A2, r2, c2);
    //multiplication function
    start = clock();
    multiply(r1, c1, r2, c2, A1, A2);
    end = clock();
    CPU_time_uesd = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total time comnsumed is: %f", CPU_time_uesd);
    return 0;
}