#include <stdio.h> 
int main() {
    int matrix[3][3];
    int i, j, minrow, maxcol;
    int saddlepoint = 0;
    printf("Enter the elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }}
    printf("\n3x3 matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }printf("\n");  
    }
    for (i = 0; i < 3; i++) {
        minrow = matrix[i][0];
        for (j = 1; j < 3; j++) {
            if (matrix[i][j] < minrow) {
                minrow = matrix[i][j];
            }
        }
         for (j = 0; j < 3; j++) {
            if (matrix[i][j] == minrow) {
                maxcol = matrix[0][j];
                for (int k = 1; k < 3; k++) {
                    if (matrix[k][j] > maxcol) {
                        maxcol = matrix[k][j];
                    }}
                if (maxcol == minrow) {
                    printf("Saddle point found at (%d, %d): %d\n", i, j, minrow);
                    saddlepoint++;
                } }}
    } if (saddlepoint == 0) {
        printf("No saddle point found\n");
    }}
