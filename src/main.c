#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "password_manager.h"

void list_password_names();

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
    printf("1. Generate password\n2. Retrieve password\n");
    scanf("%d", &choice);

    if (choice == 1) {
        char password[MAX_PASSWORD_LENGTH + 1];
        generate_password(password);
        printf("Generated password: %s\n", password);
        char name[256];
        printf("Enter name for the password: ");
        scanf("%255s", name);
        save_password(name, password, key);
    } else if (choice == 2) {
        list_password_names();
        char name[256];
        printf("Enter name of the password to retrieve: ");
        scanf("%255s", name);
        retrieve_password(name, key);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}