#include "Conscience.h"
#include "HeapSort.h"
#include <chrono>

/** 
 * Refaz uma subárvore com um nó "root" que é a raiz da subárvore,
 * sendo este uma posição no array "cons".
 * 
 * @param {Conscience *cons} O array de consciencias a ser ordenado
 * @param {int root} Raiz da subárvore
 * @param {int heapSize} A posição do último elemento do vetor
*/  
void HeapS::heapify(Conscience *cons, int heapSize, int root)
{
  int largest = root;
  int left = 2 * root + 1; // filho da esquerda
  int right = 2 * root + 2; // filho da direita

  if (left < heapSize && cons[left].conscience_person > cons[largest].conscience_person){
    largest = left;
  }

  if (right < heapSize && cons[right].conscience_person > cons[largest].conscience_person){
    largest = right;
  }

  if (largest != root) {
    Conscience::swapCons(&cons[root], &cons[largest]);

    heapify(cons, heapSize, largest);
  }
}
  
/** 
 * Constrói o Heap e realiza a ordenação
 * 
 * @param {Conscience *cons} O array de consciencias a ser ordenado
 * @param {int numCons} o número de consciencias no array, i.e. o tamanho do array
*/

void HeapS::heapSort(Conscience *cons, int numCons)
{
  // Constrói o Heap
  for (int i = numCons / 2 - 1; i >= 0; i--){
    heapify(cons, numCons, i);
  }

  // One by one extract an element from heap
  for (int i = numCons - 1; i > 0; i--) {
    // Move current root to end
    Conscience::swapCons(&cons[0], &cons[i]);

    // call max heapify on the reduced heap
    heapify(cons, i, 0);
  }
}

/**
 * Realiza o heapSort e mede o tempo gasto para a operação, retornando-o
 * 
 * @param {Conscience cons} O array de consciencias a ser ordenado
 * @param {int numCons} O número de consciências no array-1,
 *        i.e. a posição da última consciência no array
 */
std::chrono::microseconds HeapS::testHeap(Conscience *cons, int numCons){
  auto start = std::chrono::high_resolution_clock::now();
  HeapS::heapSort (cons,numCons );
  auto end = std::chrono::high_resolution_clock::now();
  auto durationHeap = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
  return durationHeap;
}