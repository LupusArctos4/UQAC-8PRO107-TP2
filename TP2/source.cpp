//Partie en tete
//Nom prenom codeurs : 
// Louis De MILLEVILLE
// Lo�c FAUCQUENOY
//Nom programme : TP n�2
//Created : 24/10/2023
//Last update : 24/10/2023
/*Description :
TP N�1
Automne 2023
Enseignante : Im�ne Benkalai
Date de remise : 10 novembre 2023 avant 23h59
*/

//Partie Clauses d'inclusion
#include <iostream> // lib de lecture �criture
#include <string> // lib pour variable string
#include <math.h> // lib pour les fonctions math�matique
#include <sstream> // lib pour string to int
using namespace std; // utiliser l'espace de noms standard

// Fonction de v�rificateur d'entier
// prend en entr� un string
// et renvoit un entier
int intVerificator(string str) {
	stringstream ss;
	int x;

restartVerif:
	for (int i = 0; i < str.size() - 1; i++) {
		if (isdigit(str[i]) == false) {
			cout << "Ce n'est pas un entier." << endl;
			cout << "Veuillez entrer un entier : ";
			cin >> str;
			goto restartVerif;
		}
	}
	ss << str;
	ss >> x;
	return x;
}


// Fonction principale
int main()
{
	//Partie D�claration de variable
	

	//Partie Instruction
	

	return 0;
}
