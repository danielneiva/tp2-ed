#include "List.h"
#include <iostream>
Conscience List::getConscience ( int pos ){
  return this->consciences[pos];
}

void List::setConscience( Conscience consc, int pos ){
  this->consciences[pos] = consc;
}

void List::insertEnd ( Conscience consc ){
  if ( this->currentSize == maxSize ) {
    throw "Error: List already at its maximum size.";
  }
  this->consciences[this->currentSize] = consc;
  this->currentSize++;
}

void List::printList () {
  for ( int i =0; i < this->currentSize-1; i++ ) {
    std::cout << this->consciences[i].name_person << " " << i <<std::endl;
  }
}
