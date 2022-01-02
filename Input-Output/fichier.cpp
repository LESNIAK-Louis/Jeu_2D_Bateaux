/**
 * \file fichier.cpp
 * \brief Fonctions qui gèrent la communication les fichiers
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "fichier.hpp"
Point* readPoint(std::string *line)
{
    try{
        int x = std::stoi(line->substr(line->find_first_of("<")+1, line->find_first_of(";") - line->find_first_of("<") -1));
        int y = std::stoi(line->substr(line->find_first_of(";")+1, line->find_first_of(">") - line->find_first_of(";") -1));
        if(line->find_first_of(">")+2 < line->length() && line->find_first_of(">")+2 > 0) // Verification si on est pas en fin de ligne
            *line = line->substr(line->find_first_of(">")+2);

        return new Point(x, y);
    }catch(std::exception &e){error("Format incorrect du fichier de sauvegarde | readPoint - fichier ");}
}


int readNextNumber(std::string *line)
{
    try{
        int number = std::stoi(line->substr(0, line->find_first_of(";")));
        if(line->find_first_of(";")+1 < line->length() && line->find_first_of(";")+1 > 0) // Verification si on est pas en fin de ligne
            *line = line->substr(line->find_first_of(";")+1);

        return number;
    }catch(std::exception &e){error("Format incorrect du fichier de sauvegarde | readNextNumber - fichier ");}
}

void addPatrouilleurs(std::string *line, Flotte* flotte, int nbPatrouilleurs)
{
    if(nbPatrouilleurs > 0)
    {
        line->substr(1);
        checkNbParam(*line, 9*nbPatrouilleurs + nbPatrouilleurs-1);
        for(int i = 0; i < nbPatrouilleurs; i++)
        {
            flotte->addPatrouilleur(new Patrouilleur(flotte->getNumero(), i, readPoint(line), readPoint(line), readNextNumber(line),readNextNumber(line),readNextNumber(line),readNextNumber(line),readNextNumber(line)));
            flotte->getPatrouilleur(i)->setPv(readNextNumber(line));
        }
        line->substr(2);
    }
}

void checkNbParam(std::string line, long unsigned int requestedParamNumber)
{
    size_t n;
    try{
        n = std::count(line.begin(), line.end(), ';');
    }catch(std::exception &e){error("Format incorrect du fichier de sauvegarde | checkNbParam - fichier ");}
    if(requestedParamNumber != n) error("Format incorrect du fichier de sauvegarde | checkNbParam - fichier ");
}

Monde* readSave(std::string path)
{
    std::ifstream fileSave(path.c_str());
    if(!fileSave.good()) error("Erreur dans la lecture du fichier de sauvegarde | readSave - fichier ");

    std::string line;
    getline(fileSave, line);

    checkNbParam(line, 3);
    int nbIles = readNextNumber(&line);
    int nbIlesBonus = readNextNumber(&line);
    int time = readNextNumber(&line);
    int difficulte = readNextNumber(&line);
    
    Monde* monde = new Monde(nbIles, nbIlesBonus, time, difficulte);
    
    while(getline(fileSave, line))
    {
        switch(line[0])
        {
            case 'F':
            {
                int numero;
                try{
                    numero = std::stoi(line.substr(1, line.find_first_of("{")-1));
                } catch(std::exception &s){error("Format incorrect du fichier de sauvegarde | readSave - fichier ");}
                Point* Coord = readPoint(&line);
                Point* Spawn = readPoint(&line);
                int ressource = readNextNumber(&line);
                int gain = readNextNumber(&line);
                int pv = readNextNumber(&line);
                Flotte* flotte = new Flotte(numero, Coord, Spawn, ressource, gain, pv);
                int nbPatrouilleurs = readNextNumber(&line);
                addPatrouilleurs(&line, flotte, nbPatrouilleurs);
                monde->addFlotte(flotte);
            }
            break;
            case 'I':
            {
                try{
                    line.substr(line.find_first_of("{")+1);
                } catch(std::exception &s){error("Format incorrect du fichier de sauvegarde | readSave - fichier ");}
                checkNbParam(line, 3);
                Point* Pos = readPoint(&line);
                int taille = readNextNumber(&line);
                int forme = readNextNumber(&line);
                Ile* ile = new Ile(Pos, taille, forme);
                monde->setIle(nbIles-1, ile); 
                nbIles--;
            }
            break;
            case 'B':
            break;
            case 'M':
            break;
            case 'T':
            break;
            default:
                error("Erreur de format | readSave - fichier ");
            break;
        }
    }
    fileSave.close();
    return monde;
}

void writeMonde(std::string path, Monde* monde)
{
    std::ofstream fileSave(path.c_str(), std::ios::out | std::ios::app);
    if(!fileSave.is_open())  error("Erreur dans l'ouverture du fichier | sauvegarder - fichier");

    fileSave << monde->formattedInfo();

    fileSave.close();
    SDL_Delay(50);
}

bool isFileExist(std::string fileName)
{
    std::ifstream infile(fileName.c_str());
    bool exist = infile.good();
    SDL_Delay(50);
    return exist;
}

void save(std::string path, Monde* monde)
{
    if(monde == NULL) error("Monde null en param | sauvegarder - fichier");
    if(isFileExist(path.c_str()))
    {
        if(remove(path.c_str()) != 0)
            error("Erreur, un fichier porte deja le nom de la sauvegarde et est impossible a supprimer | sauvegarder - fichier");
    }
    writeMonde(path, monde);
}