Projet Refuge ChenYI-TECH

Ce projet pour but de simuler la gestion d’un refuge pour animaux. L’utilisateur peut y ajouter de nouveaux animaux, rechercher ceux déjà présents à l'aide d'un ou plusieurs critères, permettre leur adoption, faire l'inventaire du refuge par rapport aux différents âges des animaux ou encore gérer le temps de nettoyage du refuge.
Ce refuge peut accueillir jusqu’à 50 animaux. Chaque animal est caractérisé par un numéro d’identification, un nom, une espèce, une année de naissance, un poids et une éventuelle description. Les données sont stockées dans un fichier texte (liste_animaux.txt) et mises à jour dynamiquement.

FONCTIONNALITÉS 

À travers le menu, on peut :

Rechercher un animal : par nom, espèce ou tranche d’âge (jeune, âge moyen, senior).
Ajouter un animal confié au refuge : La saisie est guidée, vous devrez entrer les différentes informations de l'animal afin de l'ajouter au sein du refuge. Les données sont ajoutées au fichier texte.
Adopter un animal : l’animal est supprimé de la base, il suffit simplement de saisir son numéro d'identification.
Afficher l’inventaire : affiche le nombre total d'animaux et ensuite une répartition par quartile d’âge (les plus jeunes aux plus âgés).
Prévoir le temps de nettoyage : calcule le temps total nécessaire pour entretenir les enclos des animaux, selon leur espèce.
Quitter : Sortie du programme.

ORGANISATION DU PROJET

Voici les fichiers principaux :

Un dossier Animaux contenant un fichier texte liste_animaux.txt (base de données des animaux du refuge).
refuge.h : contient les structures et les prototypes (de fonctions et de procédures).
makefile : permet de compiler rapidement le programme.
menu.c : gère le menu principal et la navigation utilisateur et permet de choisir parmis les différents choix proposés.
main.c : point d’entrée du programme.

fonction_stockage.c : lit le fichier liste_animaux.txt, remplit le tableau d’animaux et le sauvegarde.

fonction_ajouter.c : ajoute un nouvel animal au tableau et au fichier texte.

fonction_adoption.c : supprime un animal du fichier à partir de son ID.

fonction_variantes.c : 2 fonctions sont présentes : nettoyage : indique combien de temps de nettoyage sera nécessaire
                                                    inventaire âge : affiche le nombre total d'animaux et les répartis par quartile pour ensuite en afficher le nombre.

rechercheNv.c : permet de rechercher un ou plusieurs animaux selon 3 différents critères (nom, espèce et type d'âge).

Nous avons aussi crée un fichier Makefile qui permet de compiler plus facilement notre programme.


