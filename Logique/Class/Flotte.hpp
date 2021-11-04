/**file Flotte.hpp
 *@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition d'une flotte (~= un joueur)
*/

#include <stdio.h>
#include <stdbool.h>
#include <list>
#include "./Point.hpp"
#include "./Navire/Patrouilleur.hpp"

#ifndef FLOTTE_HPP
#define FLOTTE_HPP

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