#include <vector>
#include <list>
#include <map>
#include <string>
#include <cassert>

class Ngram {

public:

  //Generate an NgramCollection object with N equal to argument num
  //Also seeds the RNG (there are better ways of ensuring this only happens once, but this will probably be good enough)
  //Note that you may want to change this to a fixed seed
  Ngram(unsigned num, std::string file) : n(num), filename(file) {}

  //Increase count for NgramCollection representing values from begin up to end
  //begin is an iterator to the first word in the Ngram,
  //end is an iterator to the end of the Ngram
  // (so (end - begin) == N)
  void increment(std::vector<std::string>::const_iterator begin,
		 std::vector<std::string>::const_iterator end);

  std::map<std::vector<std::string>,unsigned> getCounts() {return counts; }

  int valuesum();

  std::string getFilename() {return filename; }
  
private:

  //the collection of entries in this NgramCollection
  std::map<std::vector<std::string>, unsigned> counts;

  //the number of items in our NgramCollection
  unsigned n;

  //the file the class came from
  std::string filename;
};
