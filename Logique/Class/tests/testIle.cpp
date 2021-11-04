#include "../Ile.hpp"
#include <iostream>

void testIle()
{
    Ile* ile = new Ile(4, 2, 2, 1);
    if(ile->getAbscisse() != 4 || ile->getOrdonnee() != 2) perror("Position non correspondante - testIle");
    if(ile->getTaille() != 2) perror("Taille non correspondante - testIle");
    if(ile->getForme() != 1) perror("Forme non correspondante - testIle");
    std::cout << ile->toString();
    ile->~Ile();
}

int main()
{
    testIle();

    return 0;
}