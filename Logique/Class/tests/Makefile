CC = g++
CFLAGS = -Wno-unused-value -W -Wall -ansi -std=c++14 -g
EXEC = testPoint testIle testFlotte

OBJ = $(SRC:.cpp=.o)

SRCPoint = testPoint.cpp ../Point.cpp 
OBJPoint = $(SRCPoint:.cpp=.o)

SRCIle = testIle.cpp ../Point.cpp ../Ile.cpp 
OBJIle = $(SRCIle:.cpp=.o)

SRCFlotte = testFlotte.cpp ../Flotte.cpp ../Point.cpp ../Navire/Navire.cpp ../Navire/Patrouilleur.cpp
OBJFlotte = $(SRCFlotte:.cpp=.o)



all: $(EXEC)

testPoint: $(OBJPoint)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<


testFlotte: $(OBJFlotte)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<


testIle: $(OBJIle)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<



clean:
	rm -rf *.o *~ ../Class/*.o ../Class/*~ ../Class/Navire/*.o ../Class/Navire/*~ ../*.o ../*~
mrproper: clean
	rm -rf $(EXEC)