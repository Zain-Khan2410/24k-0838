#include <stdio.h>

int main() {
    
    float P, R, T,I;

    printf("Enter the principal amount (between 100 Rs. and 1,000,000 Rs.): ");
    scanf("%f", &P);
    if (P< 100 || P > 1000000) {
        printf("Invalid Principal Amount\n");
    }


    printf("Enter the rate of interest (between 5 and 10): ");
    scanf("%f", &R);
    if (R< 5 || R > 10) {
        printf("Invalid Rate Of Interest.\n");
    }

    
    printf("Enter the time period in years (between 1 and 10 years): ");
    scanf("%f", &T);
    if (T < 1 || T > 10) {
        printf("Invalid Time Period\n");
    }

    I = (P * R * T) / 100;
    printf("The simple interest is: Rs. %.2f \n", I);

}