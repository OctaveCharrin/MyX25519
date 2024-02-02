// curve25519.h

#include <gmp.h>


void decodeLittleEndian(char const *b, int const bits, mpz_t out);

void decodeUCoordinate(char const *u, int const bits, mpz_t out);

void encodeUCoordinate(mpz_t u, int const bits, char *out);

void decodeScalar25519(char const *k, mpz_t out);