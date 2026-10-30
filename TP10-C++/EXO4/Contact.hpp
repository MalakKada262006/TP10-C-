#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string nom;
    std::string telephone;
    std::string email;

public:
    Contact(const std::string& nom, const std::string& telephone, const std::string& email);
    ~Contact();

    std::string getNom() const;
    void afficher() const;
};

#endif
