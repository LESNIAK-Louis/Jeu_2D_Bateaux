/**
 * \file logique.hpp
 * \brief Définition du module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "Class/Monde.hpp"
#include "Class/Rectangle.hpp"
#include "Class/Point.hpp"
#include <stdio.h>
#include <cmath>

#ifndef LOGIQUE_HPP
#define LOGIQUE_HPP


void moveSelectedShips(Monde* monde, int x, int y);
void unSelectAll(Monde* monde);

void moveShips(Monde* monde);

bool collisionCercleRectangle(Point* centre, int rayon, Rectangle* rect);
bool collisionRectangles(Rectangle* r1, Rectangle* r2);
bool collisionCercles(Point* ctr1, int taille1, Point* ctr2, int taille2);

#endif