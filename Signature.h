#pragma once
#include "hash.h"
Signature{
	public String signatureStr;// taille 64 hexadecimal (0_F)
public : 
	Signature();
	//ds dll creer la paire de clé grace aux deux fonctions
	//penser a stocker la cle publique et privé dans un fichier 
	//la clé publique peut etre donnée a tous 
	String createPublicKey();
	String createPrivateKey(String public_key);

	//appeler le hasheur
	//crypter avec la clé privé
	//donner la clé publique sur le canal
	
	//signe message avec la clé privée les données hash : data => hash => hash crypté 
	//appeler hash dans la fonction
	Signature signMessage(String data, String private_key);
	//signature , on compare avec la signature en entrée
	//appeler la fonction verifie ECDSA 
	boolean validateSignature(String data, String public_key,String signature);

}
