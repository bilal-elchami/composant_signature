#include "KeyChain.h"

KeyChain::KeyChain(string _private_key, string _public_key) : private_key(_private_key), public_key(_public_key) {
	
}

void KeyChain::save() {
	ofstream privateOutputFile("private.key");
	privateOutputFile << private_key;
	privateOutputFile.close();
	cout << "File 'private.key' containing private key is created" << endl;

	ofstream publicOutputFile("public.key");
	publicOutputFile << public_key;
	publicOutputFile.close();
	cout << "File 'public.key' containing public key is created" << endl << endl;
}
