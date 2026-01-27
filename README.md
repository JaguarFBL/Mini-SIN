# Mini‑SIN — Projet STI2D (Spécialité SIN)

Mini projet de STI2D — simulation Arduino / Proteus d’un chariot automatisé entre deux points A et B.  
Ce dépôt contient deux versions du programme :
- V1 : version de base (1 cycle — convoyage simple)
- V2 : version avancée (afficheur LCD, sonde de température, afficheur 4 chiffres, compteur)

Langage principal : C++ (sketches Arduino)

---

## Objectifs pédagogiques
- Concevoir l’algorithme de déplacement du chariot entre deux points (A ↔ B).
- Savoir simuler des capteurs (boutons) et actionneurs (LEDs, buzzer) sous Proteus et sur Arduino.
- Implémenter des retours utilisateurs : moniteur série, signaux sonores, afficheurs (LCD / 4 digits).
- Structurer le code en versions (V1, V2) et en fonctions réutilisables.

---

## Organisation du dépôt
- `V1/` — code et fichiers Proteus pour la version 1 (simple)
- `V2/` — code et fichiers Proteus pour la version 2 (LCD, capteur de température, TM1637)
- `README.md` — ce fichier

---

## Consignes de rendu (format attendu)
Nom recommandé du zip : `GroupeX_Mini-SIN_vN.zip` (ex. `Groupe3_Mini-SIN_v2.zip`)

Contenu minimal :
- Dossier `Mini_SIN 1/` contenant :
  - le sketch Arduino (.ino)
  - le projet Proteus ou capture d’écran du câblage
- Dossier `Mini_SIN 2 (le retour)/` contenant :
  - le sketch Arduino (.ino)
  - Dossier `Bibliothèque/` contenant toute les bibliothèques
- `README.txt` : noms, logins, rôle de chacun


Checklist de dépôt :
- [ ] Compte rendu complet
- [ ] Projet Proteus fonctionnel
- [ ] Code commenté (fonctions séparées: son_AB(), son_DCY(), ...)
- [ ] Indication claire de la version soumise (V1 / V2)

---

## Résumé des versions (attentes fonctionnelles)

V1 — Objectifs
- 1 cycle de convoyage A → B → A.
- Détection des positions par deux capteurs (fcg / fcd) simulés par des boutons.
- Immobilisation 4 s au point B pour chargement.
- Affichage permanent sur moniteur série des états (position initiale, marche avant, marche arrière, point B).

V2 — Objectifs
- Même fonctionnement que V1 mais avec :
  - Déploiement sur afficheur LCD (rgb_lcd).
  - Affichage du nombre de tours sur afficheur 4 chiffres (TM1637).
  - Mesure de la température (sonde DS18B20) et affichage éventuel.
  - Signaux sonores pour événements (arrivée A/B et fin de cycle).

---

## Pinouts (tels qu’utilisés dans les deux sketches fournis)

V1 (fichier initial — version basique)
- LEDAV (avant) : D2
- LEDAR (arrière): D3
- DCY (bouton départ) : D4
- FCG (fin course A) : D5
- FCD (fin course B) : D6
- BUZ (buzzer) : D10

V2 (version avancée — LCD + TM1637 + DS18B20)
- LEDAV : D9
- LEDAR : D3
- DCY : D4
- FCG : D5
- FCD : D6
- BUZ : D10
- TM1637 CLK : D7
- TM1637 DIO : D8
- DS18B20 OneWire : D2
- LCD : via la bibliothèque rgb_lcd (sérial I2C ou pins selon ton montage)

---

## Exemples d’affichages attendus

Exemple moniteur série (V1) :
```
Position initiale
Démarrage en cours....
Marche avant
Arrivé au point B
Chargement 4s
Marche arrière
Arrivé au point A
Fin du cycle 1/1
```

Exemple LCD / TM1637 (V2) :
- LCD : ligne 1 → "Marche avant", ligne 2 → "Temp: 24.3 C"
- TM1637 : afficheur 0001 → nombre de tours

---

## Dépannage / erreurs fréquentes
- Le code ne compile pas : vérifie les bibliothèques (rgb_lcd, TM1637, DallasTemperature, OneWire).
- Conflits de pins : évite d’utiliser la même pin pour plusieurs périphériques (ex. OneWire sur la même pin que LED dans V1).
- Bouton qui déclenche plusieurs fois : ajouter debounce.
- TM1637 affiche des valeurs étranges : vérifier conversion float→int et initialisation de la librairie.

---

## Références
- Créer des sons avec Arduino (buzzer) — https://ledisrupteurdimensionnel.com/arduino/creer-des-sons-avec-arduino-buzzer/#sons_arduino
- Tone Arduino (archive) — https://web.archive.org/web/20211209095312/http://www.mon-club-elec.fr/pmwiki_reference_arduino/pmwiki.php?n=Main.Tone
- Grove 4-Digit Display / TM1637 — https://wiki.seeedstudio.com/Grove-4-Digit_Display/
- DallasTemperature / OneWire — bibliothèques Arduino

---

Réalisé par :
-------------
  -  <a href="https://github.com/JaguarFBL">Louan</a><br>
  -  <a href="https://github.com/EsteJAAJ">Estevan</a>



