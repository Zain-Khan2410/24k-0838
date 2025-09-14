#include <stdio.h>
#include <string.h>
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

int addCar(struct Car cars[], int count) {
    printf("Enter car make: ");
    scanf("%s", cars[count].make);
    printf("Enter car model: ");
    scanf("%s", cars[count].model);
    printf("Enter car year: ");
    scanf("%d", &cars[count].year);
    printf("Enter car price: ");
    scanf("%f", &cars[count].price);
    printf("Enter car mileage: ");
    scanf("%f", &cars[count].mileage);
    count++;
    printf("Car added successfully!\n");
    return count;
}
void displayCars(struct Car cars[], int count) {
    if (count == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }
    printf("\nAvailable Cars:\n");
    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("  Make: %s\n", cars[i].make);
        printf("  Model: %s\n", cars[i].model);
        printf("  Year: %d\n", cars[i].year);
        printf("  Price: %.2f\n", cars[i].price);
        printf("  Mileage: %.2f\n", cars[i].mileage);
    }
}
void carsearch(struct Car cars[], int count) {
    if (count == 0) {
        printf("No cars available to search.\n");
        return;
    }

    char keyword[50];
    printf("Enter make or model to search: ");
    scanf("%s", keyword);

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(cars[i].make, keyword) != NULL || strstr(cars[i].model, keyword) != NULL) {
            printf("Car %d:\n", i + 1);
            printf("  Make: %s\n", cars[i].make);
            printf("  Model: %s\n", cars[i].model);
            printf("  Year: %d\n", cars[i].year);
            printf("  Price: %.2f\n", cars[i].price);
            printf("  Mileage: %.2f\n", cars[i].mileage);
            found = 1;
        }
    }
if (!found) {
        printf("No cars found matching the keyword '%s'.\n", keyword);
    }
}
int main() {
    struct Car cars[100]; 
    int count = 0;        
    int choice;

    do {
        printf("\nCar Dealership System\n");
        printf("1. Add a new car\n");
        printf("2. Display all cars\n");
        printf("3. Search for a car by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addCar(cars, count); 
                break;
            case 2:
                displayCars(cars, count);
                break;
            case 3:
                Carsearch(cars, count);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
