CXX = g++
# Flags for the C++ compiler: C++11 and all the warnings
CXXFLAGS = -std=c++17 -fno-rtti
# Workaround for an issue of -std=c++11 and the current GCC headers
CXXFLAGS += -Wno-literal-suffix

# Determine the plugin-dir and add it to the flags
PLUGINDIR=$(shell $(CXX) -print-file-name=plugin)
CXXFLAGS += -I$(PLUGINDIR)/include

INPUT = testfiles
TESTFILE = testfile.c

# top level goal: build our plugin as a shared library
all: clean plugin.so

plugin.so: main.o
	$(CXX) $(LDFLAGS) -shared -o $@ $<

main.o : src/main.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c -o $@ $<

clean:
	rm -f main.o plugin.so out err

run: plugin.so
	$(CXX) -fplugin=./plugin.so -c $(INPUT)/$(TESTFILE) -o /dev/null 1>out 2>err
 
.PHONY: all clean check