# Mini-SIN

## Introduction
Ce dépôt contient les consignes et les éléments du projet Mini‑SIN, réalisé en binômes. Le but est de concevoir et tester un chariot automatisé (simulation Proteus et Arduino) qui circule entre deux points A et B, géré par des capteurs de fin de course et un bouton de départ.

---

## Table des matières
- [Consignes générales](#consignes-générales)  
- [Prérequis](#prérequis)  
- [Livrables attendus](#livrables-attendus)  
- [Descriptions des versions](#descriptions-des-versions)  
- [Simulation / Exécution](#simulation--exécution)  
- [Bonus](#bonus)  
- [Sources et références](#sources-et-références)

---

## Consignes générales
- Travail en binôme. Rédiger un compte rendu (format Word ou PDF) et le sauvegarder dans un dossier par binôme.
- Déposer un dossier zippé contenant :
  - Le compte rendu des activités (suivre le plan du document fourni).
  - Chaque projet Proteus, renommé avec sa version (voir ci‑dessous).
  - Tout code Arduino utilisé.
- Utiliser le vocabulaire technique de l’énoncé.

---

## Prérequis
- Arduino IDE (version recommandée : préciser si nécessaire)  
- Proteus (version recommandée)  
- Accès aux bibliothèques Grove (si affichage Grove utilisé)  
- Buzzer / LED / afficheur 4 chiffres (pour les tests matériels, optionnel en simulation)

---

## Livrables attendus
Nom du fichier zip recommandé : `GroupeX_Mini-SIN_vN.zip`  
Contenu minimal du zip :
- `CompteRendu.docx` ou `CompteRendu.pdf`
- `Proteus/` (projets Proteus, fichiers .PSD/.PRO ou similaires)
- `Arduino/` (fichiers .ino, bibliothèques utilisées)
- `README_equipe.txt` (nom des membres, login, date)

Checklist de dépôt :
- [ ] Compte rendu présent
- [ ] Projet Proteus(s) avec version correctement nommée
- [ ] Code Arduino commenté (fonctions clairement séparées)
- [ ] Instructions pour exécuter la simulation

---

## Descriptions des versions
V1 — 1 cycle de convoyage
- Gestion des déplacements par détection des points A et B (capteurs fcg et fcd simulés par boutons poussoirs).
- Immobilisation de 4 secondes au point B pour chargement puis retour vers A.
- Affichage permanent sur le moniteur série des états (position initiale, marche avant, marche arrière, au point B).

V2 — 3 cycles de convoyage
- Depuis A, une impulsion sur le bouton DCY déclenche 3 allers-retours entre A et B.
- À chaque extrémité (A ou B), immobilisation de 4 secondes.
- Moniteur série affichant les états et le nombre d’allers‑retours effectués.

V3.1 — Sons
- SON_AB : à l’arrivée en A ou B, le robot émet 2 bips (440 Hz) à 1 Hz.
- SON_FCY : à la fin d’un cycle, le robot émet 3 bips (880 Hz) à 1 Hz.

V3.2 — Fonctions
- Intégrer les deux sons dans des fonctions séparées à placer en fin de programme :
  - `son_AB()`
  - `son_FCY()`
- Ajouter des commentaires pour séparer visuellement les fonctions (ex. `// ======= Fonction SON_AB =======`).

---

## Simulation / Exécution
- Les capteurs fin de course (fcg, fcd) et le bouton DCY sont simulés par des boutons poussoirs.
- Les mouvements sont simulés par deux LEDs : `ledav` (avant) et `ledar` (arrière).
- Le moniteur série doit afficher en permanence :
  - État courant (ex. "Position initiale", "Marche avant", "Au point B", etc.)
  - Compteur d’allers-retours (pour V2+)

Exemple d’affichage série attendu (extrait) :
```
Position initiale
Départ : cycle 1/3
Marche avant...
Arrivé au point B
Chargement 4s
Marche arrière...
Arrivé au point A
Fin du cycle 1/3
```

(pinout / schéma) — À ajouter : indiquer ici les pins Arduino utilisés pour fcg, fcd, DCY, ledav, ledar, buzzer, afficheur.

---

## Bonus
- Affichage du nombre de tours sur un afficheur 4 chiffres (Mini_SIN_Arduino_V1).
- Affichage de la température sur afficheur 4 chiffres (Mini_SIN_Arduino_V2).
Préciser si ces bonus sont évalués et comment les soumettre.

---

## Sources et références
- Créer des sons avec Arduino (buzzer) — ledisrupteurdimensionnel.com  
- Reference Tone Arduino (archive) — mon-club-elec.fr  
- Grove 4-Digit Display — SeeedStudio Wiki (Grove LCD / 4-digit)

Liens originaux :
- https://ledisrupteurdimensionnel.com/arduino/creer-des-sons-avec-arduino-buzzer/#sons_arduino
- https://web.archive.org/web/20211209095312/http://www.mon-club-elec.fr/pmwiki_reference_arduino/pmwiki.php?n=Main.Tone
- https://wiki.seeedstudio.com/Grove-LCD_RGB_Backlight/
- https://wiki.seeedstudio.com/Grove-4-Digit_Display/

---

## Remarques finales / Suggestions
- Corriger les fautes et supprimer les balises HTML inutiles.  
- Ajouter un schéma de câblage (vidéo) ou un fichier Proteus clair pour aider la correction.  

