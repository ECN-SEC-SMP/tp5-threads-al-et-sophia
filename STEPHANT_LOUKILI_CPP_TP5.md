# TP5 - Threads
---

## Noms du binome

* Sophia Loukili
* André-Louis Stéphant
---

##  Introduction
L'objectif de ce TP est de prendre en main les concepts vus en cours, ainsi que le sujet de ce TP : Les Threads.

Pour rappel, les threads (ou processus concurrents, en français) sont une notion essentielle en informatique, et permettent de faire tourner des programmes "concurrents" (c'est à dire réalier plusieurs fonctions simultanément, avec une notion d'ordonnancement pour gérer le partage des ressources et des priorités).

L'objectif de ce TP est de prendre en main ce concept, en utilisant le langage C++.

Nous avons déjà appréhendé de principe lors du module de PTR, mais nous allons ici aborder un aspect plus "pratique", appliqué à des cas concret de gestion de priorités (pour e TP, nous prendrons l'exemple d'une voie de train partagée dans les deux sens).

Nos répondrons donc aux questions demandées et apporterons une conclusion sur les différentes compétences mises en oeuvre pendant ces deux heures de travaux pratiques.


---

## Partie 1 : Les lecteurs-écrivains

### Question 1zz :

On veut ici modifier le processus lecteur et écrivains (cf dossier "TPLecteursEcrivants) afin que les ressources partagées entre les deux fonctions puissent être cohérentes.

On réutilise ici un principe vu pendant le cours, en synchronisant les sémaphores (cf cours, slide 52).

A l'aide des fonctions sem.P() et sem.V(), on peut synchroniser les tâches afin que le processus de lecture-écriture soit cohérent. On crée deux sémaphores (respectivement read et write).

Le code de ces fonctions est le suivant : 

---
void lecteur(int numLecteur)
{
  read.P(numLecteur);
  ressourcePartagee += 1;
  if (ressourcePartagee == 1)
  {
    write.P(numLecteur);
  }
  read.V(numLecteur);
  for (int i = 0; i < 4; i++)
  {
    std::cout << "Lecteur n° " << numLecteur << " en cours " << endl;
    this_thread::sleep_for(chrono::milliseconds(rand() % 20000));
    std::cout << "        Valeur lue = " << ressourcePartagee << "  " << endl;
  }
  read.P(numLecteur);
  ressourcePartagee -= 1;
  if (ressourcePartagee == 0)
  {
    write.V(numLecteur);
  }
  read.V(numLecteur);
}
---
void ecrivain(int numEcrivain)
{
  int x;

  for (int i = 0; i < 4; i++)
  {
    write.P(numEcrivain);
    std::cout << "Ecrivain n° " << numEcrivain << " en cours " << endl;
    x = ressourcePartagee;
    this_thread::sleep_for(chrono::milliseconds(rand() % 20000));
    std::cout << "valeur à incrémenter de la ressourcePartagee = " << x << "  " << endl;
    ressourcePartagee = x + 1;
    write.V(numEcrivain);
  }
}
---


---


## Partie 2 : Les trains

### Question 1 :


---

### Question 2 :

---

# Conclusion



 