#include "Signature.h"
#include <iostream>
using namespace std;

std::vector<char> HexToBytes(const std::string& hex) {
	std::vector<char> bytes;

	for (unsigned int i = 0; i < hex.length(); i += 2) {
		std::string byteString = hex.substr(i, 2);
		char byte = (char)strtol(byteString.c_str(), NULL, 16);
		bytes.push_back(byte);
	}

	return bytes;
}


vector<uint8_t> test(string in) {
	
	size_t len = in.length();

	std::vector<uint8_t> out;
	for (size_t i = 0; i < len; i += 2) {
		std::istringstream strm(in.substr(i, 2));
		uint8_t x;
		strm >> std::hex >> x;
		out.push_back(x);
	}
	// "out" contains the solution
	return out;
}


uint8_t* datahex(char* string) {

	if (string == NULL)
		return NULL;

	size_t slength = strlen(string);
	if ((slength % 2) != 0) // must be even
		return NULL;

	size_t dlength = slength / 2;

	uint8_t* data = (uint8_t*) malloc(dlength);

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

string asd(const vector<uint8_t>& v) {
	stringstream ss;
	ss << std::hex << setfill('0');
	vector<uint8_t>::const_iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		ss << setw(2) << static_cast<unsigned>(*it);
	}

	return ss.str();
}

vector<uint8_t> fill(uint8_t* data, int size) {
	std::vector<uint8_t> out;
	for (int x = 0; x < size; x++)
	{
		out.push_back(data[x]);
	}
	return out;
}

int main(){
	Signature *signature = new Signature();
	
	signature->generateKeys();
	cout << "Private Key : " << signature->getPrivateKey() << endl;
	cout << "Public Key : " << signature->getPublicKey() << endl;

	string data = "projet composant";
	uint8_t* sig = signature->signMessage(data, signature->getPrivateKey());
	cout << "[" << data << "] : " << sig << endl;
	
	bool isValidated = signature->validateSignature(data, signature->getPublicKey(), sig);
	cout << "Is validated ?" << isValidated << endl;
	
	//vector<char> privateVector = HexToBytes("3E92D13BE9CDC533A5801ABD15904EBFD4323973F057C2A11245B0C690341ABE");
	uint8_t* result = { 0 };
	result = datahex("eb03ea3eaee6236089ab1f94445f02bab5d2a9f5f7735814efa95aadd0cb0259944309f53ff4d10d8d54d6c5eb5d6f3400000000000000000000000000000000");
	for (int asd = 0; asd < 64; asd++)
	{
		cout << "value of a: " << unsigned(result[asd]) << endl;
	}

	vector<uint8_t> privateVector = fill(result, 64);

	//cout << privateVector.data();

	string hexval = asd(privateVector);

	cout << hexval << endl;
	cout << "eb03ea3eaee6236089ab1f94445f02bab5d2a9f5f7735814efa95aadd0cb0259944309f53ff4d10d8d54d6c5eb5d6f3400000000000000000000000000000000" << endl;

	return 0;
}