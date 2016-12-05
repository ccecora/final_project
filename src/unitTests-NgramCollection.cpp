/*
 * Unit test cases for textBase and Ngram classes.
 *
 */

#include "catch.hpp" // simple unit-testing framework
#include "Ngram.hpp" // header declaring the functions we want to test
#include "textBase.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

TEST_CASE("build", "[build]") {
  NgramCollection g3(3);
  NgramCollection g4(4);
  REQUIRE(g3.getN() == 3);
  REQUIRE(g4.getN() == 4);
}


TEST_CASE("parse", "[parse]") {
  NgramCollection g3(3);
  REQUIRE(g3.toString() == "");
  REQUIRE(g3.toString('a') == "");
  REQUIRE(g3.toString('r') == "");
  REQUIRE(g3.toString('c') == "");

  NgramCollection g4(4);
  REQUIRE(g4.toString() == "");
  REQUIRE(g4.toString('a') == "");
  REQUIRE(g4.toString('r') == "");
  REQUIRE(g4.toString('c') == "");

}

TEST_CASE("increment", "[increment]") {
  NgramCollection g3(3);

  vector<string> v;
  v.push_back("Four");
  v.push_back("score");
  v.push_back("and");
  v.push_back("seven");
  
  g3.increment(v.begin(), v.end()-1);
  REQUIRE(g3.toString() == "Four score and 1\n");
  REQUIRE(g3.toString('a') == "Four score and 1\n");
  REQUIRE(g3.toString('r') == "Four score and 1\n");
  REQUIRE(g3.toString('c') == "Four score and 1\n");

  g3.increment(v.begin()+1, v.end());
  REQUIRE(g3.toString() == "Four score and 1\nscore and seven 1\n");
  REQUIRE(g3.toString('a') == "Four score and 1\nscore and seven 1\n");
  REQUIRE(g3.toString('r') == "score and seven 1\nFour score and 1\n");
  REQUIRE(g3.toString('c') == "Four score and 1\nscore and seven 1\n");

  g3.increment(v.begin(), v.end()-1);
  REQUIRE(g3.toString() == "Four score and 2\nscore and seven 1\n");  
  REQUIRE(g3.toString('a') == "Four score and 2\nscore and seven 1\n");  
  REQUIRE(g3.toString('r') == "score and seven 1\nFour score and 2\n");
  REQUIRE(g3.toString('c') == "score and seven 1\nFour score and 2\n");

  g3.increment(v.begin()+1, v.end());
  g3.increment(v.begin()+1, v.end());
  REQUIRE(g3.toString() == "Four score and 2\nscore and seven 3\n");
  REQUIRE(g3.toString('a') == "Four score and 2\nscore and seven 3\n");
  REQUIRE(g3.toString('r') == "score and seven 3\nFour score and 2\n");
  REQUIRE(g3.toString('c') == "Four score and 2\nscore and seven 3\n");
}


 */
TEST_CASE("readText", "[readText]") {
  NgramCollection g3(3);
  vector<string> text;
  text.push_back("I");
  text.push_back("have");
  text.push_back("a");
  text.push_back("dream");
  text.push_back("that");
  text.push_back("one");
  text.push_back("day");
  
  g3.increment(text.begin(), text.end()-4); //adds "I, have, a"
  g3.increment(text.begin()+1, text.end()-3); //adds "have, a, dream"
  g3.increment(text.begin()+2, text.end()-2); //adds "a, dream, that"
  g3.increment(text.begin()+3, text.end()-1); //adds "dream, that, one"
  g3.increment(text.begin(), text.end()-4); //adds "I, have, a" AGAIN
  
  list<string> wordsToFollow;
  wordsToFollow.push_back("I");
  wordsToFollow.push_back("have");
  wordsToFollow.push_back("a");

  list<string>::iterator begin_list = wordsToFollow.begin();
  list<string>::iterator end_list = begin_list;  //now points to "I"
  end_list = std::next(end_list);
  end_list = std::next(end_list);  //now points to "a"
  REQUIRE(g3.pickWord(begin_list, end_list) == "a");

  begin_list++; //now points to "have"
  end_list = std::next(end_list); //now points to "dream"
  REQUIRE(g3.pickWord(begin_list, end_list) == "dream");

}


TEST_CASE("buildNgram", "[buildNgram]") {

  NgramCollection g4(4);

  vector<string> text;
  text.push_back("I");
  text.push_back("have");
  text.push_back("a");
  text.push_back("dream");
  text.push_back("that");
  text.push_back("one");
  text.push_back("day");
  
  g4.increment(text.begin(), text.end()-3); //adds "I, have, a, dream"
  g4.increment(text.begin()+1, text.end()-2); //adds "have, a, dream, that"
  g4.increment(text.begin()+2, text.end()-1); //adds "a, dream, that one"
  g4.increment(text.begin()+3, text.end()); //adds "dream, that, one, day"
  g4.increment(text.begin(), text.end()-3); //adds "I, have, a, dream" AGAIN
  
  list<string> wordsToFollow;
  wordsToFollow.push_back("I");
  wordsToFollow.push_back("have");
  wordsToFollow.push_back("a");
  wordsToFollow.push_back("dream");
  wordsToFollow.push_back("that");
  wordsToFollow.push_back("one");
	       

  list<string>::iterator begin_list = wordsToFollow.begin();
  list<string>::iterator end_list = begin_list;  //now points to "I"
  end_list = std::next(end_list);
  end_list = std::next(end_list);
  end_list = std::next(end_list);  //now points to "dream"
  REQUIRE(g4.pickWord(begin_list, end_list) == "dream");

  begin_list++; //now points to "have"
  end_list = std::next(end_list); //now points to "that"
  REQUIRE(g4.pickWord(begin_list, end_list) == "that");

}


