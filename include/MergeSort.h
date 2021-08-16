#ifndef ED_MERGESORT_H
#define ED_MERGESORT_H
#include "Conscience.h"

namespace MergeS{
  void mergeSort(Conscience *cons, int const begin, int const end);
  void merge(Conscience *cons, int const left, int const mid, int const right);

}
#endif