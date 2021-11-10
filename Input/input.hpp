/**
 * \file input.hpp
 * \brief Définition des fonctions gérant les entrées utilisateur
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>

/**
 * \brief La fonction gère les saisis clavier/souris
 * \param event evenement
*/
void gestion_evenements(SDL_Event* event);

#endif