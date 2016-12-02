#include <vector>
#include <string>
#include <map>
#inlcude "Ngram.hpp"
#include "Cosine.hpp"

class textBase {
public:
  
  void build(std::string groupFile, char deg='h');

  std::vector<std::string> readText(std::string file);

  void parse(char deg);

  void buildNgram(std::vector<std::string> text);
  
private:

  //value for cosine class to deem somthing suspisous
  float threshold;

  //value to be used to construct ngram class
  int gramCount;

  //ngram information
  //Ngram ngram;

  //cosine information
  class Cosine {
  public:
    std::vector<string> text;
    std::map<std::string,std::int> wordCount1;
    std::map<std::string,std::int> wordCount2;

    void buildInitMap(std::vector<std::string> text);
    void buildCompMap(std::map<std::string,std::int> wordCount1, std::map<std::string,std::int> wordCount2);
    void cosineCalc(std::map<std::string,std::int> wordCount1, std::map<std::string,std::int> wordCount2);
  };
 

};
