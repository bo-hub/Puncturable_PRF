//
// Created by bob on 2021/3/12.
//

#include "Utils.h"

unsigned int key_derivation(unsigned char *plaintext, int plaintext_len,
                            unsigned char *key, int key_len,
                            unsigned char *digest) {
    HMAC_CTX *ctx;

    unsigned int len;

    /* Create and initialise the context */
    ctx = HMAC_CTX_new();

    /* Initialise the decryption operation. */
    HMAC_Init_ex(ctx, key, key_len, EVP_md5(), NULL);

    /* compute the digest */
    HMAC_Update(ctx, plaintext, plaintext_len);

    /* Finalise the digest */
    HMAC_Final(ctx, digest, &len);

    /* Clean up */
    HMAC_CTX_free(ctx);

    return len;
}