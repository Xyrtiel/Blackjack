#include "Jeu.h"
#include "GestionFichier.h"
#include "Affichage.h"
#include <iostream>
#include <windows.h>

void InitGame() {
    int nb_joueurs = 0;
    int choix_connexion = 0;

    std::cout << "Bienvenue au Jeu de Poker" << std::endl;
    std::cout << "Souhaitez-vous vous connecter à votre propre compte pour battre peut-être votre record ? (0 = Oui, 1 = Non)" << std::endl;
    std::cin >> choix_connexion;

    if (choix_connexion == 0) {
        connexion_compte("../stats.txt");
    }

    std::cout << "Combien de joueurs veulent jouer au Blackjack ?" << std::endl;
    std::cin >> nb_joueurs;

    ajouterScore("stats.txt", "Joueur1", 100);
    mettreAJourScore("../stats.txt", "Joueur1", 150);

    int result = MessageBoxA(NULL, "Le jeu va commencer. Cliquez sur OK pour continuer.", "Démarrage du jeu", MB_OKCANCEL | MB_ICONINFORMATION);
    if (result == IDOK) {
        std::cout << "Le jeu commence maintenant..." << std::endl;
    } else {
        std::cout << "Le jeu a été annulé." << std::endl;
    }
}
