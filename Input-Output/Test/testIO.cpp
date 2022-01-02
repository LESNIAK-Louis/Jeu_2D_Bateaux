/** 
* \file testI0.cpp
* \brief Les tests relatifs aux entrées/sorties
* \author Louis Lesniak & Hugues Steiner
* \date 8 Dec. 2021
*/

#include "../fichier.hpp"

void testSauvegarder()
{
    Monde* monde = new Monde(1,0,1,1);
    monde->addFlotte(new Flotte(0, new Point(0,0), new Point(0,0), 0,10,500));
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->addElemListeSelected(monde->getFlotte(0)->getPatrouilleur(0));
    monde->getFlotte(0)->newPatrouilleur();

    monde->addFlotte(new Flotte(1, new Point(3,3), new Point(3,3), 50,75,100));
    monde->getFlotte(1)->newPatrouilleur();
    monde->getFlotte(1)->addElemListeSelected(monde->getFlotte(1)->getPatrouilleur(0));
    monde->getFlotte(1)->newPatrouilleur();
    monde->getFlotte(1)->addElemListeSelected(monde->getFlotte(1)->getPatrouilleur(1));

    monde->setIle(0, new Ile(new Point(5,6), 5, 1));

    save("testSave.txt", monde);
    monde->~Monde();
}

void testLireSauvegarde()
{
    readSave("testSave.txt");
}

int main()
{
    //testSauvegarder();
    testLireSauvegarde();

    return 0;
}