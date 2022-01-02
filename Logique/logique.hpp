/**
 * \file logique.hpp
 * \brief Définition du module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "Class/Monde.hpp"
#include "Class/Point.hpp"
#include <stdio.h>
#include <cmath>

#ifndef LOGIQUE_HPP
#define LOGIQUE_HPP

/**
 * @brief permet à un navire de naviguer autour d'une ile/ilebonus
 * 
 * @param navire 
 * @param centreIle 
 * @param tailleIle 
 */
void pathFinding(Navire* navire, Point* centreIle, int tailleIle);

void moveSelectedShips(Monde* monde, int x, int y);

void moveShips(Monde* monde);

void tirsBateaux(Monde* monde, unsigned int currentTime);

bool collisionCercles(Point* ctr1, int taille1, Point* ctr2, int taille2);

#endif