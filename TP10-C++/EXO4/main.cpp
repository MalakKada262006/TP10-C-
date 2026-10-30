#include <iostream>
#include <string>
#include <limits>
#include "Contact.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void supprimerContact(Contact**& carnet, int& taille, const std::string& nomRecherche) {
    int indexTrouve = -1;

    for (int i = 0; i < taille; ++i) {
        if (carnet[i]->getNom() == nomRecherche) {
            indexTrouve = i;
            break;
        }
    }

    if (indexTrouve == -1) {
        std::cout << "\n[Erreur] Contact '" << nomRecherche << "' introuvable." << std::endl;
        return;
    }

    delete carnet[indexTrouve];

    for (int i = indexTrouve; i < taille - 1; ++i) {
        carnet[i] = carnet[i + 1];
    }

    taille--;

    if (taille > 0) {
        Contact** nouveauCarnet = new Contact*[taille];
        for (int i = 0; i < taille; ++i) {
            nouveauCarnet[i] = carnet[i];
        }
        delete[] carnet;
        carnet = nouveauCarnet;
    } else {
        delete[] carnet;
        carnet = nullptr;
    }

    std::cout << "\n[Succes] Contact '" << nomRecherche << "' supprime avec succes." << std::endl;
}

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int capaciteInitiale = 0;
    std::cout << "=== Gestion avancee d un carnet d adresses ===" << std::endl;
    std::cout << "Entrez le nombre initial de contacts a creer : ";
    std::cin >> capaciteInitiale;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (capaciteInitiale <= 0) {
        std::cerr << "Erreur : La capacite initiale doit etre positive." << std::endl;
        return 1;
    }

    int tailleActuelle = capaciteInitiale;
    Contact** carnet = new Contact*[tailleActuelle];

    for (int i = 0; i < tailleActuelle; ++i) {
        std::string nom, tel, email;
        std::cout << "\n--- Saisie du contact #" << (i + 1) << " ---" << std::endl;
        std::cout << "Nom : ";
        std::getline(std::cin, nom);
        std::cout << "Telephone : ";
        std::getline(std::cin, tel);
        std::cout << "Email : ";
        std::getline(std::cin, email);

        carnet[i] = new Contact(nom, tel, email);
    }

    int choix = 0;
    do {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "        MENU - CARNET D'ADRESSES          " << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "1. Afficher tous les contacts" << std::endl;
        std::cout << "2. Supprimer un contact par nom" << std::endl;
        std::cout << "3. Quitter et liberer la memoire" << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choix) {
            case 1: {
                if (tailleActuelle == 0) {
                    std::cout << "\nLe carnet d adresses est vide." << std::endl;
                } else {
                    std::cout << "\n--- Liste des Contacts (" << tailleActuelle << ") ---" << std::endl;
                    for (int i = 0; i < tailleActuelle; ++i) {
                        std::cout << "[" << i << "] ";
                        carnet[i]->afficher();
                    }
                }
                break;
            }
            case 2: {
                if (tailleActuelle == 0) {
                    std::cout << "\nAucun contact a supprimer." << std::endl;
                    break;
                }
                std::string nomASupprimer;
                std::cout << "Entrez le nom du contact à supprimer : ";
                std::getline(std::cin, nomASupprimer);

                supprimerContact(carnet, tailleActuelle, nomASupprimer);
                break;
            }
            case 3:
                std::cout << "\nFermeture du programme..." << std::endl;
                break;
            default:
                std::cout << "\nOption invalide." << std::endl;
        }

    } while (choix != 3);

    for (int i = 0; i < tailleActuelle; ++i) {
        delete carnet[i];
    }
    delete[] carnet;
    carnet = nullptr;

    std::cout << "Memoire entierement liberee. Fin propre du programme." << std::endl;

    return 0;
}

