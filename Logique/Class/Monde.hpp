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
#include "Armes_Explosives.hpp"
#include "Flotte.hpp"
#include "Ile.hpp"
#include "IleBonus.hpp"
#include "../../definitions.hpp"

class Monde {
    private : 
        std::vector<Flotte*>* flottes;
        Ile** iles;
        IleBonus** ilesBonus;
        int nbFlottes;
        int nbIles;
        int nbIlesBonus;
        std::vector<Mine*>* mines;
        std::vector<Torpille*>* torpilles;
        int timer;
        int difficulte;
    public : 
        Monde(int nbIles, int nbIlesBonus, int time, int difficulte);
        ~Monde();

        Flotte* getFlotte(int index);
        Ile* getIle(int index);
        IleBonus* getIleBonus(int index);
        Mine* getMine(int index);
        Torpille* getTorpille(int index);
        int getTimer();
        int getDifficulte();

        int getNbFlottes();
        int getNbIles();
        int getNbIlesBonus();
        int getNbMines();
        int getNbTorpilles();

        void setIle(int index, Ile* ile);
        void setIleBonus(int index, IleBonus* ilebonus);
        void setTimer(int time);
        void setDifficulte(int difficulte);

        void addFlotte(Flotte* flotte);
        void addMine(Mine* mine);
        void addTorpille(Torpille* torpille);

        void removeFlotte(int id);
        void removeMine(int id);
        void removeTorpille(int id);

        void removeAllFlottes();
        void removeAllMines();
        void removeAllTorpilles();
        void removeAllIles();
        void removeAllIlesBonus();

        void updateControleIleBonus();

        std::string toString();
        std::string formattedInfo();
};

#endif