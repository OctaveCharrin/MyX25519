
#include <gmp.h>

#include "curve25519.h"
#include "utils.h"


void decodeLittleEndian(char const *b, int const bits, mpz_t out){
    LeByteToMPZ((unsigned char *)b, (bits+7)/8, out);
}


void decodeUCoordinate(char const *u, int const bits, mpz_t out){
    int len = (bits+7)/8;
    unsigned char tmp[32];
    HexStringToBytes(u, tmp);
    tmp[31] &= ~(1<<7);
    decodeLittleEndian(tmp, bits, out);
}


void encodeUCoordinate(mpz_t u, int const bits, char *out){
    mpz_t p;
    mpz_init_set(p, 2);
    mpz_pow_ui(p, p, 255);
    mpz_sub_ui(p, p, 19);

    mpz_mod(u, u, p);
    MPZToLeHexString(u, out, (bits+7)/8);
}

void decodeScalar25519(char const *k, mpz_t out){
    char k_list[32];
    HexStringToBytes(k, k_list);
    k_list[0] &= 248;
    k_list[31] &= 127;
    k_list[31] |= 64;
    decodeLittleEndian(k_list, 255, out);
}


