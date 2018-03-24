//#include <iostream>
//#include <iomanip>
//#include <fstream> 
//#include <stdint.h>
#include <string>
//#define ROL(x, n) (((x) << (n)) | ((x) >> (32-(n))))
//using namespace std;
//
//uint32_t R1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15,
//7, 4, 13, 1, 10, 6, 15, 3, 12, 0, 9, 5, 2, 14, 11, 8,
//3, 10, 14, 4, 9, 15, 8, 1, 2, 7, 0, 6, 13, 11, 5, 12,
//1, 9, 11, 10, 0, 8, 12, 4, 13, 3, 7, 15, 14, 5, 6, 2,
//4, 0, 5, 9, 7, 12, 2, 10, 14, 1, 3, 8, 11, 6, 15, 13 };
//uint32_t R2[] = { 5,14, 7, 0, 9, 2, 11, 4, 13, 6, 15, 8, 1, 10, 3, 12,
//6, 11, 3, 7, 0, 13, 5, 10, 14, 15, 8, 12, 4, 9, 1, 2,
//15, 5, 1, 3, 7, 14, 6, 9, 11, 8, 12, 2, 10, 0, 4, 13,
//8, 6, 4, 1, 3, 11, 15, 0, 5, 12, 2, 13, 9, 7, 10, 14,
//12, 15, 10, 4, 1, 5, 8, 7, 6, 2, 13, 14, 0, 3, 9, 11 };
//uint32_t S1[] = { 11, 14, 15, 12, 5, 8, 7,9, 11, 13, 14, 15, 6, 7, 9, 8,
//7, 6, 8, 13, 11, 9, 7, 15, 7, 12, 15, 9, 11, 7, 13, 12,
//11, 13, 6, 7, 14, 9, 13, 15, 14, 8, 13, 6, 5, 12, 7, 5,
//11, 12, 14, 15, 14, 15, 9, 8, 9, 14, 5, 6, 8, 6, 5, 12,
//9, 15, 5, 11, 6, 8, 13, 12, 5, 12, 13, 14, 11, 8, 5, 6 };
//uint32_t S2[] = { 8, 9, 9, 11, 13, 15, 15, 5,7, 7, 8, 11, 14, 14, 12, 6,
//9, 13, 15, 7, 12, 8, 9, 11, 7, 7, 12, 7, 6, 15, 13, 11,
//9, 7, 15, 11, 8, 6, 6, 14, 12, 13, 5, 14, 13, 13, 7, 5,
//15, 5, 8, 11, 14, 14, 6, 14, 6, 9, 12, 9, 12, 5, 15, 8,
//8, 5, 12, 9, 12, 5, 14, 6, 8, 13, 6, 5, 15, 13, 11, 11 };
//uint32_t h0 = 0x67452301, h1 = 0xEFCDAB89, h2 = 0x98BADCFE, h3 = 0x10325476, h4 = 0xC3D2E1F0, **X;
//uint32_t F(uint32_t j, uint32_t x, uint32_t y, uint32_t z)
//{
//	if (j <= 15)
//	{
//		return x^y^z;
//	}
//	else if (j <= 31)
//	{
//		return (x&y) | (~x&z);
//	}
//	else if (j <= 47)
//	{
//		return (x | ~y) ^ z;
//	}
//	else if (j <= 63)
//	{
//		return (x&z) | (y&~z);
//	}
//	else if (j <= 79)
//	{
//		return x ^ (y | ~z);
//	}
//	else
//		return NULL;
//}
//uint32_t K1(uint32_t j)
//{
//	if (j <= 15)
//	{
//		return 0x00000000;
//	}
//	else if (j <= 31)
//	{
//		return 0x5A827999;
//	}
//	else if (j <= 47)
//	{
//		return 0x6ED9EBA1;
//	}
//	else if (j <= 63)
//	{
//		return 0x8F1BBCDC;
//	}
//	else if (j <= 79)
//	{
//		return 0xA953FD4E;
//	}
//	else
//		return NULL;
//}
//uint32_t K2(uint32_t j)
//{
//	if (j <= 15)
//	{
//		return 0x50A28BE6;
//	}
//	else if (j <= 31)
//	{
//		return 0x5C4DD124;
//	}
//	else if (j <= 47)
//	{
//		return 0x6D703EF3;
//	}
//	else if (j <= 63)
//	{
//		return 0x7A6D76E9;
//	}
//	else if (j <= 79)
//	{
//		return 0x00000000;
//	}
//	else
//		return NULL;
//}
//uint32_t fourBytesToUint(char* array)
//{
//	uint32_t res = 0;
//	res |= ((uint32_t)array[3] << 24) & 0xFF000000;
//	res |= ((uint32_t)array[2] << 16) & 0xFF0000;
//	res |= ((uint32_t)array[1] << 8) & 0xFF00;
//	res |= ((uint32_t)array[0] << 0) & 0xFF;
//	return res;
//}
//uint32_t messageExtension(string theMessage)
//{
//	uint64_t bitSizeOriginMessage = theMessage.size() << 3;
//	theMessage.push_back(-128);
//	while ((theMessage.size() * 8) % 512 != 448)
//		theMessage.push_back(0);
//	uint32_t blocks = (uint32_t)(theMessage.size() / 64) + 1;
//	X = new uint32_t*[blocks];
//	for (int i = 0; i < blocks; i++)
//	{
//		X[i] = new uint32_t[16];
//		for (int j = 0; j < (i == blocks - 1 ? 14 : 16); j++)
//			X[i][j] = fourBytesToUint(&theMessage[(j << 2) + 64 * i]);
//		if (i == blocks - 1)
//		{
//			X[i][14] = bitSizeOriginMessage & 0xFFFFFFFF;
//			X[i][15] = bitSizeOriginMessage >> 32 & 0xFFFFFFFF;
//		}
//	}
//	return blocks;
//}
//uint32_t inv(uint32_t a) {
//	uint32_t b = 0;
//	b |= ((a >> 0) & 0xFF) << 24;
//	b |= ((a >> 8) & 0xFF) << 16;
//	b |= ((a >> 16) & 0xFF) << 8;
//	b |= ((a >> 24) & 0xFF) << 0;
//	return b;
//}
//char* ripemd160Hash(const char *strng)
//{
//
//
//
//	uint16_t blocks = messageExtension(strng);
//	uint32_t A1, B1, C1, D1, E1,
//		A2, B2, C2, D2, E2, T;
//	for (uint32_t i = 0; i <= blocks - 1; i++)
//	{
//		A1 = h0, B1 = h1, C1 = h2, D1 = h3, E1 = h4,
//			A2 = h0, B2 = h1, C2 = h2, D2 = h3, E2 = h4;
//		for (uint32_t j = 0; j <= 79; j++)
//		{
//			T = ROL((A1 + F(j, B1, C1, D1) + X[i][R1[j]] + K1(j)), S1[j]) + E1;
//			A1 = E1, E1 = D1, D1 = ROL(C1, 10), C1 = B1, B1 = T;
//			T = ROL((A2 + F(79 - j, B2, C2, D2) + X[i][R2[j]] + K2(j)), S2[j]) + E2;
//			A2 = E2, E2 = D2, D2 = ROL(C2, 10), C2 = B2, B2 = T;
//		}
//		T = h1 + C1 + D2, h1 = h2 + D1 + E2, h2 = h3 + E1 + A2, h3 = h4 + A1 + B2, h4 = h0 + B1 + C2, h0 = T;
//	}
//
//	cout << "ripemd160Hash: ";
//	cout << setfill('0') << setw(8) << hex << endl << inv(h0) << " " << inv(h1) << " " << inv(h2) << " " << inv(h3) << " " << inv(h4) << endl;
//
//
//	return "proccess complete!";
//
//}
//int main4(int argc, const char * argv[])
//{
//
//	char* error;
//
//	error = new char[256];
//
//	error = ripemd160Hash("3E92D13BE9CDC533A5801ABD15904EBFD4323973F057C2A11245B0C690341ABE");
//	cout << error << endl;
//	return -1;
//}

