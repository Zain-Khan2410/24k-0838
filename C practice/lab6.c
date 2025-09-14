#include <stdio.h>

int main() {
    int i, number;

    printf("Enter number: ");
    scanf("%d", &number);

    
    if (number <= 1) {
        printf("Number is neither prime nor composite.\n");
    } else {
        for (i = 2; i < number; i++) {
            if (number % i == 0) {
                printf("Number is composite.\n");
                return 0;  
            }
        }
        printf("Number is prime.\n");
    }
}