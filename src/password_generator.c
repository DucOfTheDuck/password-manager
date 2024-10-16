#include "password_generator.h"
#include <stdlib.h>
#include <time.h>

void generate_password(char *password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$^&*()";
    int length = MIN_PASSWORD_LENGTH + rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1);
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';
}