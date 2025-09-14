#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * CRUD operations are implemented on a single file ('players_data.txt') because:
  The dataset is small (5 players), making a single file efficient and sufficient.
 */

struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[15];
    char arm[5];   
    struct player ply;
};

struct bat {
    char type[15]; 
    char handed[8]; 
    struct bowl ply2;
};


void createPlayerData();
void readPlayerData();
void updatePlayerData(char *playerName);
void deletePlayerData(char *playerName);
const char *FILENAME = "players_data.txt";

void createPlayerData() {
    
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct bat players[5] = {
        {"top order", "righty", {"seamer", "right", {"John", "TeamA"}}},
        {"middle order", "lefty", {"spinner", "left", {"Mike", "TeamB"}}},
        {"lower order", "righty", {"pacer", "right", {"Raj", "TeamC"}}},
        {"N/A", "N/A", {"N/A", "N/A", {"Chris", "TeamD"}}},
        {"N/A", "N/A", {"N/A", "N/A", {"Sam", "TeamE"}}}
    };

    for (int i = 0; i < 5; i++) {
        fwrite(&players[i], sizeof(struct bat), 1, file);
    }

    fclose(file);
    printf("Player data created successfully.\n");
}


void readPlayerData() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    struct bat player;
    printf("Player Data:\n");
    while (fread(&player, sizeof(struct bat), 1, file)) {
        printf("Name: %s, Team: %s, Bowl Type: %s, Arm: %s, Bat Type: %s, Handed: %s\n",
               player.ply2.ply.name, player.ply2.ply.team, player.ply2.type, player.ply2.arm,
               player.type, player.handed);
    }

    fclose(file);
}


void updatePlayerData(char *playerName) {
    FILE *file = fopen(FILENAME, "r+");
    if (!file) {
        printf("Error opening file for updating.\n");
        return;
    }

    struct bat player;
    int found = 0;

    while (fread(&player, sizeof(struct bat), 1, file)) {
        if (strcmp(player.ply2.ply.name, playerName) == 0) {
            found = 1;

            strcpy(player.ply2.ply.team, "UpdatedTeam");
            strcpy(player.type, "middle order");

            fseek(file, -sizeof(struct bat), SEEK_CUR);
            fwrite(&player, sizeof(struct bat), 1, file);
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("Player data updated successfully.\n");
    } else {
        printf("Player not found.\n");
    }
}

void deletePlayerData(char *playerName) {
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Error opening files for deletion.\n");
        return;
    }

    struct bat player;
    int found = 0;

    while (fread(&player, sizeof(struct bat), 1, file)) {
        if (strcmp(player.ply2.ply.name, playerName) != 0) {
            fwrite(&player, sizeof(struct bat), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Player data deleted successfully.\n");
    } else {
        printf("Player not found.\n");
    }
}
int main() {
    int choice;
    char playerName[20];

    createPlayerData(); 
    printf("Initial player data has been created.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Display all players\n");
        printf("2. Update a player\n");
        printf("3. Delete a player\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readPlayerData();
                break;

            case 2:
                printf("Enter the name of the player to update: ");
                scanf("%19s", playerName);
                updatePlayerData(playerName);
                break;

            case 3:
                printf("Enter the name of the player to delete: ");
                scanf("%19s", playerName); 
                deletePlayerData(playerName);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

