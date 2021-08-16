#ifndef ED_CONSCIENCE_H
#define ED_CONSCIENCE_H
#include <string>

struct Conscience{
  std::string name_person ="";
  std::string conscience_person ="";

  static void swapCons ( Conscience *a, Conscience *b ){
    Conscience aux = *a;
    *a = *b;
    *b = aux;
  }
};

#endif