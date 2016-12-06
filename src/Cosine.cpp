#include "Cosine.hpp"

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

void std::textBase::Cosine::buildCompMap(std::map<std::string,std::int> wordCount1, std::map<std::string,std::int> wordCount2){
  std::map<std::string,std::int> temp1 = wordCount1;
  std::map<std::string,std::int> temp2 = wordCount2;
  typedef std::map<std::string,std::int>::iterator mapSpot;

  for(mapSpot iterator = wordCount1.begin(); iterator != wordCount1.end(); iterator++){
    if(wordCount2.find(iterator->first) == wordCount2.end()){
      temp2[iterator->first] = 0;
    }
  }

  for(mapSpot iterator = wordCount2.begin(); iterator != wordCount2.end(); iterator++){
    if(wordCount1.find(iterator->first) == wordCount1.end()){
      temp1[iterator->first] = 0;
    }
  }

  *wordCount1 = temp1;
  *wordCount2 = temp2;
  //test: make sure the new wordcounts are the same size, print out all keys and value to check later for proper
  //ordering
}

std::float std::textBase::Cosine::cosineCalc((std::map<std::string,std::int> wordCount1, std::map<std::string,std::int> wordCount2){
    std::vector<int> w1,w2;
    float dotSum = 0;
    float mag1 = 0;
    float mag2 = 0;

    typedef std::map<std::string,std::int>::iterator mapSpot;

    for(mapSpot iterator = wordCount1.begin(); iterator != wordCount1.end(); iterator++){
      w1.push_back( iterator -> second );
    }

    for(mapSpot iterator = wordCount2.begin(); iterator != wordCount2.end(); iterator++){
      w2.push_back( iterator -> second );
    }

    for(unsigned i = 0; i<w1.size(); i++){
      dotSum = dotSum + (w1[i]*w2[i]);
      mag1 = mag1 + pow(w1[i], 2);
      mag2 = mag2 + pow(w2[i], 2);
    }

    mag1 = pow(mag1, 0.5);
    mag2 = pow(mag2, 0.5);

    return dotSum/(mag1*mag2);
  }
  
    
