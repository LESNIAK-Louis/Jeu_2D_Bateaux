/**
 * \file Flotte.hpp
 * \brief Definition d'une flotte (~= un joueur)
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef FLOTTE_HPP
#define FLOTTE_HPP

#include <stdio.h>
#include <stdbool.h>
#include <list>
#include "./Point.hpp"
#include "./Navire/Patrouilleur.hpp"
#include "../../definitions.hpp"



class Flotte 
{
    public : 
        int numeroFlotte;
        Point* coordBase;
        int ressource1;
        int gainRessource1;
        int[] caracPatrouilleur; //index : 0: vitesse; 1: pvMax; 2: degatArme; 3: cooldown; 
        std::list<Patrouilleur> Patrouilleurs;
}

#endif