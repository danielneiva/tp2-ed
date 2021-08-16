#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <stdlib.h>

struct Conscience{
  std::string name_person ="";
  std::string conscience_person ="";
};

namespace QuickS{

  void swap ( Conscience *a, Conscience *b ){
    Conscience aux = *a;
    *a = *b;
    *b = aux;
  }

  int partition ( Conscience *cons, int left, int right ){
    std::string pivotValue = cons[right].name_person;
    int index = ( left - 1 );
    for ( int j = left; j <= right -1; j++ ){
      if ( cons[j].name_person <= pivotValue ){
        index++; 
        swap ( &cons[index], &cons[j] );
      }
    }
    swap ( &cons[index+1], &cons[right] );
    return ( index + 1 );
  }

  void quickSort ( Conscience *cons, int left, int right ){
    if ( left < right ){
      int partIndex = partition ( cons, left, right );
      quickSort ( cons, left, partIndex -1 );
      quickSort ( cons, partIndex + 1, right );
    }
  }
}

namespace MergeS{
  void merge(Conscience *cons, int const left, int const mid, int const right){
    auto const leftPortionSize = mid - left + 1;
    auto const rightPortionSize = right - mid;

    // Create temporary arrays to store the values of the portions
    auto *leftArray = new Conscience[leftPortionSize];
    auto *rightArray = new Conscience[rightPortionSize];

    // Gets the data from cons and insert it into leftArray and roghtArray
    for (auto i = 0; i < leftPortionSize; i++){
      leftArray[i].name_person = cons[left + i].name_person;
    }
    for (auto j = 0; j < rightPortionSize; j++){
      rightArray[j].name_person = cons[mid + 1 + j].name_person;
    }

    auto indexOfleftPortionSize = 0;  // Initial index of first portion
    auto indexOfrightPortionSize = 0; // Initial index of second portion
    int indexOfMergedArray = left;    // Initial index of merged array

    // Merge the temporary arrays back into cons
    while (indexOfleftPortionSize < leftPortionSize && indexOfrightPortionSize < rightPortionSize) {
      if (leftArray[indexOfleftPortionSize].name_person <= rightArray[indexOfrightPortionSize].name_person) {
        cons[indexOfMergedArray].name_person = leftArray[indexOfleftPortionSize].name_person;
        indexOfleftPortionSize++;
      }
      else {
        cons[indexOfMergedArray].name_person = rightArray[indexOfrightPortionSize].name_person;
        indexOfrightPortionSize++;
      }
      indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfleftPortionSize < leftPortionSize) {
      cons[indexOfMergedArray].name_person = leftArray[indexOfleftPortionSize].name_person;
      indexOfleftPortionSize++;
      indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfrightPortionSize < rightPortionSize) {
      cons[indexOfMergedArray].name_person = rightArray[indexOfrightPortionSize].name_person;
      indexOfrightPortionSize++;
      indexOfMergedArray++;
    }
  }
  
  /**
   *  Begin is the first potition of the array,
   *  End is the last position of the array 
   * 
   */
  void mergeSort(Conscience *cons, int const begin, int const end)
  {
    if (begin >= end)
      return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(cons, begin, mid);
    mergeSort(cons, mid + 1, end);
    merge(cons, begin, mid, end);
  }

}

namespace HeapS{
  // To heapify a subtree rooted with node i which is
  // an index in arr[]. n is size of heap
  void swap ( Conscience *a, Conscience *b ){
    Conscience aux = *a;
    *a = *b;
    *b = aux;
}

  void heapify(Conscience *cons, int heapSize, int index)
  {
    int largest = index; // Initialize largest as root
    int left = 2 * index + 1; // left = 2*i + 1
    int right = 2 * index + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < heapSize && cons[left].conscience_person > cons[largest].conscience_person){
      largest = left;
    }

    // If right child is larger than largest so far
    if (right < heapSize && cons[right].conscience_person > cons[largest].conscience_person){
      largest = right;
    }

    // If largest is not root
    if (largest != index) {
      swap(&cons[index], &cons[largest]);

      // Recursively heapify the affected sub-tree
      heapify(cons, heapSize, largest);
    }
  }
  
  // main function to do heap sort
  void heapSort(Conscience *cons, int numCons)
  {
      // Build heap (rearrange array)
      for (int i = numCons / 2 - 1; i >= 0; i--){
          heapify(cons, numCons, i);
      }
  
      // One by one extract an element from heap
      for (int i = numCons - 1; i > 0; i--) {
          // Move current root to end
          swap(&cons[0], &cons[i]);
  
          // call max heapify on the reduced heap
          heapify(cons, i, 0);
      }
  }
}

void loadConsciences(Conscience *cons, std::string file, int numCons){
  std::ifstream infile(file);
  int numLine=0;
  std::string line;
  while (std::getline(infile, line) && numLine < numCons){
    std::istringstream iss(line);
    std::string nameLine, consLine;
    iss >> nameLine >> consLine;
    cons[numLine].name_person = nameLine;
    cons[numLine].conscience_person = consLine;
    numLine++;
  } 
  std::cout << "Consciences loaded into the system!\nStarting audits...\n";
}

int main(int argc, char **argv) {

    /**
     * Get file name, type of test to be executed and number of consciences to be sorted
     * 
     * 
    */ 
    std::string fileName = argv[1];
    int testType = strtol(argv[2], nullptr, 0);
    int numCons = strtol(argv[3], nullptr, 0);;
    std::cout << numCons << " - " << fileName << " - " << testType << std::endl;
    Conscience *rellocatorCO = new Conscience[numCons];
    loadConsciences(rellocatorCO, fileName, numCons);

    
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
    auto start = std::chrono::high_resolution_clock::now();
    HeapS::heapSort(rellocatorCO, numCons  );
    auto end = std::chrono::high_resolution_clock::now();

    auto durationMS = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
    for (int i =0; i<numCons;i++){
      std::cout << "conscience: " << rellocatorCO[i].conscience_person << " - meaning: " << stoi(rellocatorCO[i].conscience_person, 0, 2) << std::endl;
    }

    std::cout << "It took: " << durationMS.count() << " Microseconds" << std::endl;
    delete [] rellocatorCO;
  return 0;
}