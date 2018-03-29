#pragma once
#ifndef KEY_CHAIN_H
#define KEY_CHAIN_H

#ifdef KEY_CHAIN_EXPORTS
#define KEY_CHAIN_INTERFACE __declspec(dllexport)
#else
#define KEY_CHAIN_INTERFACE __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class KeyChain {
public:
	KEY_CHAIN_INTERFACE KeyChain(string private_key, string public_key);
	KEY_CHAIN_INTERFACE void save();
	string private_key;
	string public_key;
};
#endif