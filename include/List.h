#ifndef ED_LISTA_H
#define ED_LISTA_H
#include <string>
#include "Conscience.h"

class List
{
    public:
        List (int sizeList) { 
            this->currentSize = 0;
            this->maxSize = sizeList;
            this->consciences = new Conscience[maxSize];
        };
        ~List () {
            delete this->consciences;
        }
        Conscience getConscience ( int pos );
        void setConscience ( Conscience consc, int pos );
        void insertPos ( Conscience consc );
        void insertEnd ( Conscience cosnc );
        Conscience removePos ( int pos );
        void printList ();
        void clear ();
    
    protected:
        int currentSize;
        int maxSize;
        Conscience *consciences;

};


#endif