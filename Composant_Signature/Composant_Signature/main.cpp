#include "Signature.h"
#include <iostream>

using namespace std;

int main(){
	Signature *signature = new Signature();
	
	signature->generateKeys();
	cout << "Private Key : " << signature->getPrivateKey() << endl;
	cout << "Public Key : " << signature->getPublicKey() << endl;

	string data = "projet composant";
	string signatureStr = signature->signMessage(data, signature->getPrivateKey());
	cout << "Signature[" << data << "] : " << signature << endl;
	
	bool isValidated = signature->validateSignature(data, signature->getPublicKey(), signatureStr);
	cout << "Is validated ?" << isValidated << endl;
	return 0;
}