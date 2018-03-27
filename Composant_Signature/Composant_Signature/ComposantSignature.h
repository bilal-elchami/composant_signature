#pragma once
#ifndef COMPOSANT_SIGNATURE_H
#define COMPOSANT_SIGNATURE_H

#ifdef COMPOSANT_SIGNATURE_EXPORTS
#define COMPOSANT_SIGNATURE_INTERFACE __declspec(dllexport)
#else
#define COMPOSANT_SIGNATURE_INTERFACE __declspec(dllimport)
#endif

COMPOSANT_SIGNATURE_INTERFACE KeyChain generateKeys();
COMPOSANT_SIGNATURE_INTERFACE string signMessage(string data, string private_key);
COMPOSANT_SIGNATURE_INTERFACE bool validateSignature(string data, string public_key, string signature);

#endif