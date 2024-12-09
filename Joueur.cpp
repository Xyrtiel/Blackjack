#include "Joueur.h"
#include <iostream>

void afficherScores(const std::vector<Joueur>& joueurs) {
    std::cout << "Scores des joueurs:" << std::endl;
    for (const auto& joueur : joueurs) {
        std::cout << "Nom: " << joueur.nom << ", Score: " << joueur.score << std::endl;
    }
}
