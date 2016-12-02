#include "textBase.hpp"
#include <iostream>
#include <fstream>


void textBase :: build(std::string groupFile, char deg) {
  std::vector<std::string> flist = readText(groupFile);
  parse(deg);
  for (std::string &fname : flist) {
    std::vector<std::string> text = readText(fname);
    ngram(gramCount);
    buildCosine(text);
    buildNgram(text);
    
  }
}

void textBase :: parse(char deg) {
  switch (deg) {
  case 'h':
    gramCount=4;
    threshold=.5;
  case 'm':
    gramCount=7;
    threshold=.7;
  case 'l':
    gramCount=10;
    threshold=.9;
  default :
    std::cerr << "Invalid sensitivity given! Please enter h, m, or l\n";
    //should we give throw and catch error to have them renter an input
    exit(1);
  }
}

std::vector<std::string> textBase :: readText(std::string file) {
  std::vector<std::string> text;
  std::ifstream fin(file);
  if (!fin.is_open()) { // see if it worked
    std::cerr << "Was unable to open the groupFile: " << groupFile << "\n";
    exit(1);
  }
  std::string word;
  while (fin >> word) {
    text.push_back(word);
  }
  fin.close();
  
  return text;  
}


