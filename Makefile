CXX=g++
CXXFLAGS=-std=c++17 -O2

all: EmergenceSim

EmergenceSim: src/main.cpp src/map.cpp
	$(CXX) $(CXXFLAGS) -o EmergenceSim src/main.cpp src/map.cpp

clean:
	rm -f EmergenceSim
