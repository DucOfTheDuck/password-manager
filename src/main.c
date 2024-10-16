#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "password_manager.h"

int main() {
    srand(time(NULL));

    char key[17];
    FILE *key_file = fopen("data/key.txt", "r");
    if (key_file == NULL) {
        perror("Error opening key file");
        return 1;
    }
    fgets(key, sizeof(key), key_file);
    fclose(key_file);

    int choice;
    printf("======================================\n");
    printf("        Password Manager\n");
    printf("======================================\n");
    printf("1. Generate password\n");
    printf("2. Retrieve password\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char password[MAX_PASSWORD_LENGTH + 1];
        generate_password(password);
        printf("\nGenerated password: %s\n", password);
        char name[256];
        printf("Enter name for the password: ");
        scanf("%255s", name);
        if (strlen(name) == 0) {
            printf("Error: Password name cannot be empty.\n");
            return 1;
        }
        save_password(name, password, key);
        printf("Password saved successfully!\n");
    } else if (choice == 2) {
        if (!list_password_names()) {
            printf("No passwords are saved.\n");
        } else {
            char name[256];
            printf("Enter name of the password to retrieve: ");
            scanf("%255s", name);
            if (strlen(name) == 0) {
                printf("Error: Password name cannot be empty.\n");
                return 1;
            }
            retrieve_password(name, key);
        }
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    printf("======================================\n");
    return 0;
}
