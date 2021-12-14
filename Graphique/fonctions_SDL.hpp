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
#include "../Logique/logique.hpp"
#include "../Logique/Class/Monde.hpp"
#include "../Logique/Class/Flotte.hpp"
#include "../Logique/Class/Navire/Patrouilleur.hpp"

/**
 * \brief La fonction initialise la SDL et TTF : elle crée la fenêtre du jeu ainsi que le renderer
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param width largeur de l'écran de jeu
 * \param height hauteur de l'écran de jeu
*/
void initSDL(SDL_Window** window, SDL_Renderer** renderer, int width, int height);

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
 * @brief La foncion qui affiche le monde
 * @param ecran l'écran
 * @param monde le monde
 * @param textureIles la texture correspondant aux iles
 * @param texturePatrouilleur la texture correspondant aux patrouilleurs
 */
void afficherMonde(SDL_Renderer* ecran, Monde* monde, SDL_Texture* textureIle, SDL_Texture* texturePatrouilleur);

/**
 * @brief La fonction qui affiche les iles
 * @param ecran l'écran
 * @param monde le monde
 * @param textureIles la texture correspondant aux iles
 */
void afficherIles(SDL_Renderer* ecran, Monde* monde, SDL_Texture* textureIle);

/**
 * @brief  La fonction affiche les navire du monde
 * @param ecran l'ecran
 * @param monde le monde
 * @param texturePatrouilleur la texture correspondant aux patrouilleurs
 */
void afficherNavires(SDL_Renderer* ecran, Monde* monde, SDL_Texture* texturePatrouilleur);

/**
 * @brief affiche les patrouilleurs
 * @param ecran l'ecran
 * @param monde 
 * @param texturePatrouilleur la texture correspondant aux patrouilleurs
 */
void afficherPatrouilleurs(SDL_Renderer* ecran, Flotte* flotte, SDL_Texture* texturePatrouilleur);


/**
 * \brief La fonction charge une police
 * \param path le chemin du fichier correpondant à la police
 * \param font_size la taille de la police
 * \return la police chargee
*/
TTF_Font* charger_police(const char* path, int font_size);

/**
 * \brief La fonction charge un texte en param
 * \param message le texte a charger
 * \param renderer le renderer
 * \param font la police a utiliser
 * \param color la couleur a appliquer
 * \return la texture du texte charge
*/
SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color);

/**
 * \brief La fonction nettoie toutes les textures d'un vector en mémoire
 * \param textures vector des textures
*/
void cleanTextures(std::vector<SDL_Texture*>* textures);

/**
 * \brief La fonction nettoie toutes les polices d'un vector en mémoire
 * \param fonts vector des polices
*/
void cleanPolices(std::vector<TTF_Font*>* fonts);

/**
 * \brief La fonction nettoie toute la SDL et TTF
 * \param renderer le renderer
 * \param window la fenêtre du jeu
 * \param textures vector des textures
 * \param fonts vector des polices
*/
void cleanSDL(SDL_Renderer* renderer, SDL_Window* window, std::vector<SDL_Texture*>* textures, std::vector<TTF_Font*>* fonts);

#endif