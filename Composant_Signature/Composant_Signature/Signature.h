#pragma once
#include <string>

using namespace std;

class Signature {
public:
	Signature();
	~Signature();

	//ds dll creer la paire de cl� grace aux deux fonctions
	//penser a stocker la cle publique et priv� dans un fichier 
	//la cl� publique peut etre donn�e a tous 
	string createPublicKey();
	string createPrivateKey(string public_key);

	//appeler le hasheur
	//crypter avec la cl� priv�
	//donner la cl� publique sur le canal

	//signe message avec la cl� priv�e les donn�es hash : data => hash => hash crypt� 
	//appeler hash dans la fonction
	Signature signMessage(string data, string private_key);
	//signature , on compare avec la signature en entr�e
	//appeler la fonction verifie ECDSA 
	bool validateSignature(string data, string public_key, string signature);

private:
	string signatureStr;// taille 64 hexadecimal (0_F)
};