#include <stdio.h>

#define CITIES 4    // Number of cities
#define DAYS 7      // Number of days

void HottestDay(int temperature[CITIES][DAYS]) {
    const char *cities[CITIES] = {"Karachi", "Lahore", "Peshawar", "Islamabad"};
    
    for (int i = 0; i < CITIES; i++) {
        int maxTemp = temperature[i][0];
        int hottestDay = 0; // 0 represents Monday

        for (int j = 1; j < DAYS; j++) {
            if (temperature[i][j] > maxTemp) {
                maxTemp = temperature[i][j];
                hottestDay = j; // Update hottest day index
            }
        }

        printf("Hottest day for %s is %d with a temperature of %d°C.\n", 
               cities[i], hottestDay + 1, maxTemp); // +1 to match the day number (Mon=1, Tue=2, ...)
    }
}

void AverageTemperature(int temperature[CITIES][DAYS]) {
    int sum = 0;
    
    for (int j = 0; j < DAYS; j++) {
        sum += temperature[3][j]; // 3 represents Islamabad
    }
    
    float average = sum / (float)DAYS; // Calculate average temperature
    printf("Average temperature in Islamabad for the week: %.2f°C\n", average);
}

int main() {
    int temperature[CITIES][DAYS];

    // Input temperature data
    for (int i = 0; i < CITIES; i++) {
        printf("Enter temperatures for city %d (Karachi: 0, Lahore: 1, Peshawar: 2, Islamabad: 3):\n", i);
        for (int j = 0; j < DAYS; j++) {
            printf("Day %d: ", j + 1); // Day numbers from 1 to 7
            scanf("%d", &temperature[i][j]);
        }
    }

    // Display hottest day for each city
    HottestDay(temperature);

    // Display average temperature for Islamabad
    AverageTemperature(temperature);

    return 0;
}
