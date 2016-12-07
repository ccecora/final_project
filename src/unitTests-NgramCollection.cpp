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
  REQUIRE(tb.getThreshold == .5);
  tb.parse('m');
  REQUIRE(tb.getThreshold == .7);
  tb.parse('b');
  REQUIRE(tb.getThreshold == .7);
  tb.parse('l');
  REQUIRE(tb.getThreshold == .9);

}

TEST_CASE("increment", "[increment]") {


}



TEST_CASE("readText", "[readText]") {


}


TEST_CASE("buildNgram", "[buildNgram]") {



}


