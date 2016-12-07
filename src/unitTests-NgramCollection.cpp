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


TEST_CASE("parse", "[parse]") {
  textBase tb;
  tb.parse();
  REQUIRE(tb.getThreshold == 0);
  tb.parse('a');
  REQUIRE(tb.getThreshold == 0);
  tb.parse('h');
  REQUIRE(tb.getThreshold == .03);
  tb.parse('m');
  REQUIRE(tb.getThreshold == .02);
  tb.parse('b');
  REQUIRE(tb.getThreshold == .02);
  tb.parse('l');
  REQUIRE(tb.getThreshold == .005);

}

TEST_CASE("increment", "[increment]") {
  
  
  

}



TEST_CASE("readText", "[readText]") {


}


TEST_CASE("buildNgram into increment", "[buildNgram],[increment]") {
  textBase tb;
  tb.parse('h');
  std::vector<std::string> text;
  std::string fname= "file.txt"
  text.push_back("I");
  text.push_back("hope");
  text.push_back("this");
  text.push_back("test");
  text.push_back("will");
  text.push_back("pass");
  tb.buildNgram(text,fname);
  Ngram testgram=tb.getNgram(0);
  std::map<std::vector<std::string>, unsigned> > grammap=testgram.getCounts();
  std::vector<stdd::string> word1;
  word1.push_back("I");
  word1.push_back("hope");
  word1.push_back("this");
  REQUIRE(grammap.find(word1)!=grammap.end());
  std::vector<stdd::string> word2;
  word2.push_back("hope");
  word2.push_back("this");
  word2.push_back("test");
  REQUIRE(grammap.find(word2)!=grammap.end());
  std::vector<stdd::string> word3;
  word3.push_back("test");
  word3.push_back("will");
  word3.push_back("pass");
  REQUIRE(grammap.find(word3)!=grammap.end());
    
}


