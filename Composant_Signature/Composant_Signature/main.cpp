#include "Signature.h"
#include <iostream>

using namespace std;

int main2(){
	Signature *signature = new Signature();
	string privateKey = signature->createPrivateKey();
	string publicKey = signature->createPublicKey(privateKey);
	cout << privateKey << endl;
	cout << publicKey << endl << endl;
	return 0;
}