/**
 * \file input.hpp
 * \brief Définition des fonctions gérant les entrées utilisateur
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "../Logique/logique.hpp"
#include "../Logique/Class/Monde.hpp"
#include "Mouse.hpp"
#include "../Graphique/menu.hpp"

/**
 * \brief La fonction gère les saisis clavier/souris
 * \param event evenement
*/
void gestion_evenements_jeu(SDL_Event* event, Mouse* mouse, Monde* monde, bool* terminer, bool* arreterApplication);
#ifndef MENU_C_HPP
void gestion_evenements_menu(Menu* menu)
#endif
bool isPointingIle(Monde* monde, Mouse* mouse);
void addNavToSelection(Flotte* flotte, Mouse* mouse);
bool collisionCercleRectangle(Point* centre, int rayon, SDL_Rect* rect);
void appliquerEffetBouton(Flotte* flotte, int i, int j);

#endif