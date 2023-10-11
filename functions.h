#include <iostream>
#include <bitset>
#include <string>

using namespace std;

#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 

string sdes(string plainText, string roundKey); // sdes function
string leftPlain(string l); // return first 6 chars of plaintext
string rightPlain(string r); // return last 6 chars of plaintext
string expansion(string r); // expansion function
bitset<8> to_bitset8bit(string s); // cast 8 bit to bitset
string to_string8bit(bitset<8> bs); // cast 8 bit bitset to string
string xorElems(string r, string key); // xor two strings converted to bitsets
string leftXored(string xored); // return first 4 chars of xored
string rightXored(string xored); // return last 4 chars of xored
int binToDec(int bin); // convert int from binary to decimal
string sbox(string in, const string sbox[2][8]); // emulate sbox
bitset<6> to_bitset6bit(string s); // cast 8 bit to bitset
string to_string6bit(bitset<6> bs); // cast 8 bit bitset to string
string xorFinal(string r, string l); // final xor function
string rotateKey(string key, int round); // rotate key based on round

#endif
