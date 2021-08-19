#ifndef ED_QUICKSORT_H
#define ED_QUICKSORT_H
#include "Conscience.h"
#include <chrono>

namespace QuickS{
  void partition ( Conscience *cons, int left, int right, int *i, int *j );
  void quickSort ( Conscience *cons, int left, int right );
  std::chrono::microseconds testQuick(Conscience *cons, int left , int right);
}

#endif