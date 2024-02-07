# MyX25519
C implementation of "X25519" key exchange according to RFC7748

## Initialization

You need to have [GMP](https://gmplib.org/) installed on your computer to build the program.

Run the following command in the root directory to build the program
```bash
make
```
To clean the forlder use:
```bash
make clean
```

## Usage

To create a public key corresponding to the secret `m`, run the following command:

```bash
./x25519 m
```
Where `m` is a 64-hexadecimal character string. Any extra character are ignored.

To generate the shared secret from your secret `m` and a public key `u`:
```bash
./x25519 m u
```
Where `u` is also a 64-hexadecimal character string. Any extra character are also ignored.

### Author
Octave Charrin