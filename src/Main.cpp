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

  std::chrono::microseconds radixExecTime;
  std::chrono::microseconds quickExecTime;
  std::chrono::microseconds mergeExecTime;
  std::chrono::microseconds heapExecTime;
  bool bStability;

   switch (testType){
    case 1:
      heapExecTime = HeapS::testHeap(rellocatorCO, numCons-1);
      quickExecTime = QuickS::testQuick(rellocatorCO, 0 , numCons-1);
      Utils::listConsciences(rellocatorCO, numCons);
      bStability = Utils::isStable(rellocatorCO, numCons);
      std::cout << "A combinação " << (bStability ? "é ": "não é ") << "estável" << std::endl;
      std::cout << "Teste concluido. Os resultados são: \n - HeapSort demorou " 
                << heapExecTime.count() << " microsegundos.\n - QuickSort demorou " 
                << quickExecTime.count() << " microsegundos.\n";
      break;
    case 2:
      radixExecTime = RadixS::testRadix(rellocatorCO, 0, numCons-1, 7, 7);
      quickExecTime = QuickS::testQuick(rellocatorCO, 0 , numCons-1);
      Utils::listConsciences(rellocatorCO, numCons);
      bStability = Utils::isStable(rellocatorCO, numCons);
      std::cout << "A combinação " << (bStability ? "é ": "não é ") << "estável" << std::endl;
      std::cout << "Teste concluido. Os resultados são: \n - RadixSort demorou " 
                << radixExecTime.count() << " microsegundos.\n - QuickSort demorou " 
                << quickExecTime.count() << " microsegundos.\n";
      break;
    case 3:
      heapExecTime = HeapS::testHeap(rellocatorCO, numCons-1);
      mergeExecTime = MergeS::testMerge(rellocatorCO, numCons-1);
      Utils::listConsciences(rellocatorCO, numCons);
      bStability = Utils::isStable(rellocatorCO, numCons);
      std::cout << "A combinação " << (bStability ? "é ": "não é ") << "estável" << std::endl;
      std::cout << "Teste concluido. Os resultados são: \n - HeapSort demorou " 
                << heapExecTime.count() << " microsegundos.\n - MergeSort demorou " 
                << mergeExecTime.count() << " microsegundos.\n";
      break;
    case 4:
      radixExecTime = RadixS::testRadix(rellocatorCO, 0, numCons-1, 7, 7);
      mergeExecTime = MergeS::testMerge(rellocatorCO, numCons-1);
      Utils::listConsciences(rellocatorCO, numCons);
      bStability = Utils::isStable(rellocatorCO, numCons);
      std::cout << "A combinação " << (bStability ? "é ": "não é ") << "estável" << std::endl;
      std::cout << "Teste concluido. Os resultados são: \n - RadixSort demorou " 
                << radixExecTime.count() << " microsegundos.\n - MergeSort demorou " 
                << mergeExecTime.count() << " microsegundos.\n";
      break;
  } 
  delete [] rellocatorCO;
  return 0;
}