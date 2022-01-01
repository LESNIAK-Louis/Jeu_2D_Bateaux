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


struct textures_s{
    TTF_Font* police; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* fond; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ile; /*Texture liée aux iles*/
    SDL_Texture* contourPV;
    SDL_Texture* remplissagePV;
    SDL_Texture* patrouilleur; /*Texture liée à l'image représentant un patrouilleur*/
    SDL_Texture* porteAvion;
    SDL_Texture* interface; /*Texture liée à l'image représentant l'interface*/
    SDL_Texture* bouton; /*Texture liée à l'image représentant un bouton*/
    SDL_Texture* plus; /*texture liée au signe plus */
};

/**
 * @brief initialise les textures
 * 
 * @param renderer 
 * @param textures 
 */
void  init_textures(SDL_Renderer *renderer, textures_s* textures);


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
 * @param textures
 */
void afficherMonde(SDL_Renderer* ecran, Monde* monde, textures_s* textures);

/**
 * @brief affiche l'interface au sommet de l'écran
 * 
 * @param ecran 
 * @param monde 
 * @param textures
 */
void afficherInterface(SDL_Renderer* ecran, Monde* monde, textures_s* textures);

/**
 * @brief affiche les informations relatives à la flotte du joueur : or, nombre de bateau, pv de la base...
 * 
 * @param ecran 
 * @param flotte 
 * @param  textures les textures du jeu
 */
void afficherInformations(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures);

/**
 * @brief affiche les boutons de l'interface
 * 
 * @param ecran 
 * @param textures les textures du jeu
 */
void afficherTousLesBoutons(SDL_Renderer* ecran, textures_s* textures);

/**
 * @brief affiche un bouton à une position
 * 
 * @param ecran 
 * @param textures 
 * @param abscisse abscisse du coin superieur gauche
 * @param ordonnee ordonnee du coin superieur gauche
 */
void afficherBouton(SDL_Renderer* ecran, textures_s* textures, int abscisse, int ordonnee, int i, int j);

/**
 * @brief La fonction qui affiche les iles
 * @param ecran l'écran
 * @param monde le monde
 * @param textures les textures du jeu
 */
void afficherIles(SDL_Renderer* ecran, Monde* monde, textures_s* textures);

/**
 * @brief  La fonction affiche les navire du monde
 * @param ecran l'ecran
 * @param monde le monde
 * @param textures les textures du jeu
 */
void afficherNavires(SDL_Renderer* ecran, Monde* monde, textures_s* textures);

/**
 * @brief affiche les patrouilleurs
 * @param ecran l'ecran
 * @param monde 
 * @param textures les textures du jeu
 */
void afficherPatrouilleurs(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures);

/**
 * @brief affiche les barres de vie au dessus des bateaux selectionnés par l'utilisateur
 * 
 * @param ecran 
 * @param monde 
 * @param textures les textures du jeu
 */
void afficherBarreDeVie(Navire* navire, SDL_Renderer* ecran, textures_s* textures);

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