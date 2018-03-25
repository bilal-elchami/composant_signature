#pragma once
#include <string>
#include "KeyChain.h"
using namespace std;

KeyChain generateKeys();
string signMessage(string data, string private_key);
bool validateSignature(string data, string public_key, string signature);