#include "Contact.hpp"
#include <iostream>

Contact::Contact(const std::string& nom, const std::string& telephone, const std::string& email)
    : nom(nom), telephone(telephone), email(email) {}

Contact::~Contact() {
}

std::string Contact::getNom() const {
    return nom;
}

void Contact::afficher() const {
    std::cout << "Nom : " << nom << " | Telephone : " << telephone << " | Email : " << email << std::endl;
}



