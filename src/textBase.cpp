#include "textBase.hpp"
#include <iostream>
#include <fstream>
#include <utility>
#include <stdbool.h>

textBase :: textBase(std::string groupFile, char deg) {
  degree = deg;
  threshold = 0.02;
  std::vector<std::string> flist = readText(groupFile);
  //std::cout<<"just read file names";
  parse(deg);
  for (std::string &fname : flist) {
    //std::cout<<"about to read individual files";
    std::vector<std::string> text = readText(fname);
    //std::cout<<"file read, about to buildCos";
    buildCosine(text, fname);
    //std::cout<<"cos built, about to build ngram";
    buildNgram(text, fname); 
  }
  compCosine();
  compNgram();
  toString();
}

void textBase :: parse(char deg) {
  switch (deg) {
  case 'h':
    gramCount=3;
    threshold=.03;
    break;
  case 'm':
    gramCount=4;
    threshold=.015;
    break;
  case 'l':
    gramCount=5;
    threshold=.005;
    break;
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
    std::cerr << "Was unable to open the file: " << file << "\n";
    exit(1);
  }
  std::string word;
  while (fin >> word) {
    text.push_back(word);
  }
  fin.close();
  
  return text;  
}

void textBase :: buildNgram(std::vector<std::string> text, std::string fname) {
  Ngram gramholder(gramCount,fname);
  auto first = text.begin(); // first element
  auto last = text.begin() + gramCount; // n-1th element
  while (last-1 != text.end()) {
    gramholder.increment(first, last); // add ngrams until we run out
    ++first;
    ++last;
  }
  ngram.push_back(gramholder);
}

void textBase :: compNgram() {
  for (std::vector<Ngram>::iterator niti = ngram.begin();niti != ngram.end(); niti++) {
    for (std::vector<Ngram>::iterator nitj = niti ; nitj != ngram.end(); nitj++) {
      if( niti != nitj ){
	combineNgram(*niti, *nitj);
      }
    }
  }	  
}

void textBase :: combineNgram(Ngram primary, Ngram secondary) {
  unsigned freq;
  unsigned sum=0;
  int sharedcount=std::min(primary.valuesum(), secondary.valuesum());
  auto gram1=primary.getCounts();
  auto gram2=secondary.getCounts();
  
  typedef std::map<std::vector<std::string>, int>::iterator itgram;
  itgram it2;
  for(itgram it = gram1.begin(); it != gram1.end(); it++) {
    if((it2=gram2.find(it->first)) != gram2.end()) {
      freq=(unsigned) std::min(it->second,it2->second);
      sum = sum+freq;
    }
  }
  bool suspect=playalg(sum, sharedcount);
  std::pair<std::string,std::string> sfiles;
  if (suspect) {
    sfiles=std::make_pair(primary.getFilename(), secondary.getFilename());
    nsuspicousfiles.push_back(sfiles);
  }
}


bool textBase :: playalg(int value, int total) {
  float ngramthresh= threshold * (float) total;
  bool suspicous= ((float)value)>ngramthresh;
  return suspicous;
}


void textBase :: toString() {
  typedef std::vector<std::pair<std::string,std::string> >::iterator fit;
  for (fit it =nsuspicousfiles.begin(); it != nsuspicousfiles.end(); it++) {
    std::cout << "Suspicous file pair(ngram):" << it->first << " &  " << it->second << '\n';
  }  
}

void textBase :: toStringCos(std::vector<float> cosValues) {
  typedef std::vector<std::pair<std::string,std::string> >::iterator fit;
  typedef std::vector<float>::iterator iit;
  for (std::pair<fit, iit>  i(cossuspicousfiles.begin(), cosValues.begin()); i.first != cossuspicousfiles.end(); i.first++, i.second++) {
    std::cout << "Suspicous file pair(cosine):" << i.first->first << " &  " << i.first->second << " with cosine value: " << *i.second << '\n';
  }
}
      
void textBase :: buildCosine(std::vector<std::string> text, std::string fileName){
  Cosine CurrCos(fileName, threshold, degree);
  CurrCos.buildInitMap(text);
  cos.push_back(CurrCos);
}

std::vector<int> textBase::  buildCompVects(Cosine doc1, Cosine doc2){
  std::map<std::string,int> temp1 = doc1.fetchWordMap();
  std::map<std::string,int> temp2 = doc2.fetchWordMap();

  typedef std::map<std::string,int>::iterator mapSpot;

  for(mapSpot iterator = temp2.begin(); iterator != temp2.end(); iterator++){
    if(temp1.find(iterator->first) == temp1.end()){
      temp1[iterator->first]=0;
    }
  }

  std::vector<int> w1;

  for(mapSpot iterator = temp1.begin(); iterator != temp1.end(); iterator++){
    w1.push_back( iterator -> second );
  }
  return w1;
}

void textBase :: compCosine(){
  typedef std::vector<Cosine>::iterator CosIt;
  std::vector<float> cosVals;
  
  for(CosIt i = cos.begin(); i != cos.end(); ++i){
    for(CosIt j = i; j != cos.end(); ++j){
      if( i != j ){ //if they aren't the same doc, compare
	std::vector<int> v1,v2;
	//v1 and v2 each contain the wordcounts of each string with 0s included
	v1 = buildCompVects(*i,*j);
	v2 = buildCompVects(*j,*i);

	float dotSum=0;
	float mag1=0;
	float mag2=0;
	for(unsigned i = 0; i<v1.size(); i++){
	  dotSum = dotSum + (v1[i]*v2[i]);
	  mag1 = mag1 + pow(v1[i], 2);
	  mag2 = mag2 + pow(v2[i], 2);
	}

	mag1 = pow(mag1, 0.5);
	mag2 = pow(mag2, 0.5);

	float cosV = dotSum/(mag1*mag2);
	
	
	Cosine k = *i;
	Cosine l = *j;
	if(k.checkThresh(cosV)){
	  cossuspicousfiles.push_back(std::make_pair(k.fetchfName(), l.fetchfName()));
	  cosVals.push_back(cosV);
	}
      }
    }
  }

  toStringCos(cosVals);
  
}
