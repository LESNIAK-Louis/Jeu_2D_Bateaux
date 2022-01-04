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
#include <algorithm>
#include "../definitions.hpp"
#include "../Logique/Class/Monde.hpp"


Point* readPoint(std::string *line);
int readNextNumber(std::string *line);
void addNavireFlotte(std::string *line, Flotte* flotte, int nbNavires);
void addDefenseurIleBonus(std::string *line, IleBonus* ileBonus, int nbNavires, int nbIlesBonus);
void checkNbParam(std::string line, long unsigned int requestedParamNumber);
Monde* readSave(std::string path);
void writeMonde(std::string fileName, Monde* monde);
bool isFileExist(std::string fileName);
void save(std::string path, Monde* monde);

#endif