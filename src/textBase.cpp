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
    //^maybe a good piazza, like asking if we should throw and catch in general
    //but will def affect out unit tests
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

void std::textBase::Cosine::buildInitMap(std::vector<std::string> input){
  std::map<std::string,std::int> wc;

  for(unsigned j = 0; j<input.size(); j++){
    temp = in[j];
    count = wc.find(temp);
    if(count == wc.end()){
      wc[temp] = 1;
    } else {
      wc[temp]++;
    }
  }
  return wc;
}
