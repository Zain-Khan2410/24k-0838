#include <stdio.h>

int main() {
    int bYear, bMonth, bDay;
    int tYear, tMonth, tDay;
    int age;
    int isLeapYear;
    int isValidDate = 1;

    
    printf("Enter the person's birthday (YYYY MM DD): ");
    scanf("%d %d %d", &bYear, &bMonth, &bDay);
    
    printf("Enter today's date (YYYY MM DD): ");
    scanf("%d %d %d", &tYear, &tMonth, &tDay);

   
    if (bMonth < 1 || bMonth > 12 || tMonth < 1 || tMonth > 12) {
        isValidDate = 0;
    }

    
    if (isValidDate) {
        
        isLeapYear = (bYear % 4 == 0 );

        
        if (bMonth == 2) {
            if (isLeapYear) {
                if (bDay < 1 || bDay > 29) {
                    isValidDate = 0;
                }
            } else {
                if (bDay < 1 || bDay > 28) {
                    isValidDate = 0;
                }
            }
        } else if (bMonth == 4 || bMonth == 6 || bMonth == 9 || bMonth == 11) {
            if (bDay < 1 || bDay > 30) {
                isValidDate = 0;
            }
        } else {
            if (bDay < 1 || bDay > 31) {
                isValidDate = 0;
            }
        }

        
        if (isValidDate) {
            isLeapYear = (tYear % 4 == 0 && tYear % 100 != 0) || (tYear % 400 == 0);

            if (tMonth == 2) {
                if (isLeapYear) {
                    if (tDay < 1 || tDay > 29) {
                        isValidDate = 0;
                    }
                } else {
                    if (tDay < 1 || tDay > 28) {
                        isValidDate = 0;
                    }
                }
            } else if (tMonth == 4 || tMonth == 6 || tMonth == 9 || tMonth == 11) {
                if (tDay < 1 || tDay > 30) {
                    isValidDate = 0;
                }
            } else {
                if (tDay < 1 || tDay > 31) {
                    isValidDate = 0;
                }
            }
        }
    }

   
    if (!isValidDate) {
        printf("One or both of the dates are invalid.\n");
        return 1;  
    }

    
    age = tYear - bYear;

    
    if (tMonth < bMonth || (tMonth == bMonth && tDay < bDay)) {
        age--;
    }


    printf("The person's age is: %d\n", age);

    return 0;
}
