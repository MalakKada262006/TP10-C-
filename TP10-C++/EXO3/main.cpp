#include <iostream>
#include <string>
#include <limits>
#include "Livre.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // Configuration de l'encodage pour l'affichage correct sous Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int taille = 0;
    std::cout << "=== Gestion dynamique d'un tableau de Livres ===" << std::endl;
    std::cout << "Combien de livres voulez-vous créer ? ";

    // 1. Vérifier si l'utilisateur a bien entré un nombre (et non du texte)
    if (!(std::cin >> taille)) {
        std::cerr << "Erreur : Entrée invalide. Veuillez entrer un nombre entier." << std::endl;
        std::cin.clear();                     // Réinitialise l'état d'erreur de cin
        std::cin.ignore(10000, '\n');         // Vide le mauvais contenu du tampon
        return 1;
    }

    // 2. Vérifier si la taille est strictement positive
    if (taille <= 0) {
        std::cerr << "Erreur : La taille du tableau doit être strictement positive." << std::endl;
        std::cin.ignore(10000, '\n');         // Nettoie le tampon par sécurité
        return 1;
    }

    // 3. Nettoyer le saut de ligne restant dans le tampon après une saisie valide
    std::cin.ignore(10000, '\n');

    // 4. Allocation dynamique d'un tableau d'objets Livre avec new[]
    Livre* tableauLivres = new Livre[taille];

    // 5. Remplir chaque élément avec des données fournies par l'utilisateur
    for (int i = 0; i < taille; ++i) {
        std::cout << "\n--- Saisie du livre #" << (i + 1) << " ---" << std::endl;
        tableauLivres[i].saisir();
    }

    // 6. Afficher tous les livres saisis
    std::cout << "\n==========================================" << std::endl;
    std::cout << "         LISTE DES LIVRES SAISIS          " << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < taille; ++i) {
        std::cout << "Livre [" << i << "] -> ";
        tableauLivres[i].afficher();
    }

    // 7. Libérer la mémoire allouée à la fin avec delete[]
    delete[] tableauLivres;
    tableauLivres = nullptr; // Bonne pratique anti-pointeur suspendu

    std::cout << "\nMémoire libérée avec succès. Fin du programme." << std::endl;

    return 0;
}
