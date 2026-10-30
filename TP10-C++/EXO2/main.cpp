#include <iostream>
#include "Personne.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::cout << "=== Gestion dynamique d un objet Personne ===" << std::endl;

    Personne* p1 = new Personne("Fatima Zahra", 22);

    std::cout << "\nAffichage via l objet dynamique :" << std::endl;
    p1->afficher();

    delete p1;
    p1 = nullptr;

    std::cout << "\nFin du programme." << std::endl;

    return 0;
}
