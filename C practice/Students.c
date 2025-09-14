#include <stdio.h>

int main() {
    int numStudents, i, highestScore = 0, lowestScore = 100, range, totalMarks = 0;
    int studentMarks[100]; // Assuming a maximum of 100 students

    // Get the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Get marks for each student
    printf("Enter the marks of each student: ");
    for (i = 0; i < numStudents; i++) {
        scanf("%d", &studentMarks[i]);

        // Update highest and lowest scores
        if (studentMarks[i] > highestScore) {
            highestScore = studentMarks[i];
        }
        if (studentMarks[i] < lowestScore) {
            lowestScore = studentMarks[i];
        }

        // Calculate total marks
        totalMarks += studentMarks[i];
    }

    // Calculate range, average score, and number of students
    range = highestScore - lowestScore;
    float averageScore = (float)totalMarks / numStudents;

    // Print the statistics
    printf("\nHighest Score: %d\n", highestScore);
    printf("Lowest Score: %d\n", lowestScore);
    printf("Range: %d\n", range);
    printf("Number of Students: %d\n", numStudents);
    printf("Average Score: %.2f\n", averageScore);

    // Calculate and print the scores Ali and Fatima need to achieve
    printf("\nAli needs to improve his score by: %d\n", highestScore - 85);
    printf("Fatima needs to improve her score by: %d\n", highestScore - 92);

    return 0;
}