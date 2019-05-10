CC		=	gcc
CFLAGS	=	-Wall -O2 -g
LDFLAGS	=   -lSDL -lGLU -lGL -lm -lglut -lSDL_image
BIN		=	./bin/
INC 	=	./include/
OBJ		=	./obj/
SRC		=	./src/

$(BIN)towerdefense: $(OBJ)main.o $(OBJ)map.o $(OBJ)monster.o $(OBJ)tower.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ)main.o: $(SRC)main.c $(INC)map.h $(INC)monster.h $(INC)tower.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)map.o: $(SRC)map.c $(INC)map.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)monster.o: $(SRC)monster.c $(INC)monster.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)tower.o: $(SRC)tower.c $(INC)tower.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)installation.o: $(SRC)installation.c $(INC)installation.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)joueur.o: $(SRC)joueur.c $(INC)joueur.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

clean:
	rm -rf $(OBJ)*.o