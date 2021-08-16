#include "RadixSort.h"
#include "Conscience.h"
#include <chrono>

void RadixS::radixExchangeSort(Conscience *cons, int left, int right, int bit, int tam){
  int i = left;
  int j = right;
  if (right > left && bit >=0) {
    while ( j != i ) {
      while (cons[i].conscience_person[tam-bit] == '0' && i < j) i++;
      while (cons[j].conscience_person[tam-bit] == '1' && i < j) j--;
      Conscience::swapCons(&cons[i], &cons[j]);
    }
    if (cons[right].conscience_person[tam-bit] == '0') j++;
    radixExchangeSort(cons, left, j-1, bit-1, tam);
    radixExchangeSort(cons, j, right, bit-1, tam);
  }
}

std::chrono::microseconds RadixS::testRadix(Conscience *cons, int left , int right, int bit, int tam){
  auto start = std::chrono::high_resolution_clock::now();
  RadixS::radixExchangeSort(cons, left, right, bit, tam);
  auto end = std::chrono::high_resolution_clock::now();
  auto durationRadix = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
  return durationRadix;
}