// curve25519.h

#ifndef CURVE25519_H
#define CURVE25519_H

#include <gmp.h>

typedef struct Point{
    
}Point;

void decodeLittleEndian(unsigned char const *b, int const bits, mpz_t out);

void decodeUCoordinate(char const *u, int const bits, mpz_t out);

void encodeUCoordinate(mpz_t u, mpz_t p, int const bits, char *out);

void decodeScalar25519(char const *k, mpz_t out);

void cswap(int swap, mpz_t a, mpz_t b);

void X25519(char const *k, char const *u, mpz_t out);

#endif //CURVE25519_H