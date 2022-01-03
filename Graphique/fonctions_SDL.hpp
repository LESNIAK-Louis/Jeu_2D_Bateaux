/**
 * \file fonctions_SDL.hpp
 * \brief Fonctions SDL
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef FONCTIONS_SDL
#define FONCTIONS_SDL

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../definitions.hpp"

/**
 * \brief La fonction initialise la SDL et TTF
*/ 
void initSDL();

/**
 * \brief La fonction initialise la fenêtre du jeu ainsi que le renderer
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param width largeur de l'écran de jeu
 * \param height hauteur de l'écran de jeu
*/
void initWindowRenderer(SDL_Window** window, SDL_Renderer** renderer, int width, int height);

/**
 * \brief La fonction charge une image et renvoie la texture correspondante 
 * \param nomfichier est le chemin du fichier image. Le fichier doit être obligatoirement du BMP
 * \param renderer le renderer
 * \return la texture SDL contenant l'image
*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer);

/**
 * \brief La fonction charge une image et renvoie la texture correspondante où la couleur RGB passee en param est rendue transparente
 * \param nomfichier est le chemin du fichier image. Le fichier doit être obligatoirement du BMP
 * \param renderer le renderer
 * \param r niveau de rouge rendu transparant
 * \param g niveau de vert rendu transparant
 * \param b niveau de bleu rendu transparant
 * \return la texture SDL contenant l'image avec la couleur RGB (r,g,b) rendue transparente
*/
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);

/**
 * \brief La fonction charge une police
 * \param path le chemin du fichier correpondant à la police
 * \param font_size la taille de la police
 * \return la police chargee
*/
TTF_Font* charger_police(const char* path, int font_size);

/**
 * \brief La fonction affiche un texte à l'ecran
 * \param message le texte a charger
 * \param renderer le renderer
 * \param DestR destination de l'affichage
 * \param font la police a utiliser
 * \param color la couleur a appliquer
*/
void afficher_texte(const char* message, SDL_Renderer* renderer, SDL_Rect DestR, TTF_Font* font, SDL_Color color, bool query);

/**
 * @brief la fonction nettoye l'écran
 * 
 */
void cleanRenderer(SDL_Renderer* renderer);

/**
 * \brief La fonction detruit le renderer et la fenetre
 * \param renderer le renderer
 * \param window la fenêtre du jeu
*/
void cleanSDL(SDL_Renderer* renderer, SDL_Window* window);

/**
 * @brief La fonction permet de quitter SDL et TTF
 */
void quitSDL();

#endif