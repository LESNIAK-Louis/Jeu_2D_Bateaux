/**
 * \file Navire.hpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

#define TAILLE_PATROUILLEUR 24

#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <cmath>
#include "../Point.hpp"
#include "../../../definitions.hpp"


class Navire
{
    protected :
       
        int idFlotte;
        int id;
        Point* centre;
        Point* destination;
        Point* wayPoint;
        std::vector<Point*>* chemin;
        Navire* cible;
        int taille;
        bool move;
        int angle;
        int pv;
        int vitesse;
        int vitesseVerticale;
        int vitesseHorizontale;
        int pvMax;
        int degatArme;
        int cdArme; //cool down pour le tir
        int portee;
        bool isSelected;
        

    public : 
        Navire();
        Navire(int idFlotte, int id, Point* pos, Point* dest, int pvMax, int vitesse, int degatArme, int cdArme, int portee);

        ~Navire();

        int getIdFlotte();
        int getId();
        Point* getCentre();
        Point* getDestination();
        Point* getNextWayPoint();
        int getTaille();
        int getAbscisse();
        int getOrdonnee();
        bool isMoving();
        int getAngle();
        int getPv();
        int getVitesse();
        int getVitesseHorizontale();
        int getVitesseVerticale();
        int getPvMax();
        int getDegatArme();
        int getCdArme();
        int getPortee();
        Navire* getCible();
        bool getIsSelected();

        void setIdFlotte(int idFlotte);
        void setId(int i);
        void reduireId();
        void setCentre(Point* centre);
        void setAbscisse(int abs);
        void setOrdonnee(int ord);
        void deplacer(int abs, int ord);
        void setMove(bool b);
        void setAngle(int angle);
        void setPv(int pv);
        void ajouterPV(int pv);
        void setVitesse(int vitesse);
        void setVitesseHorizontale(int vh);
        void setVitesseVerticale(int vt);
        void calculerVitesseHorVert();
        void setDestination(Point* dest);
        void avancer();
        void setPvMax(int pvMax);
        void setDegatArme(int degat);
        void setCdArme(int cd);
        void setPortee(int p);
        void setCible(Navire* navire);
        void setIsSelected(bool isSelected);
        void ajouterPV();

        bool estEnCollisionAvec(int taille, Point* ctr);
        void findPathTo(Point* p);

        std::string formattedInfo();
};


#endif