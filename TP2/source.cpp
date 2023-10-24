//Partie en tete
//Nom prenom codeurs : 
// Louis De MILLEVILLE
// Loic FAUCQUENOY
//Nom programme : TP n'2
//Created : 24/10/2023
//Last update : 24/10/2023
/*Description :
TP N'1
Automne 2023
Enseignante : Imene Benkalai
Date de remise : 10 novembre 2023 avant 23h59
*/

//Partie Clauses d'inclusion
#include <iostream> // lib de lecture ecriture
#include <string> // lib pour variable string
#include <math.h> // lib pour les fonctions mathematique
#include <sstream> // lib pour string to int
using namespace std; // utiliser l'espace de noms standard

// Fonction de verificateur d'entier
// prend en entre un string
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
	/* todo a modifier


	*/
	
	// Introduction du TP
	cout << " /$$$$$$$$ /$$$$$$$    /$$         /$$$$$$$                   /$$$$$$                  " << endl;
	cout << "|__  $$__/| $$__  $$ /$$$$        | $$__  $$                 /$$__  $$ /$$       /$$   " << endl;
	cout << "   | $$   | $$    $$|_  $$        | $$    $$  /$$$$$$       | $$   __/| $$      | $$   " << endl;
	cout << "   | $$   | $$$$$$$/  | $$        | $$  | $$ /$$__  $$      | $$    /$$$$$$$$ /$$$$$$$$" << endl;
	cout << "   | $$   | $$____/   | $$        | $$  | $$| $$$$$$$$      | $$   |__  $$__/|__  $$__/" << endl;
	cout << "   | $$   | $$        | $$        | $$  | $$| $$_____/      | $$    $$| $$      | $$   " << endl;
	cout << "   | $$   | $$       /$$$$$$      | $$$$$$$/|  $$$$$$$      |  $$$$$$/|__/      |__/   " << endl;
	cout << "   |__/   |__/      |______/      |_______/  \_______/       \______/                  \n\n\n" << endl;

	cout << "Automne 2023 - Groupe 01" << endl;
	cout << "Enseignante : Imène Benkalai" << endl;
	cout << "Date de remise : 10 novembre 2023 avant 23h59" << endl;

	//Partie Déclaration de variable
	string stringChoixPartie;
	int intChoixPartie;

	//Partie Instruction
	do{
		stringChoixPartie = "Veuillez choisir l'une des parties du TP en fonction de la question ou 0 pour arreter la lecture des questions :";
		cout << "" << endl << stringChoixPartie << endl ;
		cin >> intChoixPartie;
		switch (intChoixPartie) {
		case 0:
			cout << "Arret de la lecture des questions." << endl;
			goto exitLoop;
		case 1:
			cout << "Partie 1 :" << endl;
			partie1();
			break;
		case 2:
			cout << "Partie 2 :" << endl;
			partie2();
			break;
		case 3:
			cout << "Partie 3 :" << endl;
			partie3();
			break;
		case 4:
			cout << "Partie 4 :" << endl;
			partie4();
			break;
		case 5:
			cout << "Partie 5 :" << endl;
			partie5();
			break;
		case 8:
			cout << "Partie  :" << endl;
			partie6();
			break;
		case 11:
			cout << "Partie 11 :" << endl;
			partie7();
			break;
		}
		case 13:
			cout << "Partie 13 :" << endl;
			partie7();
			break;
		}
	} while (true);
	exitLoop:;
	return 0;
}
