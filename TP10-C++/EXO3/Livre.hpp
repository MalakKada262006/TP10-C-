#ifndef LIVRE_HPP
#define LIVRE_HPP

#include <string>

class Livre {
private:
    std::string titre;
    double prix;

public:
    Livre();

    Livre(const std::string& titre, double prix);

    ~Livre();

    void saisir();
    void afficher() const;
};

#endif
