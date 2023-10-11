#include "functions.h"

using namespace std;

int main(){
	string plainText, key;
	string roundKey;

	// get input plaintext --> 12 bits
	cout << "[?] Plaintext: ";
	cin >> plainText;

	while (plainText.length() != 12){
		cout << "[!] Plaintext has to be of length 12." << endl;
		cout << "[?] Plaintext: ";
		cin >> plainText;
	}

	// get input key --> 9 bits
	cout << "Key: ";
	cin >> key;

	while (key.length() != 9){
		cout << "[!] Key has to be of length 9." << endl;
		cout << "[?] Key: ";
		cin >> key;
	}

	roundKey = rotateKey(key, 1);
	plainText = sdes(plainText, roundKey);

	cout << "[~] Final ciphertext:	 " << plainText << endl;

	return 0;
}
