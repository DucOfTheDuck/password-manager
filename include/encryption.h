#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stddef.h>

void encrypt_password(const char *password, const char *key, char *encrypted);
void decrypt_password(const char *encrypted, const char *key, char *decrypted);
char *base64_encode(const unsigned char *data, size_t input_length, size_t *output_length);
char *base64_decode(const char *data, size_t input_length, size_t *output_length);

#endif
