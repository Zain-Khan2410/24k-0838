#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROLLS 50
#define MSG_LENGTH 200

void Message(char msg[MSG_LENGTH]) {
    // Append "pos" to the game message
    if (strlen(msg) + 3 < MSG_LENGTH) {
        strcat(msg, "pos");
    }
}

int MaxScore(int rolls[], int rollCount) {
    int maxScore = rolls[0];
    for (int i = 1; i < rollCount; i++) {
        if (rolls[i] > maxScore) {
            maxScore = rolls[i];
        }
    }
    return maxScore;
}

void Utility(int rolls[], int rollCount, char msg[MSG_LENGTH]) {
    printf("Game Message Extracted Every Five Rolls:\n");
    for (int i = 0; i < rollCount; i += 5) {
        int len = strlen(msg);
        if (len > 5) {
            printf("%.5s\n", &msg[len - 5]);
        } else {
            printf("%s\n", msg);
        }
    }
}

int main() {
    int rolls[MAX_ROLLS];
    char msg[MSG_LENGTH] = "begin";
    int score = 0;
    int maxScore = 0;

    srand(time(0));

    for (int i = 0; i < MAX_ROLLS; i++) {
        rolls[i] = (rand() % 201) - 100; // Random number between -100 and 100
        
        // Update the score based on the last two rolls
        if (i > 0) {
            score = rolls[i] + rolls[i - 1];
        } else {
            score = rolls[i];
        }

        // Check if score is positive or negative
        if (score > 0) {
            Message(msg);
        } else if (score < 0) {
            maxScore = MaxScore(rolls, i + 1);
            printf("Max score up to roll %d: %d\n", i + 1, maxScore);
        }
    }

    // After 50 rolls, call Utility function to print required message excerpts
    Utility(rolls, MAX_ROLLS, msg);

    return 0;
}
