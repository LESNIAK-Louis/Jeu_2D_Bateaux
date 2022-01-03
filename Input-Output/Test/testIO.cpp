/** 
* \file testI0.cpp
* \brief Les tests relatifs aux entrées/sorties
* \author Louis Lesniak & Hugues Steiner
* \date 8 Dec. 2021
*/

#include "../fichier.hpp"

void testSauvegarder()
{
    Monde* monde = new Monde(1,2,1,1);
    monde->addFlotte(new Flotte(0, new Point(0,0), new Point(0,0), 0,10,500));
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newCroiseur();

    monde->addFlotte(new Flotte(1, new Point(3,3), new Point(3,3), 50,75,100));
    monde->getFlotte(1)->newPatrouilleur();
    monde->getFlotte(1)->newPatrouilleur();

    monde->addFlotte(new Flotte(2, new Point(3,3), new Point(3,3), 50,75,100));
    monde->getFlotte(2)->newCroiseur();

    monde->addFlotte(new Flotte(3, new Point(3,3), new Point(3,3), 50,75,100));
   

    monde->setIleBonus(0, new IleBonus(new Point(500, 500), TAILLE_ILE2 , 1, 80, -1, 0 ,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,0,new Point(500, 500), new Point(500, 500), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Croiseur(-1,5,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,2,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Croiseur(-1,5,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->placerDefenseur();  

    monde->setIleBonus(1, new IleBonus(new Point(500, 500), TAILLE_ILE2 , 1, 80, -1, 0 ,50));

    monde->setIle(0, new Ile(new Point(5,6), 5, 1));

    save("testSave.txt", monde);
    monde->~Monde();
}

void testLireSauvegarde()
{
    Monde* m = readSave("testSave.txt");
    std::cout << m->formattedInfo();
}

int main()
{
    testSauvegarder();
    testLireSauvegarde();

    return 0;
}