#pragma once
#include <string>

using namespace std;

class Signature {
public:
	Signature();
	//~Signature();

	//ds dll creer la paire de clé grace aux deux fonctions
	//penser a stocker la cle publique et privé dans un fichier 
	//la clé publique peut etre donnée a tous 
	string createPublicKey(string private_key);
	string createPrivateKey();

	//appeler le hasheur
	//crypter avec la clé privé
	//donner la clé publique sur le canal

	//signe message avec la clé privée les données hash : data => hash => hash crypté 
	//appeler hash dans la fonction
	Signature signMessage(string data, string private_key);
	//signature , on compare avec la signature en entrée
	//appeler la fonction verifie ECDSA 
	bool validateSignature(string data, string public_key, string signature);

private:
	string signatureStr;// taille 64 hexadecimal (0_F)
	string bin_to_hex(string binaryString);
	string hex_to_bin(string binaryString);
	string bin_complement(string number);
};