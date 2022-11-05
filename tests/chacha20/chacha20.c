#include <stdint.h>
#include <stdio.h>
#include <string.h>

extern void chacha20(uint8_t *out,
                     const uint8_t *in,
                     size_t inlen,
                     const uint8_t *key,
                     const uint8_t *nonce,
                     uint32_t ctr);

int main(void)
{
    /* Test vector according to RFC 7539 section 2.4.2
     * https://tools.ietf.org/html/rfc8439#section-2.4.2
     */
    const uint8_t key[32] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                             11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                             22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    const uint8_t nonce[12] = {0, 0, 0, 0, 0, 0, 0, 74, 0, 0, 0, 0};
    const uint32_t ctr = 1;
    uint8_t in[4096] =
        "Ladies and Gentlemen of the class of '99: If I could offer you only "
        "one tip for the future, sunscreen would be it.";
    uint8_t out[4096];

    static const uint8_t exp[] = {
        0x6e, 0x2e, 0x35, 0x9a, 0x25, 0x68, 0xf9, 0x80, 0x41, 0xba, 0x07, 0x28,
        0xdd, 0x0d, 0x69, 0x81, 0xe9, 0x7e, 0x7a, 0xec, 0x1d, 0x43, 0x60, 0xc2,
        0x0a, 0x27, 0xaf, 0xcc, 0xfd, 0x9f, 0xae, 0x0b, 0xf9, 0x1b, 0x65, 0xc5,
        0x52, 0x47, 0x33, 0xab, 0x8f, 0x59, 0x3d, 0xab, 0xcd, 0x62, 0xb3, 0x57,
        0x16, 0x39, 0xd6, 0x24, 0xe6, 0x51, 0x52, 0xab, 0x8f, 0x53, 0x0c, 0x35,
        0x9f, 0x08, 0x61, 0xd8, 0x07, 0xca, 0x0d, 0xbf, 0x50, 0x0d, 0x6a, 0x61,
        0x56, 0xa3, 0x8e, 0x08, 0x8a, 0x22, 0xb6, 0x5e, 0x52, 0xbc, 0x51, 0x4d,
        0x16, 0xcc, 0xf8, 0x06, 0x81, 0x8c, 0xe9, 0x1a, 0xb7, 0x79, 0x37, 0x36,
        0x5a, 0xf9, 0x0b, 0xbf, 0x74, 0xa3, 0x5b, 0xe6, 0xb4, 0x0b, 0x8e, 0xed,
        0xf2, 0x78, 0x5e, 0x42, 0x87, 0x4d};

    chacha20(out, in, sizeof(in), key, nonce, ctr);

    printf("ChaCha20: %s\n", !memcmp(out, exp, sizeof(exp)) ? "OK" : "FAIL");
    return 0;
}