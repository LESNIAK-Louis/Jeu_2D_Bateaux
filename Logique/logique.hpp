/**
 * \file logique.hpp
 * \brief Définition du module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "Class/Monde.hpp"

#ifndef LOGIQUE_HPP
#define LOGIQUE_HPP


void moveSelectedShips(Monde* monde, int x, int y);
void unSelectAll(Monde* monde);

void moveShips(Monde* monde);

#endif