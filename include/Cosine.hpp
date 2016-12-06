#include <math.h>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>

class Cosine {

public:
  std::map<std::string,std::int> textBase::Cosine::buildInitMap(std::vector<std::string> text);

  void textBase::Cosine::buildCompMap(std::map<std::string,std::int> wordCount1, std::map<std::string,std::int> wordCount2);

private:
  //Where the maps of words to their wc goes
  std::map<std::string,std::int> wordMap;

  //vector computed after being compared to the other doc's wordMap
  std::vector<std::int> compVect;
};
