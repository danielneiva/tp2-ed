#include "Conscience.h"
#include "HeapSort.h"

  // To heapify a subtree rooted with node i which is
  // an index in arr[]. n is size of heap
  
void HeapS::heapify(Conscience *cons, int heapSize, int index)
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
    Conscience::swapCons(&cons[index], &cons[largest]);

    // Recursively heapify the affected sub-tree
    heapify(cons, heapSize, largest);
  }
}
  
// main function to do heap sort
  
void HeapS::heapSort(Conscience *cons, int numCons)
{
  // Build heap (rearrange array)
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
