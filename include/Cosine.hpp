#include <math.h>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>

class Cosine {

public:
  Cosine();

  std::map<std::string,int> fetchWordMap();
  
  void buildInitMap(std::vector<std::string> text);

  std::vector<int> buildCompVects(Cosine doc1, Cosine doc2);
  
private:
  //Where the maps of words to their wc goes
  std::map<std::string,int> wordMap;

  //vector computed after being compared to the other doc's wordMap
  std::vector<int> compVect;

  //threshold value determined from user input in textbase
  std::float level;
  
};
