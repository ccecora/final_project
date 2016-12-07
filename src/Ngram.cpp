#include "Ngram.hpp"
#include <algorithm>
#include <cassert>

/* take iterators to the start/end of an Ngram, increment the appropriate                                                                                                          
 * element of the map */
void Ngram :: increment(std::vector<std::string>::const_iterator begin,
				  std::vector<std::string>::const_iterator end) {
  assert(end - begin == n); // make sure we've got the right number of words
  std::vector<std::string> words; // make a vector containing the words
  for (auto i = begin; i != end; ++i) {
    words.push_back(*i);
  }
  counts[words] += 1; // increment the corresponding count
}

int Ngram :: valuesum() {
  int sum=0;
  typedef std::map<std::vector<std::string>, unsigned>::iterator itcount;
  for(itcount it = counts.begin(); it != counts.end(); it++) {
    sum = sum+((int) (it->second));
  }

  return sum;
}


