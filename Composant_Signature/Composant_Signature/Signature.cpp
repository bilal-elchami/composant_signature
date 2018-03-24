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
	uint8_t _private[32] = { 0 };
	uint8_t _public[64] = { 0 };
	
	for (int c = 0; c < num_curves; ++c) {
		if (!uECC_make_key(_public, _private, curves[c])) {
			cout << "uECC_make_key() failed" << endl;
		}
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

string Signature::signMessage(string data, string private_key) {
	uint8_t* hash = string_to_uint8_t(data).data();
	uint8_t* _private = string_to_uint8_t(private_key).data();

	uint8_t sig[64] = { 0 };
	vector<uint8_t> sigVectorBefore(begin(sig), end(sig));

	for (int c = 0; c < num_curves; ++c) {
		if (!uECC_sign(_private, hash, sizeof(hash), sig, curves[c])) {
			cout << "uECC_sign() failed" << endl;
		}
	}
	vector<uint8_t> sigVectorAfter(begin(sig), end(sig));
	signatureStr = uint8_vector_to_hex_string(sigVectorAfter);
	return signatureStr;
}

bool Signature::validateSignature(string data, string public_key, string signature) {
	uint8_t* hash = string_to_uint8_t(data).data();
	uint8_t* _public = string_to_uint8_t(public_key).data();
	uint8_t* _signature = string_to_uint8_t(signature).data();

	for (int c = 0; c < num_curves; ++c) {
		if (!uECC_verify(_public, hash, sizeof(hash), _signature, curves[c])) {
			cout << "uECC_verify() failed" << endl;
			return false;
		}
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