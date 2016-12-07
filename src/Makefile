###################################################
# Sample Makefile for HW8
# Ben Ramsay 
# 2016-12-5
#
###################################################

###############################
# Compiler commands
###############################
GCC = g++
CPPFLAGS = -std=c++11 -pedantic -Wall -Wextra -g -I../include

###############################
# pa.hpp variables
###############################
# where to look for .hpp files
INC_DIR = ../include
# where to put .o files
OBJ_DIR = ./obj
# where to put executables
BIN_DIR = ../bin
 
# make sure the output directories exists...
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

###############################
# targets 
###############################

all: $(BIN_DIR)/a9 $(BIN_DIR)/unitTest

test: $(BIN_DIR)/unitTest
	$(BIN_DIR)/unitTest

$(BIN_DIR)/a9: $(OBJ_DIR)/a9.o $(OBJ_DIR)/Ngram.o $(OBJ_DIR)/Cosine.o $(OBJ_DIR)/textBase.o 
	$(GCC) $(CPPFLAGS) $(OBJ_DIR)/a9.o $(OBJ_DIR)/Ngram.o $(OBJ_DIR)/Cosine.o $(OBJ_DIR)/textBase.o -o $(BIN_DIR)/a9

$(BIN_DIR)/unitTest: $(OBJ_DIR)/unitTests-NgramCollection.o $(OBJ_DIR)/unitTestDriver.o $(OBJ_DIR)/Ngram.o $(OBJ_DIR)/textBase.o $(OBJ_DIR)/Cosine.o
	$(GCC) $(CPPFLAGS) $(OBJ_DIR)/unitTestDriver.o $(OBJ_DIR)/unitTests-NgramCollection.o $(OBJ_DIR)/Ngram.o $(OBJ_DIR)/Cosine.o $(OBJ_DIR)/textBase.o -o $(BIN_DIR)/unitTest

$(OBJ_DIR)/a9.o: a9.cpp 
	$(GCC) $(CPPFLAGS) -c a9.cpp -o $(OBJ_DIR)/a9.o

$(OBJ_DIR)/unitTestDriver.o: unitTestDriver.cpp 
	$(GCC) $(CPPFLAGS) -c unitTestDriver.cpp -o $(OBJ_DIR)/unitTestDriver.o

$(OBJ_DIR)/unitTests-NgramCollection.o: unitTests-NgramCollection.cpp 
	$(GCC) $(CPPFLAGS) -c unitTests-NgramCollection.cpp -o $(OBJ_DIR)/unitTests-NgramCollection.o

$(OBJ_DIR)/Ngram.o: Ngram.cpp $(INC_DIR)/Ngram.hpp 
	$(GCC) $(CPPFLAGS) -c Ngram.cpp -o $(OBJ_DIR)/Ngram.o

$(OBJ_DIR)/Cosine.o: Cosine.cpp $(INC_DIR)/Cosine.hpp
	$(GCC) $(CPPFLAGS) -c Cosine.cpp -o $(OBJ_DIR)/Cosine.o

$(OBJ_DIR)/textBase.o: textBase.cpp $(INC_DIR)/textBase.hpp $(INC_DIR)/Ngram.hpp $(INC_DIR)/Cosine.hpp
	$(GCC) $(CPPFLAGS) -c textBase.cpp -o $(OBJ_DIR)/textBase.o


###############################
# "utility" rules
###############################
# the .PHONY line says these targets aren't expected to generate files named after the target
.PHONY: clean test

# clean up generated files
clean:
	@echo removing generated files...
	@rm -f $(OBJ_DIR)/*.o 
