#include <vector>
#include <string>
#include <utility>
#include "Ngram.hpp"
#include "Cosine.hpp"

class textBase {

public:

  textBase(std::string groupFile, char deg);

  std::vector<std::string> readText(std::string file);

  float getThreshold() {return threshold; }

  unsigned getGramCount() {return gramCount; }
  
  void parse(char deg);

  void buildNgram(std::vector<std::string> text, std::string fname);

  void compNgram();

  void combineNgram(Ngram primary, Ngram secondary);

  bool playalg(int value, int total);
  
  //Given the text of one document, will create a Cosine object of the doc and
  //Insert it into the vector of Cosine objects within the constructor
  void buildCosine(std::vector<std::string> text, std::string fileName);

  std::vector<int> buildCompVects(Cosine doc1, Cosine doc2);
  
  void compCosine();

  void toString();

  void toStringCos();
  
  //for testing
  //  std::vector<Ngram> getNgram(int i) {return ngram.at(i); }


		  
private:

  //value for cosine class to deem somthing suspisous
  float threshold;

  //value to be used to construct ngram class
  unsigned gramCount;

  //ngram information
  std::vector<Ngram> ngram;

  //cosine information
  std::vector<Cosine> cos;
 
  std::vector<std::pair <std::string,std::string> > nsuspicousfiles;

  std::vector<std::pair <std::string,std::string> > cossuspicousfiles;
  
};
