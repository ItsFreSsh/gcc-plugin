CXX = g++

# Flags for the C++ compiler
CXXFLAGS = -std=c++17 -fno-rtti

# Determine the plugin-dir and add it to the flags
PLUGINDIR=$(shell $(CXX) -print-file-name=plugin)
CXXFLAGS += -I$(PLUGINDIR)/include

# Source files
SRC = $(wildcard src/*.cpp)

# Object files
OBJ = $(SRC:.cpp=.o)

# Input directory and file
INPUT = testfiles
TESTFILE = testfile.c

# top level goal: build plugin as a shared library
all: clean plugin.so

plugin.so: $(OBJ)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c -o $@ $<

clean:
	rm -f $(OBJ) main.o plugin.so out err

run: plugin.so
	$(CXX) -fplugin=./plugin.so -c $(INPUT)/$(TESTFILE) -o /dev/null 1>out 2>err
 
.PHONY: all clean check