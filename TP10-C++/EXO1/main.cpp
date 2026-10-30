#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

struct Etudiant {
    std::string nom;
    std::string prenom;
    int age;
    std::string filiere;
    std::string semestre;
};

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int taille = 0;
    std::cout << "=== Creation dynamique d'un tableau d'etudiants ===" << std::endl;
    std::cout << "Entrez la taille du tableau : ";
    std::cin >> taille;

    std::cin.ignore(10000, '\n');

    if (taille <= 0) {
        std::cerr << "Erreur : La taille doit etre strictement positive." << std::endl;
        return 1;
    }

    Etudiant* tableauEtudiants = new Etudiant[taille];

    for (int i = 0; i < taille; ++i) {
        std::cout << "\n--- Saisie de l'element [" << i << "] ---" << std::endl;

        std::cout << "Entrez le Nom : ";
        std::getline(std::cin, tableauEtudiants[i].nom);

        std::cout << "Entrez le Prenom : ";
        std::getline(std::cin, tableauEtudiants[i].prenom);

        std::cout << "Entrez l'Age : ";
        std::cin >> tableauEtudiants[i].age;
        std::cin.ignore(10000, '\n');

        std::cout << "Entrez la Filiere : ";
        std::getline(std::cin, tableauEtudiants[i].filiere);

        std::cout << "Entrez le Semestre (ex: S5) : ";
        std::getline(std::cin, tableauEtudiants[i].semestre);
    }

    std::cout << "\n==================================================" << std::endl;
    std::cout << "         AFFICHAGE DU TABLEAU D'ETUDIANTS         " << std::endl;
    std::cout << "==================================================" << std::endl;

    for (int i = 0; i < taille; ++i) {
        std::cout << "Element [" << i << "] -> "
                  << "Nom: " << tableauEtudiants[i].nom << " | "
                  << "Prenom: " << tableauEtudiants[i].prenom << " | "
                  << "Age: " << tableauEtudiants[i].age << " ans | "
                  << "Filiere: " << tableauEtudiants[i].filiere << " | "
                  << "Semestre: " << tableauEtudiants[i].semestre << std::endl;
    }

    delete[] tableauEtudiants;
    tableauEtudiants = nullptr;

    std::cout << "\nMemoire liberee avec succes. Fin du programme." << std::endl;

    return 0;
}
