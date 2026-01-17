#include <iostream>
#include <thread>
#include "Semaphore.hpp"

int ressourcePartagee; // Variable partagée entre lecteurs et écrivains
Semaphore read(1);     // Sémaphore de lecture
Semaphore write(1);    // Sémaphore d'écriture

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

void ecrivain(int numEcrivain)
{
  int x;

  write.P(numEcrivain);

  if (ressourcePartagee == 0)
  {
    for (int i = 0; i < 4; i++)
    {
      std::cout << "Ecrivain n° " << numEcrivain << " en cours " << endl;
      x = ressourcePartagee;
      this_thread::sleep_for(chrono::milliseconds(rand() % 20000));
      std::cout << "valeur à incrémenter de la ressourcePartagee = " << x << "  " << endl;
      ressourcePartagee = x + 1;
    }
  }
  write.V(numEcrivain);
}

int main()
{
  const int nbr = 8;
  std::thread r[nbr];
  std::thread w[nbr];
  int ressourcePartagee = 0;

  for (int i = 1; i < nbr; i++)
  {
    r[i] = std::thread(lecteur, -i);
    w[i] = std::thread(ecrivain, i);
  }
  // Join des threads
  for (int i = 1; i < nbr; i++)
  {
    r[i].join();
    w[i].join();
  }

  return 0;
}
