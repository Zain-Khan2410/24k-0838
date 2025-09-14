#include <stdio.h>
#include <string.h>

// Structure Definitions
typedef struct {
    int day;
    float unitsConsumed;
} DailyConsumption;

typedef struct {
    char customerName[50];
    int customerID;
    DailyConsumption dailyConsumptions[30];
} ElectricityBill;

typedef struct {
    float rate;
    float upperLimit;
} BillingTier;

// Billing Tier Configuration
BillingTier billingTiers[] = {
    {0.10, 50.0},  // Rate for the first 50 units
    {0.15, 100.0}, // Rate for the next 50 units
    {0.20, -1.0}   // Rate for any units beyond 100
};

// Function to calculate total consumption and billing
float calculateTotalConsumption(ElectricityBill bill) {
    float totalUnits = 0;
    float totalBill = 0;

    // Calculate total units consumed
    for (int i = 0; i < 30; i++) {
        totalUnits += bill.dailyConsumptions[i].unitsConsumed;
    }

    // Calculate bill based on tiers
    float remainingUnits = totalUnits;
    for (int i = 0; i < 3; i++) {
        if (billingTiers[i].upperLimit == -1.0 || remainingUnits > 0) {
            float tierUnits = billingTiers[i].upperLimit == -1.0 ? remainingUnits : 
                (remainingUnits > billingTiers[i].upperLimit ? billingTiers[i].upperLimit : remainingUnits);

            totalBill += tierUnits * billingTiers[i].rate;
            remainingUnits -= tierUnits;
        }
    }

    printf("Total Units Consumed: %.2f\n", totalUnits);
    printf("Total Bill Amount: $%.2f\n", totalBill);

    return totalUnits;
}

// Function to find frequency of each unit consumption
void findUnitFrequency(ElectricityBill bill) {
    int frequency[301] = {0};

    // Count the frequency of units consumed
    for (int i = 0; i < 30; i++) {
        int units = (int)bill.dailyConsumptions[i].unitsConsumed;
        frequency[units]++;
    }

    // Print frequency
    printf("\nUnit Consumption Frequency:\n");
    for (int i = 0; i <= 300; i++) {
        if (frequency[i] > 0) {
            printf("%d units: %d days\n", i, frequency[i]);
        }
    }
}

// Function to find the days with second highest and third lowest consumption
void analysis(ElectricityBill bill) {
    float dailyUnits[30];
    for (int i = 0; i < 30; i++) {
        dailyUnits[i] = bill.dailyConsumptions[i].unitsConsumed;
    }

    // Sort the daily units in ascending order
    for (int i = 0; i < 30 - 1; i++) {
        for (int j = 0; j < 30 - i - 1; j++) {
            if (dailyUnits[j] > dailyUnits[j + 1]) {
                float temp = dailyUnits[j];
                dailyUnits[j] = dailyUnits[j + 1];
                dailyUnits[j + 1] = temp;
            }
        }
    }

    printf("\nSecond Highest Consumption: %.2f units\n", dailyUnits[28]);
    printf("Third Lowest Consumption: %.2f units\n", dailyUnits[2]);
}

int main() {
    ElectricityBill bill;

    // Sample data initialization
    strcpy(bill.customerName, "John Doe");
    bill.customerID = 12345;

    for (int i = 0; i < 30; i++) {
        bill.dailyConsumptions[i].day = i + 1;
        bill.dailyConsumptions[i].unitsConsumed = (i % 10) * 10 + 5; // Example data
    }

    // Function Calls
    calculateTotalConsumption(bill);
    findUnitFrequency(bill);
    analysis(bill);

    return 0;
}
