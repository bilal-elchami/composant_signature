#include <iostream>
#include <string>
#include "Hacheur.h"

#include <string>

using namespace std;

void test_hash() {
	Hacheur hacheur = Hacheur();
	string input = "Group B is the best ;)";
	string output = hacheur.hacher(input);
	string expected_output = "d62f9f4d0f3abfa000a2c8c8451f72aab42a6c32cc0119d5b2ac02a7a4f34f66";
	cout << "output: " << output << endl;
	if (output.compare(expected_output) == 0) {
		cout << "La methode hash fonctionne parfaitement" << endl;
	} else {
		cout << "ATTENTION : La methode hash ne fonctionne pas bien!" << endl;
	}
}

void test_verifier_hash() {
	Hacheur hacheur = Hacheur();
	string input = "Group B is the best ;)";
	string expected_output = "d62f9f4d0f3abfa000a2c8c8451f72aab42a6c32cc0119d5b2ac02a7a4f34f66";
	string unexpected_output = "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592";

	if (hacheur.verifier_hachage(input, expected_output)) {
		cout << "La methode verifier_hash fonctionne pour un bon output" << endl;
	} else {
		cout << "ATTENTION : La methode verifier_hash ne fonctionne pas bien avec un bon output" << endl;
	}

	if (!hacheur.verifier_hachage(input, unexpected_output)) {
		cout << "La methode verifier_hash fonctionne pour un mauvais output" << endl;
	} else {
		cout << "ATTENTION : La methode verifier_hash ne fonctionne pas bien avec un mauvais output" << endl;
	}
}

int main() {
	test_hash();
	test_verifier_hash();
}