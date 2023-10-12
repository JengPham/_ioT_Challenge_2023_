/*
 * crypt.h
 *
 *  Created on: Sep 13, 2023
 *      Author: jengp
 */

#ifndef CRYPT_H_
#define CRYPT_H_

#include "mbedtls/aes.h"
#include <string.h>

void EncryptDataECB(unsigned char *data, unsigned char *encryptedData);
void DecryptDataECB(unsigned char *encryptedData, unsigned char *decryptedData);

#endif /* CRYPT_H_ */
