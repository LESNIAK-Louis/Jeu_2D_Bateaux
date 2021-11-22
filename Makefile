CC = g++
CFLAGS = -Wno-unused-value -W -Wall -ansi -std=c++14 -g
LIBS = -L./SDL2_ttf/.libs -L./SDL2_image/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image
INCLUDES = -I./SDL2_ttf -I./SDL2_image
EXEC = main testPoint testIle testIleBonus testLogique
SRC = main.cpp Graphique/fonctions_SDL.cpp Input/input.cpp
OBJ = $(SRC:.cpp=.o)

SRCPoint = Logique/Class/tests/testPoint.cpp Logique/Class/Point.cpp 
OBJPoint = $(SRCPoint:.cpp=.o)

SRCIle = Logique/Class/tests/testIle.cpp Logique/Class/Point.cpp Logique/Class/Ile.cpp 
OBJIle = $(SRCIle:.cpp=.o)

SRCIleBonus = Logique/Class/tests/testIleBonus.cpp Logique/Class/Point.cpp Logique/Class/IleBonus.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Flotte.cpp Logique/Class/Navire/Navire.cpp
OBJIleBonus = $(SRCIleBonus:.cpp=.o)

SRCPatrouilleur = Logique/Class/tests/testPatrouilleur.cpp Logique/Class/Point.cpp Logique/Class/Navire/Patrouilleur.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Flotte.cpp
OBJPatrouilleur = $(SRCPatrouilleur:.cpp=.o)

SRCFlotte = Logique/Flotte.cpp Logique/Class/Point.cpp Logique/Class/Navire/Navire.cpp Logique/Class/Navire/Patrouilleur.cpp
OBJFlotte = $(SRCFlotte:.cpp=.o)

SRCLogique = Logique/Tests/testLogique.cpp Logique/fichier.cpp Logique/logique.cpp Logique/Class/Navire/Patrouilleur.cpp
OBJLogique = $(SRCLogique:.cpp=.o)


all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	
testPoint: $(OBJPoint)
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

testPatrouilleur: $(OBJIleBonus)
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

clean:
	rm -rf *.o *~ Graphique/*.o Graphique/*~ Logique/*.o Logique/*~ Input/*.o Input/*~ Logique/Class/*.o Logique/Class/*~ Logique/Class/Navire/*.o Logique/Class/Navire/*~ Logique/Class/tests/*.o Logique/Class/tests/*~ Logique/Tests*.o Logique/Tests/*~
mrproper: clean
	rm -rf $(EXEC)