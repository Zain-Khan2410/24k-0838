#include <stdio.h>

int main() {
    
    float taxRate, salary, taxAmount, salaryAfterTax;

    
    printf("Enter the tax rate: ");
    scanf("%f", &taxRate);

    printf("Enter the salary: ");
    scanf("%f", &salary);
    taxAmount = (taxRate / 100) * salary;
    salaryAfterTax = salary - taxAmount;

    printf("Tax amount to be paid: %.2f\n", taxAmount);
    printf("Salary after paying tax: %.2f\n", salaryAfterTax);

    return 0;
}
