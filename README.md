# SDES
A C++ SDES (Semplified DES) implementation.

The binary requires two inputs:
- a 12 bit plaintext to encrypt
- a 9 bit key to use during the encryption process

### Testing the binary
An option is included in the makefile to allow testing of the binary's functionality using the `sampleInput.in` and `sampleOutput.out` files.
These files contain a test plaintext that will be encrypted and will be printed next to the expected ciphertext.

```
make TEST
[~] Final ciphertext:    000101001101
[~] Expected ciphertext: 000101001101
```

### PoC Statement
Since this project is only a proof of concept, it doens't iterate for 16 times like the original algorithm should and only encrypts for one round instead.
This should be obvious but **this project is not to be used as a proper encryption method**; the cipher has already been cracked decades ago and there is no propagation because of the number of rounds performed.
