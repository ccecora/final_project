#include "Cosine.hpp"

Cosine::Cosine(){
  level = getThreshold();
}

std::map<std::string,int> Cosine :: fetchWordMap(){
  return wordMap;
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


std::vector<int> Cosine :: buildCompVects(Cosine doc1, Cosine doc2){
  std::map<std::string,int> temp1 = doc1.fetchWordMap();
  std::map<std::string,int> temp2 = doc2.fetchWordMap();
  
  typedef std::map<std::string,int>::iterator mapSpot;

  //for(mapSpot iterator = wordCount1.begin(); iterator != wordCount1.end(); iterator++){
  //  if(pwordCount2.find(iterator->first) == wordCount2.end()){
  //    temp2[iterator->first] = 0;
  //  }
  //}

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

  

  
    
