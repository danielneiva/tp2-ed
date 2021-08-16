#ifndef ED_HEAPSORT_H
#define ED_HEAPSORT_H
#include "Conscience.h"
#include <chrono>

namespace HeapS{
  void heapify(Conscience *cons, int heapSize, int index);
  void heapSort(Conscience *cons, int numCons);
  std::chrono::microseconds testHeap(Conscience *cons, int numCons);
}
#endif