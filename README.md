# Game Memory

## Idea

Un jeu de memory avec afichage graphique (GraPic) dans l'univers des mangas !

![image](image/Memory1.jpg)
![image](image/Memory2.jpg)

Il y a 18 images choisis aleatoirement, elles sont stockees dans /data/memory donc vous pouvez ainsi les remplacer par celles de votre choix

## Subject

Pour faire ce projet en suivant les consignes d'un TP, j'ai d'abord creer un memory simple en texte/ascii (l'affichage est sur le terminal), le repo de ce projet est dans mon Cpp_perso/Memory.
Pour ensuite utiliser la librairie GraPic pour faire une version graphique.

Voici le sujet:
```
Version texte

1. Écrire en C/C++ une procédure demandant au joueur de choisir deux cases et
d’afficher le contenu de ces deux cases en les restituant dans la grille complète.

2. Écrire en C/C++ une fonction de vérification du choix de l’utilisateur. Si les deux
cases choisies sont identiques la fonction renverra 0 sinon elle renverra 1.

3. Simuler le jeu à deux joueurs jusqu’à ce que toutes les paires aient été trouvées.

Version GrAPiC

Afin de faciliter le codage de l’application en TP sous GrAPiC, nous allons écrire ici quelques
sous-programmes.
Dans la version graphique, vous allez utiliser des images plutôt que les mots de la version
texte. Les fichiers d’images seront copiés dans le dossier data de Grapic et seront nommés de
la manière suivante : Image_Memory_XX.jpg avec XX un entier compris entre 01 et 18.
Afin de pouvoir positionner aléatoirement les images dans la grille de jeu, il est impératif de
pouvoir générer automatiquement le nom du fichier qui sera associé à l’image contenue dans
la grille. Pour éviter les doublons (de paires de cartes) il faudra veiller à ce que l’indice choisi
de manière aléatoire n’ait pas déjà été sélectionné. On utilisera pour cela un tableau
t_indice_image tableau de MAX_IMAGES cases de type entier.

1. Ecrire en C/C++ une fonction qui à partir du tableau t_indice_image choisit
aléatoirement et retourne un indice non utilisé dans ce tableau.

2. Ecrire en C/C++ une procédure qui à partir d’un entier passé en paramètre génère le
nom du fichier image associé.

3. Ecrire en C/C++ une procédure qui positionne dans la grille du mémory deux fois
l’image dont le nom a été créé précédemment et marque à 1 l’indice utilisé dans le
tableau t_indice_image.
```

# GrAPiC 

## Starting

Linux, Windows and Mac instruction :

http://licence-info.univ-lyon1.fr/grapic

## Introduction

GrAPiC is a small, easy-to-use framework to add graphical functionalities to your C/C++ code. 
Its main goal is to provide easy graphical functions to be used in introduction courses of algorithm and programming in C/C++. 
It is based on SDL2 but to use it you need to know only few very simples functions. 
The Grapic archive comes with the needed SDL part, you do not have to install SDL. Just unzip and enjoy ! 

## Starting

Compiling from the github (which is not the standard way).

* On Linux you need to install:
- g++
- doxygen
- zip
- lib-sdl2-dev lib-sdl2 sd2_image... sdl2_ttf...

1. sudo apt install g++ premake4 zip doxygen libsdl2-dev libsdl2-mixer-dev libsdl2-image-dev
2. make premake
3. make
(4. script/make_linux_test.sh): to test the archive doc/download/grapic-linux.tgz
(5. script/make_web.sh): to create the zip files in doc/download or to sync everything to the webpage (need passwd).


* On windows
0. Install CB 20
1. run premake-cb20.bat to generate the projects files    or     run premake-lifami.bat to generate lifami projects 
2. open build/windows-cb20/grapic.workspace

## Best way to make a projet in windows

(windows): 
 - Open build/windows-cb20/grapic.workspace in CodeBlocks
 - In the left part (Management) of the logiciel, double clic in the projet of yours choice (it's those in /apps)
 - Finally clic in the green arrow in the top of the screen

![OpenFolder](image/OpenFolder.jpg)
![OpenFile](image/OpenFile.jpg)

## Put your new project in GraPic

Add your directory with your cpp files in "apps" and add the path in "premake4".

