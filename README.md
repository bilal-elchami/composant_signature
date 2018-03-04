# Projet Composant

## Composant 6 - Signature

La signature numérique permet au bénéficiaire de la transaction de s’assurer qu’elle provient bien d’un émetteur connu à l’avance. En d’autres termes, la signature numérique certifie l'identité d’un émetteur d’une transaction et donc de ne pas accepter de transactions frauduleuses ou d’origine inconnue.

En effet, le bénéficiaire, à l’aide de la clé publique fourni par l’émetteur, peut être certain de l’origine de la transaction. L'émetteur va hacher la transaction puis chiffrer le hachage obtenu avec une clé privée. Pour donner suite à cela, il envoie au bénéficiaire la transaction, le hachage correspondant ainsi que la clé publique liée à la clé privée.

Le bénéficiaire déchiffre le transaction hachage de la transaction et s’assure ainsi de l’origine de celle-ci. Il compare à posteriori le hachage reçu avec le résultat du hachage de la transaction (non hachée) reçue.
