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
#include "uECC.h"
#include "KeyChain.h"
using namespace std;

COMPOSANT_SIGNATURE_INTERFACE class Signature {
public:
	static KeyChain generateKeys();
	static string signMessage(string data, string private_key);
	static bool validateSignature(string data, string public_key, string signature);
private:
	static string hash(string data);
	static string uint8_to_hex_str(vector<uint8_t>& value);
	static uint8_t* hex_str_to_uint8(const char* string);
	static vector<uint8_t> fill_vector(uint8_t* data, int size);
};

#endif
