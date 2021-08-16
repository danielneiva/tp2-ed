#ifndef ED_RADIXSORT_H
#define ED_RADIXSORT_H
#include "Conscience.h"
#include <chrono>

namespace RadixS{
  void radixExchangeSort(Conscience *cons, int left, int right, int bit, int tam);
  std::chrono::microseconds testRadix(Conscience *cons, int left , int right, int bit, int tam);
}
#endif