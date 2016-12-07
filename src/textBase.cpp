#include "textBase.hpp"
#include <iostream>
#include <fstream>

textBase :: textBase(std::string groupFile, char deg) {
  std::vector<std::string> flist = readText(groupFile);
  parse(deg);
  for (std::string &fname : flist) {
    std::vector<std::string> text = readText(fname);
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

void textBase :: buildNgram(std::vector<std::string> &text) {
  Ngram gramholder(gramCount);
  auto first = text.begin(); // first element
  auto last = text.begin() + gramCount; // n-1th element
  while (last-1 != text.end()) {
    gramholder.increment(first, last); // add ngrams until we run out
    ++first;
    ++last;
  }
  ngram.push_back(gramholder);
}

void textbase :: buildCosine(std::vector<std::string> text) {
  Cosine CurrCos;
  std::map<std::string,std::int> temp1;
  temp1 = CurrCos.buildInitMap(text);
  CurrCos.setMap(temp1);
  cos.push_back(CurrCos);
}

void compCosine(std::vector< std::textBase::Cosine > vects){
  
}
