#include "Signature.h"

Signature::Signature() {
	initCurves();
	signatureStr = "";
}

void Signature::initCurves() {
#if uECC_SUPPORTS_secp160r1
	curves[num_curves++] = uECC_secp160r1();
#endif
#if uECC_SUPPORTS_secp192r1
	curves[num_curves++] = uECC_secp192r1();
#endif
#if uECC_SUPPORTS_secp224r1
	curves[num_curves++] = uECC_secp224r1();
#endif
#if uECC_SUPPORTS_secp256r1
	curves[num_curves++] = uECC_secp256r1();
#endif
#if uECC_SUPPORTS_secp256k1
	curves[num_curves++] = uECC_secp256k1();
#endif
}

void Signature::generateKeys() {
	// uint8_t _public[64] = { 0 };
	// uint8_t _private[32] = { 0 };
	
	int c = 1;
		if (!uECC_make_key(_public, _private, curves[c])) {
			cout << "uECC_make_key() failed" << endl;
		}
	

	vector<uint8_t> privateVector(begin(_private), end(_private));
	privateKey = uint8_vector_to_hex_string(privateVector);

	vector<uint8_t> publicVector(begin(_public), end(_public));
	publicKey = uint8_vector_to_hex_string(publicVector);
}

string Signature::getPublicKey() {
	return publicKey;
}

string Signature::getPrivateKey() {
	return privateKey;
}

uint8_t* Signature::signMessage(string data, string private_key) {
	string dataHashed = "A8C8E2042F702DCA60AC688EDCDFC72F6EA535745B2A0FD01EF9506E4839C134";
	uint8_t* hash = string_to_uint8_t(dataHashed).data();
	cout << "Hash in sign message " << hash << endl;
	// uint8_t sig[64] = { 0 };
	int x = 1;
	if (!uECC_sign(_private, hash, sizeof(hash), sig, curves[x])) {
		cout << "uECC_sign() failed" << endl;
	}

	return sig;
	// vector<uint8_t> sigVector(begin(sig), end(sig));
	// signatureStr = uint8_vector_to_hex_string(sigVector);
	// return signatureStr;
}

bool Signature::validateSignature(string data, string public_key, uint8_t* _signature) {
	string dataHashed = "A8C8E2042F702DCA60AC688EDCDFC72F6EA535745B2A0FD01EF9506E4839C134";
	uint8_t* hash = string_to_uint8_t(dataHashed).data();
	cout << "Hash in validate signature " << hash << endl;
	// uint8_t* _public = string_to_uint8_t(public_key).data();
	// uint8_t* _signature = string_to_uint8_t(signature).data();
	int y = 1;
	if (!uECC_verify(_public, hash, sizeof(hash), sig, curves[y])) {
		cout << "uECC_verify() failed" << endl;
		return false;
	}
	return true;
}

string Signature::uint8_vector_to_hex_string(const vector<uint8_t>& v) {
	stringstream ss;
	ss << std::hex << setfill('0');
	vector<uint8_t>::const_iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		ss << setw(2) << static_cast<unsigned>(*it);
	}

	return ss.str();
}

vector<uint8_t> Signature::string_to_uint8_t(string value) {
	vector<uint8_t> vec(value.begin(), value.end());
	return vec;


}

string Signature::uint8_t_to_string(vector<uint8_t> value) {
	string str(value.begin(), value.end());
	return str;
}