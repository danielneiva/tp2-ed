#include "QuickSort.h"
#include "Conscience.h"
#include <chrono>
#include <iostream>


/**
 * Particiona o Array com o pivô ao meio e coloca os elementos menores que o pivô
 *  à esquerda e os maiores à direita
 * 
 * @param {Conscience cons} Array de consciencias a ser ordenado
 * @param {int left} A primeira posição do array ou sub-array a ser ordenado
 * @param {int right} A ultima posição do array ou sub-array a ser ordenado
 * @param {int *i} Variável auxiliar que irá procurar elementos maiories que o pivô à esquerda
 * @param {int *j} Variável auxiliar que irá procurar elementos menores que o pivô à direita
 */
void QuickS::partition ( Conscience *cons, int left, int right, int *i, int *j ){
  *i = left;
  *j = right;
  std::string pivotValue = cons[( *i + *j )/2].name_person; // Pivô
  do{
    while(cons[*i].name_person < pivotValue) *i = *i+1;
    while(cons[*j].name_person > pivotValue) *j = *j-1;
    if(*i <=*j){
      Conscience::swapCons(&cons[*i], &cons[*j]);
      *i = *i+1;
      *j = *j-1;
    }
  }while(*i<=*j);
}

/**
 * Realiza a a chamada recursiva para a ordenação
 * 
 * @param {Conscience *cons} Array de consciencias a ser ordenado
 * @param {int left} Posição do primeiro elemento do array
 * @param {int right} Posição do último elemento do array, i.e. tamanho do array -1
 */
void QuickS::quickSort ( Conscience *cons, int left, int right ){
  int i, j;
  QuickS::partition(cons, left, right, &i, &j);
  if ( left < j ) quickSort ( cons, left, j);
  if ( i < right) quickSort ( cons, i, right );
}

/**
 * Realiza o quickSort e mede o tempo gasto para a operação, retornando-o
 * 
 * @param {Conscience cons} O array de consciencias a ser ordenado
 * @param {int numCons} O número de consciências no array-1,
 *        i.e. a posição da última consciência no array
 */
std::chrono::microseconds QuickS::testQuick(Conscience *cons, int left , int right){
  auto start = std::chrono::high_resolution_clock::now();
  QuickS::quickSort (cons,left,right );
  auto end = std::chrono::high_resolution_clock::now();
  auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
  return durationQuick;
}