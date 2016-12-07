#include <math.h>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>

class Cosine {

public:
  Cosine();

  void std::textBase::Cosine::setMap( std::map<std::string,std::int> mapNew );

  std::map<std::string,std::int> std::textBase::Cosine::fetchWordMap();
  
  std::map<std::string,std::int> textBase::Cosine::buildInitMap(std::vector<std::string> text);

  std::vector<int> textBase::Cosine::buildCompVects(std::textBase::Cosine doc1, std::textBase::Cosine doc2);
  
private:
  //Where the maps of words to their wc goes
  std::map<std::string,std::int> wordMap;

  //vector computed after being compared to the other doc's wordMap
  std::vector<std::int> compVect;

  //threshold value determined from user input in textbase
  std::float level;
  
};
