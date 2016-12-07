#include "textBase.hpp"
#include <iostream>
#include <fstream>
#include <stdbool.h>

textBase :: textBase(std::string groupFile, char deg) {
  std::vector<std::string> flist = readText(groupFile);
  parse(deg);
  for (std::string &fname : flist) {
    std::vector<std::string> text = readText(fname);
    buildCosine(text, fname);
    buildNgram(text, fname); 
  }
  compCosine(cos);
  compNgram()
}

void textBase :: parse(char deg) {
  switch (deg) {
  case 'h':
    gramCount=3;
    threshold=.03;
  case 'm':
    gramCount=4;
    threshold=.02;
  case 'l':
    gramCount=5;
    threshold=.005;
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

void textBase :: buildNgram(std::vector<std::string> &text, std::string &fname) {
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

void textBase :: compNgram() {
  for (std::vector<Ngram>::iterator niti = ngram.begin();niti != ngram.end(); niti++) {
    for (std::vector<Ngram>::iterator nitj = niti(); nitj != ngram.end(); nitj++) {
      if( niti != nitj ){
	combineNgram(*niti, *nitj);
      }
    }
  }	  
}

void textBase :: combineNgram(Ngram primary, Ngram secondary) {
  int freq;
  int sum=0;
  int sharedcount=min(primary.valuesum(), secondary.valuesum());
  gram1=primary.getCounts();
  gram2=seconday.getCounts();
  
  typedef std::map<std::vector<std::string>, unsigned> >::iterator itgram;
  itgram it2;
  for(itgram it = gram1.begin(); it != gram1.end(); it++) {
    if((it2=gram2.find(it->first)) != gram2.end()) {
      freq=(int) min(it->second,it2->second);
      sum = sum+freq;
    }
  }
  bool suspect=playalg(sum, sharedcount);
  std::pair<std::string,std::string> sfiles;
  if (suspect) {
    sfiles.make_pair(primary.getFilename, secondary.getFilename);
    nsuspicousfiles.push_back(sfiles);
  }
}


bool textBase :: playalg(int value, int total) {
  float ngramthresh= threshold * (float) total;
  bool suspicous= ((float)value)>ngramthresh;
  
  return suspicous
}


void textBase :: toString() {
  typedef std::vector<::pair<std::string,std::string> >::iterator fit;
  for (fit =nsuspicousfiles.begin(), fit != nsuspicousfiles.end(); fit++) {
    std::cout << "Suspicous file pair(ngram):" << fit->first << " &  " << fit->second << '\n';
  }  
}

void textBase :: toStringCos() {
  typedef std::vector<::pair<std::string,std::string> >::iterator fit;
  for (fit =cossuspicousfiles.begin(), fit != cossuspicousfiles.end(); fit++) {
    std::cout << "Suspicous file pair(cosine):" << fit->first << " &  " << fit->second << '\n';
  }
}
      
void textBase :: buildCosine(std::vector<std::string> text, std::string fileName){
  Cosine CurrCos(fileName, threshold);
  std::map<std::string,std::int> temp1;
  CurrCos.buildInitMap(text);
  cos.push_back(CurrCos);
}

void textBase :: compCosine(){
  typedef std::vector<Cosine>::iterator CosIt;
  std::vector<std::pair <std::string,std::string> > = temPair;
  
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

	if(checkThresh(cosV)){
	  temPair = std::make_pair(*i.fetchfName(), *j.fetchfName());
	  cossuspiciousfiles.push_back(temPair);
	}
	//NOTE: Will make function that checks values against threshold
	//Ran out of time
      }
    }
  }

  toStringCos();
  
}
