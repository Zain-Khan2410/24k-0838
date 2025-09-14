#include <stdio.h>

void printStatistics(int data[50][4], float GPA[50], int salaryDemand[50]) {
    // a) Total number of candidates with GPA higher than 3.0 and more than 50 in analytical test
    int count = 0;
    for (int i = 0; i < 50; i++) {
        if (GPA[i] > 3.0 && data[i][1] > 50) {
            count++;
        }
    }
    printf("a) Total number of candidates with GPA higher than 3.0 and more than 50 in analytical test: %d\n", count);

    // b) The percentage of candidates with cumulative test score higher than X and salary lower than Y
    int X, Y;
    printf("Enter X (cumulative test score threshold): ");
    scanf("%d", &X);
    printf("Enter Y (salary threshold): ");
    scanf("%d", &Y);

    int eligibleCount = 0;
    for (int i = 0; i < 50; i++) {
        int cumulativeScore = data[i][1] + data[i][2] + data[i][3];
        if (cumulativeScore > X && salaryDemand[i] < Y) {
            eligibleCount++; 
        }
    }
    float percentage = (float)eligibleCount / 50 * 100;
    printf("b) Percentage of candidates with cumulative score higher than %d and salary lower than %d: %.2f%%\n", X, Y, percentage);

    // c) Average salary demand for the post throughout the candidates
    int totalSalaryDemand = 0;
    for (int i = 0; i < 50; i++) {
        totalSalaryDemand += salaryDemand[i];
    }
    float averageSalaryDemand = (float)totalSalaryDemand / 50;
    printf("c) Average salary demand for the post: %.2f\n", averageSalaryDemand);

    // d) Median GPA
    float sortedGPA[50];
    for (int i = 0; i < 50; i++) {
        sortedGPA[i] = GPA[i];
    }

    // Sort GPA array to calculate the median
    for (int i = 0; i < 49; i++) {
        for (int j = 0; j < 49 - i; j++) {
            if (sortedGPA[j] > sortedGPA[j + 1]) {
                float temp = sortedGPA[j];
                sortedGPA[j] = sortedGPA[j + 1];
                sortedGPA[j + 1] = temp;
            }
        }
    }

    // Calculate the median GPA
    float medianGPA;
    if (50 % 2 == 0) {
        medianGPA = (sortedGPA[24] + sortedGPA[25]) / 2;
    } else {
        medianGPA = sortedGPA[25];
    }
    printf("d) Median GPA: %.2f\n", medianGPA);
}

int main() {
    int data[50][4];
    float GPA[50];
    int salaryDemand[50];

    // Input student data
    for (int i = 0; i < 50; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &data[i][0]);

        printf("Analytical test score: ");
        scanf("%d", &data[i][1]);

        printf("Problem-solving test score: ");
        scanf("%d", &data[i][2]);

        printf("Interview score: ");
        scanf("%d", &data[i][3]);

        printf("GPA: ");
        scanf("%f", &GPA[i]);

        printf("Salary demand: ");
        scanf("%d", &salaryDemand[i]);

        printf("\n");
    }

    // Print statistics based on the data entered
    printStatistics(data, GPA, salaryDemand);

    return 0;
}
