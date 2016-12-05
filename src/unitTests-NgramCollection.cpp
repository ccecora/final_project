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
  REQUIRE(tb.parse() == "");
  REQUIRE(tb.parse('h') == "");
  REQUIRE(tb.parse('m') == "");
  REQUIRE(tb.parse('l') == "");

}

TEST_CASE("increment", "[increment]") {


}



TEST_CASE("readText", "[readText]") {


}


TEST_CASE("buildNgram", "[buildNgram]") {



}


