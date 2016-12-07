#include "Cosine.hpp"

Cosine::Cosine(){
  level = getThreshold();
    }

std::map<std::string,std::int> std::textBase::Cosine::fetchWordMap(){
  return wordMap;
}

std::map<std::string,std::int> textBase::Cosine::buildInitMap(std::vector<std::string> text){
  std::map<std::string,std::int> wc;

  for(unsigned j = 0; j<text.size(); j++){
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

void std::textBase::Cosine::setMap( std::map<std::string,std::int> mapNew){
   wordMap = mapNew;
}

std::vector<int> std::textBase::Cosine::buildCompVects(std::textBase::Cosine doc1, std::textBase::Cosine doc2){
  std::map<std::string,std::int> temp1 = doc1.fetchWordMap();
  std::map<std::string,std::int> temp2 = doc2.fetchWordMap();
  
  typedef std::map<std::string,std::int>::iterator mapSpot;

  //for(mapSpot iterator = wordCount1.begin(); iterator != wordCount1.end(); iterator++){
  //  if(wordCount2.find(iterator->first) == wordCount2.end()){
  //    temp2[iterator->first] = 0;
  //  }
  //}

  for(mapSpot iterator = temp2.begin(); iterator != temp2.end(); iterator++){
    if(temp1.find(iterator->first) == temp1.end()){
      temp1.insert( temp1.begin(), std::pair<string,int>(temp2[iterator->first],0) );
    }
  }

  std::vector<int> w1;
  
  for(mapSpot iterator = temp1.begin(); iterator != temp1.end(); iterator++){
    w1.push_back( iterator -> second );
  }
  return temp1;
}

  

  
    
