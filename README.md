/************ PROGRAMMME ITD (IMAC TOWER DEFENSE) *****************/

Bonjour, nous vous remercions d'utiliser le programme ITD.

/--------- Préinstallation ---------/

1 - Créer un répertoire qui accueillera le programme

	exemple vous pouvez taper dans votre terminal :

		$ mkdir projetC
		(pour créer un dossier "projetC")

2 - Déplacer le .tgz ou .zip dans le dossier

		$ mv opengl1NanniPo.tgz ~/projetC

3 - Placer vous dans le dossier et décompresser l'archive

		$ cd ~/projetC
		$ tar -xzvf opengl1NanniPo.tgz

/--------- Les consignes avant utilisation ---------/

Pour utiliser ce programme vous aurez besoin d'intaller le package GLUT / OpenGL

1 - Pour installer le package GLUT, si vous vous trouvez sur Ubuntu, allez sur votre terminal et taper :

		$ sudo apt-get install freeglut3 freeglut3-dev

	Si vous possedez une version d'Ubuntu inférieur à la version 11.10 alors taper également la ligne ci-dessous :

		$ sudo apt-get install binutils-gold

	Si vous êtes sur Fedora, allez sur votre terminal est taper :

		sudo yum install freeglut-devel

/--------- Installation du programme ---------/
Pour installer le programme suivez les consignes suivantes (si vous vous trouvez dans le répertoire du programme) :

1 - Allez dans le dossier où se trouve le programme :

		$ cd opengl1NanniPo

2 - Ecrivez la ligne suivante dans votre terminal pour compiler le programme

		$ make


3 - Lancer le programme :


		$ ./bin/itd
		

/--------- Utilisation ---------/

Vous pouvez mettre en pause le jeu en cliquant sur la touche [p]. Si le jeu est déjà en pause ou en avance rapide alors
le jeu se remettra en play. 
Vous pouvez également mettre le jeu en avance rapide en cliquant sur la touche [a].
Pour afficher les proprietes de la derniere tour vous pouvez cliquer sur la touche [t].
Pour afficher l'aide cliquer sur la touche [h].
Pour quitter l'application vous pouvez utiliser la touche [q].


/********************************************************************************/
*      Projet réaliser par Jean Louis JANIN Laetitia NANNI et Julie PO		*
*				IMAC 1 - 2012/2013				*
/********************************************************************************/


