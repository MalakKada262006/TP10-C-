#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>

class Personne {
private:
    std::string nom;
    int age;

public:
    Personne(const std::string& nom, int age);

    ~Personne();

    void afficher() const;
};

#endif