/* Copyright 2014, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#include "uECC.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <iomanip>


#include <sstream>  // std::ostringstream
#include <algorithm>    // std::copy
#include <iterator> // std::ostream_iterator
#include <iostream> // std::cout
#include <iterator>

using namespace std;


string uint8_vector_to_hex_string(const vector<uint8_t>& v) {
	stringstream ss;
	ss << std::hex << setfill('0');
	vector<uint8_t>::const_iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		ss << setw(2) << static_cast<unsigned>(*it);
	}

	return ss.str();
}

vector<uint8_t> string_to_uint8(string value) {
	std::vector<uint8_t> myVector(value.begin(), value.end());
	return myVector;
}

string completePublicKey(string publicKey) {
	return "04" + publicKey;
}

vector<uint8_t> string_to_uint8_t(string value) {
	vector<uint8_t> vec(value.begin(), value.end());
	return vec;
}

string uint8_t_to_string(vector<uint8_t> value) {
	string str(value.begin(), value.end());
	return str;
}

int main2() {
	int i, c;
	uint8_t privatee[32] = { 0 };
	uint8_t publicc[64] = { 0 };
	uint8_t hash[32] = { 0 };
	uint8_t sig[64] = { 0 };

	const struct uECC_Curve_t * curves[5];
	int num_curves = 0;
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

	printf("Testing 256 signatures\n");
	for (c = 0; c < num_curves; ++c) {
		for (i = 0; i < 1; ++i) {
			printf(".");
			fflush(stdout);

			if (!uECC_make_key(publicc, privatee, curves[c])) {
				printf("uECC_make_key() failed\n");
				return 1;
			}
			
			memcpy(hash, publicc, sizeof(hash));

			if (!uECC_sign(privatee, hash, sizeof(hash), sig, curves[c])) {
				printf("uECC_sign() failed\n");
				return 1;
			}

			if (!uECC_verify(publicc, hash, sizeof(hash), sig, curves[c])) {
				printf("uECC_verify() failed\n");
				return 1;
			}
		}
		printf("\n");
	}

	std::ostringstream ss1;
	std::copy(publicc, publicc + sizeof(publicc), std::ostream_iterator<int>(ss1, ","));


	vector<uint8_t> publicVector(begin(publicc), end(publicc));
	vector<uint8_t> privateVector(begin(privatee), end(privatee));

	cout << "public key: " << uint8_vector_to_hex_string(publicVector) << endl;
	cout << "private key: " << uint8_vector_to_hex_string(privateVector) << endl;

	string bilal = "bilal";

	cout << uint8_t_to_string(string_to_uint8_t(bilal)) << endl;
	vector<uint8_t> a = string_to_uint8_t(bilal);
	uint8_t* test = a.data();
	for (unsigned int asd = 0; asd < sizeof(test) + 1; asd++)
	{
		cout << "value of a: " << test[asd] << endl;
	}

	return 0;
}

