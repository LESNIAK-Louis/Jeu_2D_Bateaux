/**
 * \file Navire.hpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

#include <string>
#include <vector>
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
        int cadenceTir; //nombre de tir par unité de temps
        int portee;
        

    public : 
        Navire();
        Navire(int idFlotte, int id, Point* pos, Point* dest, int pvMax, int vitesse, int degatArme, int cadenceTir, int portee);

        ~Navire();

        int getIdFlotte();
        int getId();
        Point* getCentre();
        Point* getDestination();
        Point* getWayPoint();
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
        int getCandenceTir();
        int getPortee();
        Navire* getCible();

        void setIdFlotte(int idFlotte);
        void setId(int i);
        void reduireId();
        void setCentre(Point* centre);
        void setAbscisse(int abs);
        void setOrdonnee(int ord);
        void deplacer(int abs, int ord);
        void setMove(bool b);
        void setAngle(int angle);
        void modifierAngle(int deltaAngle);
        void setPv(int pv);
        void ajouterPV(int pv);
        void setVitesse(int vitesse);
        void setVitesseHorizontale(int vh);
        void setVitesseVerticale(int vt);
        void calculerVitesseHorVert();
        void setDestination(Point* dest);
        void setWayPoint(Point* point);
        void avancer(int deltaAngle);
        void setPvMax(int pvMax);
        void setDegatArme(int degat);
        void setCadenceTir(int cd);
        void setPortee(int p);
        void setCible(Navire* navire);
        void ajouterPV();


        bool estEnCollisionAvec(int taille, Point* ctr);

        /**
         * @brief annule tous les ordres donnée au navire
         * 
         */
        void stop();

        //virtual std::string returnType() = 0;

        std::string formattedInfo();
};


#endif