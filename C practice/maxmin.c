#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to differentiate a term in the form ax^n
void differentiate(char* term) {
    double coefficient;
    int exponent;

    // Parse the term assuming the format ax^n
    if (sscanf(term, "%lfx^%d", &coefficient, &exponent) == 2) {
        coefficient *= exponent; // Differentiate: Multiply coefficient by the exponent
        exponent -= 1;           // Decrease exponent by 1

        if (exponent == 0)
            printf("Derivative: %.2f\n", coefficient);
        else if (exponent == 1)
            printf("Derivative: %.2fx\n", coefficient);
        else
            printf("Derivative: %.2fx^%d\n", coefficient, exponent);
    } else if (sscanf(term, "%lfx", &coefficient) == 1) {
        // If it's a linear term like ax
        printf("Derivative: %.2f\n", coefficient);
    } else if (sscanf(term, "%lf", &coefficient) == 1) {
        // If it's a constant term
        printf("Derivative: 0\n");
    } else {
        printf("Invalid term format.\n");
    }
}

// Function to integrate a term in the form ax^n
void integrate(char* term) {
    double coefficient;
    int exponent;

    // Parse the term assuming the format ax^n
    if (sscanf(term, "%lfx^%d", &coefficient, &exponent) == 2) {
        exponent += 1;           // Integrate: Increase exponent by 1
        coefficient /= exponent; // Divide coefficient by the new exponent

        printf("Integral: %.2fx^%d + C\n", coefficient, exponent);
    } else if (sscanf(term, "%lfx", &coefficient) == 1) {
        // If it's a linear term like ax
        printf("Integral: %.2fx^2/2 + C\n", coefficient);
    } else if (sscanf(term, "%lf", &coefficient) == 1) {
        // If it's a constant term
        printf("Integral: %.2fx + C\n", coefficient);
    } else {
        printf("Invalid term format.\n");
    }
}

int main() {
    char term[100];
    char choice;

    printf("Enter the term (e.g., 3x^2, 4x, or 5): ");
    scanf("%s", term);

    printf("Do you want to differentiate (d) or integrate (i) the term? Enter 'd' or 'i': ");
    scanf(" %c", &choice);

    if (choice == 'd') {
        differentiate(term);
    } else if (choice == 'i') {
        integrate(term);
    } else {
        printf("Invalid choice. Please enter 'd' for differentiation or 'i' for integration.\n");
    }

    return 0;
}
