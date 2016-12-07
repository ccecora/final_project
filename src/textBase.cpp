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
  compCosine(cos);
}

void textBase :: parse(char deg) {
  switch (deg) {
  case 'h':
    gramCount=3;
    threshold=.5;
  case 'm':
    gramCount=4;
    threshold=.7;
  case 'l':
    gramCount=5;
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

void textBase :: buildCosine(std::vector<std::string> text){
  Cosine CurrCos;
  std::map<std::string,std::int> temp1;
  temp1 = CurrCos.buildInitMap(text);
  CurrCos.setMap(temp1);
  cos.push_back(CurrCos);
}

void textBase :: compCosine(std::vector<Cosine> vects){
  typedef std::vector<Cosine>::iterator CosIt;

  for(CosIt i = vects.begin(); i != vects.end(); ++i){
    for(CosIt j = i; j != vects.end(); ++j){
      if( i != j ){ //if they aren't the same doc, compare
	std::vector<int> v1,v2;
	v1 = buildCompVects(*i,*j);
	v2 = buildCompVects(*j,*i);

	for(unsigned i = 0; i<v1.size(); i++){
	  dotSum = dotSum + (v1[i]*v2[i]);
	  mag1 = mag1 + pow(v1[i], 2);
	  mag2 = mag2 + pow(v2[i], 2);
	}

	mag1 = pow(mag1, 0.5);
	mag2 = pow(mag2, 0.5);

	std::cout << dotSum/(mag1*mag2);
	//NOTE: Will make function that checks values against threshold
	//Ran out of time
      }
    }
  }
  
}
