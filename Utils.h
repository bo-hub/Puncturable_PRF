//
// Created by bob on 2021/3/12.
//

#ifndef PUNCTURABLE_PRF_UTILS_H
#define PUNCTURABLE_PRF_UTILS_H

#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <openssl/sha.h>

#define AES_BLOCK_SIZE 16
#define DIGEST_SIZE 32
#define GGM_SIZE 8 //2^3
#define HASH_SIZE 3

unsigned int key_derivation(unsigned char *plaintext, int plaintext_len,
                            unsigned char *key, int key_len,
                            unsigned char *digest);


#endif //PUNCTURABLE_PRF_UTILS_H
