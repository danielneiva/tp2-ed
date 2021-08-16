#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <stdlib.h>
#include "Conscience.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include "Utils.h"


int main(int argc, char **argv) {

  /**
    * Get file name, type of test to be executed and number of consciences to be sorted
    * 
    * 
  */ 
  std::string fileName = argv[1];
  int testType = strtol(argv[2], nullptr, 0);
  int numCons = strtol(argv[3], nullptr, 0);;
  Conscience *rellocatorCO = new Conscience[numCons];
  Utils::loadConsciences(rellocatorCO, fileName, numCons);

   switch (testType){
    case 2:
      std::chrono::microseconds radix = RadixS::testRadix(rellocatorCO, 0, numCons-1, 7, 7);
      std::chrono::microseconds quick = QuickS::testQuick(rellocatorCO, 0 , numCons-1);
      Utils::listConsciences(rellocatorCO, numCons);
      std::cout << "Teste concluido. Os resultados são: \n - RadixSort demorou " 
                << radix.count() << " microsegundos.\n - QuickSort demorou " << quick.count() 
                << " microsegundos.\n";
  } 

  
/* 
  // QUICKSORT
  auto start = std::chrono::high_resolution_clock::now();
  QuickS::quickSort(rellocatorCO, 0, numCons -1 );
  auto end = std::chrono::high_resolution_clock::now();
*/
/* 
  // MERGESORT
  auto start = std::chrono::high_resolution_clock::now();
  MergeS::mergeSort(rellocatorCO, 0, numCons -1 );
  auto end = std::chrono::high_resolution_clock::now();
*/
/* 
  auto start = std::chrono::high_resolution_clock::now();
  HeapS::heapSort(rellocatorCO, numCons  );
  auto end = std::chrono::high_resolution_clock::now();
*/  
/*   Utils::listConsciences(rellocatorCO, numCons);
  auto start = std::chrono::high_resolution_clock::now();
  RadixS::radixExchangeSort(rellocatorCO, 0, numCons-1, 7, 7 );
  auto end = std::chrono::high_resolution_clock::now();
  auto durationMS = std::chrono::duration_cast<std::chrono::microseconds>(end - start );

  std::cout << "It took: " << durationMS.count() << " Microseconds" << std::endl; */
  delete [] rellocatorCO;
  return 0;
}