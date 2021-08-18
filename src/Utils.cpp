#include "Utils.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Utils::loadConsciences(Conscience *cons, std::string file, int numCons){
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

void Utils::listConsciences(Conscience *cons, int numCons){
  for (int i = 0; i<numCons; i++){
    std::cout << cons[i].name_person << " " << stoi(cons[i].conscience_person,0,2) << std::endl;
  }
}

bool Utils::isStable(Conscience *cons, int numCons){
  for (int i =0; i<numCons-1; i++) {
    if (cons[i].name_person > cons[i+1].name_person) return false;
    if (cons[i].conscience_person > cons[i+1].conscience_person
        && cons[i].name_person == cons[i+1].name_person) return false;
  }
  return true;
}

