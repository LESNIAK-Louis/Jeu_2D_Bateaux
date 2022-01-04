/** 
* \file Monde.hpp
* \brief Representation du jeu
* \author Louis Lesniak & Hugues Steiner
* \date 30 Nov. 2021
*/

#ifndef MONDE_HPP
#define MONDE_HPP

#include <string>
#include <vector>
#include "Flotte.hpp"
#include "Ile.hpp"
#include "IleBonus.hpp"
#include "../../definitions.hpp"

struct spritePersistant_s{
    Point* point;
    const char* type;
    int duree;
    int tempsDebut;
}; typedef struct spritePersistant_s spritePersistant;

class Monde {
    private : 
        std::vector<Flotte*>* flottes;
        std::vector<spritePersistant*>* spritesPersistants;
        Ile** iles;
        IleBonus** ilesBonus;
        int nbFlottes;
        int nbIles;
        int nbIlesBonus;
        int timer;
        int difficulte;
        std::string vainqueur;
    public : 
        Monde(int nbIles, int nbIlesBonus, int time, int difficulte);
        ~Monde();

        Flotte* getFlotte(int index);
        spritePersistant* getSpritePersistant(int index);
        Ile* getIle(int index);
        IleBonus* getIleBonus(int index);
        int getTimer();
        int getDifficulte();
        std::string getVainqueur();
        
        int getNbFlottes();
        int getNbSpritesPersistants();
        int getNbIles();
        int getNbIlesBonus();
        
        void setIle(int index, Ile* ile);
        void setIleBonus(int index, IleBonus* ilebonus);
        void setTimer(int time);
        void setDifficulte(int difficulte);
        void setVainqueur(std::string nomVainqueur);

        void addFlotte(Flotte* flotte);
        void removeFlotte(int id);

        void addSpritePersistant(Point* p, const char* type, int tempsDebut, int duree);
        void removeSpritePersistant(int index);

        void removeAllFlottes();
        void removeAllIles();
        void removeAllIlesBonus();
        void removeAllSpritesPersistant();

        void updateControleIleBonus();
        void actionBot();
        std::string formattedInfo();
};

#endif