/**
 * \file jeu.hpp
 * \brief Fonctions d'affichage lié au jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 03 Janv. 2021
*/

#ifndef FONCTIONS_AFFICHAGE_JEU
#define FONCTIONS_AFFICHAGE_JEU

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "fonctions_SDL.hpp"
#include "../Logique/logique.hpp"
#include "../Logique/Class/Monde.hpp"
#include "../Logique/Class/Flotte.hpp"
#include "../Logique/Class/Navire/Patrouilleur.hpp"

struct textures_s{
    TTF_Font* police; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* fond; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ile; /*Texture liée aux iles*/
    SDL_Texture* contourPV; /*Texture liée à l'image représentant le contour des barres de point de vie */
    SDL_Texture* remplissagePV; /*Texture liée à l'image représentant le remplissage des barres de point de vie du joueur*/
    SDL_Texture* remplissagePVEnnemis; /*Texture liée à l'image représentant le remplissage des barres de point de vie des ennemis*/
    SDL_Texture* base; /*Texture liée à l'image représentant une base */
    SDL_Texture* patrouilleur; /*Texture liée à l'image représentant un patrouilleur*/
    SDL_Texture* croiseur; /*Texture liée à l'image représentant un croiseur*/
    SDL_Texture* porteAvion;
    SDL_Texture* interface; /*Texture liée à l'image représentant l'interface*/
    SDL_Texture* bouton; /*Texture liée à l'image représentant un bouton*/
    SDL_Texture* plus; /*texture liée au signe plus */
    SDL_Texture* point; /*texture liée au point */
    SDL_Texture* tir; /*texture liée au tir */
    SDL_Texture* explosion; /*texture liée a l'explosion */
};

/**
 * @brief initialise les textures du jeu
 * 
 * @param renderer 
 * @param textures 
 */
void init_textures_jeu(SDL_Renderer *renderer, textures_s* textures);

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
 * @brief affiche les informations relatives à la flotte du joueur : or, nombre de bateau, pv de la base, navires selectionnés...
 * 
 * @param ecran 
 * @param flotte 
 * @param  textures les textures du jeu
 */
void afficherInformations(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures);

/**
 * @brief affiche les navire selectionnés
 * 
 * @param ecran 
 * @param flotte 
 * @param textures 
 */
void afficherSelection(SDL_Renderer* ecran, selectedNavire* liste, textures_s* textures, int decalageHorizontal, int decalageVertical);

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
 * @brief La fonction qui affiche les iles bonus
 * @param ecran l'écran
 * @param monde le monde
 * @param textures les textures du jeu
 */
void afficherIlesBonus(SDL_Renderer* ecran, Monde* monde, textures_s* textures);

/**
 * @brief La fonction qui affiche les flottes
 * @param ecran l'écran
 * @param monde le monde
 * @param textures les textures du jeu
 */
void afficherFlottes(SDL_Renderer* ecran, Monde* monde, textures_s* textures);

/**
 * @brief  La fonction affiche les navires d'une flotte
 * @param ecran l'ecran
 * @param flotte une flotte
 * @param textures les textures du jeu
 */
void afficherNavires(SDL_Renderer* ecran,  Flotte* flotte, textures_s* textures);

/**
 * @brief la fonction affiche la base d'une flotte
 * 
 * @param ecran 
 * @param flotte 
 * @param textures 
 */
void afficherBase(SDL_Renderer* ecran, textures_s* textures, Navire* navire);

/**
 * @brief affiche un patrouilleur
 * 
 * @param ecran 
 * @param flotte 
 * @param textures 
 */
void afficherPatrouilleur(SDL_Renderer* ecran, textures_s* textures, Navire* navire);

/**
 * @brief affiche un croiseur
 * 
 * @param ecran 
 * @param flotte 
 * @param textures 
 */
void afficherCroiseur(SDL_Renderer* ecran, textures_s* textures, Navire* navire);


/**
 * @brief affiche les barres de vie au dessus des bateaux
 * 
 * @param ecran 
 * @param monde 
 * @param textures les textures du jeu
 */
void afficherBarreDeVie(Navire* navire, SDL_Renderer* ecran, textures_s* textures);

/**
 * @brief affiche la barre de vie au dessus de la base
 * 
 * @param navire 
 * @param ecran 
 * @param textures 
 */
void afficherBarreDeVieBase(Navire* navire, SDL_Renderer* ecran, textures_s* textures);

/**
 * @brief détruit toutes les textures
 * @param textures les textures du jeu
 */
void destroy_textures_jeu(textures_s* textures);

#endif