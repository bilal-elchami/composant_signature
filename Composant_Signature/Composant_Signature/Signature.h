#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "uECC.h"
#include "KeyChain.h"
using namespace std;

class Signature {
public:
	KeyChain generateKeys();
	string signMessage(string data, string private_key);
	bool validateSignature(string data, string public_key, string signature);
private:
	string hash(string data);
	string uint8_to_hex_str(vector<uint8_t>& value);
	uint8_t* hex_str_to_uint8(const char* string);
	vector<uint8_t> fill_vector(uint8_t* data, int size);
	string signatureStr;
};