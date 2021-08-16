#include "MergeSort.h"
#include "Conscience.h"
void MergeS::merge(Conscience *cons, int const left, int const mid, int const right){
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
void MergeS::mergeSort(Conscience *cons, int const begin, int const end){
  if (begin >= end)
    return;

  auto mid = begin + (end - begin) / 2;
  mergeSort(cons, begin, mid);
  mergeSort(cons, mid + 1, end);
  merge(cons, begin, mid, end);
}
