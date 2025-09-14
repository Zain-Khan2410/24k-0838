#include <stdio.h>

int main() {
    int num, i, sum = 0;
    int divisors[100]; // Assuming a maximum of 100 divisors

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Find proper divisors and store them in the array
    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            divisors[sum++] = i;
        }
    }

    // Calculate the sum of proper divisors
    for (i = 0; i < sum; i++) {
        sum += divisors[i];
    }

    // Classify the integer
    if (sum > num) {
        printf("%d is an abundant number.\n", num);
    } else if (sum < num) {
        printf("%d is a deficient number.\n", num);
    } else {
        printf("%d is a perfect number.\n", num);
    }

    // Print the proper divisors
    printf("Proper divisors: ");
    for (i = 0; i < sum; i++) {
        printf("%d ", divisors[i]);
    }
    printf("\n");

    return 0;
}