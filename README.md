# Projet Composant

## Liens github de tous les composants :
Composant 1 (fichier) : https://github.com/lifakpo/Composant_1

Composant 2 (wallet) : https://github.com/GermanicusDM2IF/Composant_Wallet

Composant 3 (mineur) : https://github.com/oauscher/groupe_c_rendu_final

Composant 4 (hacheur) : https://github.com/kharrazDauphine/Composant4

Composant 5 (verificateur) : https://github.com/Obroo/Composant5_Dev

Composant 6 (signature) : https://github.com/bilal-elchami/composant_signature

## Composant 6 - Signature

### Description
La signature numérique permet au bénéficiaire de la transaction d’assurer qu’elle provient bien d’un émetteur connu à l’avance. En d’autres termes, la signature numérique certifie l'identité d’un émetteur d’une transaction cela permet ne pas accepter des transactions frauduleuses ou d’origine inconnue.

En effet, le bénéficiaire, à l’aide de la clé publique fourni par l’émetteur, peut être certain de l’origine de la transaction. L'émetteur va hacher la transaction puis chiffrer le hachage obtenu avec une clé privée. suite à cela, il envoie au bénéficiaire la transaction, le hachage correspondant ainsi que la clé publique liée à la clé privée.

Le bénéficiaire déchiffre le transaction hachage de la transaction et s’assure ainsi de l’origine de celle-ci. Il compare à posteriori le hachage reçu avec le résultat du hachage de la transaction (non hachée) reçue.

### Signatures des méthodes
Les méthodes du composant Signature sont les suivants :
    
    KeyChain generateKeys();
    
    string signMessage(string data, string private_key);
    
    bool validateSignature(string data, string public_key, string signature);
    
avec KeyChain étant une classe qui contient 2 attribut de type string : 
    
    string private_key
    
    string public_key

Vous pouvez sauvegarder les 2 clés : `private_key` et `public_key` dans 2 fichiers séparés : `private.key` et `public.key` en utilisant la méthode `save()` de la classe KeyChain
