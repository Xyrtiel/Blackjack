#include "GestionFichier.h"
#include "Affichage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <errno.h>

void connexion_compte(const std::string& nomFichier) {
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::cout << "Répertoire courant : " << buffer << std::endl;

    std::vector<Joueur> joueurs = lireScores(nomFichier);

    if (joueurs.empty()) {
        afficherErreur("Erreur : Aucun joueur trouvé dans le fichier.");
        return;
    }

    std::cout << "Liste des joueurs et leurs scores :" << std::endl;
    afficherScores(joueurs);
}

std::vector<Joueur> lireScores(const std::string& nomFichier) {
    std::vector<Joueur> joueurs;
    std::ifstream fichier(nomFichier);

    if (!fichier) {
        std::stringstream ss;
        ss << "Erreur : impossible d'ouvrir le fichier '" << nomFichier << "'.";
        if (errno == ENOENT) {
            ss << "\nLe fichier n'existe pas. Veuillez vérifier le chemin.";
        } else if (errno == EACCES) {
            ss << "\nAccès refusé. Vous n'avez pas les permissions nécessaires.";
        } else {
            ss << "\nRaison : " << strerror(errno);
        }
        afficherErreur(ss.str());
        return joueurs;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, scoreStr;
        int score;

        std::getline(ss, nom, ',');
        std::getline(ss, scoreStr, ',');

        try {
            score = std::stoi(scoreStr);
        } catch (...) {
            continue;
        }

        joueurs.push_back({nom, score});
    }

    fichier.close();
    return joueurs;
}

void ajouterScore(const std::string& nomFichier, const std::string& nom, int score) {
    std::ofstream fichierOut(nomFichier, std::ios::app);
    if (!fichierOut) {
        std::stringstream ss;
        ss << "Erreur : impossible d'ouvrir le fichier '" << nomFichier << "' pour ajouter le score.";
        ss << "\nRaison : " << strerror(errno);
        afficherErreur(ss.str());
        return;
    }

    fichierOut << nom << "," << score << std::endl;
    fichierOut.close();
}

void mettreAJourScore(const std::string& nomFichier, const std::string& nom, int nouveauScore) {
    auto joueurs = lireScores(nomFichier);
    bool trouve = false;

    for (auto& joueur : joueurs) {
        if (joueur.nom == nom) {
            joueur.score = nouveauScore;
            trouve = true;
            break;
        }
    }

    if (!trouve) {
        joueurs.push_back({nom, nouveauScore});
    }

    std::ofstream fichier(nomFichier);
    if (!fichier) {
        std::stringstream ss;
        ss << "Erreur : impossible d'ouvrir le fichier '" << nomFichier << "' pour réécriture.";
        ss << "\nRaison : " << strerror(errno);
        afficherErreur(ss.str());
        return;
    }

    for (const auto& joueur : joueurs) {
        fichier << joueur.nom << "," << joueur.score << std::endl;
    }
    fichier.close();
}
