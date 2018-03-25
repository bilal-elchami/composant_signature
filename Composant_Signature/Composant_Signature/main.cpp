#include "Signature.h"
#include <iostream>
using namespace std;

int main(){
	
	// Generating the private and public keys
	cout << "===============" << endl;
	cout << "Generating keys" << endl;
	cout << "===============" << endl << endl;
	KeyChain key = Signature::generateKeys();

	cout << "===========" << endl;
	cout << "Keys Values" << endl;
	cout << "===========" << endl << endl;

	// Printing each key value
	cout << "Private Key : " << key.private_key << endl;
	cout << "Public Key : " << key.public_key << endl << endl;

	cout << "========================" << endl;
	cout << "Saving the keys in files" << endl;
	cout << "========================" << endl << endl;
	// The save functions store each key in a file on your pc
	key.save();

	// Siging the following message by passing it to the sign function with the private key
	// A signature is returned by the fuction as an hexadecimal value stored in a string
	string data = "projet composant";
	
	cout << "=============================" << endl;
	cout << "Siging " << data << " value" << endl;
	cout << "=============================" << endl << endl;

	string signature_result = Signature::signMessage(data, key.private_key);
	cout << "Signature ['" << data << "'] : " << signature_result << endl << endl;
	
	// To check if the message is valid, we pass it to the validateSignature function
	// as well as the public key and the signature value (All params are string values)
	bool isValidated = Signature::validateSignature(data, key.public_key, signature_result);
	cout << "Is validated ? " << isValidated << endl << endl;

	cout << "===========================================================" << endl;
	cout << "Verifying " << data << " value with a non-valid signature" << endl;
	cout << "===========================================================" << endl << endl;

	// Verifying a message with a non-valid signature
	signature_result = "797c616b290eba27d8e7a13dc044ac641a3b8cab5cecb57dd98b518744dfe3ab42bf2a530c02f8c951855f3217fb55ae600e414c3a0040227d6091aecc62242d";
	isValidated = Signature::validateSignature(data, key.public_key, signature_result);
	cout << "Is validated (with a wrong signature) ? " << isValidated << endl << endl;
	return 0;
}