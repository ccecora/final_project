//Chase Cecora
//Section 1, cs120
//Final Project
//Input Functions

//This is my part a from hwk 7, which I will modify to work with the classes created for this project to
//import text from the a text doc, create a vector for each doc of the word counts of the all the unique words in
//both documents.

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

using namespace std;
struct wordCount
{
  string word1;
  int count;
};

//contains comparison vectors, or vectors for comparison
struct compVect
{
  vector<wordCount> doc1;
  vector<wordCount> doc2;
};

//Takes input and puts it in a vector of strings
vector<string> readInput(){
  vector<string> input;
  string space;
  while (!cin.fail() && !cin.eof()) { //If end of input not reached keep going
    cin >> space;
    input.push_back(space);
  }
  
  cin.clear();
  cin.ignore(61300, '\n');
  return input;
}

//Takes string vector and formats it into a vector of bigrams
vector<wordCount> convert2wordVect(vector<string> in){
  vector<wordCount> wordVec(in.size());
  string temp;
  for(unsigned j = 0; j<in.size(); j++){
    temp = in[j];
    wordVec[j].word.assign(temp);
    wordVec[j].count = 1;
  }
  for(unsigned k = 0; k<wordVec.size(); k++){
    for(unsigned h = k+1; h<WordVec.size(); h++){
      if(initial[k].word == initial[h].word){
	initial.erase(initial.begin()+h);
	initial[k].count++;
      }
    }
  }
}

//Creates vectors for comparison and puts them in a srtuct for easy access
//makes sure each vector is of equivalent size and is n dimensional for
//n total unique words between both documents
compVect convert2compVect(vector<wordCount> docA, vector<wordCount> docB){
  //add empty wordcounts for docA, then docB (make sure same size!)
  
  //sort wordcounts by alphabetical order

  //insert in compVect to return
}
