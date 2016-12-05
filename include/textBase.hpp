#include <vector>
#include <string>
#inlcude "Ngram.hpp"
#include "Cosine.hpp"

class textBase {

public:

  textBase();
  
  void build(std::string groupFile, char deg='h');

  std::vector<std::string> readText(std::string file);

  float getThreshold() {return threshold; };

  unsigned getGramCount() {return gramCount; };
  
  void parse(char deg);

  void buildNgram(std::vector<std::string> text);

  void buildCosine(std::vector<std::string> text);

private:

  //value for cosine class to deem somthing suspisous
  float threshold;

  //value to be used to construct ngram class
  unsigned gramCount;

  //ngram information
  std::vector<Ngram> ngram;

  //cosine information
  Cosine cosi;
 

};
