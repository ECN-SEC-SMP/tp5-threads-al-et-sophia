#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class Controleur
{
public:
  Controleur(int valeur_initiale) : val(valeur_initiale)
  {
    cout << "valeur initiale du sémaphore = " << val << endl;
  }

  // Entrée en B, si val <=0, return true (autorisation de passer)
  inline bool controlinEnB(int numero)
  {
    if (val <= 0 && val >= -2) // Maximum de trains autorisés dans ce sens = 2
    {
      val--;
      return true;
    }
    return false;
  }

  // Entrée en A, si val >=0, return true (autorisation de passer)
  inline bool controlinEnA(int numero)
  {
    if (val >= 0 && val <= 2) // Maximum de trains autorisés dans ce sens = 2
    {
      val++;
      return true;
    }
    return false;
  }

  inline bool controloutEnB(int numero)
  {
    val--; // "Incrément" du sens vers B
    return true;
  }

  inline bool controloutEnA(int numero)
  {
    val++; // "Incrément" du sens vers A
    return true;
  }

private:
  int val = 0; // Direction du train sur la voie
};

#endif // CONTROLEUR_HPP
