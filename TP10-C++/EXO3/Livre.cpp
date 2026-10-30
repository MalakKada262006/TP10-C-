#include "Livre.hpp"
#include <iostream>
#include <limits>

Livre::Livre() : titre("Inconnu"), prix(0.0) {}

Livre::Livre(const std::string& titre, double prix) : titre(titre), prix(prix) {}

Livre::~Livre() {}

void Livre::saisir() {
    std::cout << "Entrez le titre du livre : ";
    std::getline(std::cin, titre);

    std::cout << "Entrez le prix du livre : ";
    while (!(std::cin >> prix)) {
        std::cout << "Erreur : Veuillez entrer un nombre valide pour le prix : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Livre::afficher() const {
    std::cout << "Titre : " << titre << " | Prix : " << prix << " EUR" << std::endl;
}
