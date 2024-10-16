#include "encryption.h"
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <string.h>
#include <stdlib.h>

void encrypt_password(const char *password, const char *key, char *encrypted) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, (const unsigned char *)key, NULL);
    int len;
    EVP_EncryptUpdate(ctx, (unsigned char *)encrypted, &len, (const unsigned char *)password, strlen(password));
    int ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, (unsigned char *)encrypted + len, &len);
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    encrypted[ciphertext_len] = '\0';
}

void decrypt_password(const char *encrypted, const char *key, char *decrypted) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, (const unsigned char *)key, NULL);
    int len;
    EVP_DecryptUpdate(ctx, (unsigned char *)decrypted, &len, (const unsigned char *)encrypted, strlen(encrypted));
    int plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, (unsigned char *)decrypted + len, &len);
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    decrypted[plaintext_len] = '\0';
}

char *base64_encode(const unsigned char *data, size_t input_length, size_t *output_length) {
    BIO *bio, *b64;
    BUF_MEM *buffer_ptr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

    BIO_write(bio, data, input_length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &buffer_ptr);

    *output_length = buffer_ptr->length;
    char *b64text = (char *)malloc(buffer_ptr->length + 1);
    memcpy(b64text, buffer_ptr->data, buffer_ptr->length);
    b64text[buffer_ptr->length] = '\0';

    BIO_free_all(bio);

    return b64text;
}

char *base64_decode(const char *data, size_t input_length, size_t *output_length) {
    BIO *bio, *b64;
    int decode_len = (input_length * 3) / 4;
    unsigned char *buffer = (unsigned char *)malloc(decode_len + 1);
    if (buffer == NULL) {
        return NULL;
    }

    bio = BIO_new_mem_buf(data, input_length);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    *output_length = BIO_read(bio, buffer, input_length);
    buffer[*output_length] = '\0';

    BIO_free_all(bio);

    return (char *)buffer;
}