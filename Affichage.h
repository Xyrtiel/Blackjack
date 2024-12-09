#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>
#include <vector>
#include "GestionFichier.h"

void afficherErreur(const std::string& message);
void afficherAvertissement(const std::string& message);
void afficherScores(const std::vector<Joueur>& joueurs);

#endif
