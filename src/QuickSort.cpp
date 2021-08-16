#include "QuickSort.h"
#include "Conscience.h"
#include <chrono>

int QuickS::partition ( Conscience *cons, int left, int right ){
  std::string pivotValue = cons[right].name_person;
  int index = ( left - 1 );
  for ( int j = left; j <= right -1; j++ ){
    if ( cons[j].name_person <= pivotValue ){
      index++; 
      Conscience::swapCons ( &cons[index], &cons[j] );
    }
  }
  Conscience::swapCons ( &cons[index+1], &cons[right] );
  return ( index + 1 );
}
  
void QuickS::quickSort ( Conscience *cons, int left, int right ){
  if ( left < right ){
    int partIndex = partition ( cons, left, right );
    quickSort ( cons, left, partIndex -1 );
    quickSort ( cons, partIndex + 1, right );
  }
}

std::chrono::microseconds QuickS::testQuick(Conscience *cons, int left , int right){
  auto start = std::chrono::high_resolution_clock::now();
  QuickS::quickSort (cons,left,right );
  auto end = std::chrono::high_resolution_clock::now();
  auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
  return durationQuick;
}