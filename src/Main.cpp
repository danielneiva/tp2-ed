#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

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

void loadConsciences(Conscience *cons, std::string file, int numCons){
  std::ifstream infile("homologacao.txt");
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
}

namespace MergeS{

}

int main(int argc, char **argv) {

    /**
     * Get file name, type of test to be executed and number of consciences to be sorted
     * 
     * 
    */ 
    std::istringstream fileNameStream(argv[1]);
    std::string fileName;
    fileNameStream >> fileName;
    std::istringstream testTypeStream(argv[2]);
    int testType;
    testTypeStream >> testType;
    std::istringstream numConsStream(argv[3]);
    int numCons;
    numConsStream >> numCons;

    Conscience *rellocatorCO = new Conscience[200000];
    loadConsciences(rellocatorCO, "", numCons);

    auto start = std::chrono::high_resolution_clock::now();
    QuickS::quickSort(rellocatorCO, 0, numCons -1 );
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start );
    for (int i =0; i<numCons;i++){
      std::cout << "nome: " << rellocatorCO[i].name_person << std::endl;
    }
    std::cout << duration.count() << std::endl;
    delete [] rellocatorCO;
  return 0;
}