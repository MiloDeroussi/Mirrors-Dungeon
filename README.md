-------------------------------------- BUT DU JEU --------------------------------------

Le jeu est un petit rogue-like, chaque partie est unique dans la progression. 

Les salles sont générées aléatoirement à chaque partie, piochant dans le fichier xml 
parmi les configurations possibles.

Il faut tuer dans chaque salle tout les ennemis pour pouvoir avancer automatiquement
à la salle suivante.

Il y a aussi des salles de soins, soignant un pourcentage de PV indiqué par le sprite.

----------------------------------------- COMBAT ---------------------------------------

La mécanique principale du système de combat est le drag and drop: 

En glissant avec le clique gauche, on peut déplacer le pistolet. 
On peut tirer une balle toutes les deux secondes en appuyant sur _Espace_

En glissant avec le clique droit, on peut déplacer le bouclier.
Le bouclier détruit les balles ennemies (rouge)

--------------------------------- BUGS ET DEFAUTS CONNUS ---------------------------------

On s'est rendu compte trop tard pour modifier que l'on a choisi une très mauvaise implémentation
pour les munitions des monstres et du joueur. En effet, on stocke en mêmoire a peu près 250 munitions lors 
du lancement du jeu alors que ce n'est pas du tout nécessaire. Cela fait que le lancement du jeu est relativement long 
et consomme 400MO de mémoire. Idéalement il aurait fallu changer totalement l'implémentation pour avoir une référence à la munition et 
pouvoir l'invoquer quand on le souhaite.

Un autre bug mineur connu et que l'on n'a pas encore compris est parfois la disparation du sprite d'une munition quand on tue un autre ennemi.
Cela est un bug uniquement visuel.

--------------------------------- PATTERN & LIBRAIRIES -----------------------------------

On a implémenté deux design pattern:

  - Plusieurs factories pour pouvoir créer les salles par exemple. On possède une classe Salle générale et deux sous classes HSalle et ESalle
avec des propriétés propres découlant de Salle.

  - Un state machine pattern pour gérer les menus.

L'aspect visuel du jeu est programmé sous SFML.
Les informations sur les salles sont stockées sous XML et exploités avec PUGIXML.


