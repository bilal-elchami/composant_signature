#include "Signature.h"
#include <iostream>
using namespace std;

int main(){
	Signature *signature = new Signature();
	
	signature->generateKeys();
	cout << "Private Key : " << signature->getPrivateKey() << endl;
	cout << "Public Key : " << signature->getPublicKey() << endl;

	string data = "projet composant";
	// string signatureStr = signature->signMessage(data, signature->getPrivateKey());
	string signatureStr = signature->signMessage(data, signature->getPrivateKey());
	cout << "Signature [" << data << "] : " << signatureStr << endl;

	bool isValidated = signature->validateSignature(data, signature->getPublicKey(), signatureStr);
	cout << "Is validated ? " << isValidated << endl;

	signatureStr = "797c616b290eba27d8e7a13dc044ac641a3b8cab5cecb57dd98b518744dfe3ab42bf2a530c02f8c951855f3217fb55ae600e414c3a0040227d6091aecc62242d";
	isValidated = signature->validateSignature(data, signature->getPublicKey(), signatureStr);
	cout << "Is validated (with a wrong signature) ? " << isValidated << endl;
	return 0;
}