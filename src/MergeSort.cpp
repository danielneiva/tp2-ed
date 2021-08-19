#include "MergeSort.h"
#include "Conscience.h"
#include <chrono>


/**
 * Combina dois sub-arrays do array cons. O primeiro sub-array compreende cons[left...mid]
 * e o segundo compreende cons[mid+1...right]
 * 
 * @param {Conscience cons} O array de consciencias a ser ordenado
 * @param {int left} O primeiro elemento do primeiro sub-array
 * @param {int mid} O último elemento do primeiro sub-array
 * @param {int right} O ultimo elemento do segundo sub-array
 */
void MergeS::merge(Conscience *cons, int left, int mid, int right){
  auto leftPortionSize = mid - left + 1;
  auto rightPortionSize = right - mid;

  auto *leftArray = new Conscience[leftPortionSize];
  auto *rightArray = new Conscience[rightPortionSize];

  for (int i = 0; i < leftPortionSize; i++){
    leftArray[i] = cons[left + i];
  }
  for (int j = 0; j < rightPortionSize; j++){
    rightArray[j] = cons[mid + 1 + j];
  }

  int indexOfleftPortionSize = 0;  // Initial index da primeira porção
  int indexOfrightPortionSize = 0; // Initial index da segunda porção
  int indexOfMergedArray = left;    // Initial index do array combinado

  //Combina de volta os arrays temporários em "cons"
  while (indexOfleftPortionSize < leftPortionSize && indexOfrightPortionSize < rightPortionSize) {
    if (leftArray[indexOfleftPortionSize].name_person <= rightArray[indexOfrightPortionSize].name_person) {
      cons[indexOfMergedArray] = leftArray[indexOfleftPortionSize];
      indexOfleftPortionSize++;
    }
    else {
      cons[indexOfMergedArray] = rightArray[indexOfrightPortionSize];
      indexOfrightPortionSize++;
    }
    indexOfMergedArray++;
  }
  // Recupera os itens que sobraram no primeiro sub-array, caso existam
  while (indexOfleftPortionSize < leftPortionSize) {
    cons[indexOfMergedArray] = leftArray[indexOfleftPortionSize];
    indexOfleftPortionSize++;
    indexOfMergedArray++;
  }
  // Recupera os itens que sobraram no segundo sub-array, caso existam
  while (indexOfrightPortionSize < rightPortionSize) {
    cons[indexOfMergedArray] = rightArray[indexOfrightPortionSize];
    indexOfrightPortionSize++;
    indexOfMergedArray++;
  }

  delete [] leftArray;
  delete [] rightArray;
}

/**
 * Realiza a chamada recursiva que divide o array ao meio e realiza as chamadas
 * que combinam de volta os arrays
 * 
 * @param {Conscience cons} O array de consciencias a ser ordenado
 * @param {int left} O primeiro elemento do sub-array
 * @param {int right} O último elemento do sub-array
 */
void MergeS::mergeSort(Conscience *cons, int left, int right){
  if (left >= right)
    return;

  auto mid = left + (right - left) / 2;
  mergeSort(cons, left, mid);
  mergeSort(cons, mid + 1, right);
  merge(cons, left, mid, right);
}

/**
 * Realiza o mergeSort e mede o tempo gasto para a operação, retornando-o
 * 
 * @param {Conscience cons} O array de consciencias a ser ordenado
 * @param {int numCons} O número de consciências no array-1,
 *        i.e. a posição da última consciência no array
 */
std::chrono::microseconds MergeS::testMerge(Conscience *cons, int left, int numCons){
  auto start = std::chrono::high_resolution_clock::now();
  MergeS::mergeSort (cons,left , numCons );
  auto end = std::chrono::high_resolution_clock::now();
  auto durationMerge = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
  return durationMerge;
}