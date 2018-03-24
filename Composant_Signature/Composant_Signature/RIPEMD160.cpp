using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Runtime::InteropServices;
#include <iostream>
#include <cstring>

// Print the byte array in a readable format.
void PrintByteArray(array<Byte>^array)
{
	int i;
	for (i = 0; i < array->Length; i++)
	{
		Console::Write(String::Format("{0:X2}", array[i]));
		if ((i % 4) == 3)
			Console::Write("");

	}
	Console::WriteLine();
}

int main1()
{
	// Initialize a RIPE160 hash object.
	RIPEMD160 ^ myRIPEMD160 = RIPEMD160Managed::Create();
	array<Byte>^hashValue;

	char buf[] = "00D12722DCF29EC393A05358BDF110EFE76C4E3953D363ACAB71C5E88432E436";
	int len = strlen(buf);

	array< Byte >^ byteArray = gcnew array< Byte >(len + 2);

	// convert native pointer to System::IntPtr with C-Style cast  
	Marshal::Copy((IntPtr)buf, byteArray, 0, len);

	//std::istringstream iss

	// Compute the hash of the fileStream.
	hashValue = myRIPEMD160->ComputeHash(byteArray);

	// Write the hash value to the Console.
	PrintByteArray(hashValue);
	return - 1;
}
