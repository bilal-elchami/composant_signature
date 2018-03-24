#include "Signature.h"
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

Signature::Signature() {
	signatureStr = "";
}

//Signature::~Signature() {
//	signatureStr = "";
//}

string Signature::createPrivateKey() {
	const char *hex_digits = "0123456789ABCDEF";
	//    int randomValue = rand()+;
	string resultat;

	do {
		//        resultat  = convertisseur.to_hex(randomValue);
		resultat += hex_digits[(rand() % 16)];
	} while (resultat.size() != 16);

	return resultat;
}

string Signature::createPublicKey(string private_key) {
	string resultat;
	for (unsigned int i = 0; i < private_key.size(); i += 2) {
		//get 8 bites or 2 char hexa
		resultat += bin_to_hex(
			bin_complement(
				hex_to_bin(private_key.substr(i, i + 2))
			)
		);
	}
	transform(resultat.begin(), resultat.end(), resultat.begin(), ::toupper);
	return resultat;
}


string Signature::bin_to_hex(string binaryString) {
	bitset<32> bs(binaryString);
	unsigned n = bs.to_ulong();
	stringstream ss;
	ss << hex << n;
	return  (binaryString.compare(0, 4, "0000") == 0) ? "0" + ss.str() : ss.str();
}

string Signature::hex_to_bin(string hexaString) {
	stringstream ss;
	ss << hex << hexaString;
	unsigned n;
	ss >> n;
	bitset<32> b(n);

	return b.to_string().substr(32 - 4 * (hexaString.length()));
}

//Signature Signature::signMessage(string data, string private_key) {
//	return this;
//}

bool Signature::validateSignature(string data, string public_key, string signature) {
	return false;
}

string Signature::bin_complement(string number) {
	for (int i = number.length(), carry = 1; i-- > 0;) {
		number[i] = (char)((number[i] ^ 1) + carry); // flip the bit and add the previous carry
		carry = (number[i] & 2) >> 1;        // save the overflow in the carry variable
		number[i] &= ~2;                 // mask out the overflow
	}
	return number;
}