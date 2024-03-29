CC = g++
CFLAGS = -Wno-unused-value -W -Wall -ansi -std=c++14 -g
LIBS = -L./SDL2_ttf/.libs -L./SDL2_image/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image
INCLUDES = -I./SDL2_ttf -I./SDL2_image
EXEC = main testPoint testIle testIleBonus testLogique testMonde testIO testSave.txt
SRC = main.cpp Game.cpp Menu.cpp Input-Output/fichier.cpp Input-Output/Mouse.cpp Graphique/menu.cpp  Graphique/jeu.cpp Graphique/fonctions_SDL.cpp Input-Output/input.cpp Logique/logique.cpp Logique/Class/Point.cpp Logique/Class/Ile.cpp Logique/Class/Flotte.cpp Logique/Class/IleBonus.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Croiseur.cpp Logique/Class/Navire/Base.cpp Logique/Class/Monde.cpp
OBJ = $(SRC:.cpp=.o)

SRCPoint = Logique/Class/tests/testPoint.cpp Logique/Class/Point.cpp 
OBJPoint = $(SRCPoint:.cpp=.o)

SRCMonde = Logique/Class/tests/testMonde.cpp Logique/Class/Point.cpp Logique/Class/Ile.cpp Logique/Class/Flotte.cpp Logique/Class/IleBonus.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Base.cpp Logique/Class/Monde.cpp 
OBJMonde = $(SRCMonde:.cpp=.o)

SRCIle = Logique/Class/tests/testIle.cpp Logique/Class/Point.cpp Logique/Class/Ile.cpp 
OBJIle = $(SRCIle:.cpp=.o)

SRCIleBonus = Logique/Class/tests/testIleBonus.cpp Logique/Class/Point.cpp Logique/Class/IleBonus.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Flotte.cpp Logique/Class/Navire/Navire.cpp
OBJIleBonus = $(SRCIleBonus:.cpp=.o)

SRCPatrouilleur = Logique/Class/tests/testPatrouilleur.cpp Logique/Class/Point.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Flotte.cpp
OBJPatrouilleur = $(SRCPatrouilleur:.cpp=.o)

SRCFlotte = Logique/Flotte.cpp Logique/Class/Point.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Croiseur.cpp Logique/Class/Navire/Base.cpp
OBJFlotte = $(SRCFlotte:.cpp=.o)

SRCLogique = Logique/Tests/testLogique.cpp Logique/fichier.cpp Logique/logique.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Croiseur.cpp Logique/Class/Navire/Base.cpp
OBJLogique = $(SRCLogique:.cpp=.o)

SRCIO = Input-Output/Test/testIO.cpp Input-Output/fichier.cpp Logique/logique.cpp Logique/Class/Point.cpp Logique/Class/Ile.cpp Logique/Class/Flotte.cpp Logique/Class/IleBonus.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Croiseur.cpp Logique/Class/Navire/Base.cpp Logique/Class/Monde.cpp 
OBJIO = $(SRCIO:.cpp=.o)


all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	
testPoint: $(OBJPoint)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

testMonde: $(OBJMonde)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

testIle: $(OBJIle)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	
testIleBonus: $(OBJIleBonus)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

testPatrouilleur: $(OBJPatrouilleur)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<


testLogique: $(OBJLogique)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

testFlotte: $(OBJFlotte)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

testIO: $(OBJIO)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~ Graphique/*.o Graphique/*~ Logique/*.o Logique/*~ Input-Output/*.o Input-Output/*~ Input-Output/Test/*~ Input-Output/Test/*.o Logique/Class/*.o Logique/Class/*~ Logique/Class/Navire/*.o Logique/Class/Navire/*~ Logique/Class/tests/*.o Logique/Class/tests/*~ Logique/Tests*.o Logique/Tests/*~
mrproper: clean
	rm -rf $(EXEC)