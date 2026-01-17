# TP5 - Threads
---

## Noms du binôme

* Sophia Loukili
* André-Louis Stéphant
---

##  Introduction
L'objectif de ce TP est de prendre en main les concepts vus en cours, ainsi que le sujet de ce TP : Les Threads.

Pour rappel, les threads (ou processus concurrents, en français) sont une notion essentielle en informatique, et permettent de faire tourner des programmes "concurrents" (c'est-à-dire réaliser plusieurs fonctions simultanément, avec une notion d'ordonnancement pour gérer le partage des ressources et des priorités).

L'objectif de ce TP est de prendre en main ce concept, en utilisant le langage C++.

Nous avons déjà appréhendé ce principe lors du module de PTR, mais nous allons ici aborder un aspect plus "pratique", appliqué à des cas concrets de gestion de priorités (pour ce TP, nous prendrons l'exemple d'une voie de train partagée dans les deux sens).

Nous répondrons donc aux questions demandées et apporterons une conclusion sur les différentes compétences mises en oeuvre pendant ces deux heures de travaux pratiques.


---

## Partie 1 : Les lecteurs-écrivains

### Question 1 :

On veut ici modifier le processus lecteur et écrivains (cf dossier "TPLecteursEcrivants) afin que les ressources partagées entre les deux fonctions puissent être cohérentes.

On réutilise ici un principe vu pendant le cours, en synchronisant les sémaphores (cf cours, slide 52).

A l'aide des fonctions sem.P() et sem.V(), on peut synchroniser les tâches afin que le processus de lecture-écriture soit cohérent. On crée deux sémaphores (respectivement read et write).

On reprend donc le programme vu en cours en l'adaptant à notre cas pratique.

Comme pour l'exemple du cours, il existe un problème de synchronisation en cas de nombre important de lecteurs.

La fonction qui gère l'écriture peut se retrouver à ne rien avoir à écrire si trop de lecteurs 

## Partie 2 : Les trains

On réalise ici une application concrète sur une ligne de train partagée dans les deux sens.

### Question 1 / Question 2 :

On cherche ici à réaliser une application simple. On veut que les trains puissent naviguer dans les deux sens, sans entrer en collision. 

Pour cette partie, on peut se permettre de ne pas créer de sémaphores directement avec la bibliothèque. On opte plutôt pour l'utilisation d'une variable "val", qui s'incrémente/se décrémente en fonction du sens dans lequel le train arrive.

SI le train va de A vers B, alors on incrémente (et inversement).

Le programme main s'occupe ensuite d'autoriser (ou non) les trains à passer en fonction du sens, aucune modification n'a été effectuée dans ce programme (seul le .hpp a été modifié).

Cette méthode permet alors de faire naviguer les trains dans les deux sens, et empêche également les collisions. Si un train arrive dans l'autre sens, mais que le point B n'est pas débloqué, alors il patiente jusqu'à ce que le programme renvoie 'true'.

---

### Question 3 :

---

# Conclusion

Ce TP nous aura permis de mettre en application ce qui a été vu en cours de CPP mais aussi en PTR. Nous avons pu manipuler les sémaphores en C++, sur une application concrète.

Le travail mené en groupe s’est déroulé de manière fluide et efficace, l’ensemble des membres étant aligné sur les objectifs et les choix de conception. Cette bonne coordination a permis de respecter les délais sans difficulté et de produire une solution cohérente, robuste et conforme aux attentes de l’énoncé.


 