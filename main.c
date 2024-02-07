#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "utils.h"
#include "curve25519.h"

int main(int argc, char *argv[]){
    
    if ((argc != 2) && (argc != 3)){
        fprintf(stderr, "Usage: %s <32-byte m> [<32-byte u>]\n", argv[0]);
        return 1;
    }

    char *m = malloc(65*sizeof(*m));
    char *u = malloc(65*sizeof(*u));
    m[64] = '\0';
    u[64] = '\0';

    size_t mn = strlen(argv[1]);
    if (mn < 64){
        fprintf(stderr, "Error: m must be at least 64 hexadecimal characters.\n");
        return 1;
    }
    strncpy(m, argv[1], 64);

    // Extra characters are truncated
    if (argc == 2){
        strncpy(u, "0900000000000000000000000000000000000000000000000000000000000000\0", 66); // this is to avoid warning from strncpy
    }
    if (argc == 3){
        size_t un = strlen(argv[2]);
        if (un < 64){
            fprintf(stderr, "Error: u must be at least 64 hexadecimal characters.\n");
            return 1;
        }
        strncpy(u, argv[2], 64);
    }

    mpz_t out;
    mpz_init(out);
    X25519(m, u, out);
    char output[66];
    MPZToLeHexString(out, output, 32);
    printf("%s\n", output);

    // Test #3 of RFC7748
    //*******************
    // for (int i=2; i<=1000; i+=1){
    //     strcpy(u, m);
    //     strcpy(m, output);
    //     X25519(m, u, out);
    //     MPZToLeHexString(out, output, 32);
    // }
    // printf("Ater 1000 iterations:\n");
    // printf("%s\n", output);

    mpz_clear(out);
    free(m);
    free(u);
    return 0;
}