#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORDS 100

// Function to find the three longest words and add <L> tags
void longest_words(char *line, char longest[3][MAX_LINE_LENGTH]) {
    char *words[MAX_WORDS];
    int lengths[MAX_WORDS];
    int word_count = 0;

    // Tokenize the line into words
    char *token = strtok(line, " ,.-\n");
    while (token != NULL) {
        words[word_count] = token;
        lengths[word_count] = strlen(token);
        word_count++;
        token = strtok(NULL, " ,.-\n");
    }

    // Sort words by length
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (lengths[i] < lengths[j]) {
                int temp_len = lengths[i];
                char *temp_word = words[i];
                lengths[i] = lengths[j];
                words[i] = words[j];
                lengths[j] = temp_len;
                words[j] = temp_word;
            }
        }
    }

    // Copy the top 3 longest words and surround them with <L>
    for (int i = 0; i < 3 && i < word_count; i++) {
        sprintf(longest[i], "<L>%s<L>", words[i]);
    }
}

// Function to concatenate <s> tags
void concatenate_s_tags(char *line) {
    char result[MAX_LINE_LENGTH] = "";
    char *start = strstr(line, "<s>");
    while (start != NULL) {
        char *end = strstr(start, "</s>");
        if (end == NULL) break;

        char temp[MAX_LINE_LENGTH];
        strncpy(temp, start + 3, end - start - 3);
        temp[end - start - 3] = '\0';
        strcat(result, temp);

        start = strstr(end + 4, "<s>");
    }

    // Replace the original line with the concatenated result
    strcpy(line, result);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char longest[3][MAX_LINE_LENGTH] = { "", "", "" };

    while (fgets(line, MAX_LINE_LENGTH, input)) {
        char original[MAX_LINE_LENGTH];
        strcpy(original, line);

        // Find the 3 longest words
        longest_words(line, longest);

        // Print the longest words
        printf("Longest words: %s, %s, %s\n", longest[0], longest[1], longest[2]);

        // Replace longest words with <L> tags in the original line
        for (int i = 0; i < 3; i++) {
            if (strstr(original, longest[i])) {
                char temp[MAX_LINE_LENGTH];
                strcpy(temp, original);
                char *pos = strstr(temp, longest[i]);
                if (pos) {
                    sprintf(pos, "<L>%s<L>", longest[i]);
                }
                strcpy(original, temp);
            }
        }

        // Concatenate <s> tags
        concatenate_s_tags(original);

        // Write the modified line to the output file
        fputs(original, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}
