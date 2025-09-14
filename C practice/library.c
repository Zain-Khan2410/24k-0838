#include <stdio.h>

int main() {
    int choice, bookNumber;
    int books[5] = {1, 1, 1, 1, 1}; // Array to keep track of book availability (1 = available, 0 = checked out)
    int totalBooks = 5;

    while (1) {
        // Display menu
        printf("Library Management System\n");
        printf("1. Check Out a Book\n");
        printf("2. Return a Book\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Check out a book
                printf("Available books:\n");
                for (int i = 0; i < totalBooks; i++) {
                    if (books[i] == 1) {
                        printf("Book %d\n", i + 1);
                    }
                }
                printf("Enter the number of the book you want to check out: ");
                scanf("%d", &bookNumber);
                if (bookNumber < 1 || bookNumber > totalBooks) {
                    printf("Invalid book number.\n");
                } else if (books[bookNumber - 1] == 0) {
                    printf("Sorry, Book %d is already checked out.\n", bookNumber);
                } else {
                    books[bookNumber - 1] = 0; // Mark the book as checked out
                    printf("You have successfully checked out Book %d.\n", bookNumber);
                }
                break;

            case 2: // Return a book
                printf("Enter the number of the book you want to return: ");
                scanf("%d", &bookNumber);
                if (bookNumber < 1 || bookNumber > totalBooks) {
                    printf("Invalid book number.\n");
                } else if (books[bookNumber - 1] == 1) {
                    printf("Book %d is not checked out.\n", bookNumber);
                } else {
                    books[bookNumber - 1] = 1; // Mark the book as available
                    printf("You have successfully returned Book %d.\n", bookNumber);
                }
                break;

            case 3: // Exit
                printf("Exiting the library management system.\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}
