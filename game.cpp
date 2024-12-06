#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

void connexion_compte(const string& nomFichier) {
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    cout << "Répertoire courant : " << buffer << endl;
    ifstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    fichier.close();
}

void InitGame() {
    int nb_joueurs = 0;
    int numero_carte = 0;
    int mise = 0;
    bool joueur_gagne = false, croupier_gagne = false, coucher = false;
    int choix_connexion = 0; 
    vector<int> argent_par_joueur;

    cout << "Bienvenue au Jeu de Poker" << endl;
    cout << "Souhaitez-vous vous connecter à votre propre compte pour battre peut-être votre record ? (0 = Oui, 1 = Non)" << endl;
    cin >> choix_connexion;

    if (choix_connexion == 0) {
        connexion_compte("../stats.txt");
    }

    cout << "Combien de joueurs veulent jouer au Blackjack ?" << endl;
    cin >> nb_joueurs;

}

int main() {
    InitGame();
    return 0;
}
