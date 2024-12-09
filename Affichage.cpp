#include "Affichage.h"
#include <iostream>
#include <vector>    // Ajoutez l'inclusion de <vector>
#include <windows.h>
#include "Joueur.h"  // Inclure Joueur.h pour utiliser la structure Joueur

void afficherErreur(const std::string& message) {
    MessageBoxA(NULL, message.c_str(), "Erreur", MB_ICONERROR | MB_OK);
}

void afficherAvertissement(const std::string& message) {
    MessageBoxA(NULL, message.c_str(), "Avertissement", MB_ICONWARNING | MB_OK);
}

void afficherScores(const std::vector<Joueur>& joueurs) {  // Utilisez std::vector
    for (const auto& joueur : joueurs) {
        std::cout << "Nom: " << joueur.nom << ", Score: " << joueur.score << std::endl;
    }
}
