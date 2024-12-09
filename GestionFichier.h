#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H

#include <string>
#include <vector>
#include "Joueur.h"

std::vector<Joueur> lireScores(const std::string& nomFichier);
void ajouterScore(const std::string& nomFichier, const std::string& nom, int score);
void mettreAJourScore(const std::string& nomFichier, const std::string& nom, int nouveauScore);
void connexion_compte(const std::string& nomFichier);

#endif
