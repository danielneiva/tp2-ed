#include "Conscience.h"

namespace Utils {
  void loadConsciences(Conscience *cons, std::string file, int numCons);
  void listConsciences(Conscience *cons, int numCons);
  void writeConsciences(Conscience *cons, int numCons);
  int isStable(Conscience *cons, int numCons);
}