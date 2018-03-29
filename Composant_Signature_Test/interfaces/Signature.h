#pragma once
#ifndef COMPOSANT_SIGNATURE_H
#define COMPOSANT_SIGNATURE_H

#ifdef COMPOSANT_SIGNATURE_EXPORTS
#define COMPOSANT_SIGNATURE_INTERFACE __declspec(dllexport)
#else
#define COMPOSANT_SIGNATURE_INTERFACE __declspec(dllimport)
#endif

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "KeyChain.h"
using namespace std;

class Signature {
public:
	COMPOSANT_SIGNATURE_INTERFACE static KeyChain generateKeys();
	COMPOSANT_SIGNATURE_INTERFACE static string signMessage(string data, string private_key);
	COMPOSANT_SIGNATURE_INTERFACE static bool validateSignature(string data, string public_key, string signature);
private:
	COMPOSANT_SIGNATURE_INTERFACE static string hash(string data);
	COMPOSANT_SIGNATURE_INTERFACE static string uint8_to_hex_str(vector<uint8_t>& value);
	COMPOSANT_SIGNATURE_INTERFACE static uint8_t* hex_str_to_uint8(const char* string);
	COMPOSANT_SIGNATURE_INTERFACE static vector<uint8_t> fill_vector(uint8_t* data, int size);
};

#endif
