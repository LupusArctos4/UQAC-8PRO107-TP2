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
#include <time.h> // lib pour manipuler des dates et heures = ctime
#include <fstream> // lib pour manipuler des fichiers
using namespace std; // utiliser l'espace de noms standard

// Fonction de verificateur d'entier
// prend en entre un string
// et renvoit un entier
int intVerificator(string str) {
	stringstream ss;
	int x;

	restartVerif: //goto
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


// Question 1
// programme qui renvoie le nombre de jour qu'il y a dans un mois
void partie1() {
	const int nbMois = 12;
	string nomMois[nbMois] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Decembre"};
	int nbJourInMois[nbMois] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	string numeroMoisString;

	cout << "Veuillez entrer le numero d'un mois pour connaitre le nombre de jour dans ce dernier :";
	cin >> numeroMoisString;
	/* todo
	* verifier qu'il est dans [1;12]
	* verifier que c'etait bien comme ca que j'avais ecrit la verification de int
	*/
	int numeroMois = intVerificator(numeroMoisString);
	cout << "Pour le mois numero " << numeroMoisString << " qui correspond au mois de " << nomMois[numeroMois - 1] <<
		", ce mois est de " << nbJourInMois[numeroMois - 1] << " jours." << endl;
}

// Question 2
// programme qui renvoie les puissances de 2 comprises entre 1 et 32 000
// sous le format : 2^x = y
void partie2() {
	/*todo
	*Voir si on peut aligner par rapport à la fin plutôt que le début
	*/
	int indexMax = 0;
	double tabResults[100];
	int i = -1;

	//On calcule d'abord les puissances de 2 jusqu'à obtenir une valeur supérieure à 32 000
	do
	{
		i++;
		tabResults[i] = pow(2, i);
	} while (tabResults[i] < 32000);

	indexMax = i - 1;

	//On affiche les résultats
	for (int j = 0; j <= indexMax; j++)
	{
		//Cas d'un indice pair --> colonne de gauche
		if (j % 2 == 0)
		{
			cout << "2^\t" << j << "\t=" << "\t" << tabResults[j];
		}
		//Cas d'un indice impair
		else
		{
			cout << "\t2^\t" << j << "\t=" << "\t" << tabResults[j] << endl;
		}
	}
}

// Question 3
// programme qui renvoie la moyenne, le min et le max de 5 entiers entre par l'utilisateur
float moyenne(int tableau[5], int size) {
	float somme = 0;
	cout << size;
	for (int i = 0; i < size; i++) {
		somme += tableau[i];
	}
	return somme / size;
}
int minimum(int tableau[5], int size) {
	int minimum = tableau[0];
	for (int i = 0; i < size; i++) {
		if (minimum > tableau[i]) {
			minimum = tableau[i];
		}
	}
	return minimum;
}
int maximum(int tableau[5], int size) {
	int maximum= tableau[0];
	for (int i = 0; i < size; i++) {
		if (maximum < tableau[i]) {
			maximum = tableau[i];
		}
	}
	return maximum;
}
void partie3() {
	string entierString;
	int entierTableau[5];
	int size = sizeof(entierTableau) / sizeof(entierTableau[0]);

	for (int i = 0; i < size; i++) {
		cout << "Veuillez entrer un entier : ";
		cin >> entierString;
		entierTableau[i] = intVerificator(entierString);
	}
	cout << "La moyenne de ces 5 entiers est " << moyenne(entierTableau, size) << endl;
	cout << "La valeur minimal de ces 5 entiers est " << minimum(entierTableau, size) << endl;
	cout << "La valeur maximal de ces 5 entiers est " << maximum(entierTableau, size) << endl;
}

// Question 4
// programme qui trouve les nbr 1er entre 50 et 100
// répondre aux questions : 
// Quelles structures répétitives devrait-on choisir ?
// et Pourquoi ?
void partie4() {
	/*todo
	* Voir pour éventuelement remplacer le for interne par un do while
	*/
	//On utilise 2 boucles for imbriquée, la principale pour tester les nombres de 50 à 100
	//et la deuxième pour déterminer si le nombre testé est premier ou non
	cout << "Les nombres premiers entre 50 et 100 sont : ";
	for (int i = 50; i <= 100; i++)
	{
		bool nbreEstPremier = true;
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				nbreEstPremier = false;
			}
		}

		if (nbreEstPremier)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

// Question 5
// programme qui renvoie les impots preleves
// 5% pour la premiere tranche de 10k $
// 15% le reste
void partie5() {
	float revenuFloat, impots5, impots15;
	
	cout << "Veuillez entrer votre revenu annuel afin de pouvoir calculer l'impot que vous devez payer : ";
	cin >> revenuFloat;
	impots5 = revenuFloat * 0.05;
	if (revenuFloat > 10000) {
		revenuFloat -= 10000;
		impots15 = revenuFloat * 0.15;
		cout << "Vous allez payer " << impots5 << "$ pour la premiere tranche de 10k$ ";
		cout << "et " << impots15 << "$ pour le reste." << endl;
		cout << "Soit un total de " << impots5 + impots15 << "$.";
	}
	else
	{
		cout << "Vous allez payer " << impots5 << " d'impots";
	}
}

// Question 8
// programme qui fait deviner un nombre aleatoire compris dans [0;50]
void partie8() {
	srand(time(NULL));
	int nbMystere = rand() % 51;
	int nbSaisi = -1;
	int nbTentatives = 1;
	do
	{
		cout << "Saisissez un nombre entre 0 et 50 :" << endl;
		cin >> nbSaisi;
		if (nbSaisi < nbMystere)
		{
			cout << "C'est plus !" << endl;
		}
		else if (nbSaisi > nbMystere)
		{
			cout << "C'est moins !" << endl;
		}
		else
		{
			cout << "Vous avez trouve en " << nbTentatives << " essais !" << endl;
		}
		nbTentatives++;
	} while (nbMystere != nbSaisi);
}

// Question 11
// programme qui renvoie les titres des livres de l'année A rentre par l'utilisateur
// en fonction de donnees extraites d'un fichier .dat
void partie11() {

}

// Question 13
// programme qui calcule le perimetre d'un polygone donne
// en fonction de coordonnee de points donnees dans un fichier .dat
void partie13() {

}



// Fonction principale
int main()
{

	// Introduction du TP
	cout << " /$$$$$$$$ /$$$$$$$    /$$$$$      /$$$$$$$                   /$$$$$$                  " << endl;
	cout << "|__  $$__/| $$__  $$ /$$__  $$    | $$__  $$                 /$$__  $$ /$$       /$$   " << endl;
	cout << "   | $$   | $$    $$|__/    $$    | $$    $$  /$$$$$$       | $$   __/| $$      | $$   " << endl;
	cout << "   | $$   | $$$$$$$/  /$$$$$$/    | $$  | $$ /$$__  $$      | $$    /$$$$$$$$ /$$$$$$$$" << endl;
	cout << "   | $$   | $$____/  /$$____/     | $$  | $$| $$$$$$$$      | $$   |__  $$__/|__  $$__/" << endl;
	cout << "   | $$   | $$      | $$          | $$  | $$| $$_____/      | $$    $$| $$      | $$   " << endl;
	cout << "   | $$   | $$      | $$$$$$$$    | $$$$$$$/|  $$$$$$$      |  $$$$$$/|__/      |__/   " << endl;
	cout << "   |__/   |__/      |________/    |_______/  \_______/       \______/                  \n\n\n" << endl;

	cout << "Automne 2023 - Groupe 01" << endl;
	cout << "Enseignante : Imène Benkalai" << endl;
	cout << "Date de remise : 10 novembre 2023 avant 23h59" << endl;

	//Partie Déclaration de variable
	string stringChoixPartie;
	int intChoixPartie;
	bool exercice = true;
	
	//Partie Instruction
	do{
		stringChoixPartie = "Veuillez choisir l'une des parties du TP en fonction de la question ou 0 pour arreter la lecture des questions :";
		cout << "" << endl << stringChoixPartie << endl ;
		cin >> intChoixPartie;
		switch (intChoixPartie) {
		case 0:
			cout << "Arret de la lecture des questions." << endl;
			exercice = !exercice;
			break;
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
			cout << "Partie 8 :" << endl;
			partie8();
			break;
		case 11:
			cout << "Partie 11 :" << endl;
			partie11();
			break;
		case 13:
			cout << "Partie 13 :" << endl;
			partie13();
			break;
		}
	} while (exercice);

	return 0;
}
