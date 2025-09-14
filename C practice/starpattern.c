#include <stdio.h>

int main() {
    int size, temp;

    // Prompt user for the size of the message
    printf("Enter the size of the message: ");
    scanf("%d", &size);
    
    // Declare an array to hold the message
    int message[size];
    
    printf("Enter your digits (0-25):\n");
    for (int i = 0; i < size; i++) {
        printf("Digit %d: ", i + 1);
        scanf("%d", &message[i]); // Fixed: added a comma in scanf
        // Check if the input is within the bounds
        if (message[i] < 0 || message[i] > 25) {
            printf("Number is out of bounds. Enter again.\n");
            i--; // Decrement i to repeat the input for this index
        }
    }

    // Reverse the array
    for (int i = 0; i < (size / 2); i++) {
        temp = message[i];
        message[i] = message[size - 1 - i];
        message[size - 1 - i] = temp;
    }

    // Create an array to hold the corresponding characters
    char arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = message[i] + 97; // Convert to corresponding uppercase letter
    }

    // Print the resulting characters
    printf("Resulting message: ");
    for (int i = 0; i < size; i++) {
        printf(" %c", arr[i]);
    }
    printf("\n");

    return 0;
}
