#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings dynamically
char* concatenateStrings(char* str1, char* str2) {
    // Calculate the length of the new string
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Allocate memory for the concatenated string (+1 for null terminator)
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Copy and concatenate strings
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    char *input1 = NULL, *input2 = NULL, *concatenated = NULL;
    size_t size1 = 0, size2 = 0;

    printf("Enter 'Q' to stop inputting strings.\n\n");

    while (1) {
        // Take first string input
        printf("Enter first string: ");
        getline(&input1, &size1, stdin);
        input1[strcspn(input1, "\n")] = '\0'; // Remove newline character

        // Stop if user inputs 'Q'
        if (strcmp(input1, "Q") == 0) {
            break;
        }

        // Take second string input
        printf("Enter second string: ");
        getline(&input2, &size2, stdin);
        input2[strcspn(input2, "\n")] = '\0'; // Remove newline character

        // Stop if user inputs 'Q'
        if (strcmp(input2, "Q") == 0) {
            break;
        }

        // Concatenate the strings
        if (concatenated == NULL) {
            concatenated = concatenateStrings(input1, input2);
        } else {
            char* temp = concatenateStrings(concatenated, input1);
            free(concatenated);
            concatenated = concatenateStrings(temp, input2);
            free(temp);
        }

        // Output the original inputs and concatenated result
        printf("\nOriginal Strings: \"%s\", \"%s\"\n", input1, input2);
        printf("Concatenated String: %s\n\n", concatenated);
    }

    // Free allocated memory
    free(input1);
    free(input2);
    free(concatenated);

    printf("Program terminated.\n");
    return 0;
}
