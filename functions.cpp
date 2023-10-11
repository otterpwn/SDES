#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <string>
#include <cmath>
#include "functions.h"

using namespace std;

// declare sboxes for reference
const string sboxOne[2][8] = {
	{"101", "010", "001", "110", "011", "100", "111", "000"},
	{"001", "100", "110", "010", "000", "111", "101", "011"}
};

const string sboxTwo[2][8] = {
	{"100", "00", "110", "101", "111", "001", "011", "010"},
	{"101", "011", "000", "111", "110", "010", "001", "100"}
};

// split initial plaintext in left and right portion
string leftPlain(string l){
	return l.substr(0, 6);
}

string rightPlain(string r){
	return r.substr(6, r.length());
}

// perform expand operation on string
string expansion(string r){
	return r.substr(0, 2) + r[3] + r[2] + r[3] + r[2] + r.substr(4, r.length());
}

// convert string to bitset of 8 bits
bitset<8> to_bitset8bit(string s){
	auto binary = [](char c) { return c == '0' || c == '1'; };
	auto not_binary = [binary](char c) { return !binary(c); };

	s.erase(remove_if(begin(s), end(s), not_binary), end(s));

	return bitset<8>(s);
}

// convert bitset of 8 bits to string
string to_string8bit(bitset<8> bs){
	return bs.to_string();
}

// perform xor between two 8 bit bitsets
string xorElems(string r, string key){
	return to_string8bit(to_bitset8bit(r) ^ to_bitset8bit(key));
}

// split xored result into left and right portions
string leftXored(string xored){
	return xored.substr(0, 4);
}
string rightXored(string xored){
	return xored.substr(4, xored.length());
}

// convert binary numbers to binary numbers for sbox reference
int binToDec(int bin){
	int dec = 0, i = 0, rem;

	while (bin != 0) {
		rem = bin % 10;
		bin /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return dec;
}

// apply sbox to string to find result
string sbox(string in, const string sbox [2][8]){
	int row = stoi(in.substr(0, 1));
	int col = binToDec(stoi(in.substr(1, in.length())));

	return sbox[row][col];
}

//bitset<6> to_bitset6bit(string s){
//	auto binary = [](char c) { return c == '0' || c == '1'; };
//	auto not_binary = [binary](char c) { return !binary(c); };
//
//	s.erase(remove_if(begin(s), end(s), not_binary), end(s));
//
//	return bitset<6>(s);
//}
//
//string to_string6bit(bitset<6> bs){
//	return bs.to_string();
//}
//
//string xorFinal(string r, string l){
//	return to_string6bit(to_bitset6bit(r) ^ to_bitset6bit(r));
//}

// function to rotate general key based on round and find roundkey
string rotateKey(string key, int round){
	string expandedKey = key + key;
	string roundKey = expandedKey.substr(round, 8);

	//cout << "Expanded Key: " << expandedKey << endl;
	//cout << "Round key: " << roundKey << endl;
	//cout << "Lenght of round key: " << roundKey.length() << endl;
	
	return roundKey;
}

// calls sdes algorithm
string sdes(string plainText, string roundKey){
	string l, r, exp;
	string xl, xr;
	string sboxOutL, sboxOutR;
	string finalLeft, finalRight, finalC;
	string tempXored;

	// divide plaintext into left and right parts
	l = leftPlain(plainText);	
	r = rightPlain(plainText);	
	//cout << "Left plaintext: " << l << " " << "Right plaintext: " << r << endl;

	// expand right part of pt
	exp = expansion(r);
	//cout << "Expanded right plaintext: " << exp << endl;


	// xor expanded right pt with round key
	auto xored = xorElems(exp, roundKey);
	//cout << "Expanded xored with key: " << xored << endl;

	// xored is divided in two parts of 4 bits each
	xl = leftXored(xored);	
	xr = rightXored(xored);	
	//cout << "Xored left: " << xl << " " << "Xored right: " << xr << endl;

	// apply sbox to xoredLeft and xoredRight
	sboxOutL = sbox(xl, sboxOne);
	sboxOutR = sbox(xr, sboxTwo);
	//cout << "Result of sboxes: " << sboxOutL << " " << sboxOutR << endl;

	// Li = Ri-1
	finalLeft = r;
	// Ri = xorFinal ^ Li-1
	tempXored = xorElems(sboxOutL + sboxOutR, l);
	finalRight = tempXored.substr(2, tempXored.length());
	//cout << "beforeXored: " << tempXored << endl;
	//cout << "finalRight: " << finalRight << endl;

	// put toghether final string
	finalC = finalLeft + finalRight;

	// final output
//	cout << "Plaintext: " << plainText << ", " << plainText.length() << endl;
//	cout << "Round key: " << roundKey <<  ", " << roundKey.length() << endl;
//	cout << "Round ciphertext: " << finalC << ", " << finalC.length() << endl;

	cout << tempXored.substr(2, tempXored.length()) << endl;

	return finalC;
}
