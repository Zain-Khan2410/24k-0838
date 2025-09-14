#include <stdio.h>

int main() {
    
    float FuelAvg, FuelForward, FuelBack, totalfuel, totalfuelcost, costforward, costback;
    const float Distance = 1207.00;  
    const float price_forward = 118.00; 
    const float price_back = 123.00; 
        printf("Enter Fuel Average (km per liter): ");
        scanf("%f", &FuelAvg);
        if (FuelAvg <= 0) {
            printf("Fuel average must be a positive number.\n");
        } 
    FuelForward = Distance / FuelAvg;
    FuelBack = Distance / FuelAvg;
    totalfuel = FuelForward + FuelBack;
    costforward = FuelForward * price_forward;
    costback = FuelBack * price_back;
    totalfuelcost = costforward + costback;

    printf("Total fuel consumed (both ways): %.2f liters\n", totalfuel);
    printf("Total fuel cost (both ways): Rs. %.2f\n", totalfuelcost);

}
