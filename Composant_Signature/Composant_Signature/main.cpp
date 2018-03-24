#include "Signature.h"
#include <iostream>
using namespace std;

int main(){
	Signature *signature = new Signature();
	
	signature->generateKeys();
	cout << "Private Key : " << signature->getPrivateKey() << endl;
	cout << "Public Key : " << signature->getPublicKey() << endl;

	string data = "projet composant";
	uint8_t* sig = signature->signMessage(data, signature->getPrivateKey());
	cout << "[" << data << "] : " << sig << endl;
	
	bool isValidated = signature->validateSignature(data, signature->getPublicKey(), sig);
	cout << "Is validated ?" << isValidated << endl;
	return 0;
}