#include <stdio.h>

int main() {
    int customerID;
    int units; // Changed to int
    float netamount, cperu, bill, surcharge = 0; // Initialized surcharge to 0

    printf("Enter the customer ID: ");
    scanf("%d", &customerID);

    printf("Enter the units consumed: ");
    scanf("%d", &units);
  
    // Calculate bill based on units consumed
    if (units <= 199) {
        cperu = 16.20;
        bill = units * cperu;
    } else if (units >= 200 && units < 300) {
        cperu = 20.10;
        bill = units * cperu;
    } else if (units >= 300 && units < 500) {
        cperu = 27.10;
        bill = units * cperu;
    } else if (units >= 500) {
        cperu = 35.90;
        bill = units * cperu;
    }

    // Calculate surcharge if applicable
    if (bill > 18000) {
        surcharge = bill * 0.15;
    }

    // Calculate net amount
    netamount = bill + surcharge;

    // Print results
    printf("Customer ID = %d\n", customerID);
    printf("Units Consumed = %d\n", units);
    printf("Amount Charges @ per unit = %.2f\n", bill);
    printf("Surcharge Amount = %.2f\n", surcharge);
    printf("Net amount paid by the customer = %.2f\n", netamount);

    return 0;
}
