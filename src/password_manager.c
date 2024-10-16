#include "password_manager.h"
#include "encryption.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void save_password(const char *name, const char *password, const char *key) {
    FILE *file = fopen("data/passwords.txt", "a");
    if (file == NULL) {
        perror("Error opening password file");
        return;
    }

    char encrypted[MAX_PASSWORD_LENGTH + 1];
    encrypt_password(password, key, encrypted);

    size_t output_length;
    char *encoded = base64_encode((unsigned char *)encrypted, strlen(encrypted), &output_length);

    char name_buffer[256];
    strncpy(name_buffer, name, sizeof(name_buffer) - 1);
    name_buffer[sizeof(name_buffer) - 1] = '\0';

    fprintf(file, "%s:%s\n", name_buffer, encoded);
    free(encoded);
    fclose(file);
}

void retrieve_password(const char *name, const char *key) {
    FILE *file = fopen("data/passwords.txt", "r");
    if (file == NULL) {
        perror("Error opening password file");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *stored_name = strtok(line, ":");
        if (strcmp(stored_name, name) == 0) {
            char *encoded = strtok(NULL, "\n");
            size_t output_length;
            char *decoded = base64_decode(encoded, strlen(encoded), &output_length);
            char decrypted[MAX_PASSWORD_LENGTH + 1];
            decrypt_password(decoded, key, decrypted);
            free(decoded);
            printf("Password: %s\n", decrypted);
            fclose(file);
            return;
        }
    }
    printf("Password not found.\n");
    fclose(file);
}

int list_password_names() {
    FILE *file = fopen("data/passwords.txt", "r");
    if (file == NULL) {
        perror("Error opening password file");
        return 0;
    }

    char line[256];
    int found = 0;
    printf("\nList of password names:\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ":");
        printf("%s\n", name);
        found = 1;
    }

    fclose(file);
    return found;
}
