#include <stdio.h>

#define MAX_SIZE 100

// Function to sum the diagonal elements (primary + secondary)
int sum_diagonal(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];  // Primary diagonal
        sum += matrix[i][n - 1 - i];  // Secondary diagonal
    }
    // If n is odd, subtract the center element (which was added twice)
    if (n % 2 != 0) {
        sum -= matrix[n / 2][n / 2];
    }
    return sum;
}

// Function to sum the boundary elements
int sum_boundary(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;

    // Sum top and bottom rows
    for (int i = 0; i < n; i++) {
        sum += matrix[0][i];  // Top row
        sum += matrix[n - 1][i];  // Bottom row
    }

    // Sum left and right columns (excluding corners)
    for (int i = 1; i < n - 1; i++) {
        sum += matrix[i][0];  // Left column
        sum += matrix[i][n - 1];  // Right column
    }

    return sum;
}

// Function to sum the elements other than the boundary elements
int sum_inner(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;
    
    // Inner elements, excluding the boundary (start from 1 to n-2 for rows and columns)
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int main() {
    int n;
    
    // Input the size of the matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Declare and input the matrix
    int matrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }


    // Calculate and display the sums
    printf("Sum of diagonal elements: %d\n", sum_diagonal(matrix, n));
    printf("Sum of boundary elements: %d\n", sum_boundary(matrix, n));
    printf("Sum of inner elements: %d\n", sum_inner(matrix, n));

    return 0;
}





