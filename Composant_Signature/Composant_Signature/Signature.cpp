#include "Signature.h"
#include "uECC.h"
#include "Hacheur.h"

KeyChain Signature::generateKeys() {
	uECC_Curve curve = uECC_secp256k1();
	uint8_t _public[64] = { 0 };
	uint8_t _private[32] = { 0 };
	
	if (!uECC_make_key(_public, _private, curve)) {
		cout << "uECC_make_key() failed" << endl;
	}
	
	vector<uint8_t> privateVector(begin(_private), end(_private));
	string private_key = uint8_to_hex_str(privateVector);

	vector<uint8_t> publicVector(begin(_public), end(_public));
	string public_key = uint8_to_hex_str(publicVector);

	KeyChain key_chain(private_key, public_key);
	return key_chain;
}

string Signature::signMessage(string data, string private_key) {
	uECC_Curve curve = uECC_secp256k1();
	string dataHashed = hash(data);
	uint8_t* hash = hex_str_to_uint8(dataHashed.c_str());
	uint8_t* _private = hex_str_to_uint8(private_key.c_str());
	uint8_t sig[64] = { 0 };

	if (!uECC_sign(_private, hash, sizeof(hash), sig, curve)) {
		cout << "uECC_sign() failed" << endl;
	}

	vector<uint8_t> sigVector = fill_vector(sig, 64); 
	return uint8_to_hex_str(sigVector);
}

bool Signature::validateSignature(string data, string public_key, string _signature) {
	uECC_Curve curve = uECC_secp256k1();
	string dataHashed = hash(data);

	uint8_t* hash = hex_str_to_uint8(dataHashed.c_str());
	uint8_t* _public = hex_str_to_uint8(public_key.c_str());
	uint8_t* _sig = hex_str_to_uint8(_signature.c_str());

	if (!uECC_verify(_public, hash, sizeof(hash), _sig, curve)) {
		// uECC_verify() failed
		return false;
	}
	return true;
}

string Signature::uint8_to_hex_str(vector<uint8_t>& v) {
	stringstream ss;
	ss << std::hex << setfill('0');
	vector<uint8_t>::const_iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		ss << setw(2) << static_cast<unsigned>(*it);
	}

	return ss.str();
}

uint8_t* Signature::hex_str_to_uint8(const char* string) {

	if (string == NULL)
		return NULL;

	size_t slength = strlen(string);
	if ((slength % 2) != 0) // must be even
		return NULL;

	size_t dlength = slength / 2;

	uint8_t* data = (uint8_t*)malloc(dlength);

	memset(data, 0, dlength);

	size_t index = 0;
	while (index < slength) {
		char c = string[index];
		int value = 0;
		if (c >= '0' && c <= '9')
			value = (c - '0');
		else if (c >= 'A' && c <= 'F')
			value = (10 + (c - 'A'));
		else if (c >= 'a' && c <= 'f')
			value = (10 + (c - 'a'));
		else
			return NULL;

		data[(index / 2)] += value << (((index + 1) % 2) * 4);

		index++;
	}

	return data;
}

vector<uint8_t> Signature::fill_vector(uint8_t* data, int size) {
	std::vector<uint8_t> out;
	for (int x = 0; x < size; x++)
	{
		out.push_back(data[x]);
	}
	return out;
}

string Signature::hash(string data) {
	Hacheur hacheur = Hacheur();
	string output = hacheur.hacher(data);
	return output;
}