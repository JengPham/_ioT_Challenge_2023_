/*
 * crypt.c
 *
 *  Created on: Sep 13, 2023
 *      Author: jengp
 */

#include "crypt.h"

static unsigned char AES_KEY[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

void EncryptDataECB(unsigned char *data, unsigned char *encryptedData) {

    mbedtls_aes_context aes_ctx;
    mbedtls_aes_init(&aes_ctx);
    mbedtls_aes_setkey_enc(&aes_ctx, AES_KEY, 128);
    mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_ENCRYPT, data, encryptedData);
    mbedtls_aes_free(&aes_ctx);
}

void DecryptDataECB(unsigned char *encryptedData, unsigned char *decryptedData) {

    mbedtls_aes_context aes_ctx;
    mbedtls_aes_init(&aes_ctx);
    mbedtls_aes_setkey_dec(&aes_ctx, AES_KEY, 128);
    mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, encryptedData, decryptedData);
    mbedtls_aes_free(&aes_ctx);
}
