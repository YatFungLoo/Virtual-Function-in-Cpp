### Makefile ###
EXE=Virtual
INC=\

SRC=\
	src/virtual.cpp\

CXX=clang++
CXX_STD=-std=c++23
CXXFLAGS=-g -Iinclude/
LFLAGS=
LDFLAGS=

.SUFFIXES:

all:	$(EXE)

$(INC): $(SRC)

$(EXE):	$(SRC)
	$(CXX) $(CXX_STD) $(CXXFLAGS) $(SRC) -o $@ $(LFLAGS) $(LDFLAGS)

clean:
	rm -f $(EXE)
