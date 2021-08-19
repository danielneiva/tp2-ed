#ifndef ED_MERGESORT_H
#define ED_MERGESORT_H
#include "Conscience.h"
#include <chrono>

namespace MergeS{
  void mergeSort(Conscience *cons, int const left, int const right);
  void merge(Conscience *cons, int const left, int const mid, int const right);
  std::chrono::microseconds testMerge(Conscience *cons, int left, int numCons);
}
#endif