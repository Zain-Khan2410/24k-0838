#include <stdio.h>
#include <string.h>

void compress_word(char *word) {
    int len = strlen(word);
    int j = 0;

    for (int i = 0; i < len; i++) {
        word[j++] = word[i];
        while (i + 1 < len && word[i] == word[i + 1]) {
            i++;
        }
    }

    word[j] = '\0'; // Terminate the compressed string
}

int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    compress_word(word);

    printf("Compressed word: %s\n", word);

    return 0;
}