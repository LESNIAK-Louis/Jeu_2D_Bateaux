/**
 * \file fichier.hpp
 * \brief Définitions des fonctions qui gèrent la communication les fichiers
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include "../definitions.hpp"
#include "../Logique/Class/Monde.hpp"



unsigned int getNombreLignesFichier(char* path);
unsigned int getLongueurMaxColonne(char* path);
Point* readPoint(std::string *line);
int readNextNumber(std::string *line);
void addPatrouilleurs(std::string *line, Flotte* flotte, int nbPatrouilleurs);
Monde* readSave(std::string path);
char** allouerTab2D(int n, int m);
void desallouerTab2D(char** tab, int n);
void afficherTab2D(char** tab, int n, int m);
void writeMonde(std::string fileName, Monde* monde);
bool isFileExist(std::string fileName);
void save(std::string path, Monde* monde);

#endif