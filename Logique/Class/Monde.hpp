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

class Monde {
    private : 
        std::vector<Flotte*>* flottes;
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
        Ile* getIle(int index);
        IleBonus* getIleBonus(int index);
        int getTimer();
        int getDifficulte();
        std::string getVainqueur();

        int getNbFlottes();
        int getNbIles();
        int getNbIlesBonus();
        
        void setIle(int index, Ile* ile);
        void setIleBonus(int index, IleBonus* ilebonus);
        void setTimer(int time);
        void setDifficulte(int difficulte);
        void setVainqueur(std::string nomVainqueur);

        void addFlotte(Flotte* flotte);

        void removeFlotte(int id);

        void removeAllFlottes();
        void removeAllIles();
        void removeAllIlesBonus();

        void updateControleIleBonus();
        void actionBot();
        std::string formattedInfo();
};

#endif