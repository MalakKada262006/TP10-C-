#include "Personne.hpp"
#include <iostream>

Personne::Personne(const std::string& nom, int age)
    : nom(nom), age(age) {
    std::cout << "[Constructeur] Personne " << nom << " creee dynamiquement." << std::endl;
}

Personne::~Personne() {
    std::cout << "[Destructeur] Personne " << nom << " detruite de la memoire." << std::endl;
}

void Personne::afficher() const {
    std::cout << "--- Informations de la personne ---" << std::endl;
    std::cout << "Nom : " << nom << " | Age : " << age << " ans" << std::endl;
}
