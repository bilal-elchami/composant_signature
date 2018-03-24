#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "uECC.h"

using namespace std;

class Signature {
public:
	Signature();
	//~Signature();

	//ds dll creer la paire de cl� grace aux deux fonctions
	//penser a stocker la cle publique et priv� dans un fichier 
	//la cl� publique peut etre donn�e a tous 
	void generateKeys();
	string getPublicKey();
	string getPrivateKey();

	// string createPublicKey(string private_key);
	// string createPrivateKey();

	//appeler le hasheur
	//crypter avec la cl� priv�
	//donner la cl� publique sur le canal

	//signe message avec la cl� priv�e les donn�es hash : data => hash => hash crypt� 
	//appeler hash dans la fonction
	string signMessage(string data, string private_key);
	//signature , on compare avec la signature en entr�e
	//appeler la fonction verifie ECDSA 
	bool validateSignature(string data, string public_key, string signature);

private:
	string uint8_vector_to_hex_string(const vector<uint8_t>& value);
	vector<uint8_t> string_to_uint8_t(string value);
	string uint8_t_to_string(vector<uint8_t> value);
	void initCurves();
	const struct uECC_Curve_t * curves[5];
	int num_curves = 0;
	string signatureStr;// taille 64 hexadecimal (0_F)
	string privateKey;
	string publicKey;
};