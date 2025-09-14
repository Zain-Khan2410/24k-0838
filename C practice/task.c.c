#include <stdio.h>

int main() {
    // Declare variables for salary and credit score
    float salary;
    int credit_score;

    // Input the salary and credit score from the user
    printf("Enter your salary (in Rs.): ");
    scanf("%f", &salary);
    
    printf("Enter your credit score: ");
    scanf("%d", &credit_score);

    // Determine loan eligibility based on salary and credit score
    if (salary > 50000) {
        if (credit_score > 700) {
            printf("You are eligible for a loan of Rs. 10,00,000.\n");
        } else {
            printf("You are eligible for a loan of Rs. 7,00,000.\n");
        }
    } else {
        if (credit_score > 700) {
            printf("You are eligible for a loan of Rs. 5,00,000.\n");
        } else {
            printf("You are not eligible for a loan.\n");
        }
    }

    return 0;
}
