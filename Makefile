CC		=	gcc
CFLAGS	=	-Wall -O2 -g
LDFLAGS	=   -lSDL -lGLU -lGL -lm -lglut -lSDL_image
SRC		=	./src/
OBJ		=	./obj/
BIN		=	./bin/
INCL	=	./include/


$(BIN)itd: $(OBJ)main.o $(OBJ)click.o $(OBJ)color.o $(OBJ)draw.o $(OBJ)installation.o $(OBJ)joueur.o $(OBJ)map.o $(OBJ)monstre.o $(OBJ)shot.o $(OBJ)struct.o $(OBJ)texture.o $(OBJ)tower.o
#(OBJ)monster.o $(OBJ)tower.o $(INCL)installation.o $(OBJ)joueur.o $
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ)main.o: $(SRC)main.cpp $(INCL)color.h $(INCL)map.h #$(INCL)monstre.h $(INCL)tower.h $(INCL)installation.h $(INCL)joueur.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)click.o: $(SRC)click.cpp $(INCL)click.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)color.o: $(SRC)color.cpp $(INCL)color.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)draw.o: $(SRC)draw.cpp $(INCL)draw.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)installation.o: $(SRC)installation.cpp $(INCL)installation.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)joueur.o: $(SRC)joueur.cpp $(INCL)joueur.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)map.o: $(SRC)map.cpp $(INCL)map.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)monstre.o: $(SRC)monstre.cpp $(INCL)monstre.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)shot.o: $(SRC)shot.cpp $(INCL)shot.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)struct.o: $(SRC)struct.cpp $(INCL)struct.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)texture.o: $(SRC)texture.cpp $(INCL)texture.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

$(OBJ)tower.o: $(SRC)tower.cpp $(INCL)tower.h
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)
#$(OBJ)monster.o: $(SRC)monster.cpp $(INCL)monster.h
#	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

#$(OBJ)tower.o: $(SRC)tower.cpp $(INCL)tower.h
#	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

#$(OBJ)installation.o: $(SRC)installation.c $(INCL)installation.h
#	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

clean:
	rm -rf $(OBJ)*.o