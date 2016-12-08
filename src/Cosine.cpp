#include "Cosine.hpp"

Cosine::Cosine(std::string fileName, float threshold, char deg){
  fName = fileName;
  switch(deg){
  case('h'):
    level = threshold*27.6666667;
  break;

  case('m'):
    level = threshold*52.6666667;
  break;

  case('l'):
    level = threshold*150;
  break;
  }
}

std::map<std::string,int> Cosine :: fetchWordMap(){
  return wordMap;
}

std::string Cosine :: fetchfName(){
  return fName;
}

void Cosine :: buildInitMap(std::vector<std::string> text){
  for(unsigned j = 0; j<text.size(); j++){
    std::string temp = text[j];
    auto count = wordMap.find(temp);
    if(count == wordMap.end()){
      wordMap[temp] = 1;
    } else {
      wordMap[temp]++;
    }
  }
}

bool Cosine :: checkThresh(float cosVal){
  bool suspicious;
  if(cosVal > 1 || cosVal < 0){
    std::cout<<"Error: Cosval not between 0 and 1";
    exit(1);
  } else if( cosVal >= level ){
    suspicious = 1;
  } else {
    suspicious = 0;
  }
  return suspicious;
}

			 
    
