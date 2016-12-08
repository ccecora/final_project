#include "textBase.hpp"


/* function to print how to call this program */
void printUsage() {
  std::cout << "Usage: a9 [input file location] [sensitivity letter (l:low, m:medium, h:high)]\n";
}


int main(int argc, char** argv) {
  if (argc < 2 || argc > 3) {
    printUsage();
    return 1;
  }

  std::string groupFile = argv[1];
  char deg = std::string(argv[2])[0];

  textBase master(groupFile, deg);

  return 0;
}

