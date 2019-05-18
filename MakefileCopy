# Compilateur
CC = gcc
# $(BIN) est la nom du binaire genere
BIN = itd
BIN_PATH = bin
# FLAG
CFLAGS = -Wall -O2 -g
LDFLAGS= -lglut -lGL -lGLU -lm -lSDL -lSDL_image
# INCLUDES
INC_PATH = -I include
# LIB
LIB_PATH = lib
# SRC
SRC_PATH = src
SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')
# OBJET
OBJ_PATH = obj
OBJ = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))

all: $(BIN)

$(BIN):$(OBJ)
	@echo "**** $@ ****"
	@mkdir -p $(BIN_PATH)
	$(CC) -o $(BIN_PATH)/$(BIN) $(OBJ) $(LDFLAGS)
	@echo "******* Compilation OK *******\n"
	@echo "Commande clavier : \n"
	@echo "[p] : Mettre le jeu en pause / play\n"
	@echo "[a] : Mettre le jeu en avance rapide\n"
	@echo "[t] : Afficher les proprietes de la derniere tour\n"
	@echo "[h] : Afficher l'aide\n"
	@echo "Cliquez sur texture pour avoir une carte sans l'affichage des noeuds de chaque chemin et des zones constructibles.\n"
	@echo "*******************************************************************\n"
	@echo "******* Pour ouvrir le fichier taper : ./$(BIN_PATH)/$(BIN) *******\n"
	@echo "*******************************************************************\n"


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "**** $@ ****"
	@mkdir -p "$(@D)"
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_PATH)
	@echo "Creation $@ OK"
	@echo "****************"

clean:
	rm -rf $(OBJ)
	@echo "File .o are all removed" 	

mrproper: clean
	rm -rf $(BIN_PATH)/$(BIN)
	@echo "File .o and .exe are all removed"
	
