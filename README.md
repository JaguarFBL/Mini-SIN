# SIN

V1 objectifs :
--------------

Réaliser l’algorithme, le programme chariot_V1 comprenant :
-	Une gestion des déplacements par détection des points A et B avec les capteurs fcg et fcd simulés par deux boutons poussoirs
-	Une immobilisation de 4 secondes au point B pour chargement avant un retour au point A.
-	L’affichage permanent sur le moniteur série des différents états du chariot (chariot en position initiale, chariot en marche avant, chariot en marche arrière et chariot au point B)

V2 objectifs :
--------------

Compléter votre programme V2 pour que : 
-	Le chariot étant au point A, une impulsion sur le bouton poussoir DCY permet d'effectuer 3 allers-retours, entre les points A et B.
-	A chaque extrémité, A ou B, le chariot reste immobilisé 4 secondes pour chargement ou déchargement.
-	Le moniteur série doit afficher en permanence les états du chariot ainsi que le nombre d'aller-retour effectués


V3.1 objectifs :
----------------

Compléter votre programme V3.1 pour que :
•	SON_AB : Lorsque le robot arrive A ou point B, il émet 2 bips de fréquence 440Hz à une fréquence de 1 Hz
•	SON_FCY : Lorsque le robot a fini un cycle, il émet 3 bips de fréquence 880 Hz à une fréquence de 1 Hz

V3.2 objectifs :
----------------

Intégrer les 2 types de son dans 2 fonctions à placer en fin de programme, et les appeler dans votre programme V3.2 :
•	Fonction « son_AB() » : pour le son lorsque le robot arrive au point A ou B.
•	Fonction « son_FCY() » : pour le son lorsque le robot à fini son cycle.
Mettre des commentaires dans votre programme pour séparer visuellement toutes les fonctions, en mettant par exemple : //======= Fonction SON_AB =======
