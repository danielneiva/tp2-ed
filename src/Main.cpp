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


  std::string env="production";

  if (env == "development"){  
    std::chrono::microseconds radixExecTime;
    std::chrono::microseconds quickExecTime;
    std::chrono::microseconds mergeExecTime;
    std::chrono::microseconds heapExecTime;
    std::ofstream resultados;
    int stabilityErr;

    switch (testType){
      case 1:
        heapExecTime = HeapS::testHeap(rellocatorCO, numCons-1);
        quickExecTime = QuickS::testQuick(rellocatorCO, 0 , numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        std::cout << "Teste concluido. Os resultados são: \n - HeapSort demorou " 
                  << heapExecTime.count() << " microsegundos.\n - QuickSort demorou " 
                  << quickExecTime.count() << " microsegundos.\n";
        stabilityErr = Utils::isStable(rellocatorCO, numCons);
        std::cout << "A combinação " 
              << (stabilityErr == 0 ? "é estável": "não é estável. Número de erros: " + std::to_string(stabilityErr)) << std::endl;
        resultados.open("resultados/resultados-1-" + std::to_string(numCons) + ".txt", std::ios::app);
        resultados << heapExecTime.count() << " + " << quickExecTime.count() << " + " << std::endl;
        resultados.close();
        Utils::writeConsciences(rellocatorCO, numCons);
        break;

      case 2:
        radixExecTime = RadixS::testRadix(rellocatorCO, 0, numCons-1, 7, 7);
        quickExecTime = QuickS::testQuick(rellocatorCO, 0 , numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        std::cout << "Teste concluido. Os resultados são: \n - RadixSort demorou " 
                  << radixExecTime.count() << " microsegundos.\n - QuickSort demorou " 
                  << quickExecTime.count() << " microsegundos.\n";
        stabilityErr = Utils::isStable(rellocatorCO, numCons);
        std::cout << "A combinação " 
              << (stabilityErr == 0 ? "é estável": "não é estável. Número de erros: " + std::to_string(stabilityErr)) << std::endl;
        resultados.open("resultados/resultados-2-" + std::to_string(numCons) + ".txt", std::ios::app);
        resultados << radixExecTime.count() << " + " << quickExecTime.count() << " + " << std::endl;        resultados.close();
        Utils::writeConsciences(rellocatorCO, numCons);
        break;

      case 3:
        heapExecTime = HeapS::testHeap(rellocatorCO, numCons-1);
        mergeExecTime = MergeS::testMerge(rellocatorCO,0, numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        std::cout << "Teste concluido. Os resultados são: \n - HeapSort demorou " 
                  << heapExecTime.count() << " microsegundos.\n - MergeSort demorou " 
                  << mergeExecTime.count() << " microsegundos.\n";
        stabilityErr = Utils::isStable(rellocatorCO, numCons);
        std::cout << "A combinação " 
              << (stabilityErr == 0 ? "é estável": "não é estável. Número de erros: " + std::to_string(stabilityErr)) << std::endl;
        resultados.open("resultados/resultados-3-" + std::to_string(numCons) + ".txt", std::ios::app);
        resultados << heapExecTime.count() << " + " << mergeExecTime.count() << " + " << std::endl;        resultados.close();
        Utils::writeConsciences(rellocatorCO, numCons);
        break;

      case 4:
        radixExecTime = RadixS::testRadix(rellocatorCO, 0, numCons-1, 7, 7);
        mergeExecTime = MergeS::testMerge(rellocatorCO,0, numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        std::cout << "Teste concluido. Os resultados são: \n - RadixSort demorou " 
                  << radixExecTime.count() << " microsegundos.\n - MergeSort demorou " 
                  << mergeExecTime.count() << " microsegundos.\n";
        stabilityErr = Utils::isStable(rellocatorCO, numCons);
        std::cout << "A combinação " 
              << (stabilityErr == 0 ? "é estável": "não é estável. Número de erros: " + std::to_string(stabilityErr)) << std::endl;
        resultados.open("resultados/resultados-4-" + std::to_string(numCons) + ".txt", std::ios::app);
        resultados << radixExecTime.count() << " + " << mergeExecTime.count() << " + " << std::endl;        resultados.close();
        Utils::writeConsciences(rellocatorCO, numCons);
        break;

    } 

  }else if(env=="production"){
    switch (testType){
      case 1:
        HeapS::heapSort(rellocatorCO, numCons-1);
        QuickS::quickSort(rellocatorCO, 0 , numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        break;

      case 2:
        RadixS::radixExchangeSort(rellocatorCO, 0, numCons-1, 7, 7);
        QuickS::quickSort(rellocatorCO, 0 , numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        break;

      case 3:
        HeapS::heapSort(rellocatorCO, numCons-1);
        MergeS::mergeSort(rellocatorCO,0, numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        break;

      case 4:
        RadixS::testRadix(rellocatorCO, 0, numCons-1, 7, 7);
        MergeS::testMerge(rellocatorCO,0, numCons-1);
        Utils::listConsciences(rellocatorCO, numCons);
        break;

    }
  }

  delete [] rellocatorCO;
  return 0;
}