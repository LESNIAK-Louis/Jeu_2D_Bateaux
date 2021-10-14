#include "../Ile.hpp"
#include <cassert>
#include <iostream>

void testIle()
{
    Ile* ile = new Ile(4, 2, 2, 1);
    assert(ile->getAbscisse() == 4 && ile->getOrdonnee() == 2);
    assert(ile->getTaille() == 2);
    assert(ile->getForme() == 1);
    std::cout << ile->toString();
    free(ile);
}




int main()
{
    testIle();

    return 0;
}